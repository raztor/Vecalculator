//
// Created by benjamin on 04-12-22.
//

#ifndef VECALCULATOR_VEC_RESULT_H
#define VECALCULATOR_VEC_RESULT_H
#include "./vectores.h"
#include <cmath>
class vec_result {
private:
    vec vec_orig=NULL_VEC,vec_oper=NULL_VEC,vec_total=NULL_VEC;
    int vec_escalar,dimension,operacion;
public:
    vec_result();
    void setVec1(vec vec1);
    void setVec2(vec vec2);
    void setEscalar(int escalar);
    void setOperacion(int operacion);
    //void setVecFinal(vec vec_final);
    void setDimension(int dim);
    void calcular();
    vec getVec1();
    vec getVec2();
    vec getVecFinal();
    int getEscalar();
    int getDimension();


    void suma();
    void rest();
    void p_escalar();
    float p_punto();
    float norm();
    void componentes();
    void unitario();
    float angle();
    void p_cruz();
};

#endif //VECALCULATOR_VEC_RESULT_H
