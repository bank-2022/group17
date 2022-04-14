#ifndef TAPAHTUMATWINDOW_H
#define TAPAHTUMATWINDOW_H

#include <QDialog>

namespace Ui {
class TapahtumatWindow;
}

class TapahtumatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TapahtumatWindow(QWidget *parent = nullptr);
    ~TapahtumatWindow();

private slots:
    void on_Ed10tapahtBtn_clicked();

private:
    Ui::TapahtumatWindow *ui;
};

#endif // TAPAHTUMATWINDOW_H
