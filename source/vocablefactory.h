#ifndef VOCABLEFACTORY_H
#define VOCABLEFACTORY_H

#include <QtGui>

#include "vocable.h"

/// This class creates and holds all neede vocables
class VocableFactory
{
public:
	VocableFactory();
	VocableFactory(QFont fontOrigin, QFont fontTranslation);

	QFont setFontOrigin(QFont font);
	QFont getFontOrigin() { return fontOrigin; }

	QFont setFontTranslation(QFont font);
	QFont getFontTranslation() { return fontTranslation; }

	void setScene(QGraphicsScene *scene) { this->scene = scene; }

	/// Reads from the vocable data from an XML file an creates the vocables. Returns an error string on parsing errors
	QString readFromXML(QString path);

	/// Adds all vocables to the Graphicsscene. Returns how many vocables were added
	quint32 addAllToScene();

	/// Deletes all vocables, if existing. Returns how many vocables were deleted
	quint32 clearVocables();

private:
	/// Parses one Vocable
	QXmlStreamReader::Error parseVocable(QXmlStreamReader *xml);

	QString version;
	QMap<quint32, Vocable*>	vocables;

	QFont fontOrigin, fontTranslation;
	QGraphicsScene	*scene;
};

#endif // VOCABLEFACTORY_H
