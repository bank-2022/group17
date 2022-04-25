#include "pinwindow.h"
#include "ui_pinwindow.h"
#include "dllpincode.h"

PinWindow::PinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("Syötä pin");
    ui->lineEdit->setEchoMode(QLineEdit::Normal);
    //connect(this,SIGNAL(checkLineEdit(bool)),
    //         this,SLOT(lineEditChecker(bool)));
}

PinWindow::~PinWindow()
{
    delete ui;
}

QString PinWindow::returnPinCode()
{
    return text;
}

void PinWindow::wrongPin()
{
    ui->lineEdit->setText("Väärä pin");
    ui->lineEdit->setEchoMode(QLineEdit::Normal);
}


void PinWindow::on_pushButton_1_clicked()
{

    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "1");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "1");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "1");
    }

}


void PinWindow::on_pushButton_2_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "2");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "2");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "2");
    }
}


void PinWindow::on_pushButton_3_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "3");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "3");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "3");
    }
}


void PinWindow::on_pushButton_4_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "4");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "4");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "4");
    }
}


void PinWindow::on_pushButton_5_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "5");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "5");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "5");
    }
}


void PinWindow::on_pushButton_6_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "6");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "6");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "6");
    }
}


void PinWindow::on_pushButton_7_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "7");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "7");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "7");
    }
}


void PinWindow::on_pushButton_8_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "8");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "8");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "8");
    }
}


void PinWindow::on_pushButton_9_clicked()
{
    //emit checkLineEdit(false);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "9");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "9");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "9");
    }
}


void PinWindow::on_pushButton_0_clicked()
{
    //emit checkLineEdit(true);
    //ui->lineEdit->setText(ui->lineEdit->text()+ "0");
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->setText(ui->lineEdit->text()+ "0");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text()+ "0");
    }
}


void PinWindow::on_PushButton_Back_clicked()

{
    //emit checkLineEdit(true);
    //ui->lineEdit->backspace();
    if(checker == false){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        checker = true;
        ui->lineEdit->backspace();
    }
    else{
        ui->lineEdit->backspace();
    }
}


void PinWindow::on_PushButton_Ok_clicked()
{
    emit sendPinCode(ui->lineEdit->text());
    close();
    ui->lineEdit->clear();
    checker = false;
    ui->lineEdit->setText("Syötä pin");
    ui->lineEdit->setEchoMode(QLineEdit::Normal);

}
/*
void PinWindow::lineEditChecker(bool f)
{
    qDebug()<<"lineeditchecker signal";

    if(f == true){
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        qDebug()<<f;



    }
    qDebug()<<f;

}

*/



