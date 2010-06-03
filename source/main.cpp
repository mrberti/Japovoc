#include <QtGui/QApplication>

#include <QTranslator>

#include "japovoc.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Japovoc w;

	QTranslator translator;

	translator.load("japovoctr_de","Translations");
	a.installTranslator(&translator);

	a.setApplicationName("Japovoc");
	a.setOrganizationName("MrBerti");
	a.setOrganizationDomain("http://github.com/mrberti");

	w.show();
	return a.exec();
}
