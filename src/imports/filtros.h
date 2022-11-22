#ifndef PROYECTO_TEL102_FILTROS_H
#define PROYECTO_TEL102_FILTROS_H
#include "vectores.h"
#include <iostream>

/* De momento este filtro solo sirve para la funcion de vector unitario pero planeamos reutilizarla.
    Separa las dimensiones y aplica i,j y z a los std::cout */
void filtro_dim_gen(int &dimension, vec result_vec);

// Filtro para separar 2D y 3D en el std::cout generico (x,y,z)
void filtro_dim_componente(int &dimension, vec result_vec);

// Filtros de los input para poder distinguir entre vector 2D, 3D y escalar
void filtro_input(int &operacion, int &dimension, vec &vector1, vec &vector2, float &escalar);

#endif //PROYECTO_TEL102_FILTROS_H
