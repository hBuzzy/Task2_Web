#include "widget.h"

#include <QDateTime>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget* parent):
QWidget(parent), web_({{0, 0}, rect().bottomRight() / 2}) {}

Widget::~Widget() = default;

void Widget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QCursor::setPos(KeepCursorInsideWindow(event->pos()));
        isMousePressed_ = true;
        setCursor(Qt::CrossCursor);
        repaint();
    }
}

void Widget::mouseMoveEvent(QMouseEvent* event) {
    if (isMousePressed_) {
        QCursor::setPos(KeepCursorInsideWindow(event->pos()));
        repaint();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent* event) {
    Q_UNUSED(event)
    isMousePressed_ = false;
    unsetCursor();
}

void Widget::resizeEvent(QResizeEvent* event) {
    Q_UNUSED(event)
    web_ = Web({{0, 0}, rect().bottomRight() / 2});
}

void Widget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if (isMousePressed_)
        web_.Draw(painter, mapFromGlobal(QCursor::pos()));
}

QPoint Widget::KeepCursorInsideWindow(const QPoint& pos) {
    auto wndRect = rect();
    return mapToGlobal(QPoint(
        qBound(wndRect.left(), pos.x(), wndRect.right()),
        qBound(wndRect.top(), pos.y(), wndRect.bottom())
    ));
}
