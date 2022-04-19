#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pDLLPinCode = new DLLPinCode();
    connect(pDLLPinCode,SIGNAL(sendPinToExe(QString)),
            this,SLOT(returnPinCode(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pDLLPinCode;
    pDLLPinCode = nullptr;

}


void MainWindow::on_korttiButton_clicked()
{
    ui->lineEdit->clear();
    pDLLPinCode->openPinWindow();
    //pDLLPinCode->closePinWindow();



}

void MainWindow::returnPinCode(QString pin)
{
    ui->lineEdit->setText(QString(pin));
}



