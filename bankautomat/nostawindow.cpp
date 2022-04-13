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


void NostaWindow::on_PoistuButton_clicked()
{
    this->close();
}


void NostaWindow::on_VahvitaNostoBtn_clicked()
{

}


void NostaWindow::on_Nosta20Btn_clicked()
{

}


void NostaWindow::on_Nosta40Btn_clicked()
{

}


void NostaWindow::on_Nosta60Btn_clicked()
{

}


void NostaWindow::on_Nosta100Btn_clicked()
{

}


void NostaWindow::on_Nosta200Btn_clicked()
{

}


void NostaWindow::on_Nosta500Btn_clicked()
{

}

