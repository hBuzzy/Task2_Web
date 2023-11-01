#include "widget.h"
#include "web.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    Web *web = new Web(this);
    web->setFixedSize(this->size());
    web->show();
}

Widget::~Widget() {}
