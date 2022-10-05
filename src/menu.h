#ifndef PROYECTO_TEL102_MENU_H
#define PROYECTO_TEL102_MENU_H
#include <iostream>
#include <cstring>
using namespace std;
void dim_menu(int num_int, char dim_verbose[3], bool ciclo_menu){
    cout << "El vector es 2D o 3D?" << endl;
    cout << "1. 2D" << endl;
    cout << "2. 3D" << endl;
    cout << "\n3. Para Salir" << endl;
    cin >> num_int;
    switch (num_int) {
        case 1:
            std::strcpy(dim_verbose, "2D");
            break;
        case 2:
            std::strcpy(dim_verbose, "3D");
            break;
        case 3:
            ciclo_menu = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }


}

#endif //PROYECTO_TEL102_MENU_H
