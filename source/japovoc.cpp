#include "japovoc.h"
#include "ui_japovoc.h"

Japovoc::Japovoc(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Japovoc)
{
	ui->setupUi(this);

	connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAboutBox()));
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
