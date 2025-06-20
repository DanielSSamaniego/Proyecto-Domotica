#include "arduino.hpp"
#include <string>

Arduino::Arduino(const std::string& puerto) : puerto(puerto) {}

void Arduino::enviarComando(const std::string& comando) {
    // Implementar lógica de envío de comando al Arduino
}

std::string Arduino::recibirDatos() {
    // Implementar lógica de recepción de datos desde el Arduino
    return "";
}
