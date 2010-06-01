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
	qDebug("Trying some magic...");
	scene.clear();
	sceneRect.setRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
	scene.setSceneRect(sceneRect);

	vocableFactory.setFontOrigin(ui->lbJapaneseTitle->font());
	vocableFactory.setFontTranslation(ui->lbTitle->font());

	qDebug("Vocables cleared = %d", vocableFactory.clearVocables());

	QString errorString = vocableFactory.readFromXML("../sample_vocable_data.xml");
	if(!errorString.isEmpty())
		QMessageBox::critical(this, tr("Error"), errorString);

	scene.update();
	qDebug("Kazam... did magic!");
}
