#include "widget.h"
#include "web.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent) {

    Web* spider = new Web(this);
    spider->setFixedSize(800, 600);
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(spider);
}

Widget::~Widget() {}
