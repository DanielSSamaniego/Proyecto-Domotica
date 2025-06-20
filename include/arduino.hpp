#ifndef ARDUINO_HPP
#define ARDUINO_HPP
#include <string>

class Arduino {
public:
    Arduino(const std::string& puerto);
    void enviarComando(const std::string& comando);
    std::string recibirDatos();
private:
    std::string puerto;
};

#endif // ARDUINO_HPP
