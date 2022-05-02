#ifndef BANKUI_H
#define BANKUI_H

#include <QDialog>
#include <QTimer>
#include <QElapsedTimer>
#include "nostawindow.h"
#include "talletawindow.h"
#include "tapahtumatwindow.h"



namespace Ui {
class BankUI;
}

class BankUI : public QDialog
{
    Q_OBJECT

public:
    explicit BankUI(QWidget *parent = nullptr);
    ~BankUI();
public slots:
    void getKorttiInfo(QStringList);
    void nostoSumma(float);
    void talletaSumma(float);
    void recvTilitapahtumatFromMain(QString);
signals:
     void timeout();
     void poistuSignal();
     void nostaCommandToMainWindow(QString,float,QString,QString);
     void talletaCommandToMainWindow(QString,float,QString,QString);
     void requestTiliTapahtumat(QString);
private slots:
    void on_NostaBtn_clicked();
    void on_TalletaBtn_clicked();
    void on_TapahtumatBtn_clicked();
    void on_PoistuBtn_clicked();
    void timerReset(int);
    void timeoutcheck();
private:
    Ui::BankUI *ui;
    NostaWindow *pNostaWindow;
    TalletaWindow *pTalletaWindow;
    TapahtumatWindow *pTapahtumatWindow;


    QTimer *timer;
    QElapsedTimer elapse_timer;

    int windowIndex;
    QString asiakkaanNimi;
    QString korttiNumero;
    QString idAsiakas;
    QString idKortti;
    QString idTili;
    QString saldo;

};

#endif // BANKUI_H
