// web.h
#ifndef WEB_H
#define WEB_H

#include <QPainter>
#include <QPoint>
#include <QColor>

class Web {
public:
    Web();

    void draw(QPainter *painter, const QPoint &center, bool drawing, int lineWidth, const QColor &lineColor);

private:
    void drawLines(QPainter *painter, const QPoint &center);
};

#endif // WEB_H
