#pragma once
#include "Dispositivo.h"

class AireAcondicionado : public Dispositivo {
public:
    AireAcondicionado(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override;
    void apagar() override;
    void setTemperatura(float temp);
};
