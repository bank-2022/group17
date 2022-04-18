#include "tapahtumatwindow.h"
#include "ui_tapahtumatwindow.h"

TapahtumatWindow::TapahtumatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TapahtumatWindow)
{
    ui->setupUi(this);
}

TapahtumatWindow::~TapahtumatWindow()
{
    delete ui;
}

void TapahtumatWindow::on_Ed10tapahtBtn_clicked()
{
    emit resetTimer();
}


void TapahtumatWindow::on_poistuBtn_clicked()
{
    this->close();
    emit resetTimer();
}


void TapahtumatWindow::on_Seur10tapahtBtn_clicked()
{
    emit resetTimer();
}

