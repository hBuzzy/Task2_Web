#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow){
    ui_->setupUi(this);
    web_ = new Web(this);
    active_ = false;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    if (active_) web_->paint(this);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (!(event->button() & Qt::LeftButton));
    active_ = true;
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    QPoint pos = this->mapFromGlobal(QCursor::pos());
    pos.setX(qMin(qMax(pos.x(), 0), width()));
    pos.setY(qMin(qMax(pos.y(), 0), height()));
    QCursor::setPos(this->mapToGlobal(pos));
    repaint();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (!(event->button() & Qt::LeftButton));
    active_ = false;
    repaint();
}

MainWindow::~MainWindow() {
    delete ui_;
}

