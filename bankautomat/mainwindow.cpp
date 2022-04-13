#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //connect serialPortDll, dataReadDone, this, cardNumReadDone.

    state=start;
    event=openSerial;
    runStateMachine(state, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runStateMachine(states s, events e)
{
    switch (s) {

    case start:
        startHandler(e);
        break;
    case readCard:
        readCardHandler(e);
        break;
    case readPin:
        readPinHandler(e);
        break;
    case inBank:
        inBankHandler(e);
        break;



    }
}

void MainWindow::timeoutHandler()
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

void MainWindow::cardNumReadDone()
{
    state=readCard;
    event=closeSerial;
    runStateMachine(state,event);
}

void MainWindow::startHandler(events e)
{

}

void MainWindow::readCardHandler(events e)
{
    if(e==openSerial){
        //pdllSerialPort.interfaceFunctionOpenSerialPort();
        state=readCard;
        event=readCardNum;
        runStateMachine(state, event);
    }
    else if(e==readCardNum){
        //CardNum=pdllSerialPort.interfaceFunctionReturnCardSerialNumber();
        //when card read receive signal?
    }
    else if(e==closeSerial){
        //pdllSerialPort.interfaceFunctionCloseSerialPort();
        state=readPin;
        event=openPinWindow;
        runStateMachine(state,event);
    }
    else{
        qDebug()<<"Error at "<<state<<" with event "<<e;
    }
}

void MainWindow::readPinHandler(events e)
{
    if(e==openPinWindow){
        //pdllPinCode.openPinWindow();
        state=readPin;
        event=readPinNum;
        runStateMachine(state,event);
    }
    else if(e==readPinNum){
        //CardPin=pdllPinCode.returnPinCode();
        //when read receive signal?
    }
    else if(e==closePinWindow){
        //pdllPinCode.closePinWindow
    }
    else if(e==login){
        //pdllRestApi.login
        //true or false signal?
    }
    else{
        qDebug()<<"Error at "<<state<<" with event "<<e;
    }
}

void MainWindow::inBankHandler(events e)
{

}


