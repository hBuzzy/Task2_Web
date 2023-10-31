#ifndef WIDGET_H
#define WIDGET_H

#include "web.h"

#include <QWidget>

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
  virtual void resizeEvent(QResizeEvent *event);

 private:
  void AddToTimerInterval(int milliseconds);
  void HoldInFrame(QPoint cursorPosition);

 private:
  Web* web_;
  QTimer *timer_;
  QRect windowRect_;
  QPoint cursorPosition_;
  QPixmap cursorImage_;
  QCursor cursor_;
  int timeInterval_;

};
#endif  // WIDGET_H
