#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "global.h"

#include <QDialog>
#include <QtGui>

namespace Ui {
	class Preferences;
}

class Preferences : public QDialog {
	Q_OBJECT
public:
	Preferences(QWidget *parent = 0);
	~Preferences();

public slots:
	void applyChanges();
	void ok();
	void setInitialValues();

	// font setting functions
	void editKanjiFont();
	void editOkuriganaFont();
	void editTranslationFont();
	void editReadingFont();
	void editPrimaryReadingFont();
	void editPrimaryTranslationFont();

	// language setting functions
	void setLanguage();

protected:
	void changeEvent(QEvent *e);

private:
	void connectAll();
	void initFonts();
	void initLanguage();

	Ui::Preferences *ui;

	QFont fontKanji;
	QFont fontReading;
	QFont fontTranslation;
	QFont fontPrimaryReading;
	QFont fontPrimaryTranslation;
	QFont fontOkurigana;

	QString	language;

	// initial values
	QFont fontInitialKanji;
	QFont fontInitialReading;
	QFont fontInitialTranslation;
	QFont fontInitialPrimaryReading;
	QFont fontInitialPrimaryTranslation;
	QFont fontInitialOkurigana;

	QString	initialLanguage;
};

#endif // PREFERENCES_H
