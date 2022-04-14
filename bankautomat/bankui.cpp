#include "bankui.h"
#include "ui_bankui.h"


BankUI::BankUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankUI)
{
    ui->setupUi(this);
    elapse_timer.start();
    timer=new QTimer(this);
    timer->start(2000);
}

BankUI::~BankUI()
{
    delete ui;
}

void BankUI::on_NostaBtn_clicked()
{
    elapse_timer.restart();
    pNostaWindow = new NostaWindow;
    pNostaWindow->setModal(true);
    pNostaWindow->exec();
}


void BankUI::on_TalletaBtn_clicked()
{
    elapse_timer.restart();
    pTalletaWindow = new TalletaWindow;
    pTalletaWindow->setModal(true);
    pTalletaWindow->exec();
}


void BankUI::on_TapahtumatBtn_clicked()
{
    elapse_timer.restart();
    pTapahtumatWindow=new TapahtumatWindow;
    pTapahtumatWindow->setModal(true);
    pTapahtumatWindow->exec();
    //get tapahtumat
}


void BankUI::on_PoistuBtn_clicked()
{
    this->close();
}


void BankUI::on_SaldoBtn_clicked()
{
    elapse_timer.restart();
    //get saldo
    getsaldo=450.89;
    saldo = QString::number(getsaldo);
    ui->saldo_label->setText(saldo+" €");
}

void BankUI::timeout()
{

    if(elapse_timer.elapsed()>10000){
        this->close();
    }
}

