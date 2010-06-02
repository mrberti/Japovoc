#include "vocable.h"

quint32	Vocable::maxID = 0;

Vocable::Vocable()
{
	id = ++maxID;
	lesson = 0;
	fontOrigin = 0;
	fontTranslation = 0;
	setVisible(false);
}

Vocable::Vocable(quint32 id, quint16 lesson, QString langOrigin, readings_t readings, QList<translation_t> translations, QFont *fontOrigin, QFont *fontTranslation)
	: id(id), lesson(lesson), langOrigin(langOrigin), readings(readings), translations(translations), fontOrigin(fontOrigin), fontTranslation(fontTranslation)
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
	painter->setFont(*fontOrigin);
	//painter->drawText(bounds.x() + 20, bounds.y() + 35, this->readings.first().kanji);
	//painter->drawText(bounds.x() + 20, bounds.y() + 70, this->readings.first().reading);
	painter->setFont(*fontTranslation);
	painter->drawText(bounds, print());
	//painter->drawText(bounds.x() + 20, bounds.y() + bounds.height() - 20, this->translations.first().meaning);
}

QString Vocable::print()
{
	QString		str;
	reading_t	reading;
	str = QString("Vocable>> ID = %1, Lesson = %2,").arg(this->id).arg(this->lesson);
	str += " langOrigin = " + this->langOrigin;
	str += "\n readings: size = " + QString("%1").arg(this->readings.size());
	foreach(reading, readings)
	{
		str += "\n reading = " + reading.reading;
		str += ", kanji = " + reading.kanji;
		str += ", okurigana = " + reading.okurigana;
		str += ", yomi = " + reading.yomi;
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

