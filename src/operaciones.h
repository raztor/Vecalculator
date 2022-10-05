#ifndef PROYECTO_TEL102_OPERACIONES_H
#define PROYECTO_TEL102_OPERACIONES_H
#include "data_types.h"
#include <cmath>
vec suma(vec a, vec b){
    vec c=NULL_VEC;
    c.eje_x = a.eje_x + b.eje_x;
    c.eje_y = a.eje_y + b.eje_y;
    c.eje_z = a.eje_z + b.eje_z;
    return c;
}

vec rest(vec a,vec b){
    vec c=NULL_VEC;
    c.eje_x=a.eje_x-b.eje_x;
    c.eje_y=a.eje_y-b.eje_y;
    c.eje_z=a.eje_z-b.eje_z;
    return c;
}

float p_punto(vec a, vec b, int dim){
    float c=0;
    if (dim==1){
        c = a.eje_x*b.eje_x + a.eje_y*b.eje_y;
    }else if (dim==2){
        c = a.eje_x*b.eje_x + a.eje_y*b.eje_y + a.eje_z*b.eje_z;
    }
    return c;
}

vec p_escalar(vec a, float escalar){
    vec c=NULL_VEC;
    c.eje_x=a.eje_x*escalar;
    c.eje_y=a.eje_y*escalar;
    c.eje_z=a.eje_z*escalar;
    return c;
}

float norm(vec a, int dim=1){
    float mag=0;
    if (dim == 1){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2)));
    }
    else if (dim == 2){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2) + pow(a.eje_z,2)));
    }
    std::cout << "La norma del vector es: " << mag << std::endl;
    return mag;
}

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

float angle(vec a){
    vec result_cateto = vec_unitario(a, 1);
    float angulo = atan(result_cateto.eje_y/result_cateto.eje_x);
    return angulo;

} //tangente-1 (Cateto op/cateto ad)

vec p_cruz(vec a, vec b, int dim=2){

    vec pc = NULL_VEC;
    pc.eje_x = (a.eje_y*b.eje_z - a.eje_z*b.eje_y);
    pc.eje_y = (a.eje_z*b.eje_x - a.eje_x*b.eje_z);
    pc.eje_z = (a.eje_x*b.eje_y - a.eje_y*b.eje_x);

    return pc;
}


#endif //PROYECTO_TEL102_OPERACIONES_H
