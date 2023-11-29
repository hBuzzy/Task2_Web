#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

#include <web.h>

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;

private slots:
  void changeCursor();

private:
  bool isItDraw_;
  QPoint centerOfWeb_;
  Web web_;

};

#endif // WIDGET_H
