/********************************************************************************
** Form generated from reading UI file 'japovoc.ui'
**
** Created: Sun 30. May 18:49:50 2010
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
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Japovoc
{
public:
    QAction *actionQuit;
    QAction *actionPreferences;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Japovoc)
    {
        if (Japovoc->objectName().isEmpty())
            Japovoc->setObjectName(QString::fromUtf8("Japovoc"));
        Japovoc->resize(593, 405);
        actionQuit = new QAction(Japovoc);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionPreferences = new QAction(Japovoc);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionAbout = new QAction(Japovoc);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Japovoc);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Mincho"));
        font1.setPointSize(20);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setMaximum(50);
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addLayout(verticalLayout);

        Japovoc->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Japovoc);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Japovoc->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Japovoc);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Japovoc->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Japovoc);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Japovoc->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionPreferences);
        menu->addAction(actionAbout);

        retranslateUi(Japovoc);
        QObject::connect(actionQuit, SIGNAL(activated()), Japovoc, SLOT(close()));

        QMetaObject::connectSlotsByName(Japovoc);
    } // setupUi

    void retranslateUi(QMainWindow *Japovoc)
    {
        Japovoc->setWindowTitle(QApplication::translate("Japovoc", "Japovoc", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("Japovoc", "Quit", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("Japovoc", "Preferences...", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Japovoc", "About...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Japovoc", "Japovoc", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Japovoc", "\346\227\245\346\234\254\350\252\236", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QApplication::translate("Japovoc", "%v/%m", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("Japovoc", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("Japovoc", "Edit", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("Japovoc", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Japovoc: public Ui_Japovoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAPOVOC_H
