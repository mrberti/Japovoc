#include "global.h"

#include <QtGui/QApplication>
#include <QTranslator>

#include "japovoc.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Japovoc w;

	SETTINGS_CREATE;

	// set the language
	QTranslator translator;
	if(settings.value("Language").isValid())
		translator.load(settings.value("Language").toString(), "Translations");
	a.installTranslator(&translator);

	a.setApplicationName("Japovoc");
	a.setOrganizationName("MrBerti");
	a.setOrganizationDomain("http://github.com/mrberti");

	w.show();
	return a.exec();
}
