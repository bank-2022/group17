#include "talletawindow.h"
#include "ui_talletawindow.h"

TalletaWindow::TalletaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TalletaWindow)
{
    ui->setupUi(this);
}

TalletaWindow::~TalletaWindow()
{
    delete ui;
}
