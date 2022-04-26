#include "nostawindow.h"
#include "ui_nostawindow.h"
#include <QDebug>
#include <QMessageBox>

NostaWindow::NostaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostaWindow)
{
    ui->setupUi(this);
    qDebug()<<"nosta constru";
}

NostaWindow::~NostaWindow()
{
    qDebug()<<"nosta destro";
    delete ui;

}

void NostaWindow::setKorttiInfo(QString asiakkaanNimi, QString tilinSaldo)
{
    tilinfSaldo=tilinSaldo.toFloat();
    ui->asiakas_label->setText(asiakkaanNimi+" Tilin saldo = "+tilinSaldo+"€");
}

void NostaWindow::on_PoistuButton_clicked()
{
    emit resetTimer();
    this->close();



}

void NostaWindow::on_VahvitaNostoBtn_clicked()
{
    emit resetTimer();
    nostaSum=ui->NostaLe->text();
    qDebug()<<"nosta summa"<<nostaSum;
    float nostoSum = nostaSum.toFloat();
    int tarkastus = nostaSum.toInt();           // TODO //!!!!
    if(tarkastus%20==0){ //tarkastaa %20 jos =0 jatkaa nostoon
        if(nostoSum<=tilinfSaldo){              //muuten tarkastus x-50<0 ja sitten %20 jos =0 jatkaa nostoon
        emit nostoSumma(nostoSum);
        this->close();
        }
        else{
            QMessageBox::critical(this,"VIRHE","TILILLÄSI EI OLE RIITTÄVÄSTI KATETTA!");
        }
    }
    else{
        QMessageBox::critical(this,"VIRHE","VIRHEELLINEN SUMMA!");
    }


}

void NostaWindow::on_Nosta20Btn_clicked()
{
    buttonNum="20";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_Nosta40Btn_clicked()
{
    buttonNum="40";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_Nosta60Btn_clicked()
{
    buttonNum="60";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_Nosta100Btn_clicked()
{
    buttonNum="100";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_Nosta200Btn_clicked()
{
    buttonNum="200";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_Nosta500Btn_clicked()
{
    buttonNum="500";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_peruutaBtn_clicked()
{
    ui->NostaLe->backspace();
    emit resetTimer();
}

void NostaWindow::on_pushButton_1_clicked()
{
    buttonNum="1";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_2_clicked()
{
    buttonNum="2";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_3_clicked()
{
    buttonNum="3";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_4_clicked()
{
    buttonNum="4";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_5_clicked()
{
    buttonNum="5";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_6_clicked()
{
    buttonNum="6";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_7_clicked()
{
    buttonNum="7";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_8_clicked()
{
    buttonNum="8";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_9_clicked()
{
    buttonNum="9";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

void NostaWindow::on_pushButton_0_clicked()
{
    buttonNum="0";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer();
}

