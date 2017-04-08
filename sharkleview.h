#ifndef SHARKLEVIEW_H
#define SHARKLEVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsSvgItem>
#include <QSoundEffect>
#include <QMouseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

class SharkleView : public QGraphicsView
{
	Q_OBJECT
public:
	SharkleView(QWidget *parent = 0);

protected:
	void resizeEvent(QResizeEvent*);
	void mousePressEvent(QMouseEvent*);

public slots:
	void nextFrame();

private:
	QGraphicsScene *gsSharkleScene;
	QList<QString> imgIdle;
	QList<QString> imgWave;
	QList<QSoundEffect*> lSfx;

	quint8 iCurrentAnim;
	quint8 iCurrentFrame;
	QTimer tFrameTimer;
	quint8 iFPS;
	QList<int> lPrevRands;
};

#endif // SHARKLEVIEW_H
