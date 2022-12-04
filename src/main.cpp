// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++
#include <QApplication>
#include "qt/demo.h"

bool ciclo_main= true, ciclo_menu=true;
int main(int argc, char **argv) {

    QApplication a(argc, argv);
    demo w;
    w.show();

    return a.exec();;
}
