#include "operaciones.h"

// Funcion encargada de sumar
puntos suma(puntos a, puntos b){
    puntos result;
    result.setX(a.getX()+b.getX());
    result.setY(a.getY()+b.getY());
    result.setZ(a.getZ()+b.getZ());
    return result;
}

// Funcion encargada de restar
puntos rest(puntos a, puntos b){
    puntos result;
    result.setX(a.getX()-b.getX());
    result.setY(a.getY()-b.getY());
    result.setZ(a.getZ()-b.getZ());
    return result;
}

// Funcion encargada de multiplicar por un escalar
puntos p_escalar(puntos a, float escalar){
    puntos result;
    result.setX(a.getX()*escalar);
    result.setY(a.getY()*escalar);
    result.setZ(a.getZ()*escalar);
    return result;
}

// Funcion encargada de calcular el producto punto
float p_punto(puntos a,puntos b, int dim){
    float c=0;
    if (dim==2){
        c = a.getX()*b.getX() + a.getY()*b.getY();
    }else if (dim==3){
        c = a.getX()*b.getX() + a.getY()*b.getY() + a.getZ()*b.getZ();
    }
    return c;
}

// Funcion encargada de calcular la norma
float norm(puntos a, int dimension){
    float mag=0;
    if (dimension == 2){
        mag = sqrt((pow(a.getX(), 2) + pow(a.getY(), 2)));
    }
    else if (dimension == 3){
        mag = sqrt((pow(a.getX(), 2) + pow(a.getY(), 2) + pow(a.getZ(),2)));
    }
    return mag;
}

// Funcion encargada de calcular los componentes
puntos componentes(puntos vec1_origen, int dimension){
    float mag = norm(vec1_origen, dimension);
    puntos vec_fin_origen;
    if(dimension==2) {
        vec_fin_origen.setX(mag * cos(vec1_origen.getX()));
        vec_fin_origen.setY(mag * sin(vec1_origen.getY()));
        ////////// revisar else if de abajo //////////////
    }else if (dimension==3){
        vec_fin_origen.setX(mag * cos(vec1_origen.getX()) * cos(vec1_origen.getY()));
        vec_fin_origen.setY(mag * cos(vec1_origen.getX()) * sin(vec1_origen.getY()));
        vec_fin_origen.setZ(mag * sin(vec1_origen.getZ()));
    }
    return vec_fin_origen;
}

// Funcion encargada de calcular el vector unitario
puntos unitario(puntos a, int dimension){
    float mag = norm(a, dimension);
    puntos result;
    if(dimension==2) {
        result.setX(a.getX()/mag);
        result.setY(a.getY()/mag);
    }else if (dimension==3){
        result.setX(a.getX()/mag);
        result.setY(a.getY()/mag);
        result.setZ(a.getZ()/mag);
    }
    return result;
}

// Funcion encargada de calcular el angulo
float angle(puntos a, int dim){
    float angulo;
    if (dim==2){
        puntos result_cateto = unitario(a, 2);
        angulo = atan(result_cateto.getY()/result_cateto.getX());
    } else if (dim==3){
        angulo = 0;
    }
    return angulo;

} //tangente-1 (Cateto op/cateto ad)

// Funcion encargada de calcular el producto cruz
puntos p_cruz(puntos a, puntos b){
    puntos pc;
    pc.setX(a.getY()*b.getZ() - a.getZ()*b.getY());
    pc.setY(a.getZ()*b.getX() - a.getX()*b.getZ());
    pc.setZ(a.getX()*b.getY() - a.getY()*b.getX());
    return pc;
}
