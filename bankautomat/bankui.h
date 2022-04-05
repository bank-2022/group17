#ifndef BANKUI_H
#define BANKUI_H

#include <QDialog>

namespace Ui {
class BankUI;
}

class BankUI : public QDialog
{
    Q_OBJECT

public:
    explicit BankUI(QWidget *parent = nullptr);
    ~BankUI();

private:
    Ui::BankUI *ui;
};

#endif // BANKUI_H
