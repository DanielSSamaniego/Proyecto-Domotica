#pragma once
#include <string>

class Dispositivo {
protected:
    std::string nombre;
public:
    Dispositivo(const std::string& nombre) : nombre(nombre) {}
    virtual ~Dispositivo() = default;
    virtual void encender() = 0;
    virtual void apagar() = 0;
    std::string getNombre() const { return nombre; }
};
