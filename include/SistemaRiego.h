#pragma once
#include "Dispositivo.h"

class SistemaRiego : public Dispositivo {
public:
    SistemaRiego(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override;
    void apagar() override;
};
