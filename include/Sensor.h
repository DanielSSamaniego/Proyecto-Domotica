#pragma once
#include <string>

class Sensor {
protected:
    std::string tipo;
public:
    Sensor(const std::string& tipo) : tipo(tipo) {}
    virtual ~Sensor() = default;
    virtual float leerValor() = 0;
    std::string getTipo() const { return tipo; }
};
