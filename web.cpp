#include "web.h"

Web::Web(QObject *parent) : QObject(parent) {

}

void Web::paint(QWidget *ctx) {
    QPainter painter(ctx);

    QPoint center = ctx->mapFromGlobal(QCursor::pos());

    QPen pen = QPen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    QPoint p1(0, 0);
    QPoint p2(ctx->width(), 0);
    QPoint p3(ctx->width(), ctx->height());
    QPoint p4(0, ctx->height());

    QLineF line1(center, p1);
    QLineF line2(center, p2);
    QLineF line3(center, p3);
    QLineF line4(center, p4);

    QPoint endPoints[] = {
        p1,
        {ctx->width() / 3, 0},
        {ctx->width() / 3 * 2, 0},
        p2,
        {ctx->width(), ctx->height() / 2},
        p3,
        {ctx->width() / 3 * 2, ctx->height()},
        {ctx->width() / 3, ctx->height()},
        p4,
        {0, ctx->height() / 2},
    };

    for (QPoint end : endPoints){
        painter.drawLine(center.x(), center.y(), end.x(), end.y());
    }

    for (int i = 0; i < 10; i ++) {
        QPoint localP1(0 + (line1.x1() - line1.x2()) / 10 * i, 0 + (line1.y1() - line1.y2()) / 10 * i);
        QPoint localp2(ctx->width() + (line2.x1() - line2.x2()) / 10 * i, 0 + (line2.y1() - line2.y2()) / 10 * i);
        QPoint localp3(ctx->width() + (line3.x1() - line3.x2()) / 10 * i, ctx->height() + (line3.y1() - line3.y2()) / 10 * i);
        QPoint localp4(0 + (line4.x1() - line4.x2()) / 10 * i, ctx->height() + (line4.y1() - line4.y2()) / 10 * i);

        QRect rect(localP1, localp3);
        painter.drawEllipse(rect);
        //painter.drawArc(rect, getAngle(localp2, localp3), getAngle(localp2, localp4));
        //painter.drawArc(rect, getAngle(localP1, localp2), getAngle(localP1, localp3));

    }
}

int Web::getAngle(const QPoint& p1, const QPoint& p2) {
    qreal dx = p2.x() - p1.x();
    qreal dy = p2.y() - p1.y();
    qreal angle = qAtan2(dy, dx) * 180.0 / M_PI;
    return static_cast<int>(angle * 16);
}
