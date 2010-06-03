#include "japovoc.h"
#include "ui_japovoc.h"

Japovoc::Japovoc(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Japovoc)
{
	ui->setupUi(this);

	// connect all SIGNALS and SLOTS
	connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAboutBox()));
	connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(showPreferences()));

	connect(ui->btMagicButton, SIGNAL(clicked()), this, SLOT(doMagic()));

	sceneRect.setRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());  //(QRect(ui->graphicsView->geometry()));
	scene.setSceneRect(sceneRect);
	ui->graphicsView->setScene(&scene);
}

Japovoc::~Japovoc()
{
	delete ui;
}

void Japovoc::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void Japovoc::showAboutBox()
{
	AboutDialog aboutBox(this);
	aboutBox.exec();
}

void Japovoc::showPreferences()
{
	Preferences preferences(this);
	preferences.exec();
}

void Japovoc::doMagic()
{
	qDebug("Trying some magic...");
	scene.clear();
	sceneRect.setRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
	scene.setSceneRect(sceneRect);

	fontA = new QFont();
	fontB = new QFont();

	*fontA = ui->lbJapaneseTitle->font();
	*fontB = ui->lbTitle->font();

	Vocable::fonts_t fonts;
	fonts.fontKanji = fontA;
	fonts.fontReading = fontA;
	fonts.fontPrimaryOrigin = fontA;
	fonts.fontTranslation = fontB;
	fonts.fontPrimaryTranslation = fontB;

	SETTINGS_CREATE;
	settings.beginGroup("Fonts");
	settings.setValue("Kanji", *fonts.fontKanji);
	settings.setValue("Reading", *fonts.fontReading);
	settings.endGroup();

	vocableFactory.setFonts(fonts);

	QString errorString = vocableFactory.readFromXML("sample_vocable_data.xml");
	if(!errorString.isEmpty())
		QMessageBox::critical(this, tr("Error"), errorString);

	vocableFactory.setScene(&scene);


	vocableFactory.setVisible(1);
	vocableFactory.setAllBounds(sceneRect);

	vocableFactory.addAllToScene();

	scene.update();
	qDebug("Kazam... did magic!");
}
