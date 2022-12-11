#include "vec_result.h"


// Constructor por defecto, setea todas las coordenadas a 0
vec_result::vec_result() {
    vec_escalar=0;
    dimension=0;
    operacion=0;
}


// Funcion encargada de setear el punto origen del vec 1
void vec_result::setVec1(puntos vec1_origen) {
    this->vec1_origen = vec1_origen;
}


// Funcion encargada de setear el punto origen del vec 2
void vec_result::setVec2(puntos vec2_origen) {
    this->vec2_origen= vec2_origen;
}

// Funcion encargada de setear el escalar
void vec_result::setEscalar(int escalar) {
    this->vec_escalar = escalar;
}


// Funcion encargada de setear la operacion del vector result
void vec_result::setOperacion(int operacion) {
    this->operacion = operacion;
}


/*void vec_result::setVecFinal(vec vec_final) {
    this->vec_total = vec_final;
}*/


// Funcion encargada de setear la dimension del vector result
void vec_result::setDimension(int dimension){
    this->dimension = dimension;
}


// Funcion encargada de retornar el punto Vec1
puntos vec_result::getVec1() {
    return this->vec1_origen;
}


// Funcion encargada de retornar el punto vec 2
puntos vec_result::getVec2() {
    return this->vec2_origen;
}


// Funcion encargada de retornar el punto vec final
puntos vec_result::getVecFinal() {
    return this->vec_fin_origen;
}

// retorna el vector original
Vecalculator_vectores vec_result::getVecOriginal() {
    return this->vec_original;
}


// Funcion encargada de retornar el escalar
int vec_result::getEscalar() {
    return this->vec_escalar;
}


// Funcion encargada de retornar la dimension
int vec_result::getDimension() {
    return this->dimension;
}


// Operacion encargada de retornar el angulo
float vec_result::getAngulo(){
        return this->angulo;
};


// Operacion encargada de la suma
void vec_result::suma(){
    vec_fin_origen.setX(vec1_origen.getX() + vec2_origen.getX());
    vec_fin_origen.setY(vec1_origen.getY() + vec2_origen.getY());
    vec_fin_origen.setZ(vec1_origen.getZ() + vec2_origen.getZ());
}


// Operacion encargada de la resta
void vec_result::rest(){
    vec_fin_origen.setX(vec1_origen.getX() - vec2_origen.getX());
    vec_fin_origen.setY(vec1_origen.getY() - vec2_origen.getY());
    vec_fin_origen.setZ(vec1_origen.getZ() - vec2_origen.getZ());
}


// Operacion encargada del producto punto
float vec_result::p_punto(){
    float c=0;
    if (dimension==2){
        c = vec1_origen.getX()*vec2_origen.getX() + vec1_origen.getY()*vec2_origen.getY();
    }else if (dimension==3){
        c = vec1_origen.getX()*vec2_origen.getX() + vec1_origen.getY()*vec2_origen.getY() + vec1_origen.getZ()*vec2_origen.getZ();
    }
    return c;
}


// Operacion encargada del producto por escalar
void vec_result::p_escalar(){
    vec_fin_origen.setX(vec1_origen.getX()*vec_escalar);
    vec_fin_origen.setY(vec1_origen.getY()*vec_escalar);
    vec_fin_origen.setZ(vec1_origen.getZ()*vec_escalar);
}


// Operacion encargada de la norma/modulo
float vec_result::norm(){
    float mag=0;
    if (dimension == 2){
        mag = sqrt((pow(vec1_origen.getX(), 2) + pow(vec1_origen.getY(), 2)));
    }
    else if (dimension == 3){
        mag = sqrt((pow(vec1_origen.getX(), 2) + pow(vec1_origen.getY(), 2) + pow(vec1_origen.getZ(),2)));
    }
    return mag;
}


// Operacion encargada del calculo de los componentes i,j / i,j,k
void vec_result::componentes(){
    float mag = norm();
    if(dimension==2) {
        vec_fin_origen.setX(mag * cos(vec1_origen.getX()));
        vec_fin_origen.setY(mag * sin(vec1_origen.getY()));
        ////////// revisar else if de abajo //////////////
    }else if (dimension==3){
        vec_fin_origen.setX(mag * cos(vec1_origen.getX()) * cos(vec1_origen.getY()));
        vec_fin_origen.setY(mag * cos(vec1_origen.getX()) * sin(vec1_origen.getY()));
        vec_fin_origen.setZ(mag * sin(vec1_origen.getZ()));
    }
}


// Operacion encargada del calculo del vector unitario
void vec_result::unitario(){
    float mag = norm();
    if(dimension==2) {
        vec1_origen.setX(vec1_origen.getX()/mag);
        vec1_origen.setY(vec1_origen.getY()/mag);
    }else if (dimension==3){
        vec1_origen.setX(vec1_origen.getX()/mag);
        vec1_origen.setY(vec1_origen.getY()/mag);
        vec1_origen.setZ(vec1_origen.getZ()/mag);
    }
}


// Operacion encargada de calcular el angulo entre dos vectores
void vec_result::angle(){
    float angulo;
    if (dimension==2){
        //unitario();
        angulo = atan(vec_fin_origen.getY()/vec_fin_origen.getX());
        this -> angulo = angulo;
    }
    //tangente-1 (Cateto op/cateto ad)
}


// Operacion encargada de calcular el producto cruz
void vec_result::p_cruz(){
    vec_fin_origen.setX(vec1_origen.getY()*vec2_origen.getZ() - vec1_origen.getZ()*vec2_origen.getY());
    vec_fin_origen.setY(vec1_origen.getZ()*vec2_origen.getX() - vec1_origen.getX()*vec2_origen.getZ());
    vec_fin_origen.setZ(vec1_origen.getX()*vec2_origen.getY() - vec1_origen.getY()*vec2_origen.getX());
}


// Filtro encargado de la operacion a realizar
void vec_result::calcular(){
    if(this->operacion==1){
        suma();
    }else if(this->operacion==2){
        rest();
    }else if(this->operacion==3){
        angle();
    }else if(this->operacion==4){
        norm();
    }else if(this->operacion==5){
        componentes();
    }else if(this->operacion==6){
        p_cruz();
    }else if(this->operacion==7){
        p_punto();
    }else if(this->operacion==8){
        p_escalar();
    }else if(this->operacion==9){
        unitario();
    }
}