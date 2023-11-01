#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "web.h"

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Web *web;
};
#endif  // WIDGET_H
