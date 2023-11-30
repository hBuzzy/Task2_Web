#include "web.h"

Web::Web() {}

void Web::drawWeb(QPainter *painter, const QPoint &StartPoint, bool drawCheck) {
        if (drawCheck == true) {
        int startPointX = StartPoint.x();
        int startPointY = StartPoint.y();
        const int kLineLength = 50;
        const int kWebPointCount = 8;
        const int kDivisorOfPi = 4;
        QPoint pointsOfWeb[kWebPointCount];
        double angel = 0;
        for (int i {0}; i < kWebPointCount; i++) {
               angel = angel + (M_PI/kDivisorOfPi);
               pointsOfWeb[i].setX(startPointX + kLineLength * cos(angel));
               pointsOfWeb[i].setY(startPointY + kLineLength * sin(angel));
            }
            painter->drawLine(startPointX, startPointY, pointsOfWeb[0].x(), pointsOfWeb[0].y());
            painter->drawLine(pointsOfWeb[0].x(), pointsOfWeb[0].y(), pointsOfWeb[kWebPointCount - 1].x(), pointsOfWeb[kWebPointCount-1].y());
            for(int i {1}; i < kWebPointCount; i++){
            painter->drawLine(startPointX, startPointY, pointsOfWeb[i].x(), pointsOfWeb[i].y());
            painter->drawLine(pointsOfWeb[i - 1].x(), pointsOfWeb[i - 1].y(), pointsOfWeb[i].x(), pointsOfWeb[i].y());
            }
        } else {
            return;
        }
}
