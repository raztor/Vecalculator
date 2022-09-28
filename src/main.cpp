// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct vec{
    double eje_x;
    double eje_y;
    double eje_z;
};

vec suma(vec a, vec b){
    vec c;
    c.eje_x = a.eje_x + b.eje_x;
    c.eje_y = a.eje_y + b.eje_y;
    c.eje_z = a.eje_z + b.eje_z;
    return c;
}

vec rest(vec a,vec b){
    vec c;
    c.eje_x=a.eje_x-b.eje_x;
    c.eje_y=a.eje_y-b.eje_y;
    c.eje_z=a.eje_z-b.eje_z;
    return c;
}
//////////// Revisar el codigo de la multiplicacion y division /////////////////////

vec mult(vec a, vec b){
    vec c;
    c.eje_x=a.eje_x*b.eje_x;
    c.eje_y=a.eje_y*b.eje_y;
    c.eje_z=a.eje_z*b.eje_z;
    return c;
}
vec div(vec a, vec b){
    vec c;
    c.eje_x=a.eje_x/b.eje_x;
    c.eje_y=a.eje_y/b.eje_y;
    c.eje_z=a.eje_z/b.eje_z;
    return c;
}

///////////////////////////////////////////

//float dot();
//float cross();
float angle(); //tangente-1 (Cateto op/cateto ad)
//float unit();

double norm(vec a, int dim){
    double mag=0;
    if (dim == 1){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2)));
    }
    else if (dim == 2){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2) + pow(a.eje_z,2)));
    }
    return mag;
}

double catetos(){

}

vec catetos(vec a, int dim){
    //solo 2 dimensiones por ahora
    eje_x.a = norm(a) * cos(a);
    eje_y.a = norm(a) * sin(a);

    return a; 
}

float angle(vec a){

    float angulo = atan(catetos(eje_y.a)/catetos(eje_x.a));

    return angulo;
    
}; //tangente-1 (Cateto op/cateto ad)


int main() {
    int operacion, dimension;
    vec vector1, vector2, vector_result;
    double result_norm;
    /// (verbose significa en palabras) ////
    char op_verbose[15], dim_verbose[3];

    //hola

    ///////////////////////// Seleccion de dimension /////////////////////////
    cout << "El vector es 2D o 3D?" << endl;
    cout << "1. 2D" << endl;
    cout << "2. 3D" << endl;
    cin >> dimension;
    if (dimension == 1) {
        strcpy(dim_verbose, "2D");
    } else if (dimension == 2) {
        strcpy(dim_verbose, "3D");
    } else {
        cout << "Dimension invalida" << endl;
        return 0;
    }
    cout << "Dimension seleccionada: " << dim_verbose << endl;

/////////////////////////////// Seleccion de operacion ///////////////////////////////

    cout << "Que operacion desea realizar?" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Producto punto" << endl;
    cout << "6. Producto cruz" << endl;
    cout << "7. Modulo" << endl;
    cout << "8. Angulo" << endl;
    cout << "9. Salir" << endl;
    cin >> operacion;
    if (operacion == 1) {
        strcpy(op_verbose, "Suma");
    } else if (operacion == 2) {
        strcpy(op_verbose, "Resta");
    } else if (operacion == 3) {
        strcpy(op_verbose, "Multiplicacion");
    } else if (operacion == 4) {
        strcpy(op_verbose, "Division");
    } else if (operacion == 5) {
        strcpy(op_verbose, "Producto punto");
    } else if (operacion == 6) {
        strcpy(op_verbose, "Producto cruz");
    } else if (operacion == 7) {
        strcpy(op_verbose, "Modulo");
    } else if (operacion == 8) {
        strcpy(op_verbose, "Angulo");
    } else if (operacion == 9) {
        cout << "Saliendo..." << endl;
        return 0;
    } else {
        cout << "Operacion invalida" << endl;
        return 0;
    }
    if (operacion != 7) {
        cout << "Operacion seleccionada: " << op_verbose << endl;
        if (dimension == 1) {
            cout << "Ingrese el vector 1 en formato x y" << endl;
            cin >> vector1.eje_x >> vector1.eje_y;
            vector1.eje_z = 0;
        } else if (dimension == 2) {
            cout << "Ingrese el vector 1 en formato x y z" << endl;
            cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
        }

        if (dimension == 1) {
            cout << "Ingrese el vector 2 en formato x y" << endl;
            cin >> vector2.eje_x >> vector2.eje_y;
            vector2.eje_z = 0;
        } else if (dimension == 2) {
            cout << "Ingrese el vector 2 en formato x y z" << endl;
            cin >> vector2.eje_x >> vector2.eje_y >> vector2.eje_z;
        }
    } else if (operacion == 7) {
        cout << "Operacion seleccionada: " << op_verbose << endl;
        if (dimension == 1) {
            cout << "Ingrese el vector en formato x y" << endl;
            cin >> vector1.eje_x >> vector1.eje_y;
            vector1.eje_z = 0;
        } else if (dimension == 2) {
            cout << "Ingrese el vector en formato x y z" << endl;
            cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
        }
    }

    //////////////////////////// Iniciador de funciones ///////////////////////////////

    switch (operacion) {
        case 1:
            cout << "Suma" << endl;
            vector_result = suma(vector1, vector2);
            if(dimension == 1){
                cout << "El resultado es: " << vector_result.eje_x << " " << vector_result.eje_y << endl;
            } else if(dimension == 2){
                cout << "El resultado es: " << vector_result.eje_x << " " << vector_result.eje_y << " "
                << vector_result.eje_z << endl;
            }
            break;
        case 2:
            cout << "Resta" << endl;
            vector_result = rest(vector1, vector2);
            if (dimension == 1) {
                cout << "El resultado es:" << "(" << vector_result.eje_x << "," << vector_result.eje_y << ")" << endl;
            } else if (dimension == 2) {
                cout << "El resultado es:" << "(" << vector_result.eje_x << "," << vector_result.eje_y << ","
                     << vector_result.eje_z << ")" << endl;
            }
            break;
        case 3:
            cout << "Multiplicacion" << endl;
            vector_result = mult(vector1, vector2);
            if (dimension == 1) {
                cout << "El resultado es:" << "(" << vector_result.eje_x << "," << vector_result.eje_y << ")" << endl;
            } else if (dimension == 2) {
                cout << "El resultado es:" << "(" << vector_result.eje_x << "," << vector_result.eje_y << ","
                     << vector_result.eje_z << ")" << endl;
            }
            break;
        case 4:
            cout << "Division" << endl;
            vector_result = div(vector1, vector2);
            if (dimension == 1) {
                cout << "El resultado es:" << "(" << vector_result.eje_x << "," << vector_result.eje_y << ")" << endl;
            } else if (dimension == 2) {
                cout << "El resultado es:" << "(" << vector_result.eje_x << "," << vector_result.eje_y << ","
                     << vector_result.eje_z << ")" << endl;
            }
            break;
        case 5:
            cout << "Producto punto" << endl;
            ///////
            break;
        case 6:
            cout << "Producto cruz" << endl;
            ///////
            break;
        case 7:
            cout << "Modulo" << endl;
            result_norm = norm(vector1, dimension);
            if (dimension == 1) {
                cout << "El resultado es:" << result_norm << endl;
            } else if (dimension == 2) {
                cout << "El resultado es:" << result_norm << endl;
            }
                break;
        case 8:
            cout << "Angulo" << endl;
            break;
        case 9:
            cout << "Salir" << endl;
            break;
        default:
            cout << "Operacion no valida" << endl;
            break;

    }
    return 0;
}
