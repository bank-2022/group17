#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bankui.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "dllpincode.h"

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
    tilitapahtumat,
    saldo,
    nosto,
    talletus,
    uusisaldo,
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
    void pinCodeNum(QString pin);

signals:
    void cardReadDone();
    void pinReadDone();


private slots:
    void on_LuekorttiBtn_clicked();
    void on_AnnaPinBtn_clicked();
    void cardNumReadDone();
    void pinNumReadDone ();

private:
    Ui::MainWindow *ui;
    BankUI *pBankUI;

    QString CardNum;
    QString CardPin;
    states state = start;
    events event;
    QTimer timer;
    QPushButton  *button;

    DLLPinCode *pDllPinCode;

    void startHandler(events e);
    void readCardHandler(events e);
    void readPinHandler(events e);
    void inBankHandler(events e);


//    dllSerialPort *pdllSerialPort;
//    dllRestApi *pdllRestApi;

};
#endif // MAINWINDOW_H
