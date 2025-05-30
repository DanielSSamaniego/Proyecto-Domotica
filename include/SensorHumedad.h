#pragma once
#include "Sensor.h"

class SensorHumedad : public Sensor {
public:
    SensorHumedad() : Sensor("Humedad") {}
    float leerValor() override;
};
