#ifndef WEB_H
#define WEB_H

#include <QObject>

#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <QVector>

class Web : public QWidget
{
    Q_OBJECT

public:
    Web(QWidget* parent = nullptr);
    void DrawHeart(QPainter& painter, const QPointF& point);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QPoint centerPoint_;
    QVector<QPointF> webLines_;
    bool drawing_;
};

#endif  // WEB_H
