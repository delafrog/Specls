#ifndef COLORBOX_CPP
#define COLORBOX_CPP

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include "colorbox.h"


ColorBox::ColorBox(QWidget *parent ) : QWidget(parent)
{

	//setGeometry(0, 0, 50, 20);
	setFixedSize(50, 20);
	int xx, yy;
	xx = this->rect().width();
	yy = this->rect().height();
	boxImage = new QImage(xx, yy, QImage::Format_RGB32);
	boxImage->fill(0);

	setUpdatesEnabled(true);
	setFocusPolicy(Qt::ClickFocus);

	setcolor(QColor(255, 0, 0, 255));
	setVisible(true);
}
void ColorBox::setcolor(QColor clr)
{
	boxImage->fill(clr);
}
void ColorBox::paintEvent(QPaintEvent *event)
{
	QPainter qp(this);
	qp.drawImage(0,0, *boxImage ); 

	event->accept();
}

#endif