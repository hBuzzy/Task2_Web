#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Web;

class Widget : public QWidget {
    Q_OBJECT
    public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    protected:
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    private:
    bool isDrawing_;
    Web *web_;
    QPoint pos_;
};
#endif  // WIDGET_H
