#pragma once
#include "Dispositivo.h"

class Ventana : public Dispositivo {
public:
    Ventana(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override; // Abrir
    void apagar() override;   // Cerrar
};
