#ifndef VECALCULATOR_OPERACIONES_H
#define VECALCULATOR_OPERACIONES_H

#include "Vecalculator_vectores.h"
#include <cmath>

// Funcion encargada de sumar
puntos suma(puntos a, puntos b);

// Funcion encargada de restar
puntos rest(puntos a, puntos b);

// Funcion encargada de multiplicar por un escalar
puntos p_escalar(puntos a, float escalar);

// Funcion encargada de calcular el producto punto
float p_punto(puntos a,puntos b, int dim);

// Funcion encargada de calcular la norma
float norm(puntos a, int dimension);

// Funcion encargada de calcular los componentes
puntos componentes(puntos vec1_origen, int dimension);

// Funcion encargada de calcular el vector unitario
puntos unitario(puntos a, int dimension);

// Funcion encargada de calcular el angulo
float angle(puntos a, int dim);

// Funcion encargada de calcular el producto cruz
puntos p_cruz(puntos a, puntos b);

#endif //VECALCULATOR_OPERACIONES_H
