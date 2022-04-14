#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <dllserialport.h>
#include <QObject>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
        DLLSerialPort * serialPort;
        QString serialCardNumber;

private slots:
    void on_btnOpenSerialPort_clicked();
    void on_btnCloseSerialPort_clicked();
    void cardReadDoneSlot();

signals:
    void readySignal();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
