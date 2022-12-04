// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++
#include <QApplication>
#include "qt/vecalculator.h"

bool ciclo_main= true, ciclo_menu=true;
int main(int argc, char **argv) {
    QApplication a(argc, argv);
    vecalculator w;
    w.show();
    return a.exec();;
}
