#include "widget.h"

#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  this->setStyleSheet("background-color: pink;");
  timer_ = new QTimer(this);
  AddToTimerInterval(1000);
  windowRect_ = rect();
  cursorImage_ = QPixmap("/Users/alepopa/Desktop/учеба/4 курс 1 семестр СПбГАСУ/Букунов. Qt for C++/Web/cursor.png");
  cursor_ = QCursor(cursorImage_);
  QPoint cursorPosition(0,0);
  web_ = new Web(cursorPosition, windowRect_);
}

Widget::~Widget() {}

void Widget::resizeEvent(QResizeEvent *event) {
  Q_UNUSED(event);
  windowRect_ = rect();
}

void Widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
      cursorPosition_ = event->pos();
      web_->SetCursorPosition(cursorPosition_);
      web_->SetIsDrawingWeb(true);
      setCursor(cursor_);
      repaint();
  }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
  if (web_->GetIsDrawingWeb()) {
      cursorPosition_ = event->pos();
      HoldInFrame(cursorPosition_);
      web_->SetCursorPosition(cursorPosition_);
      repaint();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event);

  web_->SetIsDrawingWeb(false);
  unsetCursor();
}

void Widget::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  if (web_->GetIsDrawingWeb()) {
      web_->DrawWeb(&painter);
  }
}


void Widget::AddToTimerInterval(int milliseconds) {
  int minInterval = 100;
  int maxInterval = 1000;

  int newInterval = timer_->interval() + milliseconds;
  newInterval = qBound(minInterval, newInterval, maxInterval);
  timer_->setInterval(newInterval);
}

void Widget::HoldInFrame(QPoint cursorPosition) {
  if (cursorPosition.x() <= 0 and cursorPosition.y() >= 0) {
    cursorPosition_.setX(0);
  }
  if (cursorPosition.x() >= 0 and cursorPosition.y() < 0) {
    cursorPosition_.setY(0);
  }
  if (cursorPosition.x() < 0 and cursorPosition.y() < 0) {
    cursorPosition_.setX(0);
    cursorPosition_.setY(0);
  }
  if (cursorPosition.x() >= windowRect_.width() and cursorPosition.y() <= windowRect_.height()) {
    cursorPosition_.setX(windowRect_.width());
  }
  if (cursorPosition.x() <= windowRect_.width() and cursorPosition.y() >= windowRect_.height()) {
    cursorPosition_.setY(windowRect_.height());
  }
  if (cursorPosition.x() > windowRect_.width() and cursorPosition.y() > windowRect_.height()) {
    cursorPosition_.setX(windowRect_.width());
    cursorPosition_.setY(windowRect_.height());
  }
}
