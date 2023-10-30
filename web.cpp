#include "web.h"



Web::Web(QObject *parent) : QObject{parent} {}

QList<QLine> Web::GetWebLines() { return webLines; }
QList<QRect> Web::GetWebEllipses() { return webEllipses; }

void Web::SetWeb(const QRect &windowRect, const QPoint &cursorPosition) {
    float pi = 3.14;
    webLines.clear();
    for(int i = 0; i < 8; i++){
        webLines.append(QLine(QPoint(-windowRect.width(), cursorPosition.y() - (cursorPosition.x() + windowRect.width())*tan(i*pi/8)),
                              QPoint(cursorPosition.x() + windowRect.width(), cursorPosition.y() + windowRect.width()*tan(i*pi/8))));
    }
    webEllipses.clear();
    float r = sqrt(windowRect.width()*windowRect.width() + windowRect.height()*windowRect.height())/10;
    for (int i = 1; i <= 10; i++){
        webEllipses.append(QRect(cursorPosition.x() - i*r, cursorPosition.y() - i*r, 2*i*r, 2*i*r));
    }
}
