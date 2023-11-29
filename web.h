#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QPainter>
#include <QPoint>

class Web
{
public:
    Web();

    void drawWeb(QPainter *painter, const QPoint &StartPoint, bool isItDraw);
};

#endif  // WEB_H

