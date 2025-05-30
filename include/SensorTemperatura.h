#pragma once
#include "Sensor.h"

class SensorTemperatura : public Sensor {
public:
    SensorTemperatura() : Sensor("Temperatura") {}
    float leerValor() override;
};
