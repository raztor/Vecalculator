// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++

#include <iostream>
#include "operaciones.h"
#include "menu.h"
#include "filtros.h"
#include "graficador.h"

bool ciclo_main= true, ciclo_menu=true;
int main(int argc, char **argv) {

    // Ciclo principal, con seleccion de dimension
    while(ciclo_main) {
        int operacion=0, dimension=0;
        char op_verbose[20], dim_verbose[3];// Variables para hacer std::cout de la dimension y operacion en palabras
        vec vector1 = NULL_VEC, vector2 = NULL_VEC, result_vec=NULL_VEC;// Inicializacion de los vectores con valor 0
        float result_float, escalar = 0;

        // Menu de seleccion de dimension
        dim_menu(dimension, dim_verbose, ciclo_menu, ciclo_main);

        // Ciclo para operaciones (dimension constante)
        while(ciclo_menu){
            std::cout << "Dimension seleccionada: " << dim_verbose << "\n" << std::endl;

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
                case 1: {// Suma
                    result_vec = suma(vector1, vector2);
                    filtro_dim_gen(dimension, result_vec);
                    if(dimension==1){
                        graficar2d(result_vec, vector1, argc, argv);
                    }else if(dimension==2){
                        // FUNCION PENDIENTE
                        //graficar3d(result_vec.eje_x, result_vec.eje_y, result_vec.eje_z, vector1.eje_x, vector1.eje_y, vector1.eje_z, argc, argv);
                    }
                    break;
                }
                case 2: {// Resta
                    result_vec = rest(vector1, vector2);
                    filtro_dim_gen(dimension, result_vec);
                    if(dimension==1){
                        graficar2d(result_vec, vector1, argc, argv);
                    }else if(dimension==2){
                        // FUNCION PENDIENTE
                        //graficar3d(result_vec.eje_x, result_vec.eje_y, result_vec.eje_z, vector1.eje_x, vector1.eje_y, vector1.eje_z, argc, argv);
                    }                    break;
                }
                case 3: {// Vector unitario
                    result_vec = unitario(vector1, dimension);
                    filtro_dim_gen(dimension, result_vec);
                    if(dimension==1){
                        graficar2d(result_vec, vec {0,0,0}, argc, argv);
                    }else if(dimension==2){
                        // FUNCION PENDIENTE
                        //graficar3d(result_vec.eje_x, result_vec.eje_y, result_vec.eje_z, vector1.eje_x, vector1.eje_y, vector1.eje_z, argc, argv);
                    }break;
                }
                case 4: {// Angulo
                    if (dimension == 1) {
                        result_float = angle(vector1, dimension);
                        std::cout << "El resultado es: " << result_float << "°" << std::endl;
                        if(dimension==1){
                            graficar2d(result_vec, vector1, argc, argv);
                        }else if(dimension==2){
                            // FUNCION PENDIENTE
                            //graficar3d(result_vec.eje_x, result_vec.eje_y, result_vec.eje_z, vector1.eje_x, vector1.eje_y, vector1.eje_z, argc, argv);
                        }
                    } else if (dimension == 2) {
                        std::cout << "Proximamente..." << std::endl;
                    }
                    break;
                }
                case 5: {// Producto Punto
                    result_float = p_punto(vector1, vector2, dimension);
                    std::cout << "El resultado es: " << result_float << std::endl;
                    break;
                }
                case 6:{
                // Producto Cruz
                std::cout << "Producto cruz" << std::endl;
                result_vec = p_cruz(vector1, vector2);
                filtro_dim_gen(dimension, result_vec);
                break;
            }
                case 7: {
                    //Modulo;
                    result_float = norm(vector1, dimension);
                    std::cout << "El resultado es: " << result_float << std::endl;
                    break;
                }
                case 8: {
                    std::cout << "Componentes" << std::endl;
                    result_vec = componentes(vector1, dimension);
                    filtro_dim_componente(dimension, result_vec);
                    break;
                }
                case 9: {// Producto por escalar
                    result_vec = p_escalar(vector1, escalar);
                    filtro_dim_gen(dimension, result_vec);
                    if(dimension==1){
                        graficar2d(result_vec, vector1, argc, argv);
                    }else if(dimension==2){
                        // FUNCION PENDIENTE
                        //graficar3d(result_vec.eje_x, result_vec.eje_y, result_vec.eje_z, vector1.eje_x, vector1.eje_y, vector1.eje_z, argc, argv);
                    }
                    break;
                }
                case 10: {// Volver al menu
                    std::cout << "Volver a la seleccion" << std::endl;
                    break;
                }
                default: {
                    std::cout << "Operacion no valida" << std::endl;
                    break;
                }
            }
            fin_menu(ciclo_main, ciclo_menu, dim_verbose);
        }
    }
    return 1;
}
