# -------------------------------------------------
# Project created by QtCreator 2010-05-30T18:11:58
# -------------------------------------------------
QT += xml \
	xmlpatterns
TARGET = Japovoc
TEMPLATE = app
SOURCES += main.cpp \
	japovoc.cpp \
	aboutdialog.cpp \
	vocable.cpp \
	vocablefactory.cpp \
	preferences.cpp
HEADERS += japovoc.h \
	aboutdialog.h \
	vocable.h \
	vocablefactory.h \
	global.h \
	preferences.h
FORMS += japovoc.ui \
	aboutdialog.ui \
	preferences.ui
TRANSLATIONS = german.ts
DESTDIR = ../bin/
