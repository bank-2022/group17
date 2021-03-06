QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += core

TEMPLATE = lib
DEFINES += DLLPINCODE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dllpincode.cpp \
    pincodeengine.cpp \
    pinwindow.cpp

HEADERS += \
    DLLPinCode_global.h \
    dllpincode.h \
    pincodeengine.h \
    pinwindow.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    pinwindow.ui
