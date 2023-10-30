#include <QApplication>

#include "web.h"
#include "widget.h"
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  Widget w;

  w.setWindowTitle("Паутинка");
  w.show();

  return a.exec();
}
