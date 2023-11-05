#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>

#include "web.h"

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  void DrawWeb(QPoint, int, QPainter *);
  ~Widget();

 protected:
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  virtual void mousePressEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  QPoint position_;
  QRect widgetGeometry;
  bool isMousePressed_;
};
#endif  // WIDGET_H
