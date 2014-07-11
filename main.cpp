#include <QApplication>
//#include <QDebug>
#include <QLocale>
#include <QTranslator>
#include "mainwidget.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QTranslator translator;
	translator.load("piskvorky_" + QLocale::system().name());
	app.installTranslator(&translator);

	MainWidget w;
	w.show();

	return app.exec();
}
