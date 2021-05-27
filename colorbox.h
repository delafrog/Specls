#ifndef COLORBOX_H
#define COLORBOX_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>

class ColorBox : public QWidget
{
	Q_OBJECT
public:
	ColorBox(QWidget *parent = 0);


	void paintEvent(QPaintEvent *event);

//private slots:
	void setcolor(QColor clr);

private:

	QImage *boxImage;

};

#endif