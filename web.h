#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class Web : public QObject {
  Q_OBJECT
 public:
  explicit Web(QObject *parent = nullptr);
  void CreateWeb(const QRect &windowRect, const QPoint &cursorPosition);
  QList<QPolygonF> GetWebPoligons();
  QList<QLine> GetWebLines();

 private:
   int radius_;
   QList<QPolygonF> webPoligons_;
   QList<QLine> webLines_;
};

#endif  // WEB_H
