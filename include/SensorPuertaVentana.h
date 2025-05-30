#pragma once
#include "Sensor.h"

class SensorPuertaVentana : public Sensor {
public:
    SensorPuertaVentana() : Sensor("Puerta/Ventana") {}
    float leerValor() override;
};
