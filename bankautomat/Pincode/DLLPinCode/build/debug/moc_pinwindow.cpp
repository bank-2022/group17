/****************************************************************************
** Meta object code from reading C++ file 'pinwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../../KOULU/kev�t projekti 22/group17-ilari_exedev_bank/bankautomat/Pincode/DLLPinCode/pinwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pinwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PinWindow_t {
    QByteArrayData data[15];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PinWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PinWindow_t qt_meta_stringdata_PinWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PinWindow"
QT_MOC_LITERAL(1, 10, 11), // "sendPinCode"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 23), // "on_pushButton_1_clicked"
QT_MOC_LITERAL(4, 47, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 71, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 95, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(7, 119, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(8, 143, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(9, 167, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(10, 191, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(11, 215, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(12, 239, 23), // "on_pushButton_0_clicked"
QT_MOC_LITERAL(13, 263, 26), // "on_PushButton_Back_clicked"
QT_MOC_LITERAL(14, 290, 24) // "on_PushButton_Ok_clicked"

    },
    "PinWindow\0sendPinCode\0\0on_pushButton_1_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked\0on_pushButton_7_clicked\0"
    "on_pushButton_8_clicked\0on_pushButton_9_clicked\0"
    "on_pushButton_0_clicked\0"
    "on_PushButton_Back_clicked\0"
    "on_PushButton_Ok_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   82,    2, 0x08 /* Private */,
       4,    0,   83,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PinWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PinWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPinCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_1_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->on_pushButton_7_clicked(); break;
        case 8: _t->on_pushButton_8_clicked(); break;
        case 9: _t->on_pushButton_9_clicked(); break;
        case 10: _t->on_pushButton_0_clicked(); break;
        case 11: _t->on_PushButton_Back_clicked(); break;
        case 12: _t->on_PushButton_Ok_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PinWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinWindow::sendPinCode)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PinWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_PinWindow.data,
    qt_meta_data_PinWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PinWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PinWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PinWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PinWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PinWindow::sendPinCode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
