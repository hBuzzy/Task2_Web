#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtMath>
#include <QCursor>

class Web : public QObject {
    Q_OBJECT
public:
    explicit Web(QObject *parent = nullptr);
    void paint(QWidget *ctx);
    int getAngle(const QPoint& p1, const QPoint& p2);
};
int pi = 180;
int scale = 16;
int scaleParam = 10;
int scaleParamWidth = 3;
int delParam;
#endif // WEB_H
