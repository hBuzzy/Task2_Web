#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Web;

class Widget : public QWidget {
    Q_OBJECT
    public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int drawing_access;

    protected:
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    private:
    Web *web;
    QPoint pos;
};
#endif  // WIDGET_H
