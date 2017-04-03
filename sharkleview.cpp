#include "sharkleview.h"

SharkleView::SharkleView(QWidget *parent) : QGraphicsView(parent)
{
	this->gsSharkleScene = new QGraphicsScene(this);
	this->setScene(this->gsSharkleScene);

	this->imgIdle.append(QString(":/img/sharkle/00"));
	this->imgIdle.append(QString(":/img/sharkle/01"));
	this->imgIdle.append(QString(":/img/sharkle/02"));
	this->imgIdle.append(QString(":/img/sharkle/03"));
	this->imgIdle.append(QString(":/img/sharkle/04"));
	this->imgIdle.append(QString(":/img/sharkle/05"));
	this->imgIdle.append(QString(":/img/sharkle/06"));
	this->imgIdle.append(QString(":/img/sharkle/07"));

	for(int i=0; i<2; i++) {
		this->imgWave.append(QString(":/img/sharkle/08"));
		this->imgWave.append(QString(":/img/sharkle/09"));
		this->imgWave.append(QString(":/img/sharkle/10"));
		this->imgWave.append(QString(":/img/sharkle/11"));
		this->imgWave.append(QString(":/img/sharkle/12"));
		this->imgWave.append(QString(":/img/sharkle/13"));
		this->imgWave.append(QString(":/img/sharkle/14"));
		this->imgWave.append(QString(":/img/sharkle/15"));
	}

	for(int i=0; i<8; i++) {
		QSoundEffect *sfx = new QSoundEffect();
		sfx->setSource(QUrl::fromLocalFile(":/sfx/"+QString::number(i)));
		sfx->setLoopCount(1);
		this->lSfx.append(sfx);
	}

	this->iCurrentAnim = 0;
	this->iCurrentFrame = 0;

	qsrand((uint)QTime::currentTime().msec());

	connect(&this->tFrameTimer,SIGNAL(timeout()),this,SLOT(nextFrame()));
	this->tFrameTimer.start(100);
	this->nextFrame();
}

SharkleView::~SharkleView()
{
	for(int i=0; i<this->lSfx.length(); i++) {
		if(this->lSfx[i]!=0)
			delete this->lSfx[i];
	}
}



void SharkleView::resizeEvent(QResizeEvent*)
{
	this->fitInView(this->gsSharkleScene->sceneRect(),Qt::KeepAspectRatio);
}

void SharkleView::mousePressEvent(QMouseEvent *e)
{
	if(e->button()==Qt::LeftButton) {
		if(this->iCurrentAnim==0) {
			this->iCurrentAnim = 1;
			this->iCurrentFrame = 0;

			int rand = (qrand()%8);
			for(int i=0; i<this->lPrevRands.length(); i++) {
				if(this->lPrevRands[i]==rand) {
					rand = (qrand()%8);
					i = 0;
				}
			}
			this->lSfx[rand]->play();
			this->lPrevRands.append(rand);
			if(this->lPrevRands.length()>4)	this->lPrevRands.removeFirst();
		}
		return;
	}

	QGraphicsView::mousePressEvent(e);
}



void SharkleView::nextFrame()
{
	if(this->iCurrentAnim>0) {	// wave
		if(this->iCurrentFrame<this->imgWave.length()) {
			this->gsSharkleScene->clear();
			this->gsSharkleScene->addItem(new QGraphicsSvgItem(this->imgWave[this->iCurrentFrame]));
			this->iCurrentFrame++;
			return;
		} else {
			this->iCurrentAnim = this->iCurrentFrame = 0;
		}
	}							// idle
	if(this->iCurrentFrame>=this->imgIdle.length())
		this->iCurrentFrame = 0;
	this->gsSharkleScene->clear();
	this->gsSharkleScene->addItem(new QGraphicsSvgItem(this->imgIdle[this->iCurrentFrame]));
	this->iCurrentFrame++;
}
