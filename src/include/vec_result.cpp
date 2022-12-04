//
// Created by benjamin on 04-12-22.
//

#include "vec_result.h"

vec_result::vec_result() {
    vec_orig=NULL_VEC;
    vec_oper=NULL_VEC;
    vec_total=NULL_VEC;
    vec_escalar=0;
    dimension=0;
    operacion=0;
}

void vec_result::setVec1(vec vec1) {
    this->vec_orig = vec1;
}
void vec_result::setVec2(vec vec2) {
    this->vec_oper = vec2;
}
void vec_result::setEscalar(int escalar) {
    this->vec_escalar = escalar;
}
void vec_result::setOperacion(int operacion) {
    this->operacion = operacion;
}
/*void vec_result::setVecFinal(vec vec_final) {
    this->vec_total = vec_final;
}*/
void vec_result::setDimension(int dimension){
    this->dimension = dimension;
}
vec vec_result::getVec1() {
    return this->vec_orig;
}
vec vec_result::getVec2() {
    return this->vec_oper;
}
vec vec_result::getVecFinal() {
    return this->vec_total;
}
int vec_result::getEscalar() {
    return this->vec_escalar;
}
int vec_result::getDimension() {
    return this->dimension;
}


// Operacion encargada de la suma
void vec_result::suma(){
    vec_total.eje_x = vec_orig.eje_x + vec_oper.eje_x;
    vec_total.eje_y = vec_orig.eje_y + vec_oper.eje_y;
    vec_total.eje_z = vec_orig.eje_z + vec_oper.eje_z;
}
// Operacion encargada de la resta
void vec_result::rest(){
    vec_total.eje_x=vec_orig.eje_x-vec_oper.eje_x;
    vec_total.eje_y=vec_orig.eje_y-vec_oper.eje_y;
    vec_total.eje_z=vec_orig.eje_z-vec_oper.eje_z;
}
// Operacion encargada del producto punto
float vec_result::p_punto(){
    float c=0;
    if (dimension==1){
        c = vec_orig.eje_x*vec_oper.eje_x + vec_orig.eje_y*vec_oper.eje_y;
    }else if (dimension==2){
        c = vec_orig.eje_x*vec_oper.eje_x + vec_orig.eje_y*vec_oper.eje_y + vec_orig.eje_z*vec_oper.eje_z;
    }
    return c;
}
// Operacion encargada del producto por escalar
void vec_result::p_escalar(){
    vec_total.eje_x=vec_orig.eje_x*vec_escalar;
    vec_total.eje_y=vec_orig.eje_y*vec_escalar;
    vec_total.eje_z=vec_orig.eje_z*vec_escalar;
}
// Operacion encargada de la norma/modulo
float vec_result::norm(){
    float mag=0;
    if (dimension == 1){
        mag = sqrt((pow(vec_orig.eje_x, 2) + pow(vec_orig.eje_y, 2)));
    }
    else if (dimension == 2){
        mag = sqrt((pow(vec_orig.eje_x, 2) + pow(vec_orig.eje_y, 2) + pow(vec_orig.eje_z,2)));
    }
    return mag;
}
// Operacion encargada del calculo de los componentes i,j / i,j,k

void vec_result::componentes(){
    float mag = norm();
    if(dimension==1) {
        vec_total.eje_x = mag * cos(vec_orig.eje_x);
        vec_total.eje_y = mag * sin(vec_orig.eje_y);
        ////////// revisar else if de abajo //////////////
    }else if (dimension==2){
        vec_total.eje_x = mag * cos(vec_orig.eje_x) * cos(vec_orig.eje_y);
        vec_total.eje_y = mag * cos(vec_orig.eje_x) * sin(vec_orig.eje_y);
        vec_total.eje_z = mag * sin(vec_orig.eje_z);
    }
}
// Operacion encargada del calculo del vector unitario
void vec_result::unitario(){
    float mag = norm();
    if(dimension==1) {
        vec_orig.eje_x = vec_orig.eje_x/mag;
        vec_orig.eje_y = vec_orig.eje_y/mag;
    }else if (dimension==2){
        vec_orig.eje_x = vec_orig.eje_x/mag;
        vec_orig.eje_y = vec_orig.eje_y/mag;
        vec_orig.eje_z = vec_orig.eje_z/mag;
    }
}
// Operacion encargada de calcular el angulo entre dos vectores
float vec_result::angle(){
    float angulo;
    if (dimension==1){
        unitario();
        angulo = atan(vec_total.eje_y/vec_total.eje_x);
    }
    return angulo;

} //tangente-1 (Cateto op/cateto ad)

void vec_result::p_cruz(){
    vec_total.eje_x = (vec_orig.eje_y*vec_oper.eje_z - vec_orig.eje_z*vec_oper.eje_y);
    vec_total.eje_y = (vec_orig.eje_z*vec_oper.eje_x - vec_orig.eje_x*vec_oper.eje_z);
    vec_total.eje_z = (vec_orig.eje_x*vec_oper.eje_y - vec_orig.eje_y*vec_oper.eje_x);

}

void vec_result::calcular(){
    if(this->operacion==1){
        suma();
    }else if(this->operacion==2){
        rest();
    }else if(this->operacion==3){
        p_escalar();
    }else if(this->operacion==4){
        p_punto();
    }else if(this->operacion==5){
        norm();
    }else if(this->operacion==6){
        componentes();
    }else if(this->operacion==7){
        unitario();
    }else if(this->operacion==8){
        angle();
    }else if(this->operacion==9){
        p_cruz();
    }
}