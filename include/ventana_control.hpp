#ifndef VENTANA_CONTROL_HPP
#define VENTANA_CONTROL_HPP

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QPixmap>
#include <QString>
#include <QTimer>
#include <QObject>
#include <QSerialPort> // <-- Agregado para comunicación serial
#include "actuadores.hpp"
#include <vector>
#include <memory>
#include <string>

class VentanaControl : public QWidget {
    Q_OBJECT
public:
    explicit VentanaControl(const std::vector<std::shared_ptr<Actuador>>& dispositivos, QWidget *parent = nullptr);
    ~VentanaControl();

signals:
    void dispositivoCambiado(const std::string& nombre, bool activado);

private slots:
    void manejarCambioEstado();
    void cambiarImagenFondo();
    void mostrarMenuCuadricula();
    void mostrarMenuCochera(); // Slot para mostrar el menú de cochera
    void mostrarMenuSala(); // Slot para mostrar el menú de la sala
    void mostrarMenuCocina(); // Slot para mostrar el menú de cocina
    void mostrarMenuComedor(); // Slot para mostrar el menú del comedor
    void mostrarMenuHabitacion(); // Slot para mostrar el menú de la habitación
    void mostrarMenuBano(); // Slot para mostrar el menú del baño
    void mostrarMenuPasillo(); // Slot para mostrar el menú del pasillo
    void mostrarMenuPatio(); // Slot para mostrar el menú del patio
    void mostrarMenuHabitacionGenerico(const QString &rutaFondo); // Slot para mostrar menú genérico
    void recibirDatosArduino(); // Slot para recibir datos del Arduino
    void actualizarEstadoVentana(const QString &habitacion, bool abierta);
    void manejarBotonVentanaHabitacion1();
    void manejarBotonVentanaHabitacion2();
    void manejarBotonPuertaCochera();
    void manejarBotonPersianaHabitacion1();
    void manejarBotonPersianaHabitacion2();
    void manejarBotonRiegoPatio();
    void manejarBotonTvSala();
    void manejarBotonTvHabitacion1();
    void manejarBotonTvHabitacion2();
    void manejarBotonTvComedor();
    void manejarBotonLucesCochera();
    void manejarBotonClimaHabitacion1();
    void manejarBotonClimaHabitacion2();
    void manejarBotonAutoClimaHabitacion1();
    void manejarBotonAutoClimaHabitacion2();

private:
    std::vector<QCheckBox*> checkboxes;
    std::vector<std::shared_ptr<Actuador>> dispositivos;
    QGridLayout *gridLayout;
    QLabel *fondoLabel;
    QPushButton *botonHome;
    QPushButton *botonEngrane;
    QTimer *timerCambioFondo;
    QGridLayout *menuCuadriculaLayout = nullptr;
    std::vector<QPushButton*> botonesMenu;
    QSerialPort *serial; // <-- Miembro para comunicación serial
    void agregarBotonImagen(const QString &ruta, int fila, int columna, const QString &tooltip);
    void aplicarEstilosBotones(); // Método para aplicar estilos visuales de efecto presionado a los botones
    void configurarLayout();
    void actualizarFondoPorHora();
    void mostrarMenuPrincipal();
    void cambiarFondo(const QString &ruta, bool blur = false); // Actualizada para aceptar el parámetro blur
    void enviarComandoArduino(const QString &comando); // <-- Método para enviar comandos
    bool ventanaHabitacion1Abierta = false;
    bool ventanaHabitacion2Abierta = false;
    QPushButton *btnVentanaHabitacion1 = nullptr;
    QPushButton *btnVentanaHabitacion2 = nullptr;
    bool puertaCocheraAbierta = false;
    QPushButton *btnPuertaCochera = nullptr;
    bool persianaHabitacion1Abierta = false;
    QPushButton *btnPersianaHabitacion1 = nullptr;
    bool persianaHabitacion2Abierta = false;
    QPushButton *btnPersianaHabitacion2 = nullptr;
    bool riegoPatioActivo = false;
    QPushButton *btnRiegoPatio = nullptr;
    bool tvSalaEncendida = false;
    QPushButton *btnTvSala = nullptr;
    bool tvHabitacion1Encendida = false;
    QPushButton *btnTvHabitacion1 = nullptr;
    bool tvHabitacion2Encendida = false;
    QPushButton *btnTvHabitacion2 = nullptr;
    bool tvComedorEncendida = false;
    QPushButton *btnTvComedor = nullptr;
    bool lucesCocheraEncendidas = false;
    QPushButton *btnLucesCochera = nullptr;
    bool climaHabitacion1Encendido = false;
    QPushButton *btnClimaHabitacion1 = nullptr;
    bool autoClimaHabitacion1 = false;
    QPushButton *btnAutoClimaHabitacion1 = nullptr;
    bool climaHabitacion2Encendido = false;
    QPushButton *btnClimaHabitacion2 = nullptr;
    bool autoClimaHabitacion2 = false;
    QPushButton *btnAutoClimaHabitacion2 = nullptr;
    void mostrarMenuHabitacion1();
    void mostrarMenuHabitacion2();
};

#endif // VENTANA_CONTROL_HPP
