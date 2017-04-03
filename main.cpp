#include "sharkle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Sharkle w;
	w.show();

	return a.exec();
}
