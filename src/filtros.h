#ifndef PROYECTO_TEL102_FILTROS_H
#define PROYECTO_TEL102_FILTROS_H
#include "data_types.h"
void filtro_dim_gen(int &dimension, vec result_vec){

    if (dimension == 1) {
        cout << "El resultado es: " << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
    } else if (dimension == 2) {
        cout << "El resultado es: " << "(" << result_vec.eje_x << "," << result_vec.eje_y << ","
             << result_vec.eje_z << ")" << endl;
    } else {
        cout << "Ha ocurrido un error con las dimensiones" << endl;
    }
}

void filtro_dim_componente(int &dimension, vec result_vec){

    if (dimension == 1) {
        cout << "El resultado es: " << "(" << result_vec.eje_x << " i " << "+ " << result_vec.eje_y << " j " << ")" << endl;
    } else if (dimension == 2) {
        cout << "El resultado es: " << "(" << result_vec.eje_x << " i "<< "+ " << result_vec.eje_y << " j " << "+ "
             << result_vec.eje_z << " k " << ")" << endl;
    } else {
        cout << "Ha ocurrido un error con las dimensiones" << endl;
    }
}

void filtro_input(int &operacion, int &dimension, vec &vector1, vec &vector2, float &escalar) {
    if (operacion != 3 && operacion != 7 && operacion != 9 && operacion != 8) {
        if (dimension == 1) {
            cout << "Ingrese el vector 1 en formato x y" << endl;
            cin >> vector1.eje_x >> vector1.eje_y;
            vector1.eje_z = 0;
            cout << "Ingrese el vector 2 en formato x y" << endl;
            cin >> vector2.eje_x >> vector2.eje_y;
            vector2.eje_z = 0;

        } else if (dimension == 2) {
            cout << "Ingrese el vector 1 en formato x y z" << endl;
            cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
            cout << "Ingrese el vector 2 en formato x y z" << endl;
            cin >> vector2.eje_x >> vector2.eje_y >> vector2.eje_z;
        }

    } else if (operacion == 3 || operacion == 7) {
        if (dimension == 1) {
            cout << "Ingrese el vector en formato x y" << endl;
            cin >> vector1.eje_x >> vector1.eje_y;
            vector1.eje_z = 0;
        } else if (dimension == 2) {
            cout << "Ingrese el vector en formato x y z" << endl;
            cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
        }
    } else if (operacion == 9) {
        if (dimension == 1) {
            cout << "Ingrese el vector en formato x y" << endl;
            cin >> vector1.eje_x >> vector1.eje_y;
            vector1.eje_z = 0;
            cout << "Ingrese el escalar" << endl;
            cin >> escalar;
        } else if (dimension == 2) {
            cout << "Ingrese el vector en formato x y z" << endl;
            cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
            cout << "Ingrese el escalar" << endl;
            cin >> escalar;
        }
    }
}

#endif //PROYECTO_TEL102_FILTROS_H
