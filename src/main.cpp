// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++

#include <iostream>
#include <cstring>
#include "operaciones.h"
#include "menu.h"
using namespace std;
bool ciclo_main= true, ciclo_menu=true;
int main() {
    while(ciclo_main) {
        int operacion, dimension;
        char op_verbose[20], dim_verbose[3];
        vec vector1 = NULL_VEC, vector2 = NULL_VEC, result_vec = NULL_VEC;
        float result_float, escalar = 0;
        /// (verbose significa en palabras) ////
        dim_menu(dimension, dim_verbose, ciclo_menu, ciclo_main);
        while(ciclo_menu){
            cout << "Dimension seleccionada: " << dim_verbose << "\n" << endl;

    /////////////////////////////// Seleccion de operacion ///////////////////////////////

            func_menu(operacion);

            if (operacion == 1) {
                strcpy(op_verbose, "Suma");
            } else if (operacion == 2) {
                strcpy(op_verbose, "Resta");
            } else if (operacion == 3) {
                strcpy(op_verbose, "Vector Unitario");
            } else if (operacion == 4) {
                strcpy(op_verbose, "Angulo");
            } else if (operacion == 5) {
                strcpy(op_verbose, "Producto punto");
            } else if (operacion == 6) {
                strcpy(op_verbose, "Producto cruz");
            } else if (operacion == 7) {
                strcpy(op_verbose, "Modulo");
            } else if (operacion == 8) {
                strcpy(op_verbose, "PLACEHOLDER");
            } else if (operacion == 9) {
                strcpy(op_verbose, "Producto Escalar");
            } else if (operacion == 10) {
                cout << "Reiniciando...\n" << endl;
                break;
            } else {
                cout << "Operacion invalida" << endl;
                return 0;
            }
            cout << "Operacion seleccionada: \n" << op_verbose << endl;

            /////////////////////////////// Ingreso de vectores ///////////////////////////////
            /////////////////////////////// Ingreso de vectores ///////////////////////////////

            if (operacion != 3 && operacion != 7 && operacion != 9) {
                if (dimension == 1) {
                    cout << "Ingrese el vector 1 en formato x y" << endl;
                    cin >> vector1.eje_x >> vector1.eje_y;
                    vector1.eje_z = 0;
                    cout << "Ingrese el vector 2 en formato x y" << endl;
                    cin >> vector2.eje_x >> vector2.eje_y;
                    vector2.eje_z = 0;

                } else if (dimension == 2) {
                    cout << "Ingrese el vector 1 en formato x y z" << endl;
                    cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                    cout << "Ingrese el vector 2 en formato x y z" << endl;
                    cin >> vector2.eje_x >> vector2.eje_y >> vector2.eje_z;
                }

            } else if (operacion == 3 || operacion == 7) {
                if (dimension == 1) {
                    cout << "Ingrese el vector en formato x y" << endl;
                    cin >> vector1.eje_x >> vector1.eje_y;
                    vector1.eje_z = 0;
                } else if (dimension == 2) {
                    cout << "Ingrese el vector en formato x y z" << endl;
                    cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                }
            } else if (operacion == 9) {
                if (dimension == 1) {
                    cout << "Ingrese el vector en formato x y" << endl;
                    cin >> vector1.eje_x >> vector1.eje_y;
                    vector1.eje_z = 0;
                    cout << "Ingrese el escalar" << endl;
                    cin >> escalar;
                } else if (dimension == 2) {
                    cout << "Ingrese el vector en formato x y z" << endl;
                    cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                    cout << "Ingrese el escalar" << endl;
                    cin >> escalar;
                }
            }

            //////////////////////////// Iniciador de funciones ///////////////////////////////

            switch (operacion) {
                case 1:
                    result_vec = suma(vector1, vector2);
                    if (dimension == 1) {
                        cout << "El resultado es: " << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es: (" << result_vec.eje_x << "," << result_vec.eje_y << ","
                             << result_vec.eje_z << ")" << endl;
                    }
                    break;
                case 2:
                    result_vec = rest(vector1, vector2);
                    if (dimension == 1) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ","
                             << result_vec.eje_z << ")" << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 3:
                    cout << "Vector Unitario" << endl;
                    result_vec = vec_unitario(vector1);
                    if (dimension == 1) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << " i " << "+ " << result_vec.eje_y << " j " << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << " i "<< "+ " << result_vec.eje_y << " j " << "+ "
                             << result_vec.eje_z << " k " << ")" << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 4:
                    result_float = angle(vector1);
                    if(dimension == 1){
                        cout<<"El resultado es: "<< result_float << "°" <<endl;
                    }
                    else if (dimension == 2){
                        cout<<"Trabajando para ello... Por favor seleccione otra opcion"<<endl;
                    }

                    break;
                case 5:
                    /// Producto Punto
                    result_float = p_punto(vector1, vector2, dimension);
                    if (dimension == 1) {
                        cout << "El resultado es: " << result_float << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es: " << result_float << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 6:
                    cout << "Producto cruz" << endl;
                    result_vec = p_cruz(vector1, vector2, dimension);
                    if(dimension == 1){
                        cout<<"No se puede realizar esta operacion en 2 dimensiones, intente de nuevo."<<endl;
                    }
                    else if (dimension == 2) {
                        cout<<"El resultado es: ("<<result_vec.eje_x<<","<<result_vec.eje_y<<","<<result_vec.eje_z<<")"<<endl;
                    }
                    else{
                        cout<<"Ha ocurrido un error con las dimensiones"<<endl;
                    }
                    break;
                case 7:
                    //cout << "Modulo" << endl;
                    result_float = norm(vector1, dimension);
                    if (dimension == 1) {
                        cout << "El resultado es:" << result_float << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << result_float << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 8:
                    cout << "PLACEHOLDER" << endl;
                    //////
                    break;
                case 9:
                    //cout << "Producto Escalar" << endl;
                    result_vec = p_escalar(vector1, escalar);
                    if (dimension == 1) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ","
                             << result_vec.eje_z << ")" << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                        break;
                    }
                case 10:
                    cout << "Volver a la seleccion" << endl;
                    break;
                default:
                    cout << "Operacion no valida" << endl;
                    break;
            }
            fin_menu(ciclo_main, ciclo_menu, dim_verbose);
        }
    }
    return 0;
}
