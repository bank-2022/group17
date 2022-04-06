#ifndef BANKUI_H
#define BANKUI_H

#include <QDialog>
#include "nostawindow.h"
#include "talletawindow.h"

namespace Ui {
class BankUI;
}

class BankUI : public QDialog
{
    Q_OBJECT

public:
    explicit BankUI(QWidget *parent = nullptr);
    ~BankUI();

private slots:
    void on_NostaBtn_clicked();

    void on_TalletaBtn_clicked();

    void on_TapahtumatBtn_clicked();

    void on_PoistuBtn_clicked();

    void on_SaldoBtn_clicked();

private:
    Ui::BankUI *ui;
    NostaWindow *pNostaWindow;
    TalletaWindow *pTalletaWindow;

    QString saldo;
    float getsaldo;
};

#endif // BANKUI_H
