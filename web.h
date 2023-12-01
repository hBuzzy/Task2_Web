#ifndef WEB_H
#define WEB_H

#include "widget.h"

class Web : public Widget {
  Q_OBJECT
 public:
  explicit Web(Widget *parent = nullptr);

 public:
  void DrawWeb(QPainter *painter);

 private:
  void mousePressEvent(QMouseEvent *event);
  void paintEvent(QPaintEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void resizeEvent(QResizeEvent *event);
  void keyPressEvent(QKeyEvent *event);

 signals:
};

#endif  // WEB_H
