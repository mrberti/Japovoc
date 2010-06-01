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

	VocableFactory vocFac;

	QString errorString = vocFac.readFromXML("../sample_vocable_data.xml");
	if(!errorString.isEmpty())
		QMessageBox::critical(this, tr("Error"), errorString);

	scene.update();
	qDebug("Kazam... did magic!");
	this->close();
}
