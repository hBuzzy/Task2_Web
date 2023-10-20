#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "web/web.h"

class Widget final : public QWidget {
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() final;
protected:
    void mousePressEvent(QMouseEvent*) final;
    void mouseMoveEvent(QMouseEvent*) final;
    void mouseReleaseEvent(QMouseEvent*) final;
    void resizeEvent(QResizeEvent*) final;
    void paintEvent(QPaintEvent*) final;
private:
    QPoint KeepCursorInsideWindow(const QPoint&);
private:
    bool isMousePressed_ = false;
    Web web_;
};

#endif
