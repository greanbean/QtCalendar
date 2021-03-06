#ifndef WINDOWDRAG_H
#define WINDOWDRAG_H

#include <QMouseEvent>

#define WINDOW_DRAG \
private:\
QPoint mousePos0, windowPos0;\
bool drag = false;\
bool windowDragEnabled = true;\
public:\
void mousePressEvent(QMouseEvent *event) override\
{\
	if(!windowDragEnabled) return;\
	mousePos0 = event->globalPos();\
	windowPos0 = this->pos();\
	drag = event->button() == Qt::LeftButton;\
}\
void mouseMoveEvent(QMouseEvent *event) override\
{\
	if(!drag)	return;\
	this->move(windowPos0 + event->globalPos() - mousePos0);\
}\
void mouseReleaseEvent(QMouseEvent *) override\
{\
	drag = false;\
}

#endif // WINDOWDRAG_H
