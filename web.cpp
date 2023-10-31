#include "web.h"

#include <QPolygonF>

void Web::DrawWeb(QPainter *painter) {
  QPen pen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
  painter->setPen(pen);

  int halthDivider = 2;

  painter->drawLine(QPoint(windowRect_.topLeft()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.topRight()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.bottomRight()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.bottomLeft()), cursorPosition_);
  painter->drawLine(QPoint(windowRect_.width() / halthDivider, windowRect_.height()),cursorPosition_);
  painter->drawLine(QPoint(windowRect_.width() / halthDivider, windowRect_.y()),cursorPosition_);
  painter->drawLine(QPoint(windowRect_.width(), windowRect_.height() / halthDivider),cursorPosition_);
  painter->drawLine(QPoint(windowRect_.x(), windowRect_.height() / halthDivider),cursorPosition_);

  QPolygonF innerPolygon;
  QPolygonF outerPolygon;

  innerPolygon << cursorPosition_ + QPointF(-50, -50);
  innerPolygon << cursorPosition_ + QPointF(50, -50);
  innerPolygon << cursorPosition_ + QPointF(100, 0);
  innerPolygon << cursorPosition_ + QPointF(100, 50);
  innerPolygon << cursorPosition_ + QPointF(50, 100);
  innerPolygon << cursorPosition_ + QPointF(-50, 100);
  innerPolygon << cursorPosition_ + QPointF(-100, 50);
  innerPolygon << cursorPosition_ + QPointF(-100, 0);

  outerPolygon << cursorPosition_ + QPointF(-100, -100);
  outerPolygon << cursorPosition_ + QPointF(100, -100);
  outerPolygon << cursorPosition_ + QPointF(200, 0);
  outerPolygon << cursorPosition_ + QPointF(200, 100);
  outerPolygon << cursorPosition_ + QPointF(100, 200);
  outerPolygon << cursorPosition_ + QPointF(-100, 200);
  outerPolygon << cursorPosition_ + QPointF(-200, 100);
  outerPolygon << cursorPosition_ + QPointF(-200, 0);

  painter->drawPolygon(innerPolygon);
  painter->drawPolygon(outerPolygon);
}

bool Web::GetIsDrawingWeb() { return isDrawingWeb_; }

void Web::SetIsDrawingWeb(bool isDrawingWeb) {
  isDrawingWeb_ = isDrawingWeb;
}

void Web::SetCursorPosition(QPoint cursorPosition) {
  cursorPosition_ = cursorPosition;
}
