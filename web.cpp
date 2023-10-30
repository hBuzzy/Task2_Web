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
        int numLines_ = 12;
        double radiusWeb_ = 0.75;
        QVector<QPoint> CenterPoints;

        for (int i = 0; i < numLines_; i++) {
            int angleInDegrees = i * 360 / numLines_;
            QPoint pointOnCircle(centerPoint_.x() + webRadius_ * qCos(qDegreesToRadians(angleInDegrees)),
                                 centerPoint_.y() + webRadius_ * qSin(qDegreesToRadians(angleInDegrees)));
            QPoint centerLine(centerPoint_.x() + (webRadius_ * qCos(qDegreesToRadians(angleInDegrees))) * radiusWeb_,
                              centerPoint_.y() + (webRadius_ * qSin(qDegreesToRadians(angleInDegrees))) * radiusWeb_);
            CenterPoints.append(centerLine);

            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(centerPoint_, pointOnCircle);
            painter.drawPoint(centerLine);
        }

        for (int i = 0; i < numLines_; i++){
            int nextIndex = (i + 1) % numLines_;
            painter.drawLine(CenterPoints[i], CenterPoints[nextIndex]);
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
    if (centerPoint_.x() < webRadius_) centerPoint_.setX(webRadius_);

    if (centerPoint_.x() > width() - webRadius_) centerPoint_.setX(width() - webRadius_);

    if (centerPoint_.y() < webRadius_) centerPoint_.setY(webRadius_);

    if (centerPoint_.y() > height() - webRadius_) centerPoint_.setY(height() - webRadius_);
}
