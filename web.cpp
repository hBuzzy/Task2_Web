#include "web.h"

#include <QPainter>

Web::Web(Widget *parent) : Widget{parent} {}

void Web::DrawWeb(QPainter *painter) {
  painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));

  int halthDivider = 2;
  int webDevider = 5;
  float webThreadsDisplacement = 1.5;

  painter->drawLine(QPoint(windowRect_.topLeft()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.topRight()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.bottomRight()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.bottomLeft()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.width() / halthDivider, windowRect_.y()),
                    cursorPosition_);
  painter->drawLine(
      QPoint(windowRect_.width() / halthDivider, windowRect_.height()),
      cursorPosition_);

  for (int i = 2; i <= webDevider; i++) {
    int secondLineX =
        windowRect_.width() / halthDivider +
        (cursorPosition_.x() - windowRect_.width() / halthDivider) /
            (i * webThreadsDisplacement);
    int thirdLineX = (windowRect_.topRight().x()) -
                     (windowRect_.topRight().x() - cursorPosition_.x()) / i;
    int fourthLineX = (windowRect_.bottomRight().x()) -
                      (windowRect_.bottomRight().x() - cursorPosition_.x()) / i;
    int sixthLineX = (windowRect_.bottomLeft().x() + cursorPosition_.x()) / i;

    int thirdLineY = (windowRect_.topRight().y() + cursorPosition_.y()) / i;
    int fourthLineY = (windowRect_.bottomRight().y()) -
                      (windowRect_.bottomRight().y() - cursorPosition_.y()) / i;
    int fifthLineY =
        windowRect_.height() - (windowRect_.height() - cursorPosition_.y()) /
                                   (i * webThreadsDisplacement);
    int sixthLineY = (windowRect_.bottomLeft().y()) -
                     (windowRect_.bottomLeft().y() - cursorPosition_.y()) / i;

    painter->drawLine(((windowRect_.topLeft() + cursorPosition_) / i),
                      (QPoint(secondLineX, (cursorPosition_.y()) /
                                               (i * webThreadsDisplacement))));
    painter->drawLine((QPoint(secondLineX, (cursorPosition_.y()) /
                                               (i * webThreadsDisplacement))),
                      QPoint(thirdLineX, thirdLineY));
    painter->drawLine(QPoint(thirdLineX, thirdLineY),
                      QPoint(fourthLineX, fourthLineY));

    painter->drawLine(QPoint(secondLineX, fifthLineY),
                      QPoint(fourthLineX, fourthLineY));

    painter->drawLine(QPoint(sixthLineX, sixthLineY),
                      QPoint(secondLineX, fifthLineY));
    painter->drawLine(QPoint(sixthLineX, sixthLineY),
                      ((windowRect_.topLeft() + cursorPosition_) / i));
  }
}

void Web::paintEvent(QPaintEvent *event) {
  Widget::paintEvent(event);
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  if (isDrawingWeb_) {
    DrawWeb(&painter);
  }
}

void Web::resizeEvent(QResizeEvent *event) {
  Q_UNUSED(event);
  windowRect_ = rect();
}

void Web::mousePressEvent(QMouseEvent *event) {
  Widget::mousePressEvent(event);
}

void Web::mouseMoveEvent(QMouseEvent *event) { Widget::mouseMoveEvent(event); }

void Web::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event)
  isDrawingWeb_ = false;
  unsetCursor();
}

void Web::keyPressEvent(QKeyEvent *event) { Widget::keyPressEvent(event); }
