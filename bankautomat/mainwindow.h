#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bankui.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "dllpincode.h"
#include "dllserialport.h"
#include "dllrestapi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states{
    start,      //Program start
    readCard,   //Program is ready to read card
    readPin,    //When card is read move to read pin
    inBank,     //When login is succesful
};
enum events{
    clearAll,
    openSerial,
    readCardNum,
    closeSerial,
    openPinWindow,
    readPinNum,
    closePinWindow,
    login,
    bankUi,
    poistu,
    timeout
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void runStateMachine(states s,events e);
    void timeoutHandler();
    void poistuHandler();
    void pinCodeNum(QString pin); //slot for receiving pincode signal
    void readyToReadCardNum();  //recv signal from dllserial when cardnum is ready to be read to exe
    void recvKorttiInfoFunct(QString info);
    void recvLoginInfo(bool login); //Get response if login was succesful
    void recvRefreshRestApi();  //when  bank transaction is done get signal to refresh account info
    void recvNostoAndEmitToRestApi(QString,float,QString,QString);
    void recvTalletaAndEmitToRestApi(QString,float,QString,QString);
    void recvPinWrongFromDllPinCode(); //If pincode is wrong 3 times program returns to start
    void recvTilitapahtumatFromDllRestApi(QString);
    void requestTilitapahtumatFromDllRestApi(QString);

signals:
    void cardReadDone();  //test signal
    void eventSignal(states,events); //signal for state & event changes
    void loginCommand(QString,QString);
    void generateKorttiInfo(QString);
    void sendKorttiInfoToBankUi(QStringList);
    void sendNostoToRestApi(QString,float,QString,QString);
    void sendTalletaToRestApi(QString,float,QString,QString);
    void loginFailureToDllPinCode();
    void getTilitapahtumat(QString);
    void sendTilitapahtumatToUi(QString);

private slots:
    void on_LuekorttiBtn_clicked(); //test button
    void cardNumReadDone();         //test slot

private:
    Ui::MainWindow *ui;
    BankUI *pBankUI;

    QString CardNum;
    QString CardPin;
    QString CardInfo;
    QStringList list1;

    states state = start;
    events event;

    DLLRestAPI *pDllRestApi;
    DLLPinCode *pDllPinCode;
    DLLSerialPort *pDllSerialPort;

    void startHandler(events e);    //state handlers
    void readCardHandler(events e);
    void readPinHandler(events e);
    void inBankHandler(events e);
    void deleteDllPinCode();

};
#endif // MAINWINDOW_H
