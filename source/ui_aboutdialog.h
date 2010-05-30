/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Sun 30. May 20:18:45 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbTitle;
    QSpacerItem *horizontalSpacer;
    QLabel *lbJapaneseTitle;
    QSpacerItem *verticalSpacer;
    QLabel *lbVersion;
    QLabel *lbAuthor;
    QLabel *lbEmail;
    QLabel *lbWeb;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(244, 113);
        verticalLayout_2 = new QVBoxLayout(AboutDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbTitle = new QLabel(AboutDialog);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        QFont font;
        font.setPointSize(14);
        lbTitle->setFont(font);

        horizontalLayout->addWidget(lbTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbJapaneseTitle = new QLabel(AboutDialog);
        lbJapaneseTitle->setObjectName(QString::fromUtf8("lbJapaneseTitle"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Mincho"));
        font1.setPointSize(16);
        lbJapaneseTitle->setFont(font1);

        horizontalLayout->addWidget(lbJapaneseTitle);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lbVersion = new QLabel(AboutDialog);
        lbVersion->setObjectName(QString::fromUtf8("lbVersion"));

        verticalLayout->addWidget(lbVersion);

        lbAuthor = new QLabel(AboutDialog);
        lbAuthor->setObjectName(QString::fromUtf8("lbAuthor"));

        verticalLayout->addWidget(lbAuthor);

        lbEmail = new QLabel(AboutDialog);
        lbEmail->setObjectName(QString::fromUtf8("lbEmail"));

        verticalLayout->addWidget(lbEmail);

        lbWeb = new QLabel(AboutDialog);
        lbWeb->setObjectName(QString::fromUtf8("lbWeb"));

        verticalLayout->addWidget(lbWeb);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lbTitle->setText(QApplication::translate("AboutDialog", "Japovoc", 0, QApplication::UnicodeUTF8));
        lbJapaneseTitle->setText(QApplication::translate("AboutDialog", "\346\227\245\346\234\254\350\252\236", 0, QApplication::UnicodeUTF8));
        lbVersion->setText(QApplication::translate("AboutDialog", "Version 1.0", 0, QApplication::UnicodeUTF8));
        lbAuthor->setText(QApplication::translate("AboutDialog", "Author: Simon Bertling", 0, QApplication::UnicodeUTF8));
        lbEmail->setText(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Email: berti.x@gmx.de</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lbWeb->setText(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Web: </span><a href=\"http://github.com/mrberti/Japovoc\"><span style=\" text-decoration: underline; color:#0000ff;\">http://github.com/mrberti/Japovoc</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
