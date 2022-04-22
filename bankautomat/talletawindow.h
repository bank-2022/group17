#ifndef TALLETAWINDOW_H
#define TALLETAWINDOW_H

#include <QDialog>

namespace Ui {
class TalletaWindow;
}

class TalletaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TalletaWindow(QWidget *parent = nullptr);
    ~TalletaWindow();

signals:
    void resetTimer();
    void talletaSumma(float);

private slots:
    void on_PoistuButton_clicked();    
    void on_TalletaButton_clicked();
    void on_PeruutaButton_clicked();
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
    Ui::TalletaWindow *ui;
    QString buttonNum;
    QString talletaSum;
};

#endif // TALLETAWINDOW_H
