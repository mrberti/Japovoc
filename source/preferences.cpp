#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Preferences)
{
	ui->setupUi(this);

	connectAll();
	initFonts();
	initLanguage();
}

Preferences::~Preferences()
{
	delete ui;
}

void Preferences::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void Preferences::initLanguage()
{
	SETTINGS_CREATE;
	if(settings.value("Language").isValid())
	{
		initialLanguage = settings.value("Language").toString();
	}
	else
		initialLanguage = QString("english");

	ui->cbLanguage->addItem(QObject::tr("English"), QString("english"));

	QDir dir("Translations");
	QStringList filter;
	filter << "*.qm";
	QStringList files = dir.entryList(filter, QDir::Files, QDir::Name);

	foreach(QString language, files)
	{
		QString languageText = language.remove(".qm");
		languageText = languageText.at(0).toUpper() + languageText.right(languageText.length()-1);
		ui->cbLanguage->addItem(languageText, language);
	}

	ui->cbLanguage->setCurrentIndex(ui->cbLanguage->findData(QVariant(initialLanguage)));
}

void Preferences::setLanguage()
{
	language = ui->cbLanguage->itemData(ui->cbLanguage->currentIndex()).toString();
	QTranslator translator;
	translator.load(language, "Translations");
	QApplication::installTranslator(&translator);
}

void Preferences::applyChanges()
{
	SETTINGS_CREATE;

	// GENERAL
	settings.setValue("Language", language);

	// FONTS
	settings.beginGroup("Fonts");
	settings.setValue("Kanji", fontKanji);
	settings.setValue("Reading", fontReading);
	settings.setValue("PrimaryReading", fontPrimaryReading);
	settings.setValue("Okurigana", fontOkurigana);
	settings.setValue("Translation", fontTranslation);
	settings.setValue("PrimaryTranslation", fontPrimaryTranslation);
	settings.endGroup();
}

void Preferences::ok()
{
	this->applyChanges();
	this->close();
}

void Preferences::setInitialValues()
{
	fontKanji = fontInitialKanji;
	fontOkurigana = fontInitialOkurigana;
	fontReading = fontInitialReading;
	fontTranslation = fontInitialTranslation;
	fontPrimaryReading = fontInitialPrimaryReading;
	fontPrimaryTranslation = fontInitialPrimaryTranslation;

	ui->lbKanjiFontSample->setFont(fontInitialKanji);
	ui->lbOkuriganaFontSample->setFont(fontInitialOkurigana);
	ui->lbReadingFontSample->setFont(fontInitialReading);
	ui->lbTranslationFontSample->setFont(fontInitialTranslation);
	ui->lbPrimaryReadingFontSample->setFont(fontInitialPrimaryReading);
	ui->lbPrimaryTranslationFontSample->setFont(fontInitialPrimaryTranslation);
}

void Preferences::editKanjiFont()
{
	bool ok = false;
	fontKanji = QFontDialog::getFont(&ok, fontKanji, this, QObject::tr("Select kanji font"));
	ui->lbKanjiFontSample->setFont(fontKanji);
}

void Preferences::editOkuriganaFont()
{
	bool ok = false;
	fontOkurigana = QFontDialog::getFont(&ok, fontOkurigana, this, QObject::tr("Select okurigana font"));
	ui->lbOkuriganaFontSample->setFont(fontOkurigana);
}

void Preferences::editPrimaryReadingFont()
{
	bool ok = false;
	fontPrimaryReading = QFontDialog::getFont(&ok, fontPrimaryReading, this, QObject::tr("Select primary reading font"));
	ui->lbPrimaryReadingFontSample->setFont(fontPrimaryReading);
}

void Preferences::editPrimaryTranslationFont()
{
	bool ok = false;
	fontPrimaryTranslation = QFontDialog::getFont(&ok, fontPrimaryTranslation, this, QObject::tr("Select primary translation font"));
	ui->lbPrimaryTranslationFontSample->setFont(fontPrimaryTranslation);
}

void Preferences::editReadingFont()
{
	bool ok = false;
	fontReading = QFontDialog::getFont(&ok, fontReading, this, QObject::tr("Select reading fFont"));
	ui->lbReadingFontSample->setFont(fontReading);
}

void Preferences::editTranslationFont()
{
	bool ok = false;
	fontTranslation = QFontDialog::getFont(&ok, fontTranslation, this, QObject::tr("Select translation font"));
	ui->lbTranslationFontSample->setFont(fontTranslation);
}

void Preferences::connectAll()
{
	// connect all buttons
	connect(ui->btApply, SIGNAL(clicked()), this, SLOT(applyChanges()));
	connect(ui->btCancel, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->btOk, SIGNAL(clicked()), this, SLOT(ok()));
	connect(ui->btResetPreferences, SIGNAL(clicked()), this, SLOT(setInitialValues()));

	// font buttons
	connect(ui->btEditKanjiFont, SIGNAL(clicked()), this, SLOT(editKanjiFont()));
	connect(ui->btEditOkuriganaFont, SIGNAL(clicked()), this, SLOT(editOkuriganaFont()));
	connect(ui->btEditReadingFont, SIGNAL(clicked()), this, SLOT(editReadingFont()));
	connect(ui->btEditTranslationFont, SIGNAL(clicked()), this, SLOT(editTranslationFont()));
	connect(ui->btEditPrimaryReadingFont, SIGNAL(clicked()), this, SLOT(editPrimaryReadingFont()));
	connect(ui->btEditPrimaryTranslationFont, SIGNAL(clicked()), this, SLOT(editPrimaryTranslationFont()));

	// language
	connect(ui->cbLanguage, SIGNAL(currentIndexChanged(QString)), this, SLOT(setLanguage()));
}

void Preferences::initFonts()
{
	// initial values
	fontInitialKanji = ui->lbKanjiFontSample->font();
	fontInitialReading = ui->lbReadingFontSample->font();
	fontInitialTranslation = ui->lbTranslationFontSample->font();
	fontInitialPrimaryReading = ui->lbPrimaryReadingFontSample->font();
	fontInitialPrimaryTranslation = ui->lbPrimaryTranslationFontSample->font();
	fontInitialOkurigana = ui->lbOkuriganaFontSample->font();

	// read current settings
	SETTINGS_CREATE;
	if(!settings.value("Fonts/Kanji").isValid())
		fontKanji = ui->lbKanjiFontSample->font();
	else
		fontKanji = settings.value("Fonts/Kanji").value<QFont>();

	if(!settings.value("Fonts/Reading").isValid())
		fontReading = ui->lbReadingFontSample->font();
	else
		fontReading = settings.value("Fonts/Reading").value<QFont>();

	if(!settings.value("Fonts/PrimaryReading").isValid())
		fontPrimaryReading = ui->lbPrimaryReadingFontSample->font();
	else
		fontPrimaryReading = settings.value("Fonts/PrimaryReading").value<QFont>();

	if(!settings.value("Fonts/Okurigana").isValid())
		fontOkurigana = ui->lbOkuriganaFontSample->font();
	else
		fontOkurigana = settings.value("Fonts/Okurigana").value<QFont>();

	if(!settings.value("Fonts/Translation").isValid())
		fontTranslation = ui->lbTranslationFontSample->font();
	else
		fontTranslation = settings.value("Fonts/Translation").value<QFont>();

	if(!settings.value("Fonts/PrimaryTranslation").isValid())
		fontPrimaryTranslation = ui->lbPrimaryTranslationFontSample->font();
	else
		fontPrimaryTranslation = settings.value("Fonts/PrimaryTranslation").value<QFont>();

	ui->lbKanjiFontSample->setFont(fontKanji);
	ui->lbOkuriganaFontSample->setFont(fontOkurigana);
	ui->lbReadingFontSample->setFont(fontReading);
	ui->lbTranslationFontSample->setFont(fontTranslation);
	ui->lbPrimaryReadingFontSample->setFont(fontPrimaryReading);
	ui->lbPrimaryTranslationFontSample->setFont(fontPrimaryTranslation);
}
