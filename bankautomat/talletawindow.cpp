#include "talletawindow.h"
#include "ui_talletawindow.h"
#include <QDebug>

TalletaWindow::TalletaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TalletaWindow)
{
    ui->setupUi(this);
    qDebug()<<"talleta constru";
}

TalletaWindow::~TalletaWindow()
{
    delete ui;
    qDebug()<<"talleta destro";
}

void TalletaWindow::on_PoistuButton_clicked()
{
    this->close();
    emit resetTimer();
}

void TalletaWindow::on_TalletaButton_clicked()
{
    talletaSum=ui->Talleta_lineEdit->text();
    qDebug()<<"talletus summa"<<talletaSum;
    //signal from here?
    emit resetTimer();
}


void TalletaWindow::on_PeruutaButton_clicked()
{
    ui->Talleta_lineEdit->backspace();
    emit resetTimer();
}


void TalletaWindow::on_pushButton_1_clicked()
{
   buttonNum="1";
   ui->Talleta_lineEdit->insert(buttonNum);
   emit resetTimer();
}


void TalletaWindow::on_pushButton_2_clicked()
{
    buttonNum="2";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_3_clicked()
{
    buttonNum="3";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_4_clicked()
{
    buttonNum="4";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_5_clicked()
{
    buttonNum="5";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_6_clicked()
{
    buttonNum="6";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_7_clicked()
{
    buttonNum="7";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_8_clicked()
{
    buttonNum="8";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_9_clicked()
{
    buttonNum="9";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}


void TalletaWindow::on_pushButton_0_clicked()
{
    buttonNum="0";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer();
}

