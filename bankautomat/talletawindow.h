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

private slots:


    void on_PoistuButton_clicked();

private:
    Ui::TalletaWindow *ui;
};

#endif // TALLETAWINDOW_H
