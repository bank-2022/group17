/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnOpenSerialPort;
    QPushButton *btnCloseSerialPort;
    QLabel *labelCardNumber;
    QLabel *labelReadySignal;
    QLabel *labelSerialInfo;
    QLabel *labelCardNumber_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnOpenSerialPort = new QPushButton(centralwidget);
        btnOpenSerialPort->setObjectName(QString::fromUtf8("btnOpenSerialPort"));
        btnOpenSerialPort->setGeometry(QRect(20, 90, 231, 61));
        QFont font;
        font.setPointSize(14);
        btnOpenSerialPort->setFont(font);
        btnCloseSerialPort = new QPushButton(centralwidget);
        btnCloseSerialPort->setObjectName(QString::fromUtf8("btnCloseSerialPort"));
        btnCloseSerialPort->setGeometry(QRect(270, 90, 231, 61));
        btnCloseSerialPort->setFont(font);
        labelCardNumber = new QLabel(centralwidget);
        labelCardNumber->setObjectName(QString::fromUtf8("labelCardNumber"));
        labelCardNumber->setGeometry(QRect(270, 220, 231, 41));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        labelCardNumber->setFont(font1);
        labelCardNumber->setAutoFillBackground(true);
        labelCardNumber->setScaledContents(false);
        labelCardNumber->setAlignment(Qt::AlignCenter);
        labelCardNumber->setWordWrap(false);
        labelReadySignal = new QLabel(centralwidget);
        labelReadySignal->setObjectName(QString::fromUtf8("labelReadySignal"));
        labelReadySignal->setGeometry(QRect(520, 100, 231, 41));
        QFont font2;
        font2.setPointSize(16);
        labelReadySignal->setFont(font2);
        labelReadySignal->setAlignment(Qt::AlignCenter);
        labelSerialInfo = new QLabel(centralwidget);
        labelSerialInfo->setObjectName(QString::fromUtf8("labelSerialInfo"));
        labelSerialInfo->setGeometry(QRect(20, 40, 481, 41));
        QFont font3;
        font3.setPointSize(12);
        labelSerialInfo->setFont(font3);
        labelCardNumber_2 = new QLabel(centralwidget);
        labelCardNumber_2->setObjectName(QString::fromUtf8("labelCardNumber_2"));
        labelCardNumber_2->setGeometry(QRect(280, 180, 221, 41));
        labelCardNumber_2->setFont(font);
        labelCardNumber_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnOpenSerialPort->setText(QCoreApplication::translate("MainWindow", "Open Serial Port", nullptr));
        btnCloseSerialPort->setText(QCoreApplication::translate("MainWindow", "Close Serial Port", nullptr));
#if QT_CONFIG(accessibility)
        labelCardNumber->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        labelCardNumber->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelReadySignal->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        labelSerialInfo->setText(QString());
        labelCardNumber_2->setText(QCoreApplication::translate("MainWindow", "Card number: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
