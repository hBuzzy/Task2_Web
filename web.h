#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QPainter>

class Web : public QObject {
  Q_OBJECT
 public:
  explicit Web(QPoint& cursorPosition, QRect& windowRect, QObject *parent = nullptr) : QObject{parent} {
    cursorPosition_ = cursorPosition;
    windowRect_ = windowRect;
    isDrawingWeb_ = true;
  }

 public:
  bool GetIsDrawingWeb();
  void SetIsDrawingWeb(bool isDrawingWeb);
  void SetCursorPosition(QPoint cursorPosition);
  void DrawWeb(QPainter *painter);

 private:
  QPoint cursorPosition_;
  QRect windowRect_;
  bool isDrawingWeb_;
};

#endif  // WEB_H
