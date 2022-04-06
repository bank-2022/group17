#include "bankui.h"
#include "ui_bankui.h"

BankUI::BankUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankUI)
{
    ui->setupUi(this);

}

BankUI::~BankUI()
{
    delete ui;
}

void BankUI::on_NostaBtn_clicked()
{
    pNostaWindow = new NostaWindow;
    pNostaWindow->setModal(true);
    pNostaWindow->exec();
}


void BankUI::on_TalletaBtn_clicked()
{
    pTalletaWindow = new TalletaWindow;
    pTalletaWindow->setModal(true);
    pTalletaWindow->exec();
}


void BankUI::on_TapahtumatBtn_clicked()
{
    //get tapahtumat
}


void BankUI::on_PoistuBtn_clicked()
{
    this->close();
}


void BankUI::on_SaldoBtn_clicked()
{
    //get saldo
    getsaldo=450.89;
    saldo = QString::number(getsaldo);
    ui->saldo_label->setText(saldo+" €");
}

