#include "ventana_control.hpp"
#include <QDebug>
#include <QApplication>
#include <QScreen>
#include <QSerialPortInfo>

VentanaControl::VentanaControl(const std::vector<std::shared_ptr<Actuador>>& dispositivos, QWidget *parent)
    : QWidget(parent), dispositivos(dispositivos) {
    // Quitar bordes y barra de título para efecto de juego
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    // Opcional: establecer fondo negro por defecto
    setStyleSheet("background-color: black;");
    // Inicializar comunicación serial
    serial = new QSerialPort(this);
    // Cambia el nombre del puerto según tu sistema (ejemplo: /dev/ttyACM0)
    serial->setPortName("/dev/ttyACM0");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "No se pudo abrir el puerto serial";
    } else {
        connect(serial, &QSerialPort::readyRead, this, &VentanaControl::recibirDatosArduino);
    }
    // Menú cuadriculado de habitaciones
    gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
    // Botones de ejemplo para cada área
    QPushButton *btnSala = new QPushButton("Sala");
    QPushButton *btnCocina = new QPushButton("Cocina");
    QPushButton *btnComedor = new QPushButton("Comedor");
    QPushButton *btnHabitacion = new QPushButton("Habitación");
    QPushButton *btnBano = new QPushButton("Baño");
    QPushButton *btnCochera = new QPushButton("Cochera");
    QPushButton *btnPatio = new QPushButton("Patio");
    gridLayout->addWidget(btnSala, 0, 0);
    gridLayout->addWidget(btnCocina, 0, 1);
    gridLayout->addWidget(btnComedor, 0, 2);
    gridLayout->addWidget(btnHabitacion, 1, 0);
    gridLayout->addWidget(btnBano, 1, 1);
    gridLayout->addWidget(btnCochera, 1, 2);
    gridLayout->addWidget(btnPatio, 2, 1);
    // Conectar botones a slots que muestran menú contextual
    connect(btnSala, &QPushButton::clicked, this, &VentanaControl::mostrarMenuSala);
    connect(btnCocina, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCocina);
    connect(btnComedor, &QPushButton::clicked, this, &VentanaControl::mostrarMenuComedor);
    connect(btnHabitacion, &QPushButton::clicked, this, &VentanaControl::mostrarMenuHabitacion);
    connect(btnBano, &QPushButton::clicked, this, &VentanaControl::mostrarMenuBano);
    connect(btnCochera, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCochera);
    connect(btnPatio, &QPushButton::clicked, this, &VentanaControl::mostrarMenuPatio);
}

VentanaControl::~VentanaControl() {
    if (serial && serial->isOpen()) serial->close();
}

void VentanaControl::enviarComandoArduino(const QString &comando) {
    if (serial && serial->isOpen()) {
        serial->write(comando.toUtf8());
        serial->write("\n"); // Enviar salto de línea para delimitar comandos
    }
}

void VentanaControl::recibirDatosArduino() {
    QByteArray datos = serial->readAll();
    qDebug() << "Arduino dice:" << datos;
    // Ejemplo de mensaje esperado: "VENTANA_HAB1:ABIERTA" o "VENTANA_HAB1:CERRADA"
    QList<QByteArray> lineas = datos.split('\n');
    for (const QByteArray &linea : lineas) {
        if (linea.startsWith("VENTANA_HAB1:")) {
            actualizarEstadoVentana("HAB1", linea.endsWith("ABIERTA"));
        } else if (linea.startsWith("VENTANA_HAB2:")) {
            actualizarEstadoVentana("HAB2", linea.endsWith("ABIERTA"));
        }
    }
}

void VentanaControl::manejarCambioEstado() {
    // Por ejemplo, para encender la luz de la sala:
    enviarComandoArduino("LUZ_SALA_ON");
    // Para apagar: enviarComandoArduino("LUZ_SALA_OFF");
}

void VentanaControl::cambiarImagenFondo() {
    // Implementación vacía
}

void VentanaControl::mostrarMenuCuadricula() {
    // Limpiar layout actual
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    // Restaurar botones principales
    QPushButton *btnSala = new QPushButton("Sala");
    QPushButton *btnCocina = new QPushButton("Cocina");
    QPushButton *btnComedor = new QPushButton("Comedor");
    QPushButton *btnHabitacion = new QPushButton("Habitación");
    QPushButton *btnBano = new QPushButton("Baño");
    QPushButton *btnCochera = new QPushButton("Cochera");
    QPushButton *btnPatio = new QPushButton("Patio");
    gridLayout->addWidget(btnSala, 0, 0);
    gridLayout->addWidget(btnCocina, 0, 1);
    gridLayout->addWidget(btnComedor, 0, 2);
    gridLayout->addWidget(btnHabitacion, 1, 0);
    gridLayout->addWidget(btnBano, 1, 1);
    gridLayout->addWidget(btnCochera, 1, 2);
    gridLayout->addWidget(btnPatio, 2, 1);
    connect(btnSala, &QPushButton::clicked, this, &VentanaControl::mostrarMenuSala);
    connect(btnCocina, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCocina);
    connect(btnComedor, &QPushButton::clicked, this, &VentanaControl::mostrarMenuComedor);
    connect(btnHabitacion, &QPushButton::clicked, this, &VentanaControl::mostrarMenuHabitacion);
    connect(btnBano, &QPushButton::clicked, this, &VentanaControl::mostrarMenuBano);
    connect(btnCochera, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCochera);
    connect(btnPatio, &QPushButton::clicked, this, &VentanaControl::mostrarMenuPatio);
}

void VentanaControl::mostrarMenuSala() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QPushButton *btnLuces = new QPushButton("Luces Sala: Encender");
    btnTvSala = new QPushButton(tvSalaEncendida ? "TV: Encendida" : "TV: Apagada");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnLuces, 0, 0);
    gridLayout->addWidget(btnTvSala, 1, 0);
    gridLayout->addWidget(btnRegresar, 2, 0);
    static bool luzEncendida = false;
    connect(btnLuces, &QPushButton::clicked, [this, btnLuces]() mutable {
        static bool luzEncendida = false;
        luzEncendida = !luzEncendida;
        if (luzEncendida) {
            enviarComandoArduino("LUZ_SALA_ON");
            btnLuces->setText("Luces Sala: Apagar");
        } else {
            enviarComandoArduino("LUZ_SALA_OFF");
            btnLuces->setText("Luces Sala: Encender");
        }
    });
    connect(btnTvSala, &QPushButton::clicked, this, &VentanaControl::manejarBotonTvSala);
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::manejarBotonTvSala() {
    tvSalaEncendida = !tvSalaEncendida;
    if (tvSalaEncendida) {
        enviarComandoArduino("TV_SALA_ON");
        if (btnTvSala) btnTvSala->setText("TV: Encendida");
    } else {
        enviarComandoArduino("TV_SALA_OFF");
        if (btnTvSala) btnTvSala->setText("TV: Apagada");
    }
}

void VentanaControl::mostrarMenuCocina() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QPushButton *btnLuces = new QPushButton("Luces Cocina: Encender");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnLuces, 0, 0);
    gridLayout->addWidget(btnRegresar, 1, 0);
    static bool luzEncendida = false;
    connect(btnLuces, &QPushButton::clicked, [this, btnLuces]() mutable {
        static bool luzEncendida = false;
        luzEncendida = !luzEncendida;
        if (luzEncendida) {
            enviarComandoArduino("LUZ_COCINA_ON");
            btnLuces->setText("Luces Cocina: Apagar");
        } else {
            enviarComandoArduino("LUZ_COCINA_OFF");
            btnLuces->setText("Luces Cocina: Encender");
        }
    });
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::mostrarMenuComedor() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QPushButton *btnLuces = new QPushButton("Luces Comedor: Encender");
    btnTvComedor = new QPushButton(tvComedorEncendida ? "TV: Encendida" : "TV: Apagada");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnLuces, 0, 0);
    gridLayout->addWidget(btnTvComedor, 1, 0);
    gridLayout->addWidget(btnRegresar, 2, 0);
    static bool luzEncendida = false;
    connect(btnLuces, &QPushButton::clicked, [this, btnLuces]() mutable {
        static bool luzEncendida = false;
        luzEncendida = !luzEncendida;
        if (luzEncendida) {
            enviarComandoArduino("LUZ_COMEDOR_ON");
            btnLuces->setText("Luces Comedor: Apagar");
        } else {
            enviarComandoArduino("LUZ_COMEDOR_OFF");
            btnLuces->setText("Luces Comedor: Encender");
        }
    });
    connect(btnTvComedor, &QPushButton::clicked, this, &VentanaControl::manejarBotonTvComedor);
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::manejarBotonTvComedor() {
    tvComedorEncendida = !tvComedorEncendida;
    if (tvComedorEncendida) {
        enviarComandoArduino("TV_COMEDOR_ON");
        if (btnTvComedor) btnTvComedor->setText("TV: Encendida");
    } else {
        enviarComandoArduino("TV_COMEDOR_OFF");
        if (btnTvComedor) btnTvComedor->setText("TV: Apagada");
    }
}

void VentanaControl::mostrarMenuHabitacion() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    // Botón de luces para la habitación
    QPushButton *btnLuces = new QPushButton("Luces Habitación: Encender");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnLuces, 0, 0);
    gridLayout->addWidget(btnRegresar, 1, 0);
    // Estado de la luz (simple, solo para ejemplo)
    static bool luzEncendida = false;
    connect(btnLuces, &QPushButton::clicked, [this, btnLuces]() mutable {
        static bool luzEncendida = false;
        luzEncendida = !luzEncendida;
        if (luzEncendida) {
            enviarComandoArduino("LUZ_HABITACION_ON");
            btnLuces->setText("Luces Habitación: Apagar");
        } else {
            enviarComandoArduino("LUZ_HABITACION_OFF");
            btnLuces->setText("Luces Habitación: Encender");
        }
    });
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::mostrarMenuHabitacion1() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QPushButton *btnLuces = new QPushButton("Luces Habitación 1: Encender");
    btnVentanaHabitacion1 = new QPushButton(ventanaHabitacion1Abierta ? "Ventana: Abierta" : "Ventana: Cerrada");
    btnPersianaHabitacion1 = new QPushButton(persianaHabitacion1Abierta ? "Persiana: Abierta" : "Persiana: Cerrada");
    btnTvHabitacion1 = new QPushButton(tvHabitacion1Encendida ? "TV: Encendida" : "TV: Apagada");
    btnClimaHabitacion1 = new QPushButton(climaHabitacion1Encendido ? "Clima: Encendido" : "Clima: Apagado");
    btnAutoClimaHabitacion1 = new QPushButton(autoClimaHabitacion1 ? "Automático: Activado" : "Automático: Desactivado");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnLuces, 0, 0);
    gridLayout->addWidget(btnVentanaHabitacion1, 1, 0);
    gridLayout->addWidget(btnPersianaHabitacion1, 2, 0);
    gridLayout->addWidget(btnTvHabitacion1, 3, 0);
    gridLayout->addWidget(btnClimaHabitacion1, 4, 0);
    gridLayout->addWidget(btnAutoClimaHabitacion1, 5, 0);
    gridLayout->addWidget(btnRegresar, 6, 0);
    static bool luzEncendida = false;
    connect(btnLuces, &QPushButton::clicked, [this, btnLuces]() mutable {
        static bool luzEncendida = false;
        luzEncendida = !luzEncendida;
        if (luzEncendida) {
            enviarComandoArduino("LUZ_HABITACION1_ON");
            btnLuces->setText("Luces Habitación 1: Apagar");
        } else {
            enviarComandoArduino("LUZ_HABITACION1_OFF");
            btnLuces->setText("Luces Habitación 1: Encender");
        }
    });
    connect(btnVentanaHabitacion1, &QPushButton::clicked, this, &VentanaControl::manejarBotonVentanaHabitacion1);
    connect(btnPersianaHabitacion1, &QPushButton::clicked, this, &VentanaControl::manejarBotonPersianaHabitacion1);
    connect(btnTvHabitacion1, &QPushButton::clicked, this, &VentanaControl::manejarBotonTvHabitacion1);
    connect(btnClimaHabitacion1, &QPushButton::clicked, this, &VentanaControl::manejarBotonClimaHabitacion1);
    connect(btnAutoClimaHabitacion1, &QPushButton::clicked, this, &VentanaControl::manejarBotonAutoClimaHabitacion1);
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::manejarBotonClimaHabitacion1() {
    climaHabitacion1Encendido = !climaHabitacion1Encendido;
    if (climaHabitacion1Encendido) {
        enviarComandoArduino("CLIMA_HAB1_ON");
        if (btnClimaHabitacion1) btnClimaHabitacion1->setText("Clima: Encendido");
    } else {
        enviarComandoArduino("CLIMA_HAB1_OFF");
        if (btnClimaHabitacion1) btnClimaHabitacion1->setText("Clima: Apagado");
    }
}

void VentanaControl::manejarBotonAutoClimaHabitacion1() {
    autoClimaHabitacion1 = !autoClimaHabitacion1;
    if (autoClimaHabitacion1) {
        enviarComandoArduino("AUTO_CLIMA_HAB1_ON");
        if (btnAutoClimaHabitacion1) btnAutoClimaHabitacion1->setText("Automático: Activado");
    } else {
        enviarComandoArduino("AUTO_CLIMA_HAB1_OFF");
        if (btnAutoClimaHabitacion1) btnAutoClimaHabitacion1->setText("Automático: Desactivado");
    }
}

void VentanaControl::mostrarMenuHabitacion2() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QPushButton *btnLuces = new QPushButton("Luces Habitación 2: Encender");
    btnVentanaHabitacion2 = new QPushButton(ventanaHabitacion2Abierta ? "Ventana: Abierta" : "Ventana: Cerrada");
    btnPersianaHabitacion2 = new QPushButton(persianaHabitacion2Abierta ? "Persiana: Abierta" : "Persiana: Cerrada");
    btnTvHabitacion2 = new QPushButton(tvHabitacion2Encendida ? "TV: Encendida" : "TV: Apagada");
    btnClimaHabitacion2 = new QPushButton(climaHabitacion2Encendido ? "Clima: Encendido" : "Clima: Apagado");
    btnAutoClimaHabitacion2 = new QPushButton(autoClimaHabitacion2 ? "Automático: Activado" : "Automático: Desactivado");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnLuces, 0, 0);
    gridLayout->addWidget(btnVentanaHabitacion2, 1, 0);
    gridLayout->addWidget(btnPersianaHabitacion2, 2, 0);
    gridLayout->addWidget(btnTvHabitacion2, 3, 0);
    gridLayout->addWidget(btnClimaHabitacion2, 4, 0);
    gridLayout->addWidget(btnAutoClimaHabitacion2, 5, 0);
    gridLayout->addWidget(btnRegresar, 6, 0);
    static bool luzEncendida = false;
    connect(btnLuces, &QPushButton::clicked, [this, btnLuces]() mutable {
        static bool luzEncendida = false;
        luzEncendida = !luzEncendida;
        if (luzEncendida) {
            enviarComandoArduino("LUZ_HABITACION2_ON");
            btnLuces->setText("Luces Habitación 2: Apagar");
        } else {
            enviarComandoArduino("LUZ_HABITACION2_OFF");
            btnLuces->setText("Luces Habitación 2: Encender");
        }
    });
    connect(btnVentanaHabitacion2, &QPushButton::clicked, this, &VentanaControl::manejarBotonVentanaHabitacion2);
    connect(btnPersianaHabitacion2, &QPushButton::clicked, this, &VentanaControl::manejarBotonPersianaHabitacion2);
    connect(btnTvHabitacion2, &QPushButton::clicked, this, &VentanaControl::manejarBotonTvHabitacion2);
    connect(btnClimaHabitacion2, &QPushButton::clicked, this, &VentanaControl::manejarBotonClimaHabitacion2);
    connect(btnAutoClimaHabitacion2, &QPushButton::clicked, this, &VentanaControl::manejarBotonAutoClimaHabitacion2);
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::manejarBotonClimaHabitacion2() {
    climaHabitacion2Encendido = !climaHabitacion2Encendido;
    if (climaHabitacion2Encendido) {
        enviarComandoArduino("CLIMA_HAB2_ON");
        if (btnClimaHabitacion2) btnClimaHabitacion2->setText("Clima: Encendido");
    } else {
        enviarComandoArduino("CLIMA_HAB2_OFF");
        if (btnClimaHabitacion2) btnClimaHabitacion2->setText("Clima: Apagado");
    }
}

void VentanaControl::manejarBotonAutoClimaHabitacion2() {
    autoClimaHabitacion2 = !autoClimaHabitacion2;
    if (autoClimaHabitacion2) {
        enviarComandoArduino("AUTO_CLIMA_HAB2_ON");
        if (btnAutoClimaHabitacion2) btnAutoClimaHabitacion2->setText("Automático: Activado");
    } else {
        enviarComandoArduino("AUTO_CLIMA_HAB2_OFF");
        if (btnAutoClimaHabitacion2) btnAutoClimaHabitacion2->setText("Automático: Desactivado");
    }
}

void VentanaControl::mostrarMenuCochera() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    btnPuertaCochera = new QPushButton(puertaCocheraAbierta ? "Cerrar Puerta" : "Abrir Puerta");
    btnLucesCochera = new QPushButton(lucesCocheraEncendidas ? "Luces: Apagadas" : "Luces: Encendidas");
    QPushButton *btnRegresar = new QPushButton("Regresar");
    gridLayout->addWidget(btnPuertaCochera, 0, 0);
    gridLayout->addWidget(btnLucesCochera, 1, 0);
    gridLayout->addWidget(btnRegresar, 2, 0);
    connect(btnPuertaCochera, &QPushButton::clicked, this, &VentanaControl::manejarBotonPuertaCochera);
    connect(btnLucesCochera, &QPushButton::clicked, this, &VentanaControl::manejarBotonLucesCochera);
    connect(btnRegresar, &QPushButton::clicked, this, &VentanaControl::mostrarMenuCuadricula);
}

void VentanaControl::manejarBotonLucesCochera() {
    lucesCocheraEncendidas = !lucesCocheraEncendidas;
    if (lucesCocheraEncendidas) {
        enviarComandoArduino("LUZ_COCHERA_ON");
        if (btnLucesCochera) btnLucesCochera->setText("Luces: Apagadas");
    } else {
        enviarComandoArduino("LUZ_COCHERA_OFF");
        if (btnLucesCochera) btnLucesCochera->setText("Luces: Encendidas");
    }
}

void VentanaControl::actualizarEstadoVentana(const QString &habitacion, bool abierta) {
    if (habitacion == "HAB1") {
        ventanaHabitacion1Abierta = abierta;
        if (btnVentanaHabitacion1) btnVentanaHabitacion1->setText(abierta ? "Ventana: Abierta" : "Ventana: Cerrada");
    } else if (habitacion == "HAB2") {
        ventanaHabitacion2Abierta = abierta;
        if (btnVentanaHabitacion2) btnVentanaHabitacion2->setText(abierta ? "Ventana: Abierta" : "Ventana: Cerrada");
    }
}

void VentanaControl::mostrarMenuHabitacionGenerico(const QString &rutaFondo) {
    Q_UNUSED(rutaFondo);
    // Implementación vacía
}

void VentanaControl::agregarBotonImagen(const QString &ruta, int fila, int columna, const QString &tooltip) {
    Q_UNUSED(ruta);
    Q_UNUSED(fila);
    Q_UNUSED(columna);
    Q_UNUSED(tooltip);
    // Implementación vacía
}

void VentanaControl::aplicarEstilosBotones() {
    // Implementación vacía
}

void VentanaControl::configurarLayout() {
    // Implementación vacía
}

void VentanaControl::actualizarFondoPorHora() {
    // Implementación vacía
}

void VentanaControl::mostrarMenuPrincipal() {
    // Implementación vacía
}

void VentanaControl::cambiarFondo(const QString &ruta, bool blur) {
    Q_UNUSED(ruta);
    Q_UNUSED(blur);
    // Implementación vacía
}
