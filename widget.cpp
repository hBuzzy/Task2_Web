#include "widget.h"
#include "web.h"
#include <QPainter>
#include <QMouseEvent>
#include <QCursor>

Widget::Widget(QWidget *parent) : QWidget(parent) {}

Widget::~Widget(){}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    web_.drawWeb(&painter,centerOfWeb_, isItDraw_);
}

void Widget::changeCursor() {
    if (isItDraw_ == true) {
        setCursor(Qt::WaitCursor);
    }
    else {
        setCursor(Qt::ArrowCursor);
    }
}

void Widget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton ) {
        isItDraw_ = true;
        changeCursor();
        centerOfWeb_ = this->mapFromGlobal(QCursor::pos());
        repaint();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isItDraw_ = false;
        changeCursor();
        repaint();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (isItDraw_ == true) {
        changeCursor();
        centerOfWeb_ = this->mapFromGlobal(QCursor::pos());

            if (centerOfWeb_.x() < 0) {
              centerOfWeb_.setX(0);
            } else if (centerOfWeb_.x() > width()) {
              centerOfWeb_.setX(width());
            }

            if (centerOfWeb_.y() < 0) {
              centerOfWeb_.setY(0);
            } else if (centerOfWeb_.y() > height()) {
              centerOfWeb_.setY(height());
            }
        repaint();
    }
}
