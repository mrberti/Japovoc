#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AboutDialog)
{
	ui->setupUi(this);

	ui->lbVersion->setText("Version " + ((Japovoc*)this->parent())->getVersion());
}

AboutDialog::~AboutDialog()
{
	qDebug("Aboutbox closed");
	delete ui;
}

void AboutDialog::changeEvent(QEvent *e)
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
