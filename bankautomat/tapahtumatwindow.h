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

signals:
    void resetTimer();
private slots:
    void on_Ed10tapahtBtn_clicked();
    void on_poistuBtn_clicked();
    void on_Seur10tapahtBtn_clicked();

private:
    Ui::TapahtumatWindow *ui;

    QString tilitapahtumat;
};

#endif // TAPAHTUMATWINDOW_H