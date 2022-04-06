#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bankui.h"
#include <QMainWindow>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states{
    Aloitus,    //Ohjelman vakiotila
    Luekortti,
    Pankissa,   //Kun pankkiin on päästy
    Nosta,      //
    Talleta,
    Tilitapahtumat,
    Saldo,
    Poistu
};
enum events{
    avaaRFID,
    luekortti,
    suljeRFID,
    pinKoodi,



};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LuekorttiBtn_clicked();

    void on_AnnaPinBtn_clicked();

private:
    Ui::MainWindow *ui;
    BankUI *pBankUI;

    QString CardNum;
    QString CardPin;
    states state;
    events event;
    QTimer timer;

//    dllSerialPort *pdllSerialPort;
//    dllPinCode *pdllPinCode;
//    dllRestApi *pdllRestApi;

};
#endif // MAINWINDOW_H
