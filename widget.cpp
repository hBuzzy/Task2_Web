#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  setMouseTracking(true);
  isDrawing_ = false;
}

void Widget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::black);
  painter.setBrush(Qt::NoBrush);

  windowRect_ = rect();
  if (isDrawing_) {
    setCursor(Qt::CrossCursor);
    web_.CreateWeb(windowRect_, cursorPosition_);
    QList<QPolygonF> webPol = web_.GetWebPoligons();
    QList<QLine> webLine = web_.GetWebLines();
    for (int i = 0; i < webPol.length(); i++) {
        painter.drawPolygon(webPol[i]);
    }
    painter.drawLines(webLine);
  } else {
      unsetCursor();
    }
  }

void Widget::mouseMoveEvent(QMouseEvent *event) {
  cursorPosition_ = event->pos();
  if (cursorPosition_.x() < 0) { cursorPosition_.setX(0); }
  if (cursorPosition_.x() > width()) { cursorPosition_.setX(width()); }
  if (cursorPosition_.y() < 0) { cursorPosition_.setY(0); }
  if (cursorPosition_.y() > height()) { cursorPosition_.setY(height()); }
  QCursor::setPos(mapToGlobal(cursorPosition_));

  repaint();
}


void Widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    isDrawing_ = true;
    update();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    isDrawing_ = false;
    update();
  }
}

Widget::~Widget() {}
