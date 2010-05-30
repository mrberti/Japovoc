#ifndef JAPOVOC_H
#define JAPOVOC_H

#include <QMainWindow>

#include "aboutdialog.h"

// include the VocableFactory
#include "vocablefactory.h"
#include "vocable.h"

#define VERSION		"0.1"

namespace Ui {
	class Japovoc;
}

class Japovoc : public QMainWindow {
	Q_OBJECT
public:
	Japovoc(QWidget *parent = 0);
	~Japovoc();

	/// Returns the version of this Program
	QString getVersion() { return QString(VERSION); }

public slots:
	/// Opens up the about box
	void showAboutBox();

	/// Does magic, for debugging
	void doMagic();

protected:
	void changeEvent(QEvent *e);

private:
	Ui::Japovoc *ui;

	Vocable *voc;
	QGraphicsScene scene;
	QRect	sceneRect;

	QFont fontOrigin;
	QFont fontTranslation;


};

#endif // JAPOVOC_H
