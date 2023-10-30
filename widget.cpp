#include "widget.h"

#include <QMouseEvent>
#include <QPainter>
#include <QTimer>

#include "web.h"

Widget::Widget(int lag, QWidget *parent) : QWidget(parent) {
  drawTimer_ = new QTimer(this);
  connect(drawTimer_, &QTimer::timeout, this, &Widget::StepDrawingWeb);
  isDrawingWeb_ = false;
  currentLineIndex_ = 0;

  web_ = new Web(this);

  lag_ = lag;
  drawTimer_->start(lag_);
}

Widget::~Widget() {}

void Widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    cursorPosition_ = event->pos();
    setCursor(Qt::WaitCursor);
    isDrawingWeb_ = true;
    web_->SetWeb(windowRect_, cursorPosition_);
    repaint();
    drawTimer_->start(lag_);
  }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
  if (isDrawingWeb_) {
    cursorPosition_ = event->pos();

    if (cursorPosition_.x() < 0) {
      cursorPosition_.setX(0);
    } else if (cursorPosition_.x() > width()) {
      cursorPosition_.setX(width());
    }

    if (cursorPosition_.y() < 0) {
      cursorPosition_.setY(0);
    } else if (cursorPosition_.y() > height()) {
      cursorPosition_.setY(height());
    }

    web_->SetWeb(windowRect_, cursorPosition_);
    repaint();
  }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event)

  isDrawingWeb_ = false;
  unsetCursor();
  drawTimer_->stop();
}

void Widget::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event)

  QPainter painter(this);

  if (isDrawingWeb_ && !web_->GetWebLines().isEmpty()) {
    DrawWeb(&painter);
  }
}

void Widget::resizeEvent(QResizeEvent *event) {
  Q_UNUSED(event);

  windowRect_ = rect();
}

void Widget::DrawWeb(QPainter *painter) {
  painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));

  for (int i = 0; i <= currentLineIndex_; i++) {
    painter->drawLine(web_->GetWebLines()[i]);
  }
}

void Widget::StepDrawingWeb() {
  if (currentLineIndex_ < web_->GetWebLines().size() - 1) {
    currentLineIndex_++;
    repaint();
  } else {
    drawTimer_->stop();
    unsetCursor();
  }
}
