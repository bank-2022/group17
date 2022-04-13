#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bankui.h"
#include <QMainWindow>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states{
    start,
    readCard, //Ohjelman vakiotila
    readPin,
    inBank,   //Kun pankkiin on päästy

};
enum events{
    openSerial,
    readCardNum,
    closeSerial,
    openPinWindow,
    readPinNum,
    closePinWindow,
    login,
    tilitapahtumat,
    saldo,
    nosto,
    talletus,
    uusisaldo,
    poistu




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

private slots:
    void on_LuekorttiBtn_clicked();
    void on_AnnaPinBtn_clicked();

private:
    Ui::MainWindow *ui;
    BankUI *pBankUI;

    QString CardNum;
    QString CardPin;
    states state = start;
    events event;
    QTimer timer;

    void startHandler(events e);
    void readCardHandler(events e);
    void readPinHandler(events e);
    void inBankHandler(events e);

//    dllSerialPort *pdllSerialPort;
//    dllPinCode *pdllPinCode;
//    dllRestApi *pdllRestApi;

};
#endif // MAINWINDOW_H
