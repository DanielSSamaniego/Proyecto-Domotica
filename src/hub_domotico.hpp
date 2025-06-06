#ifndef HUB_DOMOTICO_HPP
#define HUB_DOMOTICO_HPP

#include <string>

class HubDomotico {
public:
    void recibir_comando(const std::string& comando);
    void recibir_evento_sensor(const std::string& sensor, int valor);
};

#endif // HUB_DOMOTICO_HPP
