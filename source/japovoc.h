#ifndef JAPOVOC_H
#define JAPOVOC_H

#include <QMainWindow>

namespace Ui {
    class Japovoc;
}

class Japovoc : public QMainWindow {
    Q_OBJECT
public:
    Japovoc(QWidget *parent = 0);
    ~Japovoc();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Japovoc *ui;
};

#endif // JAPOVOC_H
