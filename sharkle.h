#ifndef SHARKLE_H
#define SHARKLE_H

#include <QMainWindow>
#include <QMenu>
#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <QtMath>

//#include "sharkleitem.h"

namespace Ui {
class Sharkle;
}

class Sharkle : public QMainWindow
{
	Q_OBJECT

public:
	explicit Sharkle(QWidget *parent = 0);
	~Sharkle();

public slots:
	void resizeSharkle();
	void exitApplication();

private:
	Ui::Sharkle *ui;
	QSystemTrayIcon *trayicon;
};

#endif // SHARKLE_H
