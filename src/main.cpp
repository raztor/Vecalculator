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
using namespace std;

/// SE DEBE CAMBIAR EL TIPO DE DATO DE RETORNO //////
/// FALTA CREAR LAS FUNCIONES ///////////////////////

struct vector{
    double eje_x;
    double eje_y;
    double eje_z;
};

double sum(); //joaco
double rest(); //benja
/*float mult();
float div();
float dot();
float cross();
float angle();
float unit();*/
double exit();
double norm(); //andrea


int main(){
    int operacion, dimension;
    float vec_1[3], vec_2[3], temp_vec_1, temp_vec_2;
    /// (verbose significa en palabras) ////
    char op_verbose[10], dim_verbose[5];

    //hola

    ///////////////////////// Seleccion de dimension /////////////////////////
    cout << "El vector es 2D o 3D?" << endl;
    cout << "1. 2D" << endl;
    cout << "2. 3D" << endl;
    cin >> dimension;
    if (dimension == 1){
        strcpy(dim_verbose, "2D");
    }
    else if (dimension == 2){
        strcpy(dim_verbose, "3D");
    }
    else{
        cout << "Dimension invalida" << endl;
        return 0;
    }
    cout << "Dimension seleccionada: " << dim_verbose << endl;

/////////////////////////////// Seleccion de operacion ///////////////////////////////

    cout << "Que operacion desea realizar?" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Producto punto" << endl;
    cout << "6. Producto cruz" << endl;
    cout << "7. Norma" << endl;
    cout << "8. Angulo" << endl;
    cout << "9. Salir" << endl;
    cin >> operacion;
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
        cout << "Saliendo..." << endl;
        return 0;
    }
    else{
        cout << "Operacion invalida" << endl;
        return 0;
    }

    cout << "Operacion seleccionada: " << op_verbose << endl;
    if(dimension == 1) {
        cout << "Ingrese el vector 1 en formato x, y" << endl;
        cin >> temp_vec_1;
    }else if(dimension == 2){
        cout << "Ingrese el vector 1 en formato x, y, z" << endl;
    }

    //////////////////////////// Iniciador de funciones ///////////////////////////////

    switch (operacion) {
        case 1:
            cout << "Suma" << endl;
            break;
        case 2:
            cout << "Resta" << endl;
            break;
        case 3:
            cout << "Multiplicacion" << endl;
            break;
        case 4:
            cout << "Division" << endl;
            break;
        case 5:
            cout << "Producto punto" << endl;
            break;
        case 6:
            cout << "Producto cruz" << endl;
            break;
        case 7:
            cout << "Norma" << endl;
            break;
        case 8:
            cout << "Angulo" << endl;
            break;
        case 9:
            cout << "Salir" << endl;
            break;
        default:
            cout << "Operacion no valida" << endl;
            break;
    }



    return 0;
}

