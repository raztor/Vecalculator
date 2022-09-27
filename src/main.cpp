// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

/// SE DEBE CAMBIAR EL TIPO DE DATO DE RETORNO //////
/// FALTA CREAR LAS FUNCIONES ///////////////////////

float sum();
float rest();
float mult();
float div();
float dot();
float cross();
float norm();
float angle();
float unit();
float help();
float exit();


int main(){
    int operacion, dimension;
    /// (verbose significa en palabras) ////
    char op_verbose[10], dim_verbose[5];

    ///////////////////////// Seleccion de dimension /////////////////////////
    std::cout << "El vector es 2D o 3D?" << std::endl;
    std::cout << "1. 2D" << std::endl;
    std::cout << "2. 3D" << std::endl;
    std::cin >> dimension;
    if (dimension == 1){
        strcpy(dim_verbose, "2D");
    }
    else if (dimension == 2){
        strcpy(dim_verbose, "3D");
    }
    else{
        std::cout << "Dimension invalida" << std::endl;
        return 0;
    }
    std::cout << "Dimension seleccionada: " << dim_verbose << std::endl;

/////////////////////////////// Seleccion de operacion ///////////////////////////////

    std::cout << "Que operacion desea realizar?" << std::endl;
    std::cout << "1. Suma" << std::endl;
    std::cout << "2. Resta" << std::endl;
    std::cout << "3. Multiplicacion" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Producto punto" << std::endl;
    std::cout << "6. Producto cruz" << std::endl;
    std::cout << "7. Norma" << std::endl;
    std::cout << "8. Angulo" << std::endl;
    std::cout << "9. Salir" << std::endl;
    std::cin >> operacion;
    if (operacion == 1){
        strcpy(op_verbose, "Suma");
    }
    else if (operacion == 2){
        strcpy(op_verbose, "Resta");
    }
    else if (operacion == 3){
        strcpy(op_verbose, "Multiplicacion");
    }
    else if (operacion == 4){
        strcpy(op_verbose, "Division");
    }
    else if (operacion == 5){
        strcpy(op_verbose, "Producto punto");
    }
    else if (operacion == 6){
        strcpy(op_verbose, "Producto cruz");
    }
    else if (operacion == 7){
        strcpy(op_verbose, "Norma");
    }
    else if (operacion == 8){
        strcpy(op_verbose, "Angulo");
    }
    else if (operacion == 9){
        std::cout << "Saliendo..." << std::endl;
        return 0;
    }
    else{
        std::cout << "Operacion invalida" << std::endl;
        return 0;
    }

    std::cout << "Operacion seleccionada: " << op_verbose << std::endl;

    //////////////////////////// Iniciador de funciones ///////////////////////////////

    switch (operacion) {
        case 1:
            std::cout << "Suma" << std::endl;
            break;
        case 2:
            std::cout << "Resta" << std::endl;
            break;
        case 3:
            std::cout << "Multiplicacion" << std::endl;
            break;
        case 4:
            std::cout << "Division" << std::endl;
            break;
        case 5:
            std::cout << "Producto punto" << std::endl;
            break;
        case 6:
            std::cout << "Producto cruz" << std::endl;
            break;
        case 7:
            std::cout << "Norma" << std::endl;
            break;
        case 8:
            std::cout << "Angulo" << std::endl;
            break;
        case 9:
            std::cout << "Salir" << std::endl;
            break;
        default:
            std::cout << "Operacion no valida" << std::endl;
            break;
    }



    return 0;
}

