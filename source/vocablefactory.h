#ifndef VOCABLEFACTORY_H
#define VOCABLEFACTORY_H

#include "global.h"

#include <QtGui>

#include "vocable.h"

/// This class creates and holds all neede vocables
class VocableFactory
{
public:
	VocableFactory();
	VocableFactory(Vocable::fonts_t fonts);

	Vocable::fonts_t setFonts(Vocable::fonts_t fonts) { this->fonts = fonts; return this->fonts; }
	Vocable::fonts_t getFonts() { return this->fonts; }

	void setScene(QGraphicsScene *scene) { this->scene = scene; }

	void setAllBounds(QRectF rect);

	/// Reads from the vocable data from an XML file an creates the vocables. Returns an error string on parsing errors
	QString readFromXML(QString path);

	/// Adds all vocables to the Graphicsscene. Returns how many vocables were added
	quint32 addAllToScene();

	void setVisible(quint32 id);

	/// Deletes all vocables, if existing. Returns how many vocables were deleted
	quint32 clearVocables();

private:
	/// Parses one Vocable
	QXmlStreamReader::Error parseVocable(QXmlStreamReader *xml);

	QString version;
	QMap<quint32, Vocable*>	vocables;

	Vocable::fonts_t	fonts;
	QGraphicsScene	*scene;
};

#endif // VOCABLEFACTORY_H
