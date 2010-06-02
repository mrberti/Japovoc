#ifndef VOCABLE_H
#define VOCABLE_H

#include <QtGui>

class Vocable : public QGraphicsItem
{
public:

	/// This struct holds one reading of a vocable
	typedef struct {
		bool	primary;		// this reading is exposed
		quint32	id;
		QString yomi;			// on or kun reading
		QString	kanji;			// kanji character
		QString reading;		// kana
		QString okurigana;		// for this kanji
	} reading_t;

	/// This struct holds one translation
	typedef struct {
		bool	primary;		// this meaning is exposed
		quint32	id;
		QString language;		// language of the translation
		QString meaning;		// meaning of the origin word
	} meaning_t;

	/// This struct holds pointer to the fonts
	typedef struct {
		QFont *fontKanji;
		QFont *fontReading;
		QFont *fontMeaning;
		QFont *fontPrimaryOrigin;
		QFont *fontPrimaryTranslation;
	} fonts_t;

	typedef QMap<quint32, reading_t>	readings_t;
	typedef QMap<quint32, meaning_t>	meanings_t;
	/// Key is the language
	typedef QMap<QString, meanings_t>	translations_t;

	/// Constructor
	Vocable();
	Vocable(quint32 id, quint16 lesson, QString langOrigin, readings_t readings, translations_t translations, fonts_t fonts);
	~Vocable();

	fonts_t setFonts(fonts_t fonts) { this->fonts = fonts; return this->fonts; }
	fonts_t getFonts() { return this->fonts; }

	QRectF setBounds(QRectF bounds);

	/// Overrides the virtual function boundingRect() of QGraphicsItem
	virtual QRectF boundingRect() const { return bounds; }

	/// Overrides the virtual function paint() of QGraphicsItem
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	/// Returns a string containing some data about the vocable
	QString print();

private:
	/// Holds the value for the bounding box
	QRectF bounds;

	static quint32			maxID;
	quint32					id;
	quint16					lesson;
	QString					langOrigin;
	readings_t				readings;
	translations_t			translations;

	fonts_t	fonts;
};

#endif // VOCABLE_H
