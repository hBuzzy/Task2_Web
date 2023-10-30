#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QPainter>

class Web : public QObject {
    Q_OBJECT
    public:
    explicit Web(QObject *parent = nullptr);

     QList<QLine> GetWebLines();
     QList<QRect> GetWebEllipses();
     void SetWeb(const QRect &windowRect, const QPoint &cursorPosition);

    private:
     QList<QLine> webLines;
     QList<QRect> webEllipses;
};

#endif  // WEB_H
