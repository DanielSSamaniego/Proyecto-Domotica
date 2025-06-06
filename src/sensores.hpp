#ifndef SENSORES_HPP
#define SENSORES_HPP

#include "actuadores.hpp"
#include <string>

// Los sensores son considerados actuadores en este sistema
class Sensor : public Actuador {
public:
    Sensor(const std::string& nombre) : Actuador(nombre) {}
    void activar() override {}
    void desactivar() override {}
};

#endif // SENSORES_HPP
