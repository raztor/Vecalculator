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

void graficar2d(int x, int y, int x_orig, int y_orig, int argc, char **argv){
    QApplication a(argc, argv);
    MainWindow w(x, y, x_orig, y_orig);
    w.show();
    a.exec();
}