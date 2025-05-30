#pragma once
#include "Dispositivo.h"

class CamaraSeguridad : public Dispositivo {
public:
    CamaraSeguridad(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override;
    void apagar() override;
    void visualizar();
};
