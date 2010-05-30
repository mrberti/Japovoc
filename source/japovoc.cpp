#include "japovoc.h"
#include "ui_japovoc.h"

Japovoc::Japovoc(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Japovoc)
{
	ui->setupUi(this);

	// connect all SIGNALS and SLOTS
	connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAboutBox()));
	connect(ui->btMagicButton, SIGNAL(clicked()), this, SLOT(doMagic()));

	sceneRect.setRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());  //(QRect(ui->graphicsView->geometry()));
	scene.setSceneRect(sceneRect);
	ui->graphicsView->setScene(&scene);
	voc = 0;

	fontOrigin = ui->lbJapaneseTitle->font();
	fontTranslation = ui->lbTitle->font();
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

void Japovoc::doMagic()
{
	scene.clear();
	sceneRect.setRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
	scene.setSceneRect(sceneRect);

	Vocable::reading_t reading;
	QList<Vocable::reading_t> readings;
	QList<Vocable::translation_t> translations;

	Vocable::translation_t translation;
	translation.language = "German";
	translation.meaning = "Deine Mudda";
	translation.primary = true;

	reading.kanji = ui->leInput->text().at(0);
	reading.yomi = ui->leInput->text().at(1);
	reading.reading = ui->leInput->text();

	readings.push_back(reading);
	translations.push_back(translation);
	QString str("Japanese");
	voc = new Vocable(1,1,str, readings, translations, &fontOrigin, &fontTranslation);
	scene.addItem(voc);

	scene.update();
	qDebug("Kazam... did magic!");
}
