// Language: c++
// Path: src\main.cpp
// a calculator for vectors in c++

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef struct vec{
    float eje_x;
    float eje_y;
    float eje_z;
};
vec NULL_VEC = {0,0,0}; /// Vector "vacio" para inicializar las variables de tipo vec

vec suma(vec a, vec b){
    vec c=NULL_VEC;
    c.eje_x = a.eje_x + b.eje_x;
    c.eje_y = a.eje_y + b.eje_y;
    c.eje_z = a.eje_z + b.eje_z;
    return c;
}

vec rest(vec a,vec b){
    vec c=NULL_VEC;
    c.eje_x=a.eje_x-b.eje_x;
    c.eje_y=a.eje_y-b.eje_y;
    c.eje_z=a.eje_z-b.eje_z;
    return c;
}

float p_punto(vec a, vec b, int dim){
    float c=0;
    if (dim==1){
        c = a.eje_x*b.eje_x + a.eje_y*b.eje_y;
    }else if (dim==2){
        c = a.eje_x*b.eje_x + a.eje_y*b.eje_y + a.eje_z*b.eje_z;
    }
    return c;
}

vec p_escalar(vec a, float escalar){
    vec c=NULL_VEC;
    c.eje_x=a.eje_x*escalar;
    c.eje_y=a.eje_y*escalar;
    c.eje_z=a.eje_z*escalar;
    return c;
}

float norm(vec a, int dim=1){
    float mag=0;
    if (dim == 1){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2)));
    }
    else if (dim == 2){
        mag = sqrt((pow(a.eje_x, 2) + pow(a.eje_y, 2) + pow(a.eje_z,2)));
    }
    cout << "La norma del vector es: " << mag << endl;
    return mag;
}

vec vec_unitario(vec a, int dim= 1){
    float mag = norm(a, dim);
    if(dim==1) {
        a.eje_x = mag * cos(a.eje_x);
        a.eje_y = mag * sin(a.eje_y);
        ////////// revisar else if de abajo //////////////
    }else if (dim==2){
        a.eje_x = mag * cos(a.eje_x) * cos(a.eje_y);
        a.eje_y = mag * cos(a.eje_x) * sin(a.eje_y);
        a.eje_z = mag * sin(a.eje_z);
    }
    return a;
}

float angle(vec a){
    vec result_cateto = vec_unitario(a, 1);
    float angulo = atan(result_cateto.eje_y/result_cateto.eje_x);
    return angulo;

} //tangente-1 (Cateto op/cateto ad)

vec p_cruz(vec a, vec b, int dim=2){

    vec pc = NULL_VEC;
    pc.eje_x = (a.eje_y*b.eje_z - a.eje_z*b.eje_y);
    pc.eje_y = (a.eje_z*b.eje_x - a.eje_x*b.eje_z);
    pc.eje_z = (a.eje_x*b.eje_y - a.eje_y*b.eje_x);

    return pc;
}

bool ciclo_main= true, ciclo_menu=true;
int main() {
    while(ciclo_main==true) {
            int operacion, dimension;
            vec vector1 = NULL_VEC, vector2 = NULL_VEC, result_vec = NULL_VEC;
            float result_float, escalar = 0;
            /// (verbose significa en palabras) ////
            char op_verbose[20], dim_verbose[3];

            ///////////////////////// Seleccion de dimension /////////////////////////
            cout << "El vector es 2D o 3D?" << endl;
            cout << "1. 2D" << endl;
            cout << "2. 3D" << endl;
            cout << "\n3. Para Salir" << endl;
            cin >> dimension;
            if (dimension == 1) {
                strcpy(dim_verbose, "2D");
            } else if (dimension == 2) {
                strcpy(dim_verbose, "3D");
            } else if (dimension == 3) {
                ciclo_menu = false;
                break;
            } else {
                cout << "Opcion no valida" << endl;
                break;
            }
        while(ciclo_menu){

            cout << "Dimension seleccionada: " << dim_verbose << "\n\n" << endl;

    /////////////////////////////// Seleccion de operacion ///////////////////////////////

            cout << "Que operacion desea realizar?\n" << endl;
            cout << "1. Suma" << endl;
            cout << "2. Resta" << endl;
            cout << "3. Vector Unitario" << endl;
            cout << "4. Angulo" << endl;
            cout << "5. Producto punto" << endl;
            cout << "6. Producto cruz" << endl;
            cout << "7. Modulo" << endl;
            cout << "8. PLACEHOLDER" << endl;
            cout << "9. Producto escalar" << endl;
            cout << "10. Volver a la seleccion de dimension" << endl;
            cin >> operacion;
            if (operacion == 1) {
                strcpy(op_verbose, "Suma");
            } else if (operacion == 2) {
                strcpy(op_verbose, "Resta");
            } else if (operacion == 3) {
                strcpy(op_verbose, "Vector Unitario");
            } else if (operacion == 4) {
                strcpy(op_verbose, "Angulo");
            } else if (operacion == 5) {
                strcpy(op_verbose, "Producto punto");
            } else if (operacion == 6) {
                strcpy(op_verbose, "Producto cruz");
            } else if (operacion == 7) {
                strcpy(op_verbose, "Modulo");
            } else if (operacion == 8) {
                strcpy(op_verbose, "PLACEHOLDER");
            } else if (operacion == 9) {
                strcpy(op_verbose, "Producto Escalar");
            } else if (operacion == 10) {
                cout << "Reiniciando...\n" << endl;
                break;
            } else {
                cout << "Operacion invalida" << endl;
                return 0;
            }
            cout << "Operacion seleccionada: \n" << op_verbose << endl;

            /////////////////////////////// Ingreso de vectores ///////////////////////////////
            /////////////////////////////// Ingreso de vectores ///////////////////////////////

            if (operacion != 3 && operacion != 7 && operacion != 9) {
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

            //////////////////////////// Iniciador de funciones ///////////////////////////////

            switch (operacion) {
                case 1:
                    result_vec = suma(vector1, vector2);
                    if (dimension == 1) {
                        cout << "El resultado es: " << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es: (" << result_vec.eje_x << "," << result_vec.eje_y << ","
                             << result_vec.eje_z << ")" << endl;
                    }
                    break;
                case 2:
                    result_vec = rest(vector1, vector2);
                    if (dimension == 1) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ","
                             << result_vec.eje_z << ")" << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 3:
                    cout << "Vector Unitario" << endl;
                    result_vec = vec_unitario(vector1);
                    if (dimension == 1) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << " i " << "+ " << result_vec.eje_y << " j " << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << " i "<< "+ " << result_vec.eje_y << " j " << "+ "
                             << result_vec.eje_z << " k " << ")" << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 4:
                    result_float = angle(vector1);
                    if(dimension == 1){
                        cout<<"El resultado es: "<< result_float << "°" <<endl;
                    }
                    else if (dimension == 2){
                        cout<<"Trabajando para ello... Por favor seleccione otra opcion"<<endl;
                    }

                    break;
                case 5:
                    /// Producto Punto
                    result_float = p_punto(vector1, vector2, dimension);
                    if (dimension == 1) {
                        cout << "El resultado es: " << result_float << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es: " << result_float << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 6:
                    cout << "Producto cruz" << endl;
                    result_vec = p_cruz(vector1, vector2, dimension);
                    if(dimension == 1){
                        cout<<"No se puede realizar esta operacion en 2 dimensiones, intente de nuevo."<<endl;
                    }
                    else if (dimension == 2) {
                        cout<<"El resultado es: ("<<result_vec.eje_x<<","<<result_vec.eje_y<<","<<result_vec.eje_z<<")"<<endl;
                    }
                    else{
                        cout<<"Ha ocurrido un error con las dimensiones"<<endl;
                    }
                    break;
                case 7:
                    //cout << "Modulo" << endl;
                    result_float = norm(vector1, dimension);
                    if (dimension == 1) {
                        cout << "El resultado es:" << result_float << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << result_float << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                    }
                    break;
                case 8:
                    cout << "PLACEHOLDER" << endl;
                    //////
                    break;
                case 9:
                    //cout << "Producto Escalar" << endl;
                    result_vec = p_escalar(vector1, escalar);
                    if (dimension == 1) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << endl;
                    } else if (dimension == 2) {
                        cout << "El resultado es:" << "(" << result_vec.eje_x << "," << result_vec.eje_y << ","
                             << result_vec.eje_z << ")" << endl;
                    } else {
                        cout << "Ha ocurrido un error con las dimensiones" << endl;
                        break;
                    }
                case 10:
                    cout << "Volver a la seleccion" << endl;
                    break;
                default:
                    cout << "Operacion no valida" << endl;
                    break;
            }
            cout << "\nDesea realizar otra operacion " << dim_verbose <<"? (1 = si, 2 = no (salir), 3 = Cambiar dimension)" << endl;
            int temp_continue;
            cin >> temp_continue;
            if (temp_continue == 1) {
                ciclo_menu = true;

            } else if (temp_continue == 2) {
                cout << "Gracias por usar el programa" << endl;
                return 0;
            } else if(temp_continue == 3){
                ciclo_menu = true;
                ciclo_main = true;
                break;
            } else {
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
    return 0;
}
