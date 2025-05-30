#pragma once
#include "Sensor.h"

class SensorMovimiento : public Sensor {
public:
    SensorMovimiento() : Sensor("Movimiento") {}
    float leerValor() override;
};
