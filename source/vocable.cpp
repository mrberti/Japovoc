#include "vocable.h"

quint32	Vocable::maxID = 0;

Vocable::Vocable()
{
	id = ++maxID;
	lesson = 0;
}

Vocable::Vocable(quint32 id, quint16 lesson, QString langOrigin, QList<reading_t> readings, QList<translation_t> translations, QFont *fontOrigin, QFont *fontTranslation)
	: id(id), lesson(lesson), langOrigin(langOrigin), readings(readings), translations(translations), fontOrigin(fontOrigin), fontTranslation(fontTranslation)
{
	// assert that maxID ist always the biggest value
	if(id > maxID)
		maxID = id;
	maxID++;
	//qDebug("voc id=%d lesson=%d", this->id, this->lesson);
}

Vocable::~Vocable()
{
	qDebug("Vocable destroyed");
}

void Vocable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	//QString blub("deine mudda");
	painter->setFont(*fontOrigin);
	painter->drawText(0,20,langOrigin);
	painter->drawText(0,50,readings.first().reading);
	qDebug("blubbi");
}

QString Vocable::print()
{
	QString str;
	str = QString(" >> ID = %1, Lesson = %2").arg(this->id).arg(this->lesson);
	str += " langOrigin = " + this->langOrigin;
	str += " readingsfirst = " + this->readings.first().reading;
	str += " translatioinsfirst = " + this->translations.first().meaning;
	return str;
}
