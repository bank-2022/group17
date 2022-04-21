#include "bankui.h"
#include "ui_bankui.h"
#include <QDebug>


BankUI::BankUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankUI)
{
    ui->setupUi(this);
    elapse_timer.start();
    timer=new QTimer(this);
    timer->start(1000);     //1s timer to timeout check
    qDebug()<<"bank constru";
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timeoutcheck()));

}

BankUI::~BankUI()
{
    qDebug()<<"bank destro";
    delete ui;
    timer->deleteLater();
    timer=nullptr;
}

void BankUI::getKorttiInfo(QStringList info)
{

    qDebug()<<"at bankui getkorttiInfo";
    qDebug()<<info;

    qDebug()<<info.at(0);
    asiakkaanNimi=info.at(0);
    qDebug()<<"asiakkaan nimi = "<<asiakkaanNimi;
}

void BankUI::on_NostaBtn_clicked()
{
    elapse_timer.restart();
    pNostaWindow = new NostaWindow(this);
    pNostaWindow->setModal(true);
    pNostaWindow->show();
    connect(pNostaWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
}

void BankUI::on_TalletaBtn_clicked()
{
    elapse_timer.restart();
    pTalletaWindow = new TalletaWindow(this);
    pTalletaWindow->setModal(true);
    pTalletaWindow->show();
    connect(pTalletaWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
}

void BankUI::on_TapahtumatBtn_clicked()
{
    elapse_timer.restart();
    pTapahtumatWindow=new TapahtumatWindow(this);
    pTapahtumatWindow->setModal(true);
    pTapahtumatWindow->show();
    //get tapahtumat
    connect(pTapahtumatWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
}

void BankUI::on_PoistuBtn_clicked()
{
    emit poistuSignal();
}

void BankUI::on_SaldoBtn_clicked()
{
    elapse_timer.restart();
    //get saldo
    getsaldo=450.89;
    saldo = QString::number(getsaldo);
    ui->saldo_label->setText(saldo+" €");
}

void BankUI::timerReset()
{
    elapse_timer.restart();
    //qDebug()<<"timer reset";
}

void BankUI::timeoutcheck()
{
    //qDebug()<<"timeout check.. elapsed time= "<<elapse_timer.elapsed();
    if(elapse_timer.elapsed()>30000){ // 30s to timeout
        qDebug()<<"emit timeout";
        emit timeout();
    }
}

