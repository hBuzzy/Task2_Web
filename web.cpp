#include "web.h"

#include <QPainterPath>

Web::Web(QWidget* parent): QWidget(parent), isDrawing_(false) {
    setMouseTracking(true);
}

void Web::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 4));

    if (isDrawing_) {
        for (const QPointF& point : webLines_) {
            QPointF lineStart = centerPoint_;
            QPointF lineEnd = point;

            painter.drawLine(lineStart, lineEnd);
            DrawHeart(painter, lineStart);
            DrawHeart(painter, lineEnd);
        }
    }
}

void Web::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDrawing_ = true;
        centerPoint_ = event->pos();
        setCursor(Qt::CrossCursor);
    }
}

void Web::mouseMoveEvent(QMouseEvent* event) {
    if (isDrawing_) {
        QPoint newPoint = event->pos();
        QRect rect = this->rect();
        newPoint.setX(qMin(qMax(newPoint.x(), rect.left()), rect.right()));
        newPoint.setY(qMin(qMax(newPoint.y(), rect.top()), rect.bottom()));

        webLines_.append(newPoint);
        update();
    }
}

void Web::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDrawing_ = false;
        unsetCursor();
    }
}

void Web::DrawHeart(QPainter& painter, const QPointF& point) {
    painter.save();
    painter.setBrush(Qt::red);
    qreal x = point.x();
    qreal y = point.y();
    int size = 15;

    QPainterPath path;
    path.moveTo(x, y + size);
    path.cubicTo(x, y + size * 2.7 / 5, x - size, y + size * 2.7 / 5, x - size, y + size);
    path.cubicTo(x - size, y + size * 4 / 5, x, y + size * 1.7, x, y + size * 1.7);
    path.cubicTo(x, y + size * 1.7, x + size, y + size * 4 / 5, x + size, y + size);
    path.cubicTo(x + size, y + size * 2.7 / 5, x, y + size * 2.7 / 5, x, y + size);

    painter.drawPath(path);
    painter.restore();
}
