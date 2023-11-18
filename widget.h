#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

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
  void setCursorStyle();  // Добавим полное объявление метода setCursorStyle

 private:
  bool drawing_;
  QPoint center_;
  int lineWidth_;
  QColor lineColor_;

  void drawWeb(QPainter *painter, const QPoint &center);
};

#endif  // WIDGET_H
