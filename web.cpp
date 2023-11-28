// web.cpp
#include "web.h"
#include <QtMath>

Web::Web() {}

void Web::draw(QPainter *painter, const QPoint &center, bool drawing, int lineWidth, const QColor &lineColor) {
    if (!drawing) return;

    painter->setPen(QPen(lineColor, lineWidth, Qt::SolidLine));

    drawLines(painter, center);
}

void Web::drawLines(QPainter *painter, const QPoint &center) {
    const int numLines = 8;
    const int radius = 50;
    const double angleIncrement = 45.0;

    for (int i = 0; i < numLines; ++i) {
        double angle = i * angleIncrement * M_PI / 180.0;
        int x = center.x() + radius * qCos(angle);
        int y = center.y() + radius * qSin(angle);
        painter->drawLine(center, QPoint(x, y));
    }

    const int numSegments = 8;

    for (int i = 0; i < numSegments; ++i) {
        double angle1 = i * angleIncrement * M_PI / 180.0;
        double angle2 = (i + 1) * angleIncrement * M_PI / 180.0;

        int x1 = center.x() + radius * qCos(angle1);
        int y1 = center.y() + radius * qSin(angle1);

        int x2 = center.x() + radius * qCos(angle2);
        int y2 = center.y() + radius * qSin(angle2);

        painter->drawLine(QPoint(x1, y1), QPoint(x2, y2));
    }
}

