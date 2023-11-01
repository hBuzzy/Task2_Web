#include <QPainter>
#include <QMouseEvent>
#include <QtMath>
#include <QPen>

#include "web.h"

Web::Web(QWidget *parent) : QWidget{parent} {}

void Web::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    if (isWebDrawing_ == true) {
        QPainter painter(this);
        int numLines = 12;
        double smallRadiusWeb = 0.75;
        QVector<QPoint> centerPoints;

        for (int i = 0; i < numLines; i++) {
            double angleInDegrees = i * 360 / numLines;
            QPoint pointOnCircle(centerPoint_.x() + webRadius * qCos(qDegreesToRadians(angleInDegrees)),
                                 centerPoint_.y() + webRadius * qSin(qDegreesToRadians(angleInDegrees)));
            QPoint centerLine(centerPoint_.x() + (webRadius * qCos(qDegreesToRadians(angleInDegrees))) * smallRadiusWeb,
                              centerPoint_.y() + (webRadius * qSin(qDegreesToRadians(angleInDegrees))) * smallRadiusWeb);
            centerPoints.append(centerLine);

            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(centerPoint_, pointOnCircle);
            painter.drawPoint(centerLine);
        }

        for (int i = 0; i < numLines; i++){
            int nextIndex = (i + 1) % numLines;
            painter.drawLine(centerPoints[i], centerPoints[nextIndex]);
        }
    }
}

void Web::mousePressEvent(QMouseEvent *event) {

    if(event->button() == Qt::LeftButton) {
        centerPoint_ = event->pos();
        isWebDrawing_ = true;
        setCursor(Qt::CrossCursor);
        update();
    }
}

void Web::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    isWebDrawing_ = false;
    setCursor(Qt::ArrowCursor);
    update();
}

void Web::mouseMoveEvent(QMouseEvent *event) {

    if(isWebDrawing_ == true) {
        centerPoint_ = event->pos();
        KeepCursorInWidget();
        update();
    }
}

void Web::KeepCursorInWidget() {
    if (centerPoint_.x() < webRadius) centerPoint_.setX(webRadius);

    if (centerPoint_.x() > width() - webRadius) centerPoint_.setX(width() - webRadius);

    if (centerPoint_.y() < webRadius) centerPoint_.setY(webRadius);

    if (centerPoint_.y() > height() - webRadius) centerPoint_.setY(height() - webRadius);
}
