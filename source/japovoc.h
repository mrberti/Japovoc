#ifndef JAPOVOC_H
#define JAPOVOC_H

#include <QMainWindow>
#include <QMessageBox>

#include "aboutdialog.h"
#include "preferences.h"

#include "global.h"

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

	/// Opens up the preferences Dialog
	void showPreferences();

	/// Does magic, for debugging
	void doMagic();

protected:
	void changeEvent(QEvent *e);

private:
	Ui::Japovoc *ui;

	Vocable *voc;
	VocableFactory vocableFactory;
	QGraphicsScene scene;
	QRect	sceneRect;

	QFont *fontA;
	QFont *fontB;
};

#endif // JAPOVOC_H
