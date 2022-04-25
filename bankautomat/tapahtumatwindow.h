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

    void setTilitapahtumat(QString);

signals:
    void resetTimer();
private slots:

    void on_Ed10tapahtBtn_clicked();
    void on_poistuBtn_clicked();
    void on_Seur10tapahtBtn_clicked();

private:
    Ui::TapahtumatWindow *ui;

    void readTilitapahtumatForward();
    void readTilitapahtumatBackward();

    int tapahtumatIndex;

    QString tapahtumat;
    QStringList tapahtumatList;
    QString idtilitapahtumat;
    QString kortinnumero;
    QString paivays;
    QString tapahtuma;
    QString summa;
    QString idkortti;
    QString idtili;
};

#endif // TAPAHTUMATWINDOW_H
