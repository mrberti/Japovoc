#include <QtGui/QApplication>
#include "japovoc.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Japovoc w;

	a.setApplicationName("Japovoc");
	a.setOrganizationName("MrBerti");
	a.setOrganizationDomain("http://github.com/mrberti");

	w.show();
	return a.exec();
}
