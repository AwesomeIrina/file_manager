/****************************************************************************
** Meta object code from reading C++ file 'files_monitoring.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../file_manager/files_monitoring.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'files_monitoring.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Files_Monitoring_t {
    QByteArrayData data[18];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Files_Monitoring_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Files_Monitoring_t qt_meta_stringdata_Files_Monitoring = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Files_Monitoring"
QT_MOC_LITERAL(1, 17, 11), // "helperAsked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "fileAdded"
QT_MOC_LITERAL(4, 40, 8), // "fileName"
QT_MOC_LITERAL(5, 49, 11), // "fileRemoved"
QT_MOC_LITERAL(6, 61, 5), // "index"
QT_MOC_LITERAL(7, 67, 16), // "fileDisconnected"
QT_MOC_LITERAL(8, 84, 12), // "fileInformed"
QT_MOC_LITERAL(9, 97, 8), // "fileNeme"
QT_MOC_LITERAL(10, 106, 15), // "fileSizeChanged"
QT_MOC_LITERAL(11, 122, 18), // "fileAgainConnected"
QT_MOC_LITERAL(12, 141, 13), // "helperCommand"
QT_MOC_LITERAL(13, 155, 7), // "fileAdd"
QT_MOC_LITERAL(14, 163, 14), // "fileDisconnect"
QT_MOC_LITERAL(15, 178, 8), // "fileInfo"
QT_MOC_LITERAL(16, 187, 14), // "fileSizeChange"
QT_MOC_LITERAL(17, 202, 16) // "fileAgainConnect"

    },
    "Files_Monitoring\0helperAsked\0\0fileAdded\0"
    "fileName\0fileRemoved\0index\0fileDisconnected\0"
    "fileInformed\0fileNeme\0fileSizeChanged\0"
    "fileAgainConnected\0helperCommand\0"
    "fileAdd\0fileDisconnect\0fileInfo\0"
    "fileSizeChange\0fileAgainConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Files_Monitoring[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       5,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,
      10,    1,   92,    2, 0x06 /* Public */,
      11,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   98,    2, 0x0a /* Public */,
      13,    1,   99,    2, 0x0a /* Public */,
      14,    1,  102,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,
      16,    1,  108,    2, 0x0a /* Public */,
      17,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void Files_Monitoring::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Files_Monitoring *_t = static_cast<Files_Monitoring *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->helperAsked(); break;
        case 1: _t->fileAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->fileRemoved((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        case 3: _t->fileDisconnected((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        case 4: _t->fileInformed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->fileSizeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->fileAgainConnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->helperCommand(); break;
        case 8: _t->fileAdd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->fileDisconnect((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        case 10: _t->fileInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->fileSizeChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->fileAgainConnect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Files_Monitoring::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::helperAsked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Files_Monitoring::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::fileAdded)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Files_Monitoring::*_t)(const qint32 & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::fileRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Files_Monitoring::*_t)(const qint32 & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::fileDisconnected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Files_Monitoring::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::fileInformed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Files_Monitoring::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::fileSizeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Files_Monitoring::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files_Monitoring::fileAgainConnected)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject Files_Monitoring::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Files_Monitoring.data,
      qt_meta_data_Files_Monitoring,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Files_Monitoring::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Files_Monitoring::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Files_Monitoring.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Files_Monitoring::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Files_Monitoring::helperAsked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Files_Monitoring::fileAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Files_Monitoring::fileRemoved(const qint32 & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Files_Monitoring::fileDisconnected(const qint32 & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Files_Monitoring::fileInformed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Files_Monitoring::fileSizeChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Files_Monitoring::fileAgainConnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
