#include "tapahtumatwindow.h"
#include "ui_tapahtumatwindow.h"
#include <QDebug>
TapahtumatWindow::TapahtumatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TapahtumatWindow)
{
    ui->setupUi(this);
}

TapahtumatWindow::~TapahtumatWindow()
{
    delete ui;
}

void TapahtumatWindow::setTilitapahtumat(QString tiliTapahtumat)
{
    qDebug()<<"at set tilitapahtumat in tapahtumat window";
//    qDebug()<<tiliTapahtumat;
    QStringList tapahtumatList = tiliTapahtumat.split(QString("\r"));
  //  qDebug()<<;
//    for (int i=0; i<tapahtumatList.size(); ++i){
        //ui->TapahtumaList->addItem(tapahtumatList.at(i));

        QString tapahtumat=tapahtumatList.at(1);
        QStringList singleTapahtuma = tapahtumat.split(QString(","));
         idtilitapahtumat=singleTapahtuma.at(0);
         kortinnumero=singleTapahtuma.at(1);
         paivays=singleTapahtuma.at(2);
         tapahtuma=singleTapahtuma.at(3);
         summa=singleTapahtuma.at(4);
         idkortti=singleTapahtuma.at(5);
         idtili=singleTapahtuma.at(6);

         ui->TapahtumaList->addItem("Tapahtuma numero: "+idtilitapahtumat+" Tapahtuma: "+tapahtuma+" "+summa+"€"+" Kortinnumero: "+kortinnumero+" Päiväys: "+paivays);



        //ui->TapahtumaList->addItem(tapahtuma);
//    }
}

void TapahtumatWindow::on_Ed10tapahtBtn_clicked()
{
    emit resetTimer();
}


void TapahtumatWindow::on_poistuBtn_clicked()
{
    this->close();
    emit resetTimer();
}


void TapahtumatWindow::on_Seur10tapahtBtn_clicked()
{
    emit resetTimer();
}

