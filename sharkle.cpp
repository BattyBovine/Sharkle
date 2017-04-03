#include "sharkle.h"
#include "ui_sharkle.h"

Sharkle::Sharkle(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Sharkle)
{
	this->setWindowFlags(Qt::Widget|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint|Qt::ToolTip);
	this->setAttribute(Qt::WA_NoSystemBackground, true);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->trayicon = new QSystemTrayIcon(QIcon(":/img/icon"));
	QMenu *traymenu = new QMenu("Sharkle Configuration");
//	traymenu->addAction("Keep Sharkle close to your heart", this, SLOT(appAlwaysOnTop()));
//	traymenu->addSeparator();
	traymenu->addAction("Tell Sharkle to eff off", this, SLOT(exitApplication()));
	this->trayicon->setContextMenu(traymenu);
	this->trayicon->show();

	QDesktopWidget desktop;
	QRect screenres = desktop.availableGeometry(desktop.primaryScreen());
	int size = qRound(screenres.height()*0.15f);
	this->setFixedSize(size,size);
	this->move(screenres.width()-size,screenres.height()-size);

	ui->setupUi(this);
	ui->gvSharkle->setStyleSheet("background: transparent");
}

Sharkle::~Sharkle()
{
	delete ui;
}

void Sharkle::exitApplication()
{
	this->trayicon->hide();
	QApplication::quit();
}
