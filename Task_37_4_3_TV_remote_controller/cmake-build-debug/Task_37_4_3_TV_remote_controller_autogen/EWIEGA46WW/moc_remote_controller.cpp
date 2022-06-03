/****************************************************************************
** Meta object code from reading C++ file 'remote_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../remote_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remote_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_remote_controller_t {
    QByteArrayData data[16];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_remote_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_remote_controller_t qt_meta_stringdata_remote_controller = {
    {
QT_MOC_LITERAL(0, 0, 17), // "remote_controller"
QT_MOC_LITERAL(1, 18, 3), // "ch1"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "ch2"
QT_MOC_LITERAL(4, 27, 3), // "ch3"
QT_MOC_LITERAL(5, 31, 3), // "ch4"
QT_MOC_LITERAL(6, 35, 3), // "ch5"
QT_MOC_LITERAL(7, 39, 3), // "ch6"
QT_MOC_LITERAL(8, 43, 3), // "ch7"
QT_MOC_LITERAL(9, 47, 3), // "ch8"
QT_MOC_LITERAL(10, 51, 3), // "ch9"
QT_MOC_LITERAL(11, 55, 3), // "ch0"
QT_MOC_LITERAL(12, 59, 4), // "chUp"
QT_MOC_LITERAL(13, 64, 6), // "chDown"
QT_MOC_LITERAL(14, 71, 8), // "volumeUp"
QT_MOC_LITERAL(15, 80, 10) // "volumeDown"

    },
    "remote_controller\0ch1\0\0ch2\0ch3\0ch4\0"
    "ch5\0ch6\0ch7\0ch8\0ch9\0ch0\0chUp\0chDown\0"
    "volumeUp\0volumeDown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_remote_controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void remote_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<remote_controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ch1(); break;
        case 1: _t->ch2(); break;
        case 2: _t->ch3(); break;
        case 3: _t->ch4(); break;
        case 4: _t->ch5(); break;
        case 5: _t->ch6(); break;
        case 6: _t->ch7(); break;
        case 7: _t->ch8(); break;
        case 8: _t->ch9(); break;
        case 9: _t->ch0(); break;
        case 10: _t->chUp(); break;
        case 11: _t->chDown(); break;
        case 12: _t->volumeUp(); break;
        case 13: _t->volumeDown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject remote_controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_remote_controller.data,
    qt_meta_data_remote_controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *remote_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *remote_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_remote_controller.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int remote_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
