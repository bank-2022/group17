/********************************************************************************
** Form generated from reading UI file 'pinwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINWINDOW_H
#define UI_PINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PinWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_0;
    QPushButton *pushButton_1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *PushButton_Ok;
    QPushButton *pushButton_6;
    QPushButton *PushButton_Back;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *PinWindow)
    {
        if (PinWindow->objectName().isEmpty())
            PinWindow->setObjectName(QString::fromUtf8("PinWindow"));
        PinWindow->setWindowModality(Qt::NonModal);
        PinWindow->resize(272, 306);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PinWindow->sizePolicy().hasHeightForWidth());
        PinWindow->setSizePolicy(sizePolicy);
        PinWindow->setMinimumSize(QSize(272, 306));
        PinWindow->setMaximumSize(QSize(272, 306));
        PinWindow->setCursor(QCursor(Qt::ArrowCursor));
        PinWindow->setSizeGripEnabled(false);
        PinWindow->setModal(false);
        gridLayoutWidget = new QWidget(PinWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 37, 254, 260));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 3, 2, 1, 1);

        pushButton_0 = new QPushButton(gridLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setFont(font);

        gridLayout->addWidget(pushButton_0, 4, 1, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setFont(font);

        gridLayout->addWidget(pushButton_1, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        PushButton_Ok = new QPushButton(gridLayoutWidget);
        PushButton_Ok->setObjectName(QString::fromUtf8("PushButton_Ok"));
        PushButton_Ok->setFont(font);

        gridLayout->addWidget(PushButton_Ok, 4, 2, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);

        PushButton_Back = new QPushButton(gridLayoutWidget);
        PushButton_Back->setObjectName(QString::fromUtf8("PushButton_Back"));
        PushButton_Back->setFont(font);

        gridLayout->addWidget(PushButton_Back, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(80, 24));
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(PinWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 18, 252, 22));
        label->setMaximumSize(QSize(252, 22));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(PinWindow);

        QMetaObject::connectSlotsByName(PinWindow);
    } // setupUi

    void retranslateUi(QDialog *PinWindow)
    {
        PinWindow->setWindowTitle(QString());
        pushButton_3->setText(QCoreApplication::translate("PinWindow", "3", nullptr));
        pushButton_7->setText(QCoreApplication::translate("PinWindow", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("PinWindow", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("PinWindow", "9", nullptr));
        pushButton_0->setText(QCoreApplication::translate("PinWindow", "0", nullptr));
        pushButton_1->setText(QCoreApplication::translate("PinWindow", "1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PinWindow", "4", nullptr));
        pushButton_8->setText(QCoreApplication::translate("PinWindow", "8", nullptr));
        PushButton_Ok->setText(QCoreApplication::translate("PinWindow", "\342\234\223", nullptr));
        pushButton_6->setText(QCoreApplication::translate("PinWindow", "6", nullptr));
        PushButton_Back->setText(QCoreApplication::translate("PinWindow", "\342\237\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PinWindow", "2", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PinWindow: public Ui_PinWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINWINDOW_H
