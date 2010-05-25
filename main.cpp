#include <QtGui/QApplication>
#include "japovoc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Japovoc w;
    w.show();
    return a.exec();
}
