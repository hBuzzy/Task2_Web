#include "widget.h"
#include "web.h"

#include <QPainter>
#include <QMouseEvent>
#include <QObject>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    isDrawing_ = 0;
    web_ = new Web(this);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *){
    if(isDrawing_) {
        QPainter painter;
        web_->SetWeb(rect(), pos_);
        painter.begin(this);
        QList currentLines = web_->GetWebLines();

        for (int i = 0; i < currentLines.size(); i++) {
            painter.drawLine(currentLines[i]);
        }
        QList currentEllipses = web_->GetWebEllipses();

        for (int i = 0; i < currentEllipses.size(); i++) {
            painter.drawEllipse(currentEllipses[i]);
        }
        painter.end();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (!isDrawing_) return;
    this->pos_ = event->pos();
    if (this->pos_.x() < 0) this->pos_.setX(0);
    if (this->pos_.x() > width()) this->pos_.setX(width());
    if (this->pos_.y() < 0) this->pos_.setY(0);
    if (this->pos_.y() > height()) this->pos_.setY(height());
    this->update();
}

void Widget::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton) isDrawing_=1;
    this->pos_ = event->pos();
    setCursor(Qt::IBeamCursor);
    this->update();
}

void Widget::mouseReleaseEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton) isDrawing_=0;
    setCursor(Qt::ArrowCursor);
    this->update();
}
