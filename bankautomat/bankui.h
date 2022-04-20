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
signals:
     void timeout();
     void poistuSignal();
private slots:
    void on_NostaBtn_clicked();
    void on_TalletaBtn_clicked();
    void on_TapahtumatBtn_clicked();
    void on_PoistuBtn_clicked();
    void on_SaldoBtn_clicked();
    void timerReset();
    void timeoutcheck();
private:
    Ui::BankUI *ui;
    NostaWindow *pNostaWindow;
    TalletaWindow *pTalletaWindow;
    TapahtumatWindow *pTapahtumatWindow;

    QTimer *timer;
    QElapsedTimer elapse_timer;

    QString saldo;
    float getsaldo;
};

#endif // BANKUI_H
