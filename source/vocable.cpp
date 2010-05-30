#include "vocable.h"

Vocable::Vocable()
{
	qDebug("Vocable created");
}

Vocable::Vocable(quint32 id, quint16 lesson, QString langOrigin, QList<reading_t>readings, QList<translation_t>translations, QFont fontOrigin, QFont fontTranslation)
	: id(id), langOrigin(langOrigin), readings(readings), translations(translations), fontOrigin(fontOrigin), fontTranslation(fontTranslation)
{

}

/*Vocable::~Vocable()
{
	qDebug("Vocable destroyed");
}*/

void Vocable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	//QString blub("deine mudda");
	painter->setFont(fontOrigin);
	painter->drawText(0,0,this->langOrigin);
	painter->drawText(0,20,this->readings.first().reading);
	//painter->setBrush(Qt::black);
	//painter->drawRect(0,0,50,50);
	//painter->drawLine(0,0,100,100);
	qDebug("blubbi");
}
