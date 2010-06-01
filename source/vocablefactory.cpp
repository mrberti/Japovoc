#include "vocablefactory.h"

VocableFactory::VocableFactory()
{
	fontOrigin = 0;
	fontTranslation = 0;
}

VocableFactory::VocableFactory(QFont *fontOrigin, QFont *fontTranslation)
	: fontOrigin(fontOrigin), fontTranslation(fontTranslation)
{}

QFont *VocableFactory::setFontOrigin(QFont *font)
{
	fontOrigin = font;
	Vocable *vocable;
	foreach(vocable, vocables)
		vocable->setFontOrigin(fontOrigin);
	return fontOrigin;
}

QFont *VocableFactory::setFontTranslation(QFont *font)
{
	fontTranslation = font;
	Vocable *vocable;
	foreach(vocable, vocables)
		vocable->setFontTranslation(fontTranslation);
	return fontTranslation;
}

QString VocableFactory::readFromXML(QString path)
{
	// open the file
	QFile	file(path);
	if(!file.open(QIODevice::ReadOnly))
		return QString(QObject::tr("Could not open file '%1'").arg(path));

	QXmlStreamReader	xml(&file);
	QString name;

	// delete all old vocables
	if(vocables.size() != 0)
		vocables.clear();

	// turn off namespace processing
	xml.setNamespaceProcessing(false);

	xml.readNextStartElement();
	name = xml.name().toString();
	// read the whole file
	while(!xml.atEnd() && !xml.isEndElement() && !xml.hasError())
	{
		if(xml.isStartElement())
		{
			if(xml.name().toString() == "japovoc") {
				// read root element
				QString version = xml.attributes().value(0, "version").toString();
				QString content = xml.attributes().value(0, "content").toString();
				if(content != "vocables")
					xml.raiseError(QString(QObject::tr("readFromXML(): content is not 'vocables' in line %1").arg(xml.lineNumber())));
				this->version = version;
			}
			else if(xml.name() == "vocable")
				// read vocable data
				parseVocable(&xml);
			else
				// everything else raises an error
				xml.raiseError(QString(
						QObject::tr("readFromXML(): expected to read <vocable> or <japovoc> but read <%1> in line %1.")
						.arg(xml.name().toString())
						.arg(xml.lineNumber())));
		}
		xml.readNextStartElement();
		name = xml.name().toString();
	}
	file.close();
	return xml.errorString();
}

QXmlStreamReader::Error VocableFactory::parseVocable(QXmlStreamReader *xml)
{
	QString name = xml->name().toString();

	quint32							id;
	quint16							lesson;
	QString							langOrigin;
	Vocable::reading_t				reading;
	Vocable::translation_t			translation;
	QList<Vocable::reading_t>		readings;
	QList<Vocable::translation_t>	translations;

	if(name == "vocable") {
		id = xml->attributes().value("id").toString().toInt();
		lesson = xml->attributes().value("lesson").toString().toInt();
	}
	else {
		xml->raiseError(QString(QObject::tr("parseVocable(): Expected to read <vocable> in line %1.").arg(xml->lineNumber())));
		return QXmlStreamReader::CustomError;
	}

	xml->readNextStartElement();
	name = xml->name().toString();

	// read until the end element of 'vocable' is read
	while(!xml->isEndElement() && !xml->hasError())
	{
		if(xml->isStartElement()) {
			if(name == "origin") {
				langOrigin = xml->attributes().value("lang").toString();
				xml->readNextStartElement();
				name = xml->name().toString();
				while(!xml->isEndElement() && !xml->hasError())
				{
					if(name == "reading") {
						reading.primary = xml->attributes().hasAttribute("primary");
						reading.yomi = xml->attributes().value("yomi").toString();
						reading.reading = xml->readElementText();
					}
					else if(name == "okurigana") {
						reading.okurigana = xml->readElementText();
					}
					else if(name == "kanji") {
						reading.kanji = xml->readElementText();
					}
					else {
						xml->raiseError(QString(QObject::tr("Read unexpected tag %1 in line %1").arg(name).arg(xml->lineNumber())));
					}

					if(reading.primary)
						readings.prepend(reading);
					else
						readings.append(reading);
					xml->readNextStartElement();
					name = xml->name().toString();
				}
			}
			else if(name == "translation") {
				translation.language = xml->attributes().value("lang").toString();
				xml->readNextStartElement();
				name = xml->name().toString();
				while(!xml->isEndElement() && !xml->hasError())
				{

					if(name == "meaning") {
						translation.meaning = xml->readElementText();
						translation.primary = xml->attributes().hasAttribute("primary");
					}
					else {
						xml->raiseError(QString(QObject::tr("Read unexpected tag %1 in line %1").arg(name).arg(xml->lineNumber())));
					}

					if(translation.primary)
						translations.prepend(translation);
					else
						translations.append(translation);
					xml->readNextStartElement();
					name = xml->name().toString();
				}
			}
			else {
				xml->raiseError(QString(QObject::tr("Read unexpected tag %1 in line %1").arg(name).arg(xml->lineNumber())));
			}
		}
		xml->readNextStartElement();
		name = xml->name().toString();
	}

	if(xml->hasError()) {
		return xml->error();
	}

	Vocable *voc = new Vocable(id, lesson, langOrigin, readings, translations, fontOrigin, fontTranslation);
	vocables.insert(id, voc);

	return QXmlStreamReader::NoError;
}

