/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created: Thu 3. Jun 18:57:37 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *lbKanjiFontSample;
    QPushButton *btEditKanjiFont;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lbPrimaryReadingFontSample;
    QPushButton *btEditPrimaryReadingFont;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lbReadingFontSample;
    QPushButton *btEditReadingFont;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lbOkuriganaFontSample;
    QPushButton *btEditOkuriganaFont;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lbPrimaryTranslationFontSample;
    QPushButton *btEditPrimaryTranslationFont;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lbTranslationFontSample;
    QPushButton *btEditTranslationFont;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btOk;
    QPushButton *btApply;
    QPushButton *btCancel;
    QPushButton *btResetPreferences;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QString::fromUtf8("Preferences"));
        Preferences->resize(479, 296);
        verticalLayout_3 = new QVBoxLayout(Preferences);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(Preferences);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_8 = new QHBoxLayout(tab_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbKanjiFontSample = new QLabel(tab_2);
        lbKanjiFontSample->setObjectName(QString::fromUtf8("lbKanjiFontSample"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Mincho"));
        font.setPointSize(26);
        lbKanjiFontSample->setFont(font);
        lbKanjiFontSample->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(lbKanjiFontSample);

        btEditKanjiFont = new QPushButton(tab_2);
        btEditKanjiFont->setObjectName(QString::fromUtf8("btEditKanjiFont"));

        horizontalLayout->addWidget(btEditKanjiFont);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lbPrimaryReadingFontSample = new QLabel(tab_2);
        lbPrimaryReadingFontSample->setObjectName(QString::fromUtf8("lbPrimaryReadingFontSample"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS PGothic"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lbPrimaryReadingFontSample->setFont(font1);
        lbPrimaryReadingFontSample->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(lbPrimaryReadingFontSample);

        btEditPrimaryReadingFont = new QPushButton(tab_2);
        btEditPrimaryReadingFont->setObjectName(QString::fromUtf8("btEditPrimaryReadingFont"));

        horizontalLayout_4->addWidget(btEditPrimaryReadingFont);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lbReadingFontSample = new QLabel(tab_2);
        lbReadingFontSample->setObjectName(QString::fromUtf8("lbReadingFontSample"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Gothic"));
        font2.setPointSize(12);
        lbReadingFontSample->setFont(font2);
        lbReadingFontSample->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(lbReadingFontSample);

        btEditReadingFont = new QPushButton(tab_2);
        btEditReadingFont->setObjectName(QString::fromUtf8("btEditReadingFont"));

        horizontalLayout_2->addWidget(btEditReadingFont);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        lbOkuriganaFontSample = new QLabel(tab_2);
        lbOkuriganaFontSample->setObjectName(QString::fromUtf8("lbOkuriganaFontSample"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS PMincho"));
        font3.setPointSize(12);
        lbOkuriganaFontSample->setFont(font3);
        lbOkuriganaFontSample->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_5->addWidget(lbOkuriganaFontSample);

        btEditOkuriganaFont = new QPushButton(tab_2);
        btEditOkuriganaFont->setObjectName(QString::fromUtf8("btEditOkuriganaFont"));

        horizontalLayout_5->addWidget(btEditOkuriganaFont);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        lbPrimaryTranslationFontSample = new QLabel(tab_2);
        lbPrimaryTranslationFontSample->setObjectName(QString::fromUtf8("lbPrimaryTranslationFontSample"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        lbPrimaryTranslationFontSample->setFont(font4);
        lbPrimaryTranslationFontSample->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_7->addWidget(lbPrimaryTranslationFontSample);

        btEditPrimaryTranslationFont = new QPushButton(tab_2);
        btEditPrimaryTranslationFont->setObjectName(QString::fromUtf8("btEditPrimaryTranslationFont"));

        horizontalLayout_7->addWidget(btEditPrimaryTranslationFont);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lbTranslationFontSample = new QLabel(tab_2);
        lbTranslationFontSample->setObjectName(QString::fromUtf8("lbTranslationFontSample"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Times New Roman"));
        font5.setPointSize(14);
        lbTranslationFontSample->setFont(font5);
        lbTranslationFontSample->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(lbTranslationFontSample);

        btEditTranslationFont = new QPushButton(tab_2);
        btEditTranslationFont->setObjectName(QString::fromUtf8("btEditTranslationFont"));

        horizontalLayout_6->addWidget(btEditTranslationFont);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(435, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btOk = new QPushButton(Preferences);
        btOk->setObjectName(QString::fromUtf8("btOk"));

        horizontalLayout_3->addWidget(btOk);

        btApply = new QPushButton(Preferences);
        btApply->setObjectName(QString::fromUtf8("btApply"));

        horizontalLayout_3->addWidget(btApply);

        btCancel = new QPushButton(Preferences);
        btCancel->setObjectName(QString::fromUtf8("btCancel"));

        horizontalLayout_3->addWidget(btCancel);

        btResetPreferences = new QPushButton(Preferences);
        btResetPreferences->setObjectName(QString::fromUtf8("btResetPreferences"));

        horizontalLayout_3->addWidget(btResetPreferences);


        verticalLayout_3->addLayout(horizontalLayout_3);

        QWidget::setTabOrder(tabWidget, btOk);
        QWidget::setTabOrder(btOk, btApply);
        QWidget::setTabOrder(btApply, btCancel);
        QWidget::setTabOrder(btCancel, btResetPreferences);
        QWidget::setTabOrder(btResetPreferences, btEditKanjiFont);
        QWidget::setTabOrder(btEditKanjiFont, btEditPrimaryReadingFont);
        QWidget::setTabOrder(btEditPrimaryReadingFont, btEditReadingFont);
        QWidget::setTabOrder(btEditReadingFont, btEditOkuriganaFont);
        QWidget::setTabOrder(btEditOkuriganaFont, btEditPrimaryTranslationFont);
        QWidget::setTabOrder(btEditPrimaryTranslationFont, btEditTranslationFont);

        retranslateUi(Preferences);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "Japovoc Preferences", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Preferences", "&General", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("Preferences", "The font the Kanji appears.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Preferences", "Kanji font:", 0, QApplication::UnicodeUTF8));
        lbKanjiFontSample->setText(QApplication::translate("Preferences", "\346\227\245\346\234\254\350\252\236", 0, QApplication::UnicodeUTF8));
        btEditKanjiFont->setText(QApplication::translate("Preferences", "Edit...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("Preferences", "The font the primary reagin appears.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Preferences", "Primary reading font:", 0, QApplication::UnicodeUTF8));
        lbPrimaryReadingFontSample->setText(QApplication::translate("Preferences", "\343\202\253\343\202\277\343\202\253\343\203\212", 0, QApplication::UnicodeUTF8));
        btEditPrimaryReadingFont->setText(QApplication::translate("Preferences", "Edit...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("Preferences", "The font the readings appear.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("Preferences", "Reading font:", 0, QApplication::UnicodeUTF8));
        lbReadingFontSample->setText(QApplication::translate("Preferences", "\343\201\262\343\202\211\343\201\214\343\201\252", 0, QApplication::UnicodeUTF8));
        btEditReadingFont->setText(QApplication::translate("Preferences", "Edit...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Preferences", "The font the okurigana appear.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Preferences", "Okurigana font:", 0, QApplication::UnicodeUTF8));
        lbOkuriganaFontSample->setText(QApplication::translate("Preferences", "\343\201\212\343\201\217\343\202\212\343\201\214\343\201\252", 0, QApplication::UnicodeUTF8));
        btEditOkuriganaFont->setText(QApplication::translate("Preferences", "Edit...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("Preferences", "The font the primary translation appears.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("Preferences", "Primary translation font:", 0, QApplication::UnicodeUTF8));
        lbPrimaryTranslationFontSample->setText(QApplication::translate("Preferences", "Primary translation", 0, QApplication::UnicodeUTF8));
        btEditPrimaryTranslationFont->setText(QApplication::translate("Preferences", "Edit...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Preferences", "The font the Translation appears.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Preferences", "Translation font:", 0, QApplication::UnicodeUTF8));
        lbTranslationFontSample->setText(QApplication::translate("Preferences", "translation", 0, QApplication::UnicodeUTF8));
        btEditTranslationFont->setText(QApplication::translate("Preferences", "Edit...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Preferences", "&Fonts", 0, QApplication::UnicodeUTF8));
        btOk->setText(QApplication::translate("Preferences", "&Ok", 0, QApplication::UnicodeUTF8));
        btApply->setText(QApplication::translate("Preferences", "&Apply", 0, QApplication::UnicodeUTF8));
        btCancel->setText(QApplication::translate("Preferences", "&Cancel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btResetPreferences->setToolTip(QApplication::translate("Preferences", "Resets the preferences. Changes are applied when the buttons Ok or Apply are clicked.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btResetPreferences->setText(QApplication::translate("Preferences", "&Reset", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
