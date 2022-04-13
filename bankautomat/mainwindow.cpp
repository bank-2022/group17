#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serialPortDLLTest = new DLLSerialPort;

    connect(serialPortDLLTest,SIGNAL(dataReadDone()),this, SLOT(cardReadDoneSlot()));
    ui->labelReadySignal->setStyleSheet("QLabel { background-color : red; color : black; }");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete serialPortDLLTest;
}



void MainWindow::on_btnGetCardNumber_clicked()
{
    serialCardNumber = serialPortDLLTest->interfaceFunctionReturnCardSerialNumber();
    ui->labelCardNumber->setText(serialCardNumber);

    //ui->labelCardNumber->setText("");

}


void MainWindow::on_btnOpenSerialPort_clicked()
{
    //serialPortDLLTest->interfaceSetSerialPortManually("COM4"); //Change port manually

    ui->labelSerialInfo->setText("Serial port: OPEN");
    serialPortDLLTest->interfaceFunctionOpenSerialPort();
}


void MainWindow::on_btnCloseSerialPort_clicked()
{
    ui->labelSerialInfo->setText("Serial port: CLOSED");
    ui->labelReadySignal->setStyleSheet("QLabel { background-color : red; color : black; }");
    serialPortDLLTest->interfaceFunctionCloseSerialPort();
    ui->labelCardNumber->setText("-Card Number-");

}

void MainWindow::cardReadDoneSlot()
{
    ui->labelReadySignal->setStyleSheet("QLabel { background-color : green; color : black; }");

/*
    QPalette palette = ui->labelReadySignal->palette();
    palette.setColor(ui->labelReadySignal->backgroundRole(), Qt::green);
    palette.setColor(ui->labelReadySignal->foregroundRole(), Qt::yellow);
    ui->labelReadySignal->setPalette(palette);
*/
    qDebug() << "Card reading successful";
}




