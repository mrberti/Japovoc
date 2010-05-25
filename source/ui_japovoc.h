/********************************************************************************
** Form generated from reading UI file 'japovoc.ui'
**
** Created: Tue 25. May 18:19:20 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JAPOVOC_H
#define UI_JAPOVOC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Japovoc
{
public:

    void setupUi(QWidget *Japovoc)
    {
        if (Japovoc->objectName().isEmpty())
            Japovoc->setObjectName(QString::fromUtf8("Japovoc"));
        Japovoc->resize(585, 399);

        retranslateUi(Japovoc);

        QMetaObject::connectSlotsByName(Japovoc);
    } // setupUi

    void retranslateUi(QWidget *Japovoc)
    {
        Japovoc->setWindowTitle(QApplication::translate("Japovoc", "Japovoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Japovoc: public Ui_Japovoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAPOVOC_H
