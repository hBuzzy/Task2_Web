#include "web.h"

Web::Web(){}

void Web::drawWeb(QPainter *painter, const QPoint &StartPoint, bool drawCheck){
    {
        if(drawCheck==true){
        int startPointX=StartPoint.x();
        int startPointY=StartPoint.y();
        const int lineLength = 50;
        const int webPointCount = 8;
        QPoint pointsOfWeb[webPointCount];
        double angel = 0;
        for(int i {0}; i < webPointCount; i++){
               angel=angel+(M_PI/4);
               pointsOfWeb[i].setX(startPointX+lineLength*cos(angel));
               pointsOfWeb[i].setY(startPointY+lineLength*sin(angel));
            }
            painter->drawLine(startPointX, startPointY,pointsOfWeb[0].x(), pointsOfWeb[0].y());
            painter->drawLine(pointsOfWeb[0].x(), pointsOfWeb[0].y(),pointsOfWeb[webPointCount-1].x(), pointsOfWeb[webPointCount-1].y());
            for(int i {1}; i < webPointCount; i++){
            painter->drawLine(startPointX, startPointY,pointsOfWeb[i].x(), pointsOfWeb[i].y());
            painter->drawLine(pointsOfWeb[i-1].x(), pointsOfWeb[i-1].y(),pointsOfWeb[i].x(), pointsOfWeb[i].y());
            }
        } else{return;}
    }
}
