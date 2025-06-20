/****************************************************************************
** Meta object code from reading C++ file 'ventana_control.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/ventana_control.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventana_control.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaControl_t {
    QByteArrayData data[42];
    char stringdata0[856];
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
QT_MOC_LITERAL(18, 301, 9), // "rutaFondo"
QT_MOC_LITERAL(19, 311, 19), // "recibirDatosArduino"
QT_MOC_LITERAL(20, 331, 23), // "actualizarEstadoVentana"
QT_MOC_LITERAL(21, 355, 10), // "habitacion"
QT_MOC_LITERAL(22, 366, 7), // "abierta"
QT_MOC_LITERAL(23, 374, 30), // "manejarBotonVentanaHabitacion1"
QT_MOC_LITERAL(24, 405, 30), // "manejarBotonVentanaHabitacion2"
QT_MOC_LITERAL(25, 436, 25), // "manejarBotonPuertaCochera"
QT_MOC_LITERAL(26, 462, 31), // "manejarBotonPersianaHabitacion1"
QT_MOC_LITERAL(27, 494, 31), // "manejarBotonPersianaHabitacion2"
QT_MOC_LITERAL(28, 526, 22), // "manejarBotonRiegoPatio"
QT_MOC_LITERAL(29, 549, 18), // "manejarBotonTvSala"
QT_MOC_LITERAL(30, 568, 25), // "manejarBotonTvHabitacion1"
QT_MOC_LITERAL(31, 594, 25), // "manejarBotonTvHabitacion2"
QT_MOC_LITERAL(32, 620, 21), // "manejarBotonTvComedor"
QT_MOC_LITERAL(33, 642, 24), // "manejarBotonLucesCochera"
QT_MOC_LITERAL(34, 667, 28), // "manejarBotonClimaHabitacion1"
QT_MOC_LITERAL(35, 696, 28), // "manejarBotonClimaHabitacion2"
QT_MOC_LITERAL(36, 725, 32), // "manejarBotonAutoClimaHabitacion1"
QT_MOC_LITERAL(37, 758, 32), // "manejarBotonAutoClimaHabitacion2"
QT_MOC_LITERAL(38, 791, 19), // "mostrarMenuOpciones"
QT_MOC_LITERAL(39, 811, 18), // "mostrarPlaceholder"
QT_MOC_LITERAL(40, 830, 11), // "resizeEvent"
QT_MOC_LITERAL(41, 842, 13) // "QResizeEvent*"

    },
    "VentanaControl\0dispositivoCambiado\0\0"
    "std::string\0nombre\0activado\0"
    "manejarCambioEstado\0cambiarImagenFondo\0"
    "mostrarMenuCuadricula\0mostrarMenuCochera\0"
    "mostrarMenuSala\0mostrarMenuCocina\0"
    "mostrarMenuComedor\0mostrarMenuHabitacion\0"
    "mostrarMenuBano\0mostrarMenuPasillo\0"
    "mostrarMenuPatio\0mostrarMenuHabitacionGenerico\0"
    "rutaFondo\0recibirDatosArduino\0"
    "actualizarEstadoVentana\0habitacion\0"
    "abierta\0manejarBotonVentanaHabitacion1\0"
    "manejarBotonVentanaHabitacion2\0"
    "manejarBotonPuertaCochera\0"
    "manejarBotonPersianaHabitacion1\0"
    "manejarBotonPersianaHabitacion2\0"
    "manejarBotonRiegoPatio\0manejarBotonTvSala\0"
    "manejarBotonTvHabitacion1\0"
    "manejarBotonTvHabitacion2\0"
    "manejarBotonTvComedor\0manejarBotonLucesCochera\0"
    "manejarBotonClimaHabitacion1\0"
    "manejarBotonClimaHabitacion2\0"
    "manejarBotonAutoClimaHabitacion1\0"
    "manejarBotonAutoClimaHabitacion2\0"
    "mostrarMenuOpciones\0mostrarPlaceholder\0"
    "resizeEvent\0QResizeEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  179,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  184,    2, 0x08 /* Private */,
       7,    0,  185,    2, 0x08 /* Private */,
       8,    0,  186,    2, 0x08 /* Private */,
       9,    0,  187,    2, 0x08 /* Private */,
      10,    0,  188,    2, 0x08 /* Private */,
      11,    0,  189,    2, 0x08 /* Private */,
      12,    0,  190,    2, 0x08 /* Private */,
      13,    0,  191,    2, 0x08 /* Private */,
      14,    0,  192,    2, 0x08 /* Private */,
      15,    0,  193,    2, 0x08 /* Private */,
      16,    0,  194,    2, 0x08 /* Private */,
      17,    1,  195,    2, 0x08 /* Private */,
      19,    0,  198,    2, 0x08 /* Private */,
      20,    2,  199,    2, 0x08 /* Private */,
      23,    0,  204,    2, 0x08 /* Private */,
      24,    0,  205,    2, 0x08 /* Private */,
      25,    0,  206,    2, 0x08 /* Private */,
      26,    0,  207,    2, 0x08 /* Private */,
      27,    0,  208,    2, 0x08 /* Private */,
      28,    0,  209,    2, 0x08 /* Private */,
      29,    0,  210,    2, 0x08 /* Private */,
      30,    0,  211,    2, 0x08 /* Private */,
      31,    0,  212,    2, 0x08 /* Private */,
      32,    0,  213,    2, 0x08 /* Private */,
      33,    0,  214,    2, 0x08 /* Private */,
      34,    0,  215,    2, 0x08 /* Private */,
      35,    0,  216,    2, 0x08 /* Private */,
      36,    0,  217,    2, 0x08 /* Private */,
      37,    0,  218,    2, 0x08 /* Private */,
      38,    0,  219,    2, 0x08 /* Private */,
      39,    1,  220,    2, 0x08 /* Private */,
      40,    1,  223,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   21,   22,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 41,    2,

       0        // eod
};

void VentanaControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VentanaControl *>(_o);
        (void)_t;
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
        case 13: _t->recibirDatosArduino(); break;
        case 14: _t->actualizarEstadoVentana((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->manejarBotonVentanaHabitacion1(); break;
        case 16: _t->manejarBotonVentanaHabitacion2(); break;
        case 17: _t->manejarBotonPuertaCochera(); break;
        case 18: _t->manejarBotonPersianaHabitacion1(); break;
        case 19: _t->manejarBotonPersianaHabitacion2(); break;
        case 20: _t->manejarBotonRiegoPatio(); break;
        case 21: _t->manejarBotonTvSala(); break;
        case 22: _t->manejarBotonTvHabitacion1(); break;
        case 23: _t->manejarBotonTvHabitacion2(); break;
        case 24: _t->manejarBotonTvComedor(); break;
        case 25: _t->manejarBotonLucesCochera(); break;
        case 26: _t->manejarBotonClimaHabitacion1(); break;
        case 27: _t->manejarBotonClimaHabitacion2(); break;
        case 28: _t->manejarBotonAutoClimaHabitacion1(); break;
        case 29: _t->manejarBotonAutoClimaHabitacion2(); break;
        case 30: _t->mostrarMenuOpciones(); break;
        case 31: _t->mostrarPlaceholder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
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
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void VentanaControl::dispositivoCambiado(const std::string & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
