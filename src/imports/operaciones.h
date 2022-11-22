#ifndef PROYECTO_TEL102_OPERACIONES_H
#define PROYECTO_TEL102_OPERACIONES_H

#include "vectores.h"
#include <cmath>
#include <iostream>

// Operacion encargada de la suma
vec suma(vec a, vec b);

// Operacion encargada de la resta
vec rest(vec a,vec b);

// Operacion encargada del producto punto
float p_punto(vec a, vec b, int dim);

// Operacion encargada del producto por escalar
vec p_escalar(vec a, float escalar);

// Operacion encargada de la norma/modulo
float norm(vec a, int dim);

// Operacion encargada del calculo de los componentes i,j / i,j,k
vec componentes(vec a, int dim);

// Operacion encargada del calculo del vector unitario
vec unitario(vec a, int dim);

// Operacion encargada de calcular el angulo entre dos vectores
float angle(vec a, int dim);//tangente-1 (Cateto op/cateto ad)

vec p_cruz(vec a, vec b);

#endif //PROYECTO_TEL102_OPERACIONES_H
