#ifndef PROYECTO_TEL102_FILTROS_H
#define PROYECTO_TEL102_FILTROS_H
#include "vectores.h"
/* De momento este filtro solo sirve para la funcion de vector unitario pero planeamos reutilizarla.
    Separa las dimensiones y aplica i,j y z a los cout */
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
// Filtro para separar 2D y 3D en el cout generico (x,y,z)
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
// Filtros de los input para poder distinguir entre vector 2D, 3D y escalar
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
            if (operacion != 4){
                cout << "Ingrese el vector 1 en formato x y z" << endl;
                cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                cout << "Ingrese el vector 2 en formato x y z" << endl;
                cin >> vector2.eje_x >> vector2.eje_y >> vector2.eje_z;
            }
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
