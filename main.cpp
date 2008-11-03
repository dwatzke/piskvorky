#include <QApplication>
//#include <QDebug>
#include <QLocale>
#include <QTranslator>
#include "mainwidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	MainWidget w;
	w.show();

	QTranslator translator;
	translator.load("piskvorky_" + QLocale::system().name());
	//qDebug() << "Current system locale:" << QLocale::system().name();
	app.installTranslator(&translator);

	return app.exec();
}
