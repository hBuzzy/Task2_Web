#include "widget.h"
#include "web.h"

#include <QPainter>
#include <QMouseEvent>
#include <QObject>


Widget::Widget(QWidget *parent) : QWidget(parent) {
    drawing_access = 0;
    web = new Web(this);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *){
    if(drawing_access){
        QPainter painter;
        web->SetWeb(rect(), pos);
        painter.begin(this);
        QList currentLines = web->GetWebLines();
        for (int i = 0; i < currentLines.size(); i++) {
            painter.drawLine(currentLines[i]);
        }
        QList currentEllipses = web->GetWebEllipses();
        for (int i = 0; i < currentEllipses.size(); i++) {
            painter.drawEllipse(currentEllipses[i]);
        }
        painter.end();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(!drawing_access)return;
    this->pos = event->pos();
    if(this->pos.x() < 0)this->pos.setX(0);
    if(this->pos.x() > width())this->pos.setX(width());
    if(this->pos.y() < 0)this->pos.setY(0);
    if(this->pos.y() > height())this->pos.setY(height());
    this->update();
}

void Widget::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)drawing_access=1;
    this->pos = event->pos();
    setCursor(Qt::IBeamCursor);
    this->update();
}

void Widget::mouseReleaseEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)drawing_access=0;
    setCursor(Qt::ArrowCursor);
    this->update();
}
