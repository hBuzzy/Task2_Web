#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Web;

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(int lag = 500, QWidget *parent = nullptr);
  ~Widget();

 public:
  void StepDrawingWeb();
  void DrawWeb(QPainter *painter);

 protected:
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);
  virtual void paintEvent(QPaintEvent *event);
  virtual void resizeEvent(QResizeEvent *event);

 private:
  QRect windowRect_;
  QPoint cursorPosition_;
  QTimer *drawTimer_;

  Web *web_;

  bool isDrawingWeb_;
  int currentLineIndex_;
  int lag_;
};
#endif  // WIDGET_H
