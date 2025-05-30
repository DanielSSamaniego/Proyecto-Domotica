#pragma once
#include "Dispositivo.h"

class Cortina : public Dispositivo {
public:
    Cortina(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override; // Abrir
    void apagar() override;   // Cerrar
};
