#include "vocable.h"

quint32	Vocable::maxID = 0;

Vocable::Vocable()
{
	// assert that maxID ist always the biggest value
	if(id > maxID)
		maxID = id;
	maxID++;
	qDebug("Vocable created ID = %d, maxID = %d", this->id, this->maxID);
}

Vocable::Vocable(quint32 id, quint16 lesson, QString langOrigin, QList<reading_t> readings, QList<translation_t> translations, QFont *fontOrigin, QFont *fontTranslation)
	: id(id), langOrigin(langOrigin), readings(readings), translations(translations), fontOrigin(fontOrigin), fontTranslation(fontTranslation)
{
	Vocable();
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
