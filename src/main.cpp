#include <QApplication>
#include "ventana_control.hpp"
#include <memory>
#include <vector>
#include "actuadores.hpp"
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[]) {
    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
    std::cout << "Iniciando app..." << std::endl;
    QApplication app(argc, argv);
    // Crear algunos dispositivos de ejemplo
    std::vector<std::shared_ptr<Actuador>> dispositivos;
    dispositivos.push_back(std::make_shared<FocoPrincipal>());
    dispositivos.push_back(std::make_shared<LedFondo>());
    dispositivos.push_back(std::make_shared<Puerta>());
    // Puedes agregar más dispositivos según tu lógica
    try {
        VentanaControl ventana(dispositivos);
        ventana.setWindowState(Qt::WindowFullScreen); // Asegura que la ventana se muestre en pantalla completa
        ventana.show();
        std::cout << "Ventana creada y mostrada." << std::endl;
        return app.exec();
    } catch (const std::exception& e) {
        std::cerr << "Error al crear o mostrar la ventana: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error desconocido al crear o mostrar la ventana." << std::endl;
        return 2;
    }
}
