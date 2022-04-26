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
    pDllRestApi=new DLLRestAPI;

    connect(pDllSerialPort,SIGNAL(dataReadDone()),this,SLOT(readyToReadCardNum()));
    connect(pDllPinCode,SIGNAL(sendPinToExe(QString)),this,SLOT(pinCodeNum(QString)));
    connect(pDllRestApi,SIGNAL(sendKorttiInfoToExe(QString)),this,SLOT(recvKorttiInfoFunct(QString)));
    connect(pDllRestApi,SIGNAL(sendLoginResultToExe(bool)),this,SLOT(recvLoginInfo(bool)));
    connect(pDllPinCode,SIGNAL(vaaraPin()),this,SLOT(recvPinWrongFromDllPinCode()));
    connect(pDllRestApi,SIGNAL(sendTransactionFinishedToExe()),this,SLOT(recvRefreshRestApi()));
    connect(pDllRestApi,SIGNAL(sendTilitapahtumatToExe(QString)),this,SLOT(recvTilitapahtumatFromDllRestApi(QString)));

    connect(this,SIGNAL(getTilitapahtumat(QString)),pDllRestApi,SLOT( recvGetTilitapahtumatCommand(QString)));
    connect(this,SIGNAL(loginFailureToDllPinCode()),pDllPinCode,SLOT(vaaraPinTarkistus()));
    connect(this,SIGNAL(loginCommand(QString,QString)),pDllRestApi,SLOT(recvLoginCommand(QString,QString)));
    connect(this,SIGNAL(generateKorttiInfo(QString)),pDllRestApi,SLOT(recvGenerateKorttiInfoCommand(QString)));
    connect(this,SIGNAL(eventSignal(states,events)),this,SLOT(runStateMachine(states, events)));
    connect(this,SIGNAL(cardReadDone()),this,SLOT(cardNumReadDone()));//test signal connection
    connect(this,SIGNAL(sendNostoToRestApi(QString,float,QString,QString)),pDllRestApi,SLOT(recvNostaCommand(QString,float,QString,QString)));
    connect(this,SIGNAL(sendTalletaToRestApi(QString,float,QString,QString)),pDllRestApi,SLOT(recvTalletaCommand(QString,float,QString,QString)));

    state=start;
    event=clearAll;
    runStateMachine(state, event);
}

MainWindow::~MainWindow()
{
    disconnect(pDllSerialPort,SIGNAL(dataReadDone()),this,SLOT(readyToReadCardNum()));
    disconnect(pDllPinCode,SIGNAL(sendPinToExe(QString)),this,SLOT(pinCodeNum(QString)));
    disconnect(pDllRestApi,SIGNAL(sendKorttiInfoToExe(QString)),this,SLOT(recvKorttiInfoFunct(QString)));
    disconnect(pDllRestApi,SIGNAL(sendLoginResultToExe(bool)),this,SLOT(recvLoginInfo(bool)));
    disconnect(pDllPinCode,SIGNAL(vaaraPin()),this,SLOT(recvPinWrongFromDllPinCode()));
    disconnect(pDllRestApi,SIGNAL(sendTransactionFinishedToExe()),this,SLOT(recvRefreshRestApi()));
    disconnect(pDllRestApi,SIGNAL(sendTilitapahtumatToExe(QString)),this,SLOT(recvTilitapahtumatFromDllRestApi(QString)));

    disconnect(this,SIGNAL(getTilitapahtumat(QString)),pDllRestApi,SLOT( recvGetTilitapahtumatCommand(QString)));
    disconnect(this,SIGNAL(sendTalletaToRestApi(QString,float,QString,QString)),pDllRestApi,SLOT(recvTalletaCommand(QString,float,QString,QString)));
    disconnect(this,SIGNAL(loginFailureToDllPinCode()),pDllPinCode,SLOT(vaaraPinTarkistus()));
    disconnect(this,SIGNAL(loginCommand(QString,QString)),pDllRestApi,SLOT(recvLoginCommand(QString,QString)));
    disconnect(this,SIGNAL(generateKorttiInfo(QString)),pDllRestApi,SLOT(recvGenerateKorttiInfoCommand(QString)));
    disconnect(this,SIGNAL(eventSignal(states,events)),this,SLOT(runStateMachine(states, events)));
    disconnect(this,SIGNAL(cardReadDone()),this,SLOT(cardNumReadDone()));//test signal connection
    disconnect(this,SIGNAL(sendNostoToRestApi(QString,float,QString,QString)),pDllRestApi,SLOT(recvNostaCommand(QString,float,QString,QString)));
    delete ui;
    delete pDllSerialPort;
    delete pDllPinCode;
    delete pDllRestApi;


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
    qDebug()<<"Got Pin number = "<<CardPin;
    state=readPin;
    event=login;
    emit eventSignal(state,event);
}

void MainWindow::readyToReadCardNum()
{
    qDebug()<<"Got ready to readCardNum";
    state=readCard;
    event=readCardNum;
    emit eventSignal(state,event);
}

void MainWindow::recvKorttiInfoFunct(QString info)
{
    CardInfo=info;
    qDebug()<<"Received card info "<<CardInfo;

    list1=CardInfo.split(QString(","));
    qDebug()<<"split info "<<list1;
    emit sendKorttiInfoToBankUi(list1);
    qDebug()<<"emit kortti info to ui";
}

void MainWindow::recvLoginInfo(bool login)
{

    qDebug()<<"login result "<<login;
    if(login==true){
        state=inBank;
        event=bankUi;
        pDllPinCode->closePinWindow();
        emit eventSignal(state,event);

    }
    else{
        emit loginFailureToDllPinCode();        
    }
}

void MainWindow::recvRefreshRestApi()
{
    qDebug()<<"After transaction refresh";
    emit generateKorttiInfo(CardNum);
}

void MainWindow::recvNostoAndEmitToRestApi(QString idTili, float nostoSumma, QString KorttiNumero, QString idKortti)
{
    qDebug()<<"Exe emit nosto to RestApi";
    emit sendNostoToRestApi(idTili,nostoSumma,KorttiNumero,idKortti);
}

void MainWindow::recvTalletaAndEmitToRestApi(QString idTili, float talletaSumma, QString KorttiNumero, QString idKortti)
{
    qDebug()<<"Exe emit talleta to RestApi";
    emit sendTalletaToRestApi(idTili,talletaSumma,KorttiNumero,idKortti);
}

void MainWindow::recvPinWrongFromDllPinCode()
{
    qDebug()<<"pin väärin 3 kertaa";
    pDllPinCode->closePinWindow();
    state=start;
    event=clearAll;
    emit eventSignal(state,event);
}

void MainWindow::recvTilitapahtumatFromDllRestApi(QString tilitapahtumat)
{
    qDebug()<<"received tilitapahtumat to exe";
     qDebug()<<tilitapahtumat;
     emit sendTilitapahtumatToUi(tilitapahtumat);
}

void MainWindow::requestTilitapahtumatFromDllRestApi(QString idTili)
{
    emit getTilitapahtumat(idTili);
}

void MainWindow::on_LuekorttiBtn_clicked()
{
    emit cardReadDone();
}

void MainWindow::cardNumReadDone()
{
    state=readCard;
    event=readCardNum;
    emit eventSignal(state,event);
}

void MainWindow::startHandler(events e)
{
    if(e==clearAll){
        qDebug()<<"e=clearAll";
        //set all variables to default
        CardNum=nullptr;
        CardPin=nullptr;
        CardInfo=nullptr;

        state=readCard;
        event=openSerial;
        emit eventSignal(state, event);
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
        CardNum=pDllSerialPort->interfaceFunctionReturnCardSerialNumber();
        CardNum="42316"; //test
        qDebug()<<"cardnum is "<<CardNum;
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
    }
    else if(e==readPinNum){
        qDebug()<<"e=readPinNum";
        //Pin received by signal, see slot pinCodeNum()
    }
    else if(e==closePinWindow){
        qDebug()<<"e=closePinWindow";
        //pDllPinCode->closePinWindow(); //not in use
        state=readPin;
        event=login;
        emit eventSignal(state, event);
    }
    else if(e==login){
        qDebug()<<"e=login";
        emit loginCommand(CardNum,CardPin);
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
        connect(this,SIGNAL(sendKorttiInfoToBankUi(QStringList)),pBankUI,SLOT(getKorttiInfo(QStringList)));
        connect(pBankUI,SIGNAL(nostaCommandToMainWindow(QString,float,QString,QString)),this,SLOT(recvNostoAndEmitToRestApi(QString,float,QString,QString)));
        connect(pBankUI,SIGNAL(talletaCommandToMainWindow(QString,float,QString,QString)),this,SLOT(recvTalletaAndEmitToRestApi(QString,float,QString,QString)));
        connect(pBankUI,SIGNAL(requestTiliTapahtumat(QString)),this,SLOT(requestTilitapahtumatFromDllRestApi(QString)));
        connect(this,SIGNAL(sendTilitapahtumatToUi(QString)),pBankUI,SLOT(recvTilitapahtumatFromMain(QString)));
        emit generateKorttiInfo(CardNum);
    }  
    else if(e==poistu){
        qDebug()<<"e=poistu";
        disconnect(pBankUI,SIGNAL(timeout()),this,SLOT(timeoutHandler()));
        disconnect(pBankUI,SIGNAL(poistuSignal()),this,SLOT(poistuHandler()));
        disconnect(this,SIGNAL(sendKorttiInfoToBankUi(QStringList)),pBankUI,SLOT(getKorttiInfo(QStringList)));
        disconnect(pBankUI,SIGNAL(nostaCommandToMainWindow(QString,float,QString,QString)),this,SLOT(recvNostoAndEmitToRestApi(QString,float,QString,QString)));
        disconnect(pBankUI,SIGNAL(talletaCommandToMainWindow(QString,float,QString,QString)),this,SLOT(recvTalletaAndEmitToRestApi(QString,float,QString,QString)));
        disconnect(pBankUI,SIGNAL(requestTiliTapahtumat(QString)),this,SLOT(requestTilitapahtumatFromDllRestApi(QString)));
        disconnect(this,SIGNAL(sendTilitapahtumatToUi(QString)),pBankUI,SLOT(recvTilitapahtumatFromMain(QString)));

        pBankUI->close();
        pBankUI->deleteLater();
        pBankUI=nullptr;
        state=start;
        event=clearAll;
        emit eventSignal(state,event);
    }
    else if(e==timeout){
        qDebug()<<"e=timeout";
        state=inBank;
        event=poistu;
        emit eventSignal(state,event);    }
    else{
        qDebug()<<"Error at bankhandler with event "<<e;
    }
}


