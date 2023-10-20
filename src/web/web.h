#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QRect>
#include <QPainter>

class Web : public QObject {
    Q_OBJECT
public:
    explicit Web(const QRect&, QObject* parent = nullptr);
    void Draw(QPainter&, const QPoint&);
    Web& operator=(Web&&) noexcept;
private:
    QRect boundingRect_;
};

#endif
