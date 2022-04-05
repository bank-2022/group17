#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states{

};
enum events{

};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

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
