#include "bankui.h"
#include "ui_bankui.h"

BankUI::BankUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankUI)
{
    ui->setupUi(this);
}

BankUI::~BankUI()
{
    delete ui;
}
