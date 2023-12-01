#include <QApplication>

#include "web.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Web w;
  w.show();
  return a.exec();
}
