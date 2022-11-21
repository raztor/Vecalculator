#ifndef PROYECTO_TEL102_MENU_H
#define PROYECTO_TEL102_MENU_H
#include <iostream>
#include <cstring>
using namespace std;
// Funcion para el menu de seleccion de dimension y para salir del programa
void dim_menu(int &dim, char dim_verbose[3], bool &ciclo_menu, bool &ciclo_main){
    cout << "El vector es 2D o 3D?" << endl;
    cout << "1. 2D" << endl;
    cout << "2. 3D" << endl;
    cout << "\n3. Para Salir" << endl;
    cin >> dim;
    switch (dim) {
        case 1:
            std::strcpy(dim_verbose, "2D");
            ciclo_menu = true;
            ciclo_main = true;
            break;
        case 2:
            std::strcpy(dim_verbose, "3D");
            ciclo_menu = true;
            ciclo_main = true;
            break;
        case 3:
            ciclo_menu = false;
            ciclo_main = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            ciclo_menu = false;
            ciclo_main = true;
            break;
    }
}
// Menu de seleccion de operacion
void func_menu(int &operacion, char op_verbose[20]){
    bool ready = false;
    while(!ready) {
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
        if (operacion>=1 && operacion <=10){
            ready = true;
        }
        else{
            cout << "Opcion no valida" << endl;
        }
    }
    // Switch encargado de asignar el nombre de la operacion a la variable op_verbose
    switch (operacion) {
        case 1:
            std::strcpy(op_verbose, "Suma");
            break;
        case 2:
            std::strcpy(op_verbose, "Resta");
            break;
        case 3:
            std::strcpy(op_verbose, "Vector Unitario");
            break;
        case 4:
            std::strcpy(op_verbose, "Angulo");
            break;
        case 5:
            std::strcpy(op_verbose, "Producto punto");
            break;
        case 6:
            std::strcpy(op_verbose, "Producto cruz");
            break;
        case 7:
            std::strcpy(op_verbose, "Modulo");
            break;
        case 8:
            std::strcpy(op_verbose, "Proximamente");
            break;
        case 9:
            std::strcpy(op_verbose, "Producto escalar");
            break;
        case 10:
            break;
        default:
            std::cout << "Ha ocurrido un error" << std::endl;
            exit(1);
    }
    // condicional para hacer cout de la operacion siempre y cuando sea una operacion y no otra opcion
    if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4
        || operacion == 5 || operacion == 6 || operacion == 7 || operacion == 9)
    {
        std::cout << "Operacion seleccionada: " << op_verbose << std::endl;
    }
}
// Menu para saber si el usuario desea continuar usando el programa
void fin_menu(bool &ciclo_main, bool &ciclo_menu, char dim_verbose[3]){
    cout << "\nDesea realizar otra operacion " << dim_verbose <<"? (1 = si, 2 = no (salir), 3 = Cambiar dimension)" << endl;
    int temp_continue;
    cin >> temp_continue;
    if (temp_continue == 1) {
        ciclo_menu = true;
    } else if (temp_continue == 2) {
        cout << "Gracias por usar el programa" << endl;
        ciclo_menu = false;
        ciclo_main = false;
    } else if(temp_continue == 3){
        ciclo_menu = false;
        ciclo_main = true;
    } else {
        cout << "Opcion no valida" << endl;
    }
}

#endif //PROYECTO_TEL102_MENU_H
