/****************************************************************************
** Meta object code from reading C++ file 'engineclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../engineclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engineclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EngineClass_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EngineClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EngineClass_t qt_meta_stringdata_EngineClass = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EngineClass"
QT_MOC_LITERAL(1, 12, 19), // "sendKorttiInfoToDLL"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 23), // "sendTilitapahtumatToDLL"
QT_MOC_LITERAL(4, 57, 9), // "loginSlot"
QT_MOC_LITERAL(5, 67, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 82, 10), // "loginReply"
QT_MOC_LITERAL(7, 93, 14), // "korttiInfoSlot"
QT_MOC_LITERAL(8, 108, 15), // "korttiInfoReply"
QT_MOC_LITERAL(9, 124, 9), // "nostaSlot"
QT_MOC_LITERAL(10, 134, 10), // "nostaReply"
QT_MOC_LITERAL(11, 145, 11), // "talletaSlot"
QT_MOC_LITERAL(12, 157, 12), // "talletaReply"
QT_MOC_LITERAL(13, 170, 18), // "tilitapahtumatSlot"
QT_MOC_LITERAL(14, 189, 19) // "tilitapahtumatReply"

    },
    "EngineClass\0sendKorttiInfoToDLL\0\0"
    "sendTilitapahtumatToDLL\0loginSlot\0"
    "QNetworkReply*\0loginReply\0korttiInfoSlot\0"
    "korttiInfoReply\0nostaSlot\0nostaReply\0"
    "talletaSlot\0talletaReply\0tilitapahtumatSlot\0"
    "tilitapahtumatReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EngineClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   55,    2, 0x08 /* Private */,
       7,    1,   58,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,
      11,    1,   64,    2, 0x08 /* Private */,
      13,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void, 0x80000000 | 5,   10,
    QMetaType::Void, 0x80000000 | 5,   12,
    QMetaType::Void, 0x80000000 | 5,   14,

       0        // eod
};

void EngineClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EngineClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendKorttiInfoToDLL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendTilitapahtumatToDLL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->loginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->korttiInfoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->nostaSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->talletaSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->tilitapahtumatSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EngineClass::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineClass::sendKorttiInfoToDLL)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EngineClass::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EngineClass::sendTilitapahtumatToDLL)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EngineClass::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_EngineClass.data,
    qt_meta_data_EngineClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EngineClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EngineClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EngineClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EngineClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void EngineClass::sendKorttiInfoToDLL(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EngineClass::sendTilitapahtumatToDLL(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
