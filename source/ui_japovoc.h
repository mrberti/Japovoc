/********************************************************************************
** Form generated from reading UI file 'japovoc.ui'
**
** Created: Tue 25. May 21:40:24 2010
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Japovoc
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *btClose;

    void setupUi(QWidget *Japovoc)
    {
        if (Japovoc->objectName().isEmpty())
            Japovoc->setObjectName(QString::fromUtf8("Japovoc"));
        Japovoc->resize(303, 202);
        horizontalLayout_2 = new QHBoxLayout(Japovoc);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Japovoc);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_6 = new QLabel(Japovoc);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(Japovoc);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_3 = new QLabel(Japovoc);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(Japovoc);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(Japovoc);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        btClose = new QPushButton(Japovoc);
        btClose->setObjectName(QString::fromUtf8("btClose"));

        verticalLayout_3->addWidget(btClose);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(Japovoc);
        QObject::connect(btClose, SIGNAL(clicked()), Japovoc, SLOT(close()));

        QMetaObject::connectSlotsByName(Japovoc);
    } // setupUi

    void retranslateUi(QWidget *Japovoc)
    {
        Japovoc->setWindowTitle(QApplication::translate("Japovoc", "Japovoc", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Japovoc", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">Japovoc</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Japovoc", "<h1>\346\227\245\346\234\254\350\252\236</h1>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Japovoc", "Japenese vocab trainer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Japovoc", "Author: Simon Bertling", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Japovoc", "Email: berti.x@gmx.de", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Japovoc", "This programm is a stub! Please come back later.", 0, QApplication::UnicodeUTF8));
        btClose->setText(QApplication::translate("Japovoc", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Japovoc: public Ui_Japovoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAPOVOC_H
