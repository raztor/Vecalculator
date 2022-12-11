#ifndef VECALCULATOR_VEC_RESULT_H
#define VECALCULATOR_VEC_RESULT_H
#include <cmath>
#include "Vecalculator_vectores.h"
#include "vecalculator.h"

class vec_result {
private:
    puntos vec1_origen,vec2_origen,vec_fin_origen;
    Vecalculator_vectores vec_original;
    int vec_escalar,dimension,operacion;
    float angulo;
public:
    // Definiciones, mas detalles en el cpp
    vec_result();
    void setVec1(puntos vec1_origen);
    void setVec2(puntos vec2_origen);

    void setEscalar(int escalar);
    void setOperacion(int operacion);

    //void setVecFinal(vec vec_final);
    void setDimension(int dim);
    void calcular();
    puntos getVec1();
    puntos getVec2();
    puntos getVecFinal();
    Vecalculator_vectores getVecOriginal();
    int getEscalar();
    int getDimension();
    float getAngulo();

    void suma();
    void rest();
    void p_escalar();
    float p_punto();
    float norm();
    void componentes();
    void unitario();
    void angle();
    void p_cruz();
};
#endif //VECALCULATOR_VEC_RESULT_H
