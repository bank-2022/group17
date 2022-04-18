#include "pinwindow.h"
#include "ui_pinwindow.h"
#include "dllpincode.h"

PinWindow::PinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinWindow)
{
    ui->setupUi(this);
}

PinWindow::~PinWindow()
{
    delete ui;
}

QString PinWindow::returnPinCode()
{
    return text;
}


void PinWindow::on_pushButton_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}


void PinWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}


void PinWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}


void PinWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}


void PinWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}


void PinWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}


void PinWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}


void PinWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}


void PinWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}


void PinWindow::on_pushButton_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}


void PinWindow::on_PushButton_Back_clicked()
{
    ui->lineEdit->backspace();
}


void PinWindow::on_PushButton_Ok_clicked()
{
    emit sendPinCode(ui->lineEdit->text());
    //close();
    ui->lineEdit->clear();

}





