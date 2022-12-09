#include "Vecalculator_vectores.h"

Vecalculator_vectores::Vecalculator_vectores() {
    this->origen = puntos(0,0,0,0);
    this->fin = puntos(0,0,0,0);
    this->fin_cero = puntos(0,0,0,0);
    this->origen_cero = puntos(0,0,0,0);
}
Vecalculator_vectores::Vecalculator_vectores(puntos origen, puntos fin, puntos fin_cero) {
    this->origen = origen;
    this->fin = fin;
    this->fin_cero = fin_cero;
    this->origen_cero = puntos(0,0,0,0);
}

void Vecalculator_vectores::setOrigen(puntos origen) {
    this->origen = origen;
}
void Vecalculator_vectores::setFin(puntos fin) {
    this->fin = fin;
}
void Vecalculator_vectores::setFin_cero(puntos fin_cero) {
    this->fin_cero = fin_cero;
}
void Vecalculator_vectores::setOrigen_cero(puntos origen_cero) {
    this->origen_cero = origen_cero;
}
puntos Vecalculator_vectores::getOrigen() {
    return this->origen;
}
puntos Vecalculator_vectores::getFin() {
    return this->fin;
}
puntos Vecalculator_vectores::getFin_cero() {
    return this->fin_cero;
}
puntos Vecalculator_vectores::getOrigen_cero() {
    return this->origen_cero;
}


puntos::puntos() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->dimension = 0;
}
puntos::puntos(float x, float y, float z, int dimension) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->dimension = dimension;
}
void puntos::setX(float x) {
    this->x = x;
}
void puntos::setY(float y) {
    this->y = y;
}
void puntos::setZ(float z) {
    this->z = z;
}
void puntos::setDimension(int dim) {
    this->dimension = dim;
}
float puntos::getX() {
    return this->x;
}
float puntos::getY() {
    return this->y;
}
float puntos::getZ() {
    return this->z;
}
int puntos::getDimension() {
    return this->dimension;
}




