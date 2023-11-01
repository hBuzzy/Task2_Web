#include "web.h"

Web::Web(QObject *parent) : QObject{parent} {}

QList<QLine> Web::GetWebLines() { return webLines_; }
QList<QRect> Web::GetWebEllipses() { return webEllipses_; }

void Web::SetWeb(const QRect &windowRect, const QPoint &cursorPosition) {
    webLines_.clear();

    const int numberOfLines = 8;
    for(int i = 0; i < numberOfLines; i++) {
        webLines_.append(QLine(QPoint(-windowRect.width(), cursorPosition.y() - (cursorPosition.x() + windowRect.width())*tan(i*float(M_PI)/numberOfLines)),
                              QPoint(cursorPosition.x() + windowRect.width(), cursorPosition.y() + windowRect.width()*tan(i*float(M_PI)/numberOfLines))));
    }
    webEllipses_.clear();

    const int numberOfEllipses = 10;
    float radius = sqrt(windowRect.width()*windowRect.width() + windowRect.height()*windowRect.height())/numberOfEllipses;
    for (int i = 1; i <= numberOfEllipses; i++) {
        webEllipses_.append(QRect(cursorPosition.x() - i*radius, cursorPosition.y() - i*radius, 2*i*radius, 2*i*radius));
    }
}
