#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])

{

	QApplication a(argc, argv);

	MainWindow w;

	w.show();

	w.setFixedSize(478, 300);

	return a.exec();

}