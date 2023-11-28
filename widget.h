#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <web.h>

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

 private slots:
  void updateThreshold(int value);
  void updateLineWidth(int value);
  void setCursorStyle();

 private:
  bool isdrawing_;
  QPoint center_;
  int lineWidth_;
  QColor lineColor_;
  Web web_;

  void drawWeb(QPainter *painter, const QPoint &center);
};

#endif  // WIDGET_H
