#ifndef VOCABLE_H
#define VOCABLE_H

#include <QtGui>
//#include <QPainter>
#include <QGraphicsItem>

class Vocable : public QGraphicsItem
{
public:

	/// This struct holds one reading of a vocable
	typedef struct {
		bool	primary;
		QString yomi;
		QString	kanji;
		QString reading;
		QString okurigana;
	} reading_t;

	/// This struct hold one translation
	typedef struct {
		bool	primary;
		QString language;
		QString meaning;
	} translation_t;

	/// Constructor
	Vocable();
	Vocable(quint32 id, quint16 lesson, QString langOrigin, QList<reading_t> readings, QList<translation_t> translations, QFont *fontOrigin, QFont *fontTranslation);
	~Vocable();

	/// Overrides the virtual function boundingRect() of QGraphicsItem
	virtual QRectF boundingRect() const { return bounds; }

	/// Overrides the virtual function paint() of QGraphicsItem
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	/// Returns a string containing some data about the vocable
	QString print();

private:
	/// Holds the value for the bounding box
	QRectF bounds;

	static quint32	maxID;
	quint32		id;
	quint16		lesson;
	QString		langOrigin;
	QList<reading_t>		readings;
	QList<translation_t>	translations;

	QFont *fontOrigin;
	QFont *fontTranslation;
};

#endif // VOCABLE_H
