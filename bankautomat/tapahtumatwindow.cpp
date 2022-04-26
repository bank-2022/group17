#include "tapahtumatwindow.h"
#include "ui_tapahtumatwindow.h"
#include <QDebug>
TapahtumatWindow::TapahtumatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TapahtumatWindow)
{
    ui->setupUi(this);
    tapahtumatIndex=0;
}

TapahtumatWindow::~TapahtumatWindow()
{
    delete ui;
}

void TapahtumatWindow::setTilitapahtumat(QString tiliTapahtumat)
{
    qDebug()<<"at set tilitapahtumat in tapahtumat window";
//    qDebug()<<tiliTapahtumat;
    tapahtumatList = tiliTapahtumat.split(QString("\r"));
  //  qDebug()<<;

    readTilitapahtumatForward();
}

void TapahtumatWindow::setKorttiInfo(QString asiakkaanNimi, QString tilinSaldo)
{
    ui->label->setText(asiakkaanNimi+" Tilin saldo = "+tilinSaldo+"€");
}

void TapahtumatWindow::on_Ed10tapahtBtn_clicked()
{
    emit resetTimer();
    readTilitapahtumatBackward();
}


void TapahtumatWindow::on_poistuBtn_clicked()
{
    this->close();
    emit resetTimer();
}


void TapahtumatWindow::on_Seur10tapahtBtn_clicked()
{
    emit resetTimer();
    readTilitapahtumatForward();
}

void TapahtumatWindow::readTilitapahtumatForward()
{
    ui->TapahtumaList->clear();

    qDebug()<<"list size:"<<tapahtumatList.size();
    for (int x=tapahtumatIndex;tapahtumatIndex<x+10; ++tapahtumatIndex){

        qDebug()<<tapahtumatIndex<<" before if";
        if(tapahtumatIndex>tapahtumatList.size()-2)
        {
            qDebug()<<tapahtumatIndex;
            qDebug()<<tapahtumatList.size();
            qDebug()<<"index out of range";
            ui->TapahtumaList->addItem("Tapahtumat loppu...");
            break;
        }
        else{
            tapahtumat=tapahtumatList.at(tapahtumatIndex);

            QStringList singleTapahtuma = tapahtumat.split(QString(","));
            idtilitapahtumat=singleTapahtuma.at(0);
            kortinnumero=singleTapahtuma.at(1);
            paivays=singleTapahtuma.at(2);
            tapahtuma=singleTapahtuma.at(3);
            summa=singleTapahtuma.at(4);
            idkortti=singleTapahtuma.at(5);
            idtili=singleTapahtuma.at(6);

            ui->TapahtumaList->addItem("Tapahtuma numero: "+idtilitapahtumat+" Tapahtuma: "+tapahtuma+" "+summa+"€"+" Kortinnumero: "+kortinnumero+" Päiväys: "+paivays);
        }
    }
}

void TapahtumatWindow::readTilitapahtumatBackward()
{
    ui->TapahtumaList->clear();

    qDebug()<<"list size:"<<tapahtumatList.size();
    qDebug()<<"tapahtumat index:"<<tapahtumatIndex;
    int indexModulo=tapahtumatIndex%10;
    if(indexModulo==0){
        tapahtumatIndex-=20;
    }
    else{
    tapahtumatIndex-=indexModulo;
    tapahtumatIndex-=10;
    }
    for (int x=tapahtumatIndex;tapahtumatIndex<x+10; ++tapahtumatIndex){

        qDebug()<<tapahtumatIndex<<" before if";
        if(tapahtumatIndex<0)
        {
            tapahtumatIndex=0;

            qDebug()<<tapahtumatIndex;
            qDebug()<<tapahtumatList.size();
            qDebug()<<"index out of range";
            ui->TapahtumaList->addItem("Tapahtumat loppu...");
            break;
        }
        else{
            tapahtumat=tapahtumatList.at(tapahtumatIndex);

            QStringList singleTapahtuma = tapahtumat.split(QString(","));
            idtilitapahtumat=singleTapahtuma.at(0);
            kortinnumero=singleTapahtuma.at(1);
            paivays=singleTapahtuma.at(2);
            tapahtuma=singleTapahtuma.at(3);
            summa=singleTapahtuma.at(4);
            idkortti=singleTapahtuma.at(5);
            idtili=singleTapahtuma.at(6);

            ui->TapahtumaList->addItem("Tapahtuma numero: "+idtilitapahtumat+" Tapahtuma: "+tapahtuma+" "+summa+"€"+" Kortinnumero: "+kortinnumero+" Päiväys: "+paivays);
        }
    }
}

