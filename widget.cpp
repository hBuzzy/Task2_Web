// widget.cpp
#include "widget.h"
#include "web.h"
#include <QPainter>
#include <QMouseEvent>
#include <QCursor>
#include <QtMath>
#include <cmath>

Widget::Widget(QWidget *parent) : QWidget(parent), isdrawing_(false) {
    setMouseTracking(true);
}

Widget::~Widget() {}

void Widget::updateThreshold(int value) {
    lineColor_.setRed(value);
    setCursorStyle();
    update();
}

void Widget::updateLineWidth(int value) {
    lineWidth_ = value;
    update();
}

void Widget::setCursorStyle() {
    if (isdrawing_) {
        setCursor(Qt::CrossCursor);
    } else {
        setCursor(Qt::ArrowCursor);
    }
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    web_.draw(&painter, center_, isdrawing_, lineWidth_, lineColor_);
}

void Widget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isdrawing_ = true;
        center_ = event->pos();
        setCursorStyle();
        update();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (isdrawing_) {
        center_ = event->pos();

        QPoint globalPos = mapToGlobal(center_);
        int newX = qBound(0, globalPos.x(), width() - 1);
        int newY = qBound(0, globalPos.y(), height() - 1);
        QCursor::setPos(newX, newY);

        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && isdrawing_) {
        isdrawing_ = false;
        setCursorStyle();
    }
}
