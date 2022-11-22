#ifndef PROYECTO_TEL102_DATA_TYPES_H
#define PROYECTO_TEL102_DATA_TYPES_H
// struct para los vectores, en caso de que sea 2D el valor eje_z se mantiene en 0
struct vec{
    float eje_x;
    float eje_y;
    float eje_z;
};
extern vec NULL_VEC; /// Vector "vacio" para inicializar las variables de tipo vec

#endif //PROYECTO_TEL102_DATA_TYPES_H
