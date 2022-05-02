#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //serialPort = new DLLSerialPort;
    //connect(serialPort,SIGNAL(dataReadDone()),this, SLOT(cardReadDoneSlot()));
    ui->labelReadySignal->setStyleSheet("QLabel { background-color : red; color : black; }");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete serialPort;
}

void MainWindow::on_btnOpenSerialPort_clicked()
{

    serialPort = new DLLSerialPort;
    connect(serialPort,SIGNAL(dataReadDone()),this, SLOT(cardReadDoneSlot()));
    //serialPortDLLTest->interfaceSetSerialPortManually("COM4"); //Change port manually
    serialPort->interfaceFunctionOpenSerialPort();
    ui->labelSerialInfo->setText("Serial port: OPEN");

}


void MainWindow::on_btnCloseSerialPort_clicked()
{
    serialPort->interfaceFunctionCloseSerialPort();
    ui->labelSerialInfo->setText("Serial port: CLOSED");
    ui->labelReadySignal->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->labelCardNumber->setText("-");
    delete serialPort;

}

void MainWindow::cardReadDoneSlot()
{
    serialCardNumber = serialPort->interfaceFunctionReturnCardSerialNumber();
    ui->labelCardNumber->setText(serialCardNumber);
    ui->labelReadySignal->setStyleSheet("QLabel { background-color : green; color : black; }");

    qDebug() << "Card reading successful";


}






