#include <QApplication>
#include "ventana_control.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    VentanaControl ventana;
    ventana.setWindowState(Qt::WindowFullScreen); // Asegura que la ventana se muestre en pantalla completa
    ventana.show();
    return app.exec();
}
