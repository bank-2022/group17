#ifndef NOSTAWINDOW_H
#define NOSTAWINDOW_H

#include <QDialog>

namespace Ui {
class NostaWindow;
}

class NostaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NostaWindow(QWidget *parent = nullptr);
    ~NostaWindow();

private slots:
    void on_PoistuButton_clicked();

    void on_VahvitaNostoBtn_clicked();

    void on_Nosta20Btn_clicked();

    void on_Nosta40Btn_clicked();

    void on_Nosta60Btn_clicked();

    void on_Nosta100Btn_clicked();

    void on_Nosta200Btn_clicked();

    void on_Nosta500Btn_clicked();

private:
    Ui::NostaWindow *ui;
};

#endif // NOSTAWINDOW_H
