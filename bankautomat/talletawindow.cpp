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

void TalletaWindow::setKorttiInfo(QString asiakkaanNimi, QString tilinSaldo)
{
    ui->Talleta_lineEdit->clear();
    ui->label->setText(asiakkaanNimi+" Tilin saldo = "+tilinSaldo+"€");
}

void TalletaWindow::on_PoistuButton_clicked()
{
    this->close();
    emit resetTimer(0);
}

void TalletaWindow::on_TalletaButton_clicked()
{
    talletaSum=ui->Talleta_lineEdit->text();
    qDebug()<<"talletus summa"<<talletaSum;
    float talletaSummaf = talletaSum.toFloat();
    emit talletaSumma(talletaSummaf);
    emit resetTimer(0);
    this->close();
}


void TalletaWindow::on_PeruutaButton_clicked()
{
    ui->Talleta_lineEdit->backspace();
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_1_clicked()
{
   buttonNum="1";
   ui->Talleta_lineEdit->insert(buttonNum);
   emit resetTimer(2);
}


void TalletaWindow::on_pushButton_2_clicked()
{
    buttonNum="2";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_3_clicked()
{
    buttonNum="3";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_4_clicked()
{
    buttonNum="4";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_5_clicked()
{
    buttonNum="5";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_6_clicked()
{
    buttonNum="6";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_7_clicked()
{
    buttonNum="7";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_8_clicked()
{
    buttonNum="8";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_9_clicked()
{
    buttonNum="9";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}


void TalletaWindow::on_pushButton_0_clicked()
{
    buttonNum="0";
    ui->Talleta_lineEdit->insert(buttonNum);
    emit resetTimer(2);
}

