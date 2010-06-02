#include "vocablefactory.h"

VocableFactory::VocableFactory()
{
	clearVocables();
}

VocableFactory::VocableFactory(QFont fontOrigin, QFont fontTranslation)
	: fontOrigin(fontOrigin), fontTranslation(fontTranslation)
{
	qDebug("Vocables cleared = %d", clearVocables());
}

QFont VocableFactory::setFontOrigin(QFont font)
{
	fontOrigin = font;
	return fontOrigin;
}

QFont VocableFactory::setFontTranslation(QFont font)
{
	fontTranslation = font;
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
	quint32							id2;		// ids for meanings and readings
	quint16							lesson;
	QString							langOrigin;
	QString							kanji;
	Vocable::reading_t				reading;
	Vocable::meaning_t				meaning;
	Vocable::meanings_t				meanings;
	Vocable::readings_t				readings;
	Vocable::translations_t			translations;

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
				kanji = "";
				langOrigin = xml->attributes().value("lang").toString();
				xml->readNextStartElement();
				name = xml->name().toString();
				while(!xml->isEndElement() && !xml->hasError())
				{
					if(name == "kanji") {
						kanji = xml->readElementText();
						reading.kanji = kanji;
					}
					else if(name == "okurigana") {
						readings[id2].okurigana = xml->readElementText();
					}
					else if(name == "reading") {
						id2 = xml->attributes().value("id").toString().toInt();
						reading.id = id2;
						reading.kanji = kanji;
						reading.primary = xml->attributes().hasAttribute("primary");
						reading.yomi = xml->attributes().value("yomi").toString();
						reading.reading = xml->readElementText();
						readings.insert(id2, reading);
					}
					else {
						xml->raiseError(QString(QObject::tr("Read unexpected tag %1 in line %1").arg(name).arg(xml->lineNumber())));
					}

					xml->readNextStartElement();
					name = xml->name().toString();
				}
			}
			else if(name == "translation") {
				meaning.language = xml->attributes().value("lang").toString();
				xml->readNextStartElement();
				name = xml->name().toString();
				while(!xml->isEndElement() && !xml->hasError())
				{
					if(name == "meaning") {
						id2 = xml->attributes().value("id").toString().toInt();
						meaning.id = id2;
						meaning.meaning = xml->readElementText();
						meaning.primary = xml->attributes().hasAttribute("primary");
						meanings.insert(id2, meaning);
					}
					else {
						xml->raiseError(QString(QObject::tr("Read unexpected tag %1 in line %1").arg(name).arg(xml->lineNumber())));
					}
					translations.insert(meaning.language,meanings);

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

	Vocable *voc = new Vocable(id, lesson, langOrigin, readings, translations, &fontOrigin, &fontTranslation);
	vocables.insert(id, voc);

	return QXmlStreamReader::NoError;
}

quint32 VocableFactory::clearVocables()
{
	quint32 numDeleted = 0;
	quint32 size = vocables.size();
	Vocable *vocable;
	if(size > 0) {
		foreach(vocable, vocables)
		{
			if(vocable) {
				numDeleted++;
				delete vocable;
			}
		}
	}
	return numDeleted;
}

quint32 VocableFactory::addAllToScene()
{
	quint32 numAdded = 0;
	Vocable *vocable;
	foreach(vocable, vocables) {
		scene->addItem(vocable);
		numAdded++;
		qDebug(vocable->print().toAscii());
	}
	scene->update();



	return numAdded;
}

void VocableFactory::setVisible(quint32 id)
{
	if(vocables.contains(id))
		vocables.value(id)->setVisible(true);
}

void VocableFactory::setAllBounds(QRectF rect)
{
	Vocable *vocable;
	foreach(vocable, vocables)
		vocable->setBounds(rect);
}
