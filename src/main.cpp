// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++

#include <iostream>
#include "operaciones.h"
#include "menu.h"
#include "filtros.h"
using namespace std;
bool ciclo_main= true, ciclo_menu=true;
int main() {
    // Ciclo principal, con seleccion de dimension
    while(ciclo_main) {
        int operacion=0, dimension=0;
        char op_verbose[20], dim_verbose[3];// Variables para hacer cout de la dimension y operacion en palabras
        vec vector1 = NULL_VEC, vector2 = NULL_VEC, result_vec;// Inicializacion de los vectores con valor 0
        float result_float, escalar = 0;

        // Menu de seleccion de dimension
        dim_menu(dimension, dim_verbose, ciclo_menu, ciclo_main);

        // Ciclo para operaciones (dimension constante)
        while(ciclo_menu){
            cout << "Dimension seleccionada: " << dim_verbose << "\n" << endl;

            // Seleccion de la operación
            func_menu(operacion, op_verbose);
            if(operacion == 10){
                ciclo_menu = false;
                break;
            }

            // Filtro de dimension para el input de los vectores
            filtro_input(operacion,dimension,vector1,vector2,escalar);


            //////////////////////////// Iniciador de funciones ///////////////////////////////

            switch (operacion) {
                case 1:// Suma
                    result_vec = suma(vector1, vector2);
                    filtro_dim_gen(dimension, result_vec);
                    break;
                case 2:// Resta
                    result_vec = rest(vector1, vector2);
                    filtro_dim_gen(dimension, result_vec);
                    break;
                case 3:// Vector unitario
                    cout << "Vector Unitario" << endl;
                    result_vec = vec_unitario(vector1);
                    filtro_dim_componente(dimension, result_vec);
                    break;
                case 4:// Angulo
                    result_float = angle(vector1);
                    if(dimension == 1){
                        cout<<"El resultado es: "<< result_float << "°" <<endl;
                    }
                    else if (dimension == 2){
                        cout<<"Trabajando para ello... Por favor seleccione otra opcion"<<endl;
                    }
                    break;
                case 5:// Producto Punto
                    result_float = p_punto(vector1, vector2, dimension);
                    cout << "El resultado es: " << result_float << endl;
                    break;
                case 6:// Producto Cruz
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
                    //Modulo;
                    result_float = norm(vector1, dimension);
                    cout << "El resultado es: " << result_float << endl;
                    break;
                case 8:// Proximamente
                    cout << "Nuevas funciones vendran en proximas actualizaciones" << endl;
                    operacion = 10;
                    break;
                case 9:// Producto por escalar
                    result_vec = p_escalar(vector1, escalar);
                    filtro_dim_gen(dimension, result_vec);
                    break;
                case 10:// Volver al menu
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
