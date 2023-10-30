#include "web.h"

Web::Web(QPoint center, int radius, QPainter *painter, QObject *parent)
    : QObject{parent} {
  this->center_ = center;
  this->radius_ = radius;
  this->painter_ = painter;

  double radiusParam = 3.5;

  QVector<QPoint> points; // это линии исходящие из центра
  points.append(QPoint(center.x(), center.y() - radius));
  points.append(QPoint(center.x() + radius - radius / radiusParam,
                       center.y() - radius + radius / radiusParam));
  points.append(QPoint(center.x() + radius, center.y()));
  points.append(QPoint(center.x() + radius - radius / radiusParam,
                       center.y() + radius - radius / radiusParam));
  points.append(QPoint(center.x(), center.y() + radius));
  points.append(QPoint(center.x() - radius + radius / radiusParam,
                       center.y() + radius - radius / radiusParam));
  points.append(QPoint(center.x() - radius, center.y()));
  points.append(QPoint(center.x() - radius + radius / radiusParam,
                       center.y() - radius + radius / radiusParam));

  for (int i = 0; i < 8; i++) {
    painter->drawLine(center.x(), center.y(), points[i].x(), points[i].y());
  }
  for (int i = 0; i < 7; i++) {
    painter->drawLine(points[i].x(), points[i].y(), points[i + 1].x(),
                      points[i + 1].y());
  }
  painter->drawLine(points[0].x(), points[0].y(), points[7].x(), points[7].y());
  QPolygon polygon;

  for (int j = 1; j < 6; j++) { // линии которые образуют внутренние линии
    double parametr;
    if (j == 5) {
      parametr = j + 2;
    } else
      parametr = j + 0.5;

    polygon << QPoint(center.x() - radius / parametr, center.y())
            << QPoint(center.x() + (-radius + radius / radiusParam) / parametr,
                      center.y() + (-radius + radius / radiusParam) / parametr)
            << QPoint(center.x(), center.y() - radius / parametr)
            << QPoint(center.x() + (radius - radius / radiusParam) / parametr,
                      center.y() + (-radius + radius / radiusParam) / parametr)
            << QPoint(center.x() + radius / parametr, center.y())
            << QPoint(center.x() + (radius - radius / radiusParam) / parametr,
                      center.y() + (radius - radius / radiusParam) / parametr)
            << QPoint(center.x(), center.y() + radius / parametr)
            << QPoint(center.x() + (-radius + radius / radiusParam) / parametr,
                      center.y() + (radius - radius / radiusParam) / parametr)
            << QPoint(center.x() - radius / parametr, center.y());

    painter->drawPolyline(polygon);
  }
}
