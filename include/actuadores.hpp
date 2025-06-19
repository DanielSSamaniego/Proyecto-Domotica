#ifndef ACTUADORES_HPP
#define ACTUADORES_HPP

#include <string>
#include <vector>

// Clase base Actuador
class Actuador {
protected:
    std::string nombre;
public:
    Actuador(const std::string& nombre) : nombre(nombre) {}
    virtual void activar() = 0;
    virtual void desactivar() = 0;
    virtual ~Actuador() {}
    std::string getNombre() const { return nombre; }
};

// Clases de dispositivos
class FocoPrincipal : public Actuador {
public:
    FocoPrincipal() : Actuador("FocoPrincipal") {}
    void activar() override {}
    void desactivar() override {}
};

class LedFondo : public Actuador {
public:
    LedFondo() : Actuador("LedFondo") {}
    void activar() override {}
    void desactivar() override {}
};

class Puerta : public Actuador {
public:
    Puerta() : Actuador("Puerta") {}
    void activar() override {}
    void desactivar() override {}
};

class Ventilador : public Actuador {
public:
    Ventilador() : Actuador("Ventilador") {}
    void activar() override {}
    void desactivar() override {}
};

class Ventana : public Actuador {
public:
    Ventana() : Actuador("Ventana") {}
    void activar() override {}
    void desactivar() override {}
};

class PCorral : public Actuador {
public:
    PCorral() : Actuador("PCorral") {}
    void activar() override {}
    void desactivar() override {}
};

class LuzSeguimiento : public Actuador {
public:
    LuzSeguimiento() : Actuador("LuzSeguimiento") {}
    void activar() override {}
    void desactivar() override {}
};

class Bocina : public Actuador {
public:
    Bocina() : Actuador("Bocina") {}
    void activar() override {}
    void desactivar() override {}
};

class Cortinas : public Actuador {
public:
    Cortinas() : Actuador("Cortinas") {}
    void activar() override {}
    void desactivar() override {}
};

#endif // ACTUADORES_HPP
