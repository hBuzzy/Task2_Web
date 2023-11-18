// widget.cpp
#include "widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QCursor>
#include <QtMath>
#include <cmath> // Для использования M_PI

Widget::Widget(QWidget *parent) : QWidget(parent), drawing_(false) {
  setMouseTracking(true); // Включить отслеживание мыши для mouseMoveEvent
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
  if (drawing_) {
    setCursor(Qt::CrossCursor);
  } else {
    setCursor(Qt::ArrowCursor);
  }
}

void Widget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  drawWeb(&painter, center_);

}

void Widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    drawing_ = true;
    center_ = event->pos();
    setCursorStyle();
    update();
  }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
  if (drawing_) {
    center_ = event->pos();

    // Удерживать курсор в пределах окна виджета
    QPoint globalPos = mapToGlobal(center_);
    int newX = qBound(0, globalPos.x(), width() - 1);
    int newY = qBound(0, globalPos.y(), height() - 1);
    QCursor::setPos(newX, newY);

    update();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && drawing_) {
    drawing_ = false;
    setCursorStyle();
  }
}

void Widget::drawWeb(QPainter *painter, const QPoint &center) {
  if (!drawing_) return; // Не рисовать, если не в режиме рисования

  // Установите стиль рисования
  painter->setPen(QPen(lineColor_, lineWidth_, Qt::SolidLine));

  // Нарисуйте линии, представляющие паутину
  for (int i = 0; i < 8; ++i) {
    double angle = i * 45 * M_PI / 180.0;
    int x = center.x() + 50 * qCos(angle);
    int y = center.y() + 50 * qSin(angle);
    painter->drawLine(center, QPoint(x, y));
  }

  // Соединим линии друг с другом для формирования паутины
  for (int i = 0; i < 8; ++i) {
    double angle1 = i * 45 * M_PI / 180.0;
    double angle2 = (i + 1) * 45 * M_PI / 180.0;

    int x1 = center.x() + 50 * qCos(angle1);
    int y1 = center.y() + 50 * qSin(angle1);

    int x2 = center.x() + 50 * qCos(angle2);
    int y2 = center.y() + 50 * qSin(angle2);

    painter->drawLine(QPoint(x1, y1), QPoint(x2, y2));
  }
}


