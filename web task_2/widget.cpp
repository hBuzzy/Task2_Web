#include "widget.h"

#include "QListWidget"
Widget::Widget(QWidget *parent) : QWidget(parent) {}

void Widget::drawWeb(QPoint center, int radius, QPainter *painter) {
  Web b(center, radius, painter);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *event) {

  if (mousePressed_ == true) {
    QPoint center = pos_;

    int radius;
    if (center.y() >= height() / 2) {
      radius = height() - center.y();
    } else {
      radius = center.y();
    }

    if (width() - center.x() < radius) {
      radius = width() - center.x();
    }
    if (center.x() < radius) {
      radius = center.x();
    }

    QPainter painter;
    painter.begin(this);

    drawWeb(pos_, radius, &painter);
    painter.end();
    update();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  mousePressed_ = false;
  this->unsetCursor();
}

void Widget::mouseMoveEvent(QMouseEvent *event) //
{
  if (event->buttons() & Qt::LeftButton) {
    pos_ = event->pos();
    recta_ = this->rect();
    mousePressed_ = true;
    this->setCursor(Qt::CrossCursor);
    if (!recta_.contains(pos_)) {
      pos_.setX(qMin(qMax(recta_.left(), pos_.x()), recta_.right()));
      pos_.setY(qMin(qMax(recta_.top(), pos_.y()), recta_.bottom()));
      QCursor::setPos(mapToGlobal(pos_));
    }
  }
  repaint();
}

void Widget::mousePressEvent(QMouseEvent *event) { pos_ = event->pos(); }
