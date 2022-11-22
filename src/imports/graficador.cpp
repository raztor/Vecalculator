#include "graficador.h"

void MainWindow::setEje_x(float x) {
    eje_x = x;
}
void MainWindow::setEje_y(float y) {
    eje_y = y;
}
void MainWindow::setOr_x(float or_x) {
    original_x = or_x;
}
void MainWindow::setOr_y(float or_y) {
    original_y = or_y;
}

void graficar2d(vec final, vec inicial, int argc, char **argv){
    QApplication a(argc, argv);
    MainWindow w(final.eje_x, final.eje_y, inicial.eje_x, inicial.eje_y);
    w.show();
    a.exec();
}