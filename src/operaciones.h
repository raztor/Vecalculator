#ifndef PROYECTO_TEL102_OPERACIONES_H
#define PROYECTO_TEL102_OPERACIONES_H
#include "vectores.h"
#include <cmath>
// Operacion encargada de la suma
vec suma(vec a, vec b){
    vec c=NULL_VEC;
    c.eje_x = a.eje_x + b.eje_x;
    c.eje_y = a.eje_y + b.eje_y;
    c.eje_z = a.eje_z + b.eje_z;
    return c;
}
// Operacion encargada de la resta
vec rest(vec a,vec b){
    vec c=NULL_VEC;
    c.eje_x=a.eje_x-b.eje_x;
    c.eje_y=a.eje_y-b.eje_y;
    c.eje_z=a.eje_z-b.eje_z;
    return c;
}
// Operacion encargada del producto punto
float p_punto(vec a, vec b, int dim){
    float c=0;
    if (dim==1){
        c = a.eje_x*b.eje_x + a.eje_y*b.eje_y;
    }else if (dim==2){
        c = a.eje_x*b.eje_x + a.eje_y*b.eje_y + a.eje_z*b.eje_z;
    }
    return c;
}
// Operacion encargada del producto por escalar
vec p_escalar(vec a, float escalar){
    vec c=NULL_VEC;
    c.eje_x=a.eje_x*escalar;
    c.eje_y=a.eje_y*escalar;
    c.eje_z=a.eje_z*escalar;
    return c;
}
// Operacion encargada de la norma/modulo
float norm(vec a, int dim=1){
    float mag=0;
    if (dim == 1){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2)));
    }
    else if (dim == 2){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2) + pow(a.eje_z,2)));
    }
    return mag;
}
// Operacion encargada del calculo del vector unitario i,j / i,j,k
vec vec_unitario(vec a, int dim= 1){
    float mag = norm(a, dim);
    if(dim==1) {
        a.eje_x = mag * cos(a.eje_x);
        a.eje_y = mag * sin(a.eje_y);
        ////////// revisar else if de abajo //////////////
    }else if (dim==2){
        a.eje_x = mag * cos(a.eje_x) * cos(a.eje_y);
        a.eje_y = mag * cos(a.eje_x) * sin(a.eje_y);
        a.eje_z = mag * sin(a.eje_z);
    }
    return a;
}
// Operacion encargada de calcular el angulo entre dos vectores
float angle(vec a, int dim){
    float angulo;
    if (dim==1){
        vec result_cateto = vec_unitario(a, 1);
        angulo = atan(result_cateto.eje_y/result_cateto.eje_x);
    } else if (dim==2){
        std::cout << "Esta funcion vendra en un futuro proximo" << std::endl;
        angulo = 0;
    }
    return angulo;

} //tangente-1 (Cateto op/cateto ad)

vec p_cruz(vec a, vec b){

    vec pc = NULL_VEC;
    pc.eje_x = (a.eje_y*b.eje_z - a.eje_z*b.eje_y);
    pc.eje_y = (a.eje_z*b.eje_x - a.eje_x*b.eje_z);
    pc.eje_z = (a.eje_x*b.eje_y - a.eje_y*b.eje_x);

    return pc;
}


#endif //PROYECTO_TEL102_OPERACIONES_H
