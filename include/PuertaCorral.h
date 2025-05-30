#pragma once
#include "Dispositivo.h"

class PuertaCorral : public Dispositivo {
public:
    PuertaCorral(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override; // Abrir
    void apagar() override;   // Cerrar
};
