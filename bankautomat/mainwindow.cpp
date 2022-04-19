#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pDllPinCode=new DLLPinCode;
    pDllSerialPort=new DLLSerialPort;

    connect(pDllSerialPort,SIGNAL(dataReadDone()),this,SLOT(readyToReadCardNum()));
    connect(pDllPinCode,SIGNAL(sendPinToExe(QString)),this,SLOT(pinCodeNum(QString)));

    connect(this,SIGNAL(eventSignal(states,events)),this,SLOT(runStateMachine(states, events)));
    connect(this,SIGNAL(cardReadDone()),this,SLOT(cardNumReadDone()));
    connect(this,SIGNAL(pinReadDone()),this,SLOT(pinNumReadDone()));

    state=start;
    event=clearAll;
    runStateMachine(state, event);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pDllSerialPort;
    delete pDllPinCode;

    pDllSerialPort=nullptr;
    pDllPinCode=nullptr;
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
    default:
        qDebug()<<"State = "<<state<<" & event = "<<e;
    }
}

void MainWindow::timeoutHandler()
{
    qDebug()<<"timeout!";
   // state=inBank;
    event=timeout;
    runStateMachine(state,event);
}

void MainWindow::poistuHandler()
{
    qDebug()<<"poistu handler";
    state=inBank;
    event=poistu;
    runStateMachine(state,event);
}

void MainWindow::pinCodeNum(QString pin)
{
    CardPin=pin;
    qDebug()<<"Sain numeron"<<CardPin;
    state=inBank;   //test code
    event=bankUi;
    emit eventSignal(state,event);
    pDllPinCode->closePinWindow();
}

void MainWindow::readyToReadCardNum()
{
    state=readCard;
    event=readCardNum;
    runStateMachine(state,event);
}



void MainWindow::on_LuekorttiBtn_clicked()
{
    emit cardReadDone();
}

void MainWindow::on_AnnaPinBtn_clicked()
{
    //emit pinReadDone();
//    state=readPin;
//    event=openPinWindow;
//    runStateMachine(state,event);
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
        qDebug()<<"cardnum1 "<<CardNum;
        qDebug()<<"cardpin1 "<<CardPin;
        CardNum=nullptr;
        CardPin=nullptr;
        qDebug()<<"cardnum2 "<<CardNum;
        qDebug()<<"cardpin2 "<<CardPin;
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
        pDllSerialPort->interfaceFunctionOpenSerialPort();
    }
    else if(e==readCardNum){
        qDebug()<<"e=readCardNum";
        //when card read receive signal?
        CardNum=pDllSerialPort->interfaceFunctionReturnCardSerialNumber();
        state=readCard;
        event=closeSerial;
        emit eventSignal(state,event);


    }
    else if(e==closeSerial){
        qDebug()<<"e=closeSerial";
        pDllSerialPort->interfaceFunctionCloseSerialPort();
        state=readPin;
        event=openPinWindow;
        emit eventSignal(state,event);
        //runStateMachine(state,event);
    }
    else{
        qDebug()<<"Error at cardhandler with event "<<e;
    }
}

void MainWindow::readPinHandler(events e)
{
    if(e==openPinWindow){
        qDebug()<<"e=openPin";
        pDllPinCode->openPinWindow();
//        state=readPin;
//        event=readPinNum;
//        emit eventSignal(state,event);
//        //runStateMachine(state,event);
    }
    else if(e==readPinNum){
        qDebug()<<"e=readPinNum";
        //Pin received by signal see slot pinCodeNum()
    }
    else if(e==closePinWindow){
        qDebug()<<"e=closePinWindow";
        pDllPinCode->closePinWindow();
    }
    else if(e==login){
        qDebug()<<"e=login";
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
    }
    else if(e==saldo){
        qDebug()<<"e=saldo";
        //get tili        
    }
    else if(e==nosto){
        qDebug()<<"e=nosto";
        //put tili       
    }
    else if(e==talletus){
        qDebug()<<"e=talletus";
        //put tili       
    }
    else if(e==uusisaldo){
        // get tili
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
        qDebug()<<"e=timeout";
        state=inBank;
        event=poistu;
        runStateMachine(state,event);
    }
    else{
        qDebug()<<"Error at bankhandler with event "<<e;
    }
}


