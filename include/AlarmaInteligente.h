#pragma once
#include "Dispositivo.h"

class AlarmaInteligente : public Dispositivo {
public:
    AlarmaInteligente(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override;
    void apagar() override;
    void activarAlerta();
};
