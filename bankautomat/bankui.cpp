#include "bankui.h"
#include "ui_bankui.h"
#include <QDebug>

#include <QPixmap>
#include <QPalette>



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
    windowIndex=0;  //set default index
    timer->start(1);     //1s timer to timeout check
    qDebug()<<"bank constru";

    bankUiOn=true;

    connect(this->timer,SIGNAL(timeout()),this,SLOT(timeoutcheck()));
    connect(pNostaWindow,SIGNAL(resetTimer(int)),this,SLOT(timerReset(int)));
    connect(pNostaWindow,SIGNAL(nostoSumma(float)),this,SLOT(nostoSumma(float)));
    connect(pTalletaWindow,SIGNAL(resetTimer(int)),this,SLOT(timerReset(int)));
    connect(pTalletaWindow,SIGNAL(talletaSumma(float)),this,SLOT(talletaSumma(float)));
    connect(pTapahtumatWindow,SIGNAL(resetTimer(int)),this,SLOT(timerReset(int)));
}

BankUI::~BankUI()
{
    disconnect(pNostaWindow,SIGNAL(resetTimer(int)),this,SLOT(timerReset(int)));
    disconnect(pNostaWindow,SIGNAL(nostoSumma(float)),this,SLOT(nostoSumma(float)));
    disconnect(pTalletaWindow,SIGNAL(resetTimer(int)),this,SLOT(timerReset(int)));
    disconnect(pTalletaWindow,SIGNAL(talletaSumma(float)),this,SLOT(talletaSumma(float)));
    disconnect(pTapahtumatWindow,SIGNAL(resetTimer(int)),this,SLOT(timerReset(int)));
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
//    qDebug()<<info;

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
    bankUiOn=false;
    this->hide();
    windowIndex=1;
    pNostaWindow->setKorttiInfo(asiakkaanNimi,saldo);
    pNostaWindow->setModal(true);
    pNostaWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    pNostaWindow->show();
}

void BankUI::on_TalletaBtn_clicked()
{
    elapse_timer.restart();
    bankUiOn=false;
    this->hide();
    windowIndex=2;
    pTalletaWindow->setKorttiInfo(asiakkaanNimi,saldo);
    pTalletaWindow->setModal(true);
    pTalletaWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    pTalletaWindow->show();
}

void BankUI::on_TapahtumatBtn_clicked()
{
    elapse_timer.restart();
    bankUiOn=false;
    this->hide();
    windowIndex=3;
    pTapahtumatWindow->setKorttiInfo(asiakkaanNimi,saldo);
    pTapahtumatWindow->setModal(true);
    pTapahtumatWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    pTapahtumatWindow->show();
    emit requestTiliTapahtumat(idTili);
}

void BankUI::on_PoistuBtn_clicked()
{
    emit poistuSignal();
}

void BankUI::timerReset(int index)
{
    /* index=0 bankUI
     * index=1 NostaWindow
     * index=2 TalletaWindow
     * index=3 TapahtumatWindow
    */
    windowIndex=index;
    elapse_timer.restart();
    //qDebug()<<"timer reset";
}

void BankUI::timeoutcheck()
{

    if(windowIndex==0&&bankUiOn==false){
        this->show();
    }
    //qDebug()<<"window index = "<<windowIndex;
    if(windowIndex!=0){
        if(elapse_timer.elapsed()>=10000){
            switch (windowIndex) {
            case 1:
                pNostaWindow->close();
                windowIndex=0;
                elapse_timer.restart();
                break;
            case 2:
                pTalletaWindow->close();
                windowIndex=0;
                elapse_timer.restart();
                break;
            case 3:
                pTapahtumatWindow->close();
                windowIndex=0;
                elapse_timer.restart();
                break;
            default:
                qDebug()<<"Default at BankUi.timeoutcheck!";

            }
        }
    }
    //qDebug()<<"timeout check.. elapsed time= "<<elapse_timer.elapsed();
    if(elapse_timer.elapsed()>30000){ // 30s to timeout
        qDebug()<<"emit timeout";
        emit timeout();
    }
}

