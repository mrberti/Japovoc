#include "vocable.h"

quint32	Vocable::maxID = 0;

Vocable::Vocable()
{
	fonts.fontKanji = 0;
	fonts.fontMeaning = 0;
	fonts.fontPrimaryOrigin = 0;
	fonts.fontPrimaryTranslation = 0;
	fonts.fontReading = 0;
	id = ++maxID;
	lesson = 0;
	setVisible(false);
}

Vocable::Vocable(quint32 id, quint16 lesson, QString langOrigin, readings_t readings, translations_t translations, fonts_t fonts)
	: id(id), lesson(lesson), langOrigin(langOrigin), readings(readings), translations(translations), fonts(fonts)
{
	// assert that maxID ist always the highest value
	if(id > maxID)
		maxID = id;
	maxID++;
	setVisible(false);
}

Vocable::~Vocable()
{
	qDebug("Vocable destroyed");
}

void Vocable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawRect(bounds);
	painter->setFont(*fonts.fontPrimaryOrigin);
	painter->drawText(bounds.x() + 20, bounds.y() + 35, this->readings[1].kanji);
	painter->drawText(bounds.x() + 20, bounds.y() + 70, this->readings[1].reading);
	painter->setFont(*fonts.fontPrimaryTranslation);
	painter->drawText(bounds.x() + 20, bounds.y() + bounds.height() - 20, this->translations.value("german").value(1).meaning);
}

QString Vocable::print()
{
	QString		str;
	reading_t	reading;
	meaning_t	meaning;
	meanings_t	meanings;
	str = QString("\n<<Vocable>>\nID = %1, Lesson = %2,").arg(this->id).arg(this->lesson);
	str += " langOrigin = " + this->langOrigin;
	str += "\nreadings: size = " + QString("%1").arg(this->readings.size());
	foreach(reading, readings)
	{
		str += "\nID = " + QString("%1").arg(reading.id);
		str += ", reading = " + reading.reading;
		str += ", kanji = " + reading.kanji;
		str += ", yomi = " + reading.yomi;
		if(!reading.okurigana.isEmpty())
			str += ", okurigana = " + reading.okurigana;

		foreach(meanings, translations)
		{
			str += "\n-> lang = " + meanings[reading.id].language;
			str += ", ID = " + QString("%1").arg(meanings[reading.id].id);
			str += ", meaning = " + meanings[reading.id].meaning;
		}
	}
	return str;
}

QRectF Vocable::setBounds(QRectF bounds)
{
	   bounds.setX(bounds.x() + 10);
	   bounds.setY(bounds.y() + 10);
	   bounds.setWidth(bounds.width() - 10);
	   bounds.setHeight(bounds.height() - 10);
	   this->bounds = bounds;
	   return this->bounds;
}

