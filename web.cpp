#include "web.h"
#include <QDebug>

Web::Web(QObject *parent) : QObject{parent}{}

QList<QPolygonF> Web::GetWebPoligons() { return webPoligons_; };

QList<QLine> Web::GetWebLines() { return webLines_; };

void Web::CreateWeb(const QRect &windowRect, const QPoint &cursorPosition) {
  webPoligons_.clear();
  webLines_.clear();

  int centerX = cursorPosition.x() - windowRect.topLeft().x();
  int centerY = cursorPosition.y() - windowRect.topLeft().y();
  int numPoints = 8;

  for (int radius = 200; radius >= 50; radius -= 50) {
    QVector<QPointF> points;

    for (int i = 0; i < numPoints; ++i) {
      double angle = 2 * M_PI * i / numPoints;
      double x = centerX + radius * qCos(angle);
      double y = centerY + radius * qSin(angle);

      points.append(QPointF(x, y));
    }

      webPoligons_.append(QPolygonF(points));

      points.clear();
  }

  int divider = 2;
  webLines_.append(QLine(QPoint(centerX, centerY), windowRect.topLeft()));
  webLines_.append(QLine(QPoint(centerX, centerY), windowRect.topRight()));
  webLines_.append(QLine(QPoint(centerX, centerY), windowRect.bottomLeft()));
  webLines_.append(QLine(QPoint(centerX, centerY), windowRect.bottomRight()));
  webLines_.append(QLine(QPoint(centerX, centerY), QPoint(windowRect.width() / divider, 0)));
  webLines_.append(QLine(QPoint(centerX, centerY), QPoint(windowRect.width() / divider, windowRect.height())));
}
