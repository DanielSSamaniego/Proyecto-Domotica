#pragma once
#include "Dispositivo.h"

class Luz : public Dispositivo {
public:
    Luz(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override;
    void apagar() override;
    // Métodos adicionales para luces LED (colores, intensidad, etc.)
};
