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

private:
    Ui::NostaWindow *ui;
};

#endif // NOSTAWINDOW_H
