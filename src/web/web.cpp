#include "web.h"

Web::Web(const QRect &rect, QObject *parent)
: QObject{parent}, boundingRect_(rect) {}

void Web::Draw(QPainter& painter, const QPoint& cursor_pos) {
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));

    painter.drawLine(boundingRect_.topLeft(), cursor_pos);
    painter.drawLine(boundingRect_.topRight(), cursor_pos);
    painter.drawLine(boundingRect_.bottomRight(), cursor_pos);
    painter.drawLine(boundingRect_.bottomLeft(), cursor_pos);

    auto [center_x, center_y] = boundingRect_.size() / 2;
    painter.drawLine({center_x, boundingRect_.top()}, cursor_pos);
    painter.drawLine({center_x, boundingRect_.bottom()}, cursor_pos);
    painter.drawLine({boundingRect_.left(), center_y}, cursor_pos);
    painter.drawLine({boundingRect_.right(), center_y}, cursor_pos);

    painter.drawEllipse(QRect(
        (boundingRect_.topLeft() + cursor_pos) / 2,
        (boundingRect_.bottomRight() + cursor_pos) / 2
    ));
}

Web &Web::operator=(Web&& temp) noexcept {
    boundingRect_ = std::move(temp).boundingRect_;
    return *this;
}
