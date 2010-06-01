#include "vocable.h"

quint32	Vocable::maxID = 0;

Vocable::Vocable()
{
	id = ++maxID;
	lesson = 0;
	fontOrigin = 0;
	fontTranslation = 0;
}

Vocable::Vocable(quint32 id, quint16 lesson, QString langOrigin, QList<reading_t> readings, QList<translation_t> translations, QFont *fontOrigin, QFont *fontTranslation)
	: id(id), lesson(lesson), langOrigin(langOrigin), readings(readings), translations(translations), fontOrigin(fontOrigin), fontTranslation(fontTranslation)
{
	// assert that maxID ist always the highest value
	if(id > maxID)
		maxID = id;
	maxID++;
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
	painter->drawText(0,20,this->print());
	//painter->drawText(0,50,readings.first().reading);
	qDebug("blubbi");
}

QString Vocable::print()
{
	QString str;
	str = QString("Vocable>> ID = %1, Lesson = %2,").arg(this->id).arg(this->lesson);
	str += " langOrigin = " + this->langOrigin;
	str += ", readingsfirst = " + this->readings.first().reading;
	str += ", yomi = " + this->readings.first().yomi;
	str += ", translatioinsfirst = " + this->translations.first().meaning;
	return str;
}
