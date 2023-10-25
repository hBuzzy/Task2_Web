#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QPainter>

class Web : public QObject {
  Q_OBJECT
 public:
  explicit Web(QObject *parent = nullptr);

 public:
  QList<QLine> GetWebLines();
  void SetWeb(const QRect &windowRect, const QPoint &cursorPosition);

 private:
  QList<QLine> webLines_;
  int currentLineIndex_;
};

#endif  // WEB_H
