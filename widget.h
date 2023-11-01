#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "web.h"

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();
 protected:
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void paintEvent(QPaintEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);

 private:
  Web web_;
  QRect windowRect_;
  QPoint cursorPosition_;
  bool isDrawing_;
};
#endif  // WIDGET_H
