#include "nostawindow.h"
#include "ui_nostawindow.h"

NostaWindow::NostaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostaWindow)
{
    ui->setupUi(this);
}

NostaWindow::~NostaWindow()
{
    delete ui;
}
