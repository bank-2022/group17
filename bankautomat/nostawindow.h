#ifndef NOSTAWINDOW_H
#define NOSTAWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class NostaWindow;
}

class NostaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NostaWindow(QWidget *parent = nullptr);
    ~NostaWindow();

    void setKorttiInfo(QString,QString);

signals:
    void resetTimer();
    void nostoSumma(float);

private slots:
    void on_PoistuButton_clicked();
    void on_VahvitaNostoBtn_clicked();
    void on_Nosta20Btn_clicked();
    void on_Nosta40Btn_clicked();
    void on_Nosta60Btn_clicked();
    void on_Nosta100Btn_clicked();
    void on_Nosta200Btn_clicked();
    void on_Nosta500Btn_clicked();
    void on_peruutaBtn_clicked();
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

private:
    Ui::NostaWindow *ui;
    QMessageBox msgBox;

    bool seteliLaskuri(int sum);

    int seteli20;
    int seteli50;
    float tilinfSaldo;
    QString nostaSum;
    QString buttonNum;



};

#endif // NOSTAWINDOW_H
