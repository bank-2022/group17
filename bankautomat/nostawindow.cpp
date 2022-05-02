#include "nostawindow.h"
#include "ui_nostawindow.h"
#include <QDebug>


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
    ui->NostaLe->clear();
    tilinfSaldo=tilinSaldo.toFloat();
    ui->asiakas_label->setText(asiakkaanNimi+" Tilin saldo = "+tilinSaldo+"€");
}

void NostaWindow::on_PoistuButton_clicked()
{
    emit resetTimer(0);
    this->close();



}

void NostaWindow::on_VahvitaNostoBtn_clicked()
{
    seteli20=0;
    seteli50=0;

    nostaSum=ui->NostaLe->text();
    qDebug()<<"nosta summa"<<nostaSum;
    int nostoSumInt = nostaSum.toInt();
    float nostoSumFloat = nostaSum.toFloat();
    bool tarkistus = seteliLaskuri(nostoSumInt);

    if (nostoSumFloat<=tilinfSaldo){

        if(tarkistus==true){
            emit nostoSumma(nostoSumFloat);
            msgBox.setText("Tulostetaan seteleitä..");
            if(seteli50>0&&seteli20>0){
                msgBox.setInformativeText("50€ seteleitä = "+QString::number(seteli50)+"\n"+"20€ seteleitä = "+QString::number(seteli20));
            }
            else if(seteli50>0&&seteli20==0){
                msgBox.setInformativeText("50€ seteleitä = "+QString::number(seteli50));
            }
            else {
                msgBox.setInformativeText("20€ seteleitä = "+QString::number(seteli20));
            }
            emit resetTimer(0);
            msgBox.show();
            this->close();
            msgBox.button(QMessageBox::Ok)->animateClick(5000);
        }
        else{
            emit resetTimer(1);
            msgBox.setText("Virhe!");
            msgBox.setInformativeText("Syötit virheellisen summan!");
            msgBox.show();
            msgBox.button(QMessageBox::Ok)->animateClick(5000);
        }
    }
    else {
        emit resetTimer(1);
        msgBox.setText("Virhe!");
        msgBox.setInformativeText("Tililläsi ei ole riittävästi katetta!");
        msgBox.show();
        msgBox.button(QMessageBox::Ok)->animateClick(5000);
    }

}

void NostaWindow::on_Nosta20Btn_clicked()
{
    buttonNum="20";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_Nosta40Btn_clicked()
{
    buttonNum="40";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_Nosta60Btn_clicked()
{
    buttonNum="60";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_Nosta100Btn_clicked()
{
    buttonNum="100";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_Nosta200Btn_clicked()
{
    buttonNum="200";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_Nosta500Btn_clicked()
{
    buttonNum="500";
    ui->NostaLe->setText(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_peruutaBtn_clicked()
{
    ui->NostaLe->backspace();
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_1_clicked()
{
    buttonNum="1";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_2_clicked()
{
    buttonNum="2";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_3_clicked()
{
    buttonNum="3";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_4_clicked()
{
    buttonNum="4";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_5_clicked()
{
    buttonNum="5";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_6_clicked()
{
    buttonNum="6";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_7_clicked()
{
    buttonNum="7";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_8_clicked()
{
    buttonNum="8";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_9_clicked()
{
    buttonNum="9";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

void NostaWindow::on_pushButton_0_clicked()
{
    buttonNum="0";
    ui->NostaLe->insert(buttonNum);
    emit resetTimer(1);
}

bool NostaWindow::seteliLaskuri(int sum)
{
    int laskukelpoisuus=0; //Onnistuuko lasku 20€ ja 50€ seteleillä
    int tulos=0;
    seteli20=0; seteli50=0; //Headerin INT muuttujat (setelien kpl määrät)

    if(sum%50==0)   //50:llä jaollinen luku
    {
        do{
            tulos+=50;
            seteli50++;
        }while(tulos<sum);

    }
    else if(sum>=20)    //Muut luvut 20:stä ylöspäin
    {
        do{
            tulos+=20;
            seteli20++;
            if((sum-tulos)%50==0)
                break;
        }while(tulos<sum);

        while(tulos<sum){
            tulos+=50;
            seteli50++;
        }
    }

    if(tulos==sum)  //Tarkistetaan vielä pitääkö laskettu tulos paikkaansa
        laskukelpoisuus=true;
    else
        laskukelpoisuus=false;

    return laskukelpoisuus;
}

