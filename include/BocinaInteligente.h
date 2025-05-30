#pragma once
#include "Dispositivo.h"

class BocinaInteligente : public Dispositivo {
public:
    BocinaInteligente(const std::string& nombre) : Dispositivo(nombre) {}
    void encender() override;
    void apagar() override;
    void reproducirMusica(const std::string& cancion);
};
