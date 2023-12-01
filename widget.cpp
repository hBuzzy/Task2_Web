#include "widget.h"

#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>

#include "web.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
  isDrawingWeb_ = false;
  ellipseMoveTimer_ = new QTimer(this);
  AddToTimerInterval(1000);

  int positionYDivider = 2;
  windowRect_ = rect();
  ellipsePosition_ =
      QPoint(windowRect_.x(), windowRect_.height() / positionYDivider);

  connect(ellipseMoveTimer_, &QTimer::timeout, this, &Widget::ShowMessage);
  connect(ellipseMoveTimer_, &QTimer::timeout, this,
          &Widget::UpdateEllipsePosition);
}

Widget::~Widget() {}

void Widget::ShowMessage() { qDebug() << QDateTime::currentDateTime(); }

void Widget::UpdateEllipsePosition() {
  int dx = 10;

  ellipsePosition_.setX(ellipsePosition_.x() + dx);

  repaint();  // Принудительно вызываем событие отрисовки
}

void Widget::keyPressEvent(QKeyEvent *event) {
  int deltaTimerInterval = 50;

  if (event->key() == Qt::Key_Space &&
      event->modifiers() == Qt::ControlModifier) {
    ellipseMoveTimer_->start();
  } else if (event->key() == Qt::Key_Left) {
    AddToTimerInterval(deltaTimerInterval);
  } else if (event->key() == Qt::Key_Right) {
    AddToTimerInterval(-deltaTimerInterval);
  }
}

void Widget::resizeEvent(QResizeEvent *event) {
  Q_UNUSED(event);
  windowRect_ = rect();
}

void Widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    cursorPosition_ = event->pos();
    isDrawingWeb_ = true;
    ShowMousePosition();
    setCursor(Qt::ClosedHandCursor);
    update();
  }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
  if (isDrawingWeb_) {
    cursorPosition_ = event->pos();

    if (cursorPosition_.x() < windowRect_.x()) {
      cursorPosition_.setX(0);
    } else if (cursorPosition_.x() > windowRect_.width()) {
      cursorPosition_.setX(width());
    }

    if (cursorPosition_.y() < windowRect_.y()) {
      cursorPosition_.setY(0);
    } else if (cursorPosition_.y() > windowRect_.height()) {
      cursorPosition_.setY(height());
    }

    ShowMousePosition();
    repaint();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event)
  isDrawingWeb_ = false;
  unsetCursor();
}

void Widget::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  if (isDrawingWeb_) {
    DrawSpider(&painter);
  }

  if (ellipseMoveTimer_->isActive()) {
    DrawEllipse(&painter);
  }
}

void Widget::DrawSpider(QPainter *painter) {
  int width = 5;
  int height = 5;

  painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
  painter->drawEllipse(cursorPosition_, width, height);
}

void Widget::DrawEllipse(QPainter *painter) {
  int width = 20;
  int height = 20;

  painter->setBrush(QBrush(Qt::green));
  painter->drawEllipse(ellipsePosition_, width, height);
}

void Widget::ShowMousePosition() {
  setWindowTitle(QString("x: %1; y: %2;")
                     .arg(cursorPosition_.x())
                     .arg(cursorPosition_.y()));
}

void Widget::AddToTimerInterval(int milliseconds) {
  int minInterval = 100;
  int maxInterval = 1000;

  int newInterval = ellipseMoveTimer_->interval() + milliseconds;

  newInterval = qBound(minInterval, newInterval, maxInterval);

  ellipseMoveTimer_->setInterval(newInterval);
}
