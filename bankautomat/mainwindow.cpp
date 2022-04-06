#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    state = Aloitus;
    event = avaaRFID;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ajaTilakone(states s, events e)
{

}

void MainWindow::aikaKatkaisu()
{

}


void MainWindow::on_LuekorttiBtn_clicked()
{

}


void MainWindow::on_AnnaPinBtn_clicked()
{
    //
    pBankUI = new BankUI;
    pBankUI->setModal(true);
    pBankUI->exec();
}

