#include "web.h"

#include <QPainter>

Web::Web(QObject *parent) : QObject{parent} {}

QList<QLine> Web::GetWebLines() { return webLines_; }

void Web::SetWeb(const QRect &windowRect, const QPoint &cursorPosition) {
  int halfDivider = 2;
  float innerSegments = 10.0;

  QList<QLine> baseWebLines;

  baseWebLines.append(QLine(windowRect.topLeft(), cursorPosition));
  baseWebLines.append(
      QLine(QPoint(windowRect.width() / halfDivider, windowRect.y()),
            cursorPosition));
  baseWebLines.append(QLine(windowRect.topRight(), cursorPosition));
  baseWebLines.append(QLine(windowRect.bottomRight(), cursorPosition));
  baseWebLines.append(QLine(windowRect.bottomLeft(), cursorPosition));

  webLines_.clear();
  webLines_ += baseWebLines;

  for (int k = 1; k <= innerSegments; k++) {
    for (int i = 0; i < baseWebLines.size(); i++) {
      float fraction = static_cast<float>(k) / innerSegments;

      QPoint point1(baseWebLines[i].p1() +
                    fraction * (baseWebLines[i].p2() - baseWebLines[i].p1()));

      QPoint point2(baseWebLines[(i + 1) % baseWebLines.size()].p1() +
                    fraction *
                        (baseWebLines[(i + 1) % baseWebLines.size()].p2() -
                         baseWebLines[(i + 1) % baseWebLines.size()].p1()));

      webLines_.append(QLine(point1, point2));
    }
  }
}
