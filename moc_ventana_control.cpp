/****************************************************************************
** Meta object code from reading C++ file 'ventana_control.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/ventana_control.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventana_control.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaControl_t {
    QByteArrayData data[19];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaControl_t qt_meta_stringdata_VentanaControl = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VentanaControl"
QT_MOC_LITERAL(1, 15, 19), // "dispositivoCambiado"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "std::string"
QT_MOC_LITERAL(4, 48, 6), // "nombre"
QT_MOC_LITERAL(5, 55, 8), // "activado"
QT_MOC_LITERAL(6, 64, 19), // "manejarCambioEstado"
QT_MOC_LITERAL(7, 84, 18), // "cambiarImagenFondo"
QT_MOC_LITERAL(8, 103, 21), // "mostrarMenuCuadricula"
QT_MOC_LITERAL(9, 125, 18), // "mostrarMenuCochera"
QT_MOC_LITERAL(10, 144, 15), // "mostrarMenuSala"
QT_MOC_LITERAL(11, 160, 17), // "mostrarMenuCocina"
QT_MOC_LITERAL(12, 178, 18), // "mostrarMenuComedor"
QT_MOC_LITERAL(13, 197, 21), // "mostrarMenuHabitacion"
QT_MOC_LITERAL(14, 219, 15), // "mostrarMenuBano"
QT_MOC_LITERAL(15, 235, 18), // "mostrarMenuPasillo"
QT_MOC_LITERAL(16, 254, 16), // "mostrarMenuPatio"
QT_MOC_LITERAL(17, 271, 29), // "mostrarMenuHabitacionGenerico"
QT_MOC_LITERAL(18, 301, 9) // "rutaFondo"

    },
    "VentanaControl\0dispositivoCambiado\0\0"
    "std::string\0nombre\0activado\0"
    "manejarCambioEstado\0cambiarImagenFondo\0"
    "mostrarMenuCuadricula\0mostrarMenuCochera\0"
    "mostrarMenuSala\0mostrarMenuCocina\0"
    "mostrarMenuComedor\0mostrarMenuHabitacion\0"
    "mostrarMenuBano\0mostrarMenuPasillo\0"
    "mostrarMenuPatio\0mostrarMenuHabitacionGenerico\0"
    "rutaFondo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaControl[] = {

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
       1,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

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
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void VentanaControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VentanaControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dispositivoCambiado((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->manejarCambioEstado(); break;
        case 2: _t->cambiarImagenFondo(); break;
        case 3: _t->mostrarMenuCuadricula(); break;
        case 4: _t->mostrarMenuCochera(); break;
        case 5: _t->mostrarMenuSala(); break;
        case 6: _t->mostrarMenuCocina(); break;
        case 7: _t->mostrarMenuComedor(); break;
        case 8: _t->mostrarMenuHabitacion(); break;
        case 9: _t->mostrarMenuBano(); break;
        case 10: _t->mostrarMenuPasillo(); break;
        case 11: _t->mostrarMenuPatio(); break;
        case 12: _t->mostrarMenuHabitacionGenerico((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VentanaControl::*)(const std::string & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VentanaControl::dispositivoCambiado)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VentanaControl::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_VentanaControl.data,
    qt_meta_data_VentanaControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VentanaControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaControl.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VentanaControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void VentanaControl::dispositivoCambiado(const std::string & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
