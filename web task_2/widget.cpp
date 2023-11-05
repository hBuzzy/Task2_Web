#include "widget.h"

#include "QListWidget"
Widget::Widget(QWidget *parent) : QWidget(parent) {}

void Widget::DrawWeb(QPoint center, int radius, QPainter *painter) {
  Web b(center, radius, painter);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event)
  if (isMousePressed_ == true) {
    QPoint center = position_;

    int radius;
    int half = 2;
    if (center.y() >= height() / half) {
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

    DrawWeb(position_, radius, &painter);
    painter.end();
    update();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event)
  isMousePressed_ = false;
  this->unsetCursor();
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    position_ = event->pos();
    widgetGeometry = this->rect();
    isMousePressed_ = true;
    this->setCursor(Qt::CrossCursor);

    if (!widgetGeometry.contains(position_)) {
      position_.setX(qMin(qMax(widgetGeometry.left(), position_.x()),
                          widgetGeometry.right()));
      position_.setY(qMin(qMax(widgetGeometry.top(), position_.y()),
                          widgetGeometry.bottom()));
      QCursor::setPos(mapToGlobal(position_));
    }
  }
  repaint();
}

void Widget::mousePressEvent(QMouseEvent *event) { position_ = event->pos(); }
