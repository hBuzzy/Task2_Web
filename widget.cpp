#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {}
Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    if (BoolDrawing_ == true) {
        QPainter painter(this);
        int numLines_ = 12;
        double distCenterLine = 0.75;
        QVector<QPoint> vecCenterOnLine;

        for (int i = 0; i < numLines_; i++) {
            int angleInDegrees = i * 360 / numLines_;
            QPoint pointOnCircle(CenterPoint_.x() + RadiusCircle_ * qCos(qDegreesToRadians(angleInDegrees)), CenterPoint_.y() + RadiusCircle_ * qSin(qDegreesToRadians(angleInDegrees)));
            QPoint centerLine(CenterPoint_.x() + (RadiusCircle_ * qCos(qDegreesToRadians(angleInDegrees))) * distCenterLine, CenterPoint_.y() + (RadiusCircle_ * qSin(qDegreesToRadians(angleInDegrees))) * distCenterLine);
            vecCenterOnLine.append(centerLine);

            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(CenterPoint_, pointOnCircle);
            painter.drawPoint(centerLine);
        }
        for (int i = 0; i < numLines_; i++){
            int nextIndex = (i + 1) % numLines_;
            painter.drawLine(vecCenterOnLine[i], vecCenterOnLine[nextIndex]);
        }
    }
}
void Widget::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        CenterPoint_ = event->pos();
        BoolDrawing_ = true;
        setCursor(Qt::CrossCursor);
        update();
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    BoolDrawing_ = false;
    setCursor(Qt::ArrowCursor);
    update();
}
void Widget::mouseMoveEvent(QMouseEvent *event) {
    if(BoolDrawing_ == true) {
        CenterPoint_ = event->pos();
        KeepCursorInWidget();
        update();
    }
}
void Widget::KeepCursorInWidget() {
    int margin = RadiusCircle_;
    if (CenterPoint_.x() < margin) CenterPoint_.setX(margin);
    if (CenterPoint_.x() > width() - margin) CenterPoint_.setX(width() - margin);
    if (CenterPoint_.y() < margin) CenterPoint_.setY(margin);
    if (CenterPoint_.y() > height() - margin) CenterPoint_.setY(height() - margin);
}
