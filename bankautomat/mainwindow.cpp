#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect serialPortDll, dataReadDone, this, cardNumReadDone.

    connect(this,SIGNAL(cardReadDone()),this,SLOT(cardNumReadDone()));
    connect(this,SIGNAL(pinReadDone()),this,SLOT(pinNumReadDone()));

    state=start;
    event=clearAll;
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
    qDebug()<<"timeout!";
    event=timeout;
    runStateMachine(state,event);
}

void MainWindow::poistuHandler()
{
    qDebug()<<"poistu handler";
    event=poistu;
    runStateMachine(state,event);
}



void MainWindow::on_LuekorttiBtn_clicked()
{
    emit cardReadDone();
}

void MainWindow::on_AnnaPinBtn_clicked()
{
    emit pinReadDone();
}

void MainWindow::cardNumReadDone()
{
    state=readCard;
    event=closeSerial;
    runStateMachine(state,event);
}

void MainWindow::pinNumReadDone()
{
    //login
    state=inBank;
    event=bankUi;
    runStateMachine(state,event);
}

void MainWindow::startHandler(events e)
{
    if(e==clearAll){
        qDebug()<<"e=clearAll";
        //set all variables to default?
        state=readCard;
        event=openSerial;
        runStateMachine(state,event);
    }
    else{
        qDebug()<<"Error at starthandler with event "<<e;
    }
}

void MainWindow::readCardHandler(events e)
{
    if(e==openSerial){
        qDebug()<<"e=OpenSerial";
        //pdllSerialPort.interfaceFunctionOpenSerialPort();
        state=readCard;
        event=readCardNum;
        runStateMachine(state, event);
    }
    else if(e==readCardNum){
        //when card read receive signal?
        //CardNum=pdllSerialPort.interfaceFunctionReturnCardSerialNumber();

    }
    else if(e==closeSerial){
        qDebug()<<"e=closeSerial";
        //pdllSerialPort.interfaceFunctionCloseSerialPort();
        state=readPin;
        event=openPinWindow;
        runStateMachine(state,event);
    }
    else{
        qDebug()<<"Error at cardhandler with event "<<e;
    }
}

void MainWindow::readPinHandler(events e)
{
    if(e==openPinWindow){
        qDebug()<<"e=open=Pin";
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
        qDebug()<<"Error at pinhandler with event "<<e;
    }
}

void MainWindow::inBankHandler(events e)
{
    if(e==bankUi){
        qDebug()<<"e=bankui";
        pBankUI = new BankUI;
        pBankUI->setModal(true);
        pBankUI->show();
        connect(pBankUI,SIGNAL(timeout()),this,SLOT(timeoutHandler()));
        connect(pBankUI,SIGNAL(poistuSignal()),this,SLOT(poistuHandler()));

    }
    else if(e==tilitapahtumat){
         qDebug()<<"e=tapahtumat";
        //get tilitapahtumat
        //idletimer
    }
    else if(e==saldo){
        qDebug()<<"e=saldo";
        //get tili
        //idletimer
    }
    else if(e==nosto){
        qDebug()<<"e=nosto";
        //put tili
        //idletimer
    }
    else if(e==talletus){
        qDebug()<<"e=talletus";
        //put tili
        //idletimer
    }
    else if(e==uusisaldo){
        // get tili
        //poistu?
    }
    else if(e==poistu){
        qDebug()<<"e=poistu";
        pBankUI->close();
        pBankUI->deleteLater();
        pBankUI=nullptr;
        state=start;
        event=clearAll;
        runStateMachine(state,event);
    }
    else if(e==timeout){
        state=inBank;
        event=poistu;
        runStateMachine(state,event);
    }
    else{
        qDebug()<<"Error at bankhandler with event "<<e;
    }
}


