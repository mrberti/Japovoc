#include "japovoc.h"
#include "ui_japovoc.h"

Japovoc::Japovoc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Japovoc)
{
    ui->setupUi(this);
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
