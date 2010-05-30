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
	qDebug("%d %d %d %d", sceneRect.x(), sceneRect.y(), sceneRect.width(), sceneRect.width());
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
	sceneRect.setRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());  //(QRect(ui->graphicsView->geometry()));
	scene.setSceneRect(sceneRect);
	qDebug("Kazam... did magic!");
	if(voc)
		delete voc;

	Vocable::reading_t reading;
	reading.kanji = ui->leInput->text().at(0);
	reading.yomi = ui->leInput->text().at(1);
	reading.reading = ui->leInput->text();

	readings.push_back(reading);
	fontOrigin = ui->label_2->font();
	voc = new Vocable(1,1,"Japanese", readings, translations, fontOrigin, fontTranslation);
	//scene.addText(ui->leInput->text(),ui->label_2->font());
	scene.addItem(voc);
	scene.update();
}
