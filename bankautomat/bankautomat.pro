QT       += core gui
QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bankui.cpp \
    main.cpp \
    mainwindow.cpp \
    nostawindow.cpp \
    talletawindow.cpp \
    tapahtumatwindow.cpp

HEADERS += \
    bankui.h \
    mainwindow.h \
    nostawindow.h \
    talletawindow.h \
    tapahtumatwindow.h

FORMS += \
    bankui.ui \
    mainwindow.ui \
    nostawindow.ui \
    talletawindow.ui \
    tapahtumatwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32: LIBS += -L$$PWD/DLLPinCode/build/debug/ -lDLLPinCode

INCLUDEPATH += $$PWD/DLLPinCode
DEPENDPATH += $$PWD/DLLPinCode

win32: LIBS += -L$$PWD/DLLSerialPort/build/debug/ -lDLLSerialPort

INCLUDEPATH += $$PWD/DLLSerialPort
DEPENDPATH += $$PWD/DLLSerialPort

win32: LIBS += -L$$PWD/DLLRestAPI/build/debug/ -lDLLRestAPI

INCLUDEPATH += $$PWD/DLLRestAPI
DEPENDPATH += $$PWD/DLLRestAPI

RESOURCES += \
    Pictures/src.qrc
