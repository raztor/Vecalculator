#ifndef VECALCULATOR_VECALCULATOR_VECTORES_H
#define VECALCULATOR_VECALCULATOR_VECTORES_H


class puntos{
private:
    float x;
    float y;
    float z;
    int dimension;

public:
    puntos();
    puntos(float x, float y, float z, int dimension);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setDimension(int dim);
    float getX();
    float getY();
    float getZ();
    int getDimension();

};


class Vecalculator_vectores {
private:
    puntos origen,fin,fin_cero,origen_cero;


protected:

public:
    Vecalculator_vectores();
    Vecalculator_vectores(puntos origen, puntos fin, puntos fin_cero);
    void setOrigen(puntos origen);
    void setFin(puntos fin);
    void setFin_cero(puntos fin_cero);
    void setOrigen_cero(puntos origen_cero);
    puntos getOrigen();
    puntos getFin();
    puntos getFin_cero();
    puntos getOrigen_cero();

    puntos INVALID = {9999999999.999999,999999999999.999999999,99999999999.9999999,9999999};
    float INVALID_ESC=214212312312312432441241243423.0;


};


#endif //VECALCULATOR_VECALCULATOR_VECTORES_H
