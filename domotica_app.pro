QT += widgets serialport
CONFIG += c++11 console
SOURCES += \
    src/main.cpp \
    src/ventana_control.cpp \
    src/usuario.cpp
HEADERS += \
    include/ventana_control.hpp \
    include/actuadores.hpp
INCLUDEPATH += include
# Si tienes archivos .qrc, agrégalos aquí
# RESOURCES += resources.qrc
TARGET = domotica_app
DESTDIR = release
