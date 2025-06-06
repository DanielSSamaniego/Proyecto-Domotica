#ifndef VENTANA_CONTROL_HPP
#define VENTANA_CONTROL_HPP

#include "actuadores.hpp"
#include <vector>
#include <memory>
#include <string>

// Clase para ventana emergente de control
class VentanaControl {
private:
    std::vector<std::shared_ptr<Actuador>> dispositivos;
public:
    VentanaControl();
    void mostrar(); // Método para mostrar la ventana y controlar los dispositivos
    void agregarDispositivo(std::shared_ptr<Actuador> disp);
};

#endif // VENTANA_CONTROL_HPP
