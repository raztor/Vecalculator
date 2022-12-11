#include "Vecalculator_vectores.h"

// Constructor sin parametros del vector
Vecalculator_vectores::Vecalculator_vectores() {
    this->origen = puntos(0,0,0,0);
    this->fin = puntos(0,0,0,0);
    this->fin_cero = puntos(0,0,0,0);
    this->origen_cero = puntos(0,0,0,0);
}

// Constructor del vector
Vecalculator_vectores::Vecalculator_vectores(puntos origen, puntos fin, puntos fin_cero) {
    this->origen = origen;
    this->fin = fin;
    this->fin_cero = fin_cero;
    this->origen_cero = puntos(0,0,0,0);
}

// Establece el punto origen del vector
void Vecalculator_vectores::setOrigen(puntos origen) {
    this->origen = origen;
}

// Establece el punto final del vector
void Vecalculator_vectores::setFin(puntos fin) {
    this->fin = fin;
}

// Establece el punto final en origen 0 del vector
void Vecalculator_vectores::setFin_cero(puntos fin_cero) {
    this->fin_cero = fin_cero;
}

// Establece el punto origen en 0 del vector
void Vecalculator_vectores::setOrigen_cero(puntos origen_cero) {
    this->origen_cero = origen_cero;
}

// retorna el punto origen del vector
puntos Vecalculator_vectores::getOrigen() {
    return this->origen;
}

// retorna el punto final del vector
puntos Vecalculator_vectores::getFin() {
    return this->fin;
}

// retorna el fin en origen 0
puntos Vecalculator_vectores::getFin_cero() {
    return this->fin_cero;
}

// retorna el origen en 0
puntos Vecalculator_vectores::getOrigen_cero() {
    return this->origen_cero;
}

// Inicializa un punto en 0
puntos::puntos() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->dimension = 0;
}

// Funcion para establecer los ejes y la dimension de un punto en el vector
puntos::puntos(float x, float y, float z, int dimension) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->dimension = dimension;
}

// Funcion para establecer el valor del eje x en un punto del vector
void puntos::setX(float x) {
    this->x = x;
}

// Funcion para establecer el valor del eje y en un punto del vector
void puntos::setY(float y) {
    this->y = y;
}

// Funcion para establecer el valor del eje z en un punto del vector
void puntos::setZ(float z) {
    this->z = z;
}

// Funcion para establecer la dimension del vector
void puntos::setDimension(int dim) {
    this->dimension = dim;
}

// Funcion para retornar el eje x
float puntos::getX() {
    return this->x;
}

// Funcion para retornar el eje de Y
float puntos::getY() {
    return this->y;
}

// Funcion para retornar el eje z
float puntos::getZ() {
    return this->z;
}

// Funcion para retornar la dimension del vector
int puntos::getDimension() {
    return this->dimension;
}




