#ifndef PINWINDOW_H
#define PINWINDOW_H


#include <QDialog>


namespace Ui {
class PinWindow;
}

class PinWindow : public QDialog

{
    Q_OBJECT

public:
    explicit PinWindow(QWidget *parent = nullptr);
    ~PinWindow();
    QString returnPinCode();
    bool checker = false;

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_PushButton_Back_clicked();

    void on_PushButton_Ok_clicked();




signals:
    void sendPinCode(QString);
    //int checkLineEdit(bool f);

public slots:
      //  void lineEditChecker(bool);


private:
    Ui::PinWindow *ui;
    QString text;
    PinWindow * pPinWindow;


};

#endif // PINWINDOW_H
