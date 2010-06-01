#include "vocablefactory.h"

VocableFactory::VocableFactory()
{
}

QXmlStreamReader::Error VocableFactory::readFromXML(QString path)
{
	QFile	file(path);
	// open the file
	if(!file.open(QIODevice::ReadOnly))
		return QXmlStreamReader::CustomError;

	QMap<quint32, Vocable*>	tempVocables;

	QXmlStreamReader	xml(&file);
	QXmlStreamAttribute	attribute;
	QXmlStreamAttributes attributes;

	QString name;

	// turn off namespace processing
	xml.setNamespaceProcessing(false);

	while(!xml.atEnd())
	{
		xml.readNextStartElement();
		if(xml.isEndElement())
			break;
		name = xml.name().toString();

		qDebug("0: " + xml.tokenString().toAscii() + ", name = " + name.toAscii());

		if(xml.isStartDocument()) {}
		else if(xml.isEndDocument()) {}
		else if(xml.isStartElement())
		{
			if(xml.name().toString() == "japovoc") {
				// read root element
				QString version = xml.attributes().value(0, "version").toString();
				QString content = xml.attributes().value(0, "content").toString();
				if(content != "vocables")
					xml.raiseError(QString("readFromXML(): content is not 'vocable' in line %1").arg(xml.lineNumber()));
				this->version = version;
			}
			else if(xml.name() == "vocable")
				parseVocable(&xml);
			else
				xml.raiseError(QString("readFromXML(): expected to read <vocable> but read <" + xml.name().toString() + "> in line %1").arg(xml.lineNumber()));
		}
		else if(xml.isEndElement()) {}
	}
	file.close();
	if(xml.hasError())
	{
		qDebug(xml.errorString().toAscii());
		return xml.error();
	}

	// assert that all old vocables are deleted
	if(vocables.size() != 0)
		vocables.clear();
	vocables = tempVocables;
	return QXmlStreamReader::NoError;
}

QXmlStreamReader::Error VocableFactory::parseVocable(QXmlStreamReader *xml)
{
	QString name = xml->name().toString();
	QString text;

	quint32 id;
	quint16 lesson;
	QString langOrigin;
	Vocable::reading_t	reading;
	Vocable::translation_t	translation;
	QList<Vocable::reading_t> readings;
	QList<Vocable::translation_t> translations;

	if(name == "vocable") {
		id = xml->attributes().value("id").toString().toInt();
		lesson = xml->attributes().value("lesson").toString().toInt();
	}
	else {
		xml->raiseError(QString("parseVocable(): Expected to read <vocable> in line %1").arg(xml->lineNumber()));
		return QXmlStreamReader::CustomError;
	}

	// read until the end element of 'vocable' is read
	while(1) { //!xml->isEndElement() && !xml->hasError()) {
		xml->readNextStartElement();
		if(xml->isEndElement())
			break;
		name = xml->name().toString();
		qDebug("1: " + xml->tokenString().toAscii() + ", name = " + name.toAscii());

		if(xml->hasError()) {
			return xml->error();
		}
		else if(xml->isStartElement()) {
			if(name == "origin") {
				langOrigin = xml->attributes().value("lang").toString();
				while(1)
				{
					xml->readNextStartElement();
					if(xml->isEndElement() || xml->atEnd())
						break;
					name = xml->name().toString();
					qDebug("2: " + xml->tokenString().toAscii() + ", name = " + name.toAscii());
					if(name == "reading") {
						reading.reading = xml->readElementText();
						reading.primary = xml->attributes().hasAttribute("primary");
						reading.yomi = xml->attributes().value("yomi").toString();
					}
					else if(name == "okurigana") {
						reading.okurigana = xml->readElementText();
					}
					else if(name == "kanji") {
						reading.kanji = xml->readElementText();
					}

					if(reading.primary)
						readings.prepend(reading);
					else
						readings.append(reading);
				}
			}
			else if(name == "translation") {
				translation.language = xml->attributes().value("lang").toString();
				while(1)
				{
					xml->readNextStartElement();
					if(xml->isEndElement() || xml->atEnd())
						break;
					name = xml->name().toString();
					qDebug("3: " + xml->tokenString().toAscii() + ", name = " + name.toAscii());
					if(name == "meaning") {
						translation.meaning = xml->readElementText();
						translation.primary = xml->attributes().hasAttribute("primary");
					}
					if(translation.primary)
						translations.prepend(translation);
					else
						translations.append(translation);
				}
			}
			else {
				xml->raiseError(QString("Read unexpected tag " + name.toAscii()));
			}
		}
	}

	if(xml->hasError()) {
		qDebug(QString("Error in parseVocable:" + xml->errorString()).toAscii());
		return xml->error();
	}

	Vocable *voc = new Vocable(id, lesson, langOrigin, readings, translations, fontOrigin, fontTranslation);
	qDebug(voc->print().toAscii());
	vocables.insert(id, voc);

	return QXmlStreamReader::NoError;
}

