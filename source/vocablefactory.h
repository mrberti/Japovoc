#ifndef VOCABLEFACTORY_H
#define VOCABLEFACTORY_H

#include <QtGui>

#include "vocable.h"

/// This class creates and holds all neede vocables
class VocableFactory
{
public:
	VocableFactory();
	VocableFactory(QFont *fontOrigin, QFont *fontTranslation);

	/// Reads from the vocable data from an XML file an creates the vocables. Returns an error string on parsing errors
	QString readFromXML(QString path);

	QFont *setFontOrigin(QFont *font);
	QFont *getFontOrigin() { return fontOrigin; }

	QFont *setFontTranslation(QFont *font);
	QFont *getFontTranslation() { return fontTranslation; }

private:
	/// Parses one Vocable
	QXmlStreamReader::Error parseVocable(QXmlStreamReader *xml);

	QString version;
	QMap<quint32, Vocable*>	vocables;

	QFont *fontOrigin, *fontTranslation;
};

#endif // VOCABLEFACTORY_H
