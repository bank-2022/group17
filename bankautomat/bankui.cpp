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
     pNostaWindow = new NostaWindow(this);
     pTalletaWindow = new TalletaWindow(this);
     pTapahtumatWindow=new TapahtumatWindow(this);

    timer->start(1000);     //1s timer to timeout check
    qDebug()<<"bank constru";
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timeoutcheck()));
}

BankUI::~BankUI()
{
    disconnect(pNostaWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
    disconnect(pNostaWindow,SIGNAL(nostoSumma(float)),this,SLOT(nostoSumma(float)));
    disconnect(pTalletaWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
    disconnect(pTalletaWindow,SIGNAL(talletaSumma(float)),this,SLOT(talletaSumma(float)));
    disconnect(pTapahtumatWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
    disconnect(this->timer,SIGNAL(timeout()),this,SLOT(timeoutcheck()));
    qDebug()<<"bank destro";

    delete pNostaWindow;
    delete pTalletaWindow;
    delete pTapahtumatWindow;
    delete ui;
    timer->deleteLater();
    timer=nullptr;
    pNostaWindow=nullptr;
    pTalletaWindow=nullptr;
    pTapahtumatWindow=nullptr;
}

void BankUI::getKorttiInfo(QStringList info)
{

    qDebug()<<"at bankui getkorttiInfo";
    qDebug()<<info;

    asiakkaanNimi=info.at(0);
    korttiNumero=info.at(1);
    idAsiakas=info.at(2);
    idKortti=info.at(3);
    idTili=info.at(4);
    saldo=info.at(5);
    qDebug()<<"asiakkaan nimi = "<<asiakkaanNimi;
    qDebug()<<"asiakkaan kortti = "<<korttiNumero;
    qDebug()<<"asiakkaan id = "<<idAsiakas;
    qDebug()<<"asiakkaan korttiID = "<<idKortti;
    qDebug()<<"asiakkaan tiliId = "<<idTili;
    qDebug()<<"asiakkaan saldo = "<<saldo;

    ui->Asiakkaan_nimi_label->setText(asiakkaanNimi);
    ui->saldo_label->setText("Tilin saldo = "+saldo+"€");

}

void BankUI::nostoSumma(float nostoSumma)
{
    qDebug()<<"vastaanotettu nosto = "<<nostoSumma;
    emit nostaCommandToMainWindow(idTili,nostoSumma,korttiNumero,idKortti);

}

void BankUI::talletaSumma(float talletaSumma)
{
    qDebug()<<"vastaannotettu talletus = "<<talletaSumma;
    emit talletaCommandToMainWindow(idTili,talletaSumma,korttiNumero,idKortti);
}

void BankUI::recvTilitapahtumatFromMain(QString tiliTapahtumat)
{
    qDebug()<<"at bankui recvtilitapahtumat";
    qDebug()<<tiliTapahtumat;
    pTapahtumatWindow->setTilitapahtumat(tiliTapahtumat);
}

void BankUI::on_NostaBtn_clicked()
{
    elapse_timer.restart();

    pNostaWindow->setKorttiInfo(asiakkaanNimi,saldo);
    pNostaWindow->setModal(true);
    pNostaWindow->show();
    connect(pNostaWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
    connect(pNostaWindow,SIGNAL(nostoSumma(float)),this,SLOT(nostoSumma(float)));
}

void BankUI::on_TalletaBtn_clicked()
{
    elapse_timer.restart();

    pTalletaWindow->setKorttiInfo(asiakkaanNimi,saldo);
    pTalletaWindow->setModal(true);
    pTalletaWindow->show();
    connect(pTalletaWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
    connect(pTalletaWindow,SIGNAL(talletaSumma(float)),this,SLOT(talletaSumma(float)));
}

void BankUI::on_TapahtumatBtn_clicked()
{
    elapse_timer.restart();
    pTapahtumatWindow->setKorttiInfo(asiakkaanNimi,saldo);
    pTapahtumatWindow->setModal(true);
    pTapahtumatWindow->show();
    emit requestTiliTapahtumat(idTili);
    connect(pTapahtumatWindow,SIGNAL(resetTimer()),this,SLOT(timerReset()));
}

void BankUI::on_PoistuBtn_clicked()
{
    emit poistuSignal();
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

