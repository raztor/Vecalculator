#ifndef PROYECTO_TEL102_MENU_H
#define PROYECTO_TEL102_MENU_H
#include <iostream>
#include <cstring>
using namespace std;
void dim_menu(int &dim, char dim_verbose[3], bool &ciclo_menu, bool &ciclo_main){
    cout << "El vector es 2D o 3D?" << endl;
    cout << "1. 2D" << endl;
    cout << "2. 3D" << endl;
    cout << "\n3. Para Salir" << endl;
    cin >> dim;
    switch (dim) {
        case 1:
            std::strcpy(dim_verbose, "2D");
            break;
        case 2:
            std::strcpy(dim_verbose, "3D");
            break;
        case 3:
            ciclo_menu = false;
            ciclo_main = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}

void func_menu(int &operacion){
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
}

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
