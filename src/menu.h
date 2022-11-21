#ifndef PROYECTO_TEL102_MENU_H
#define PROYECTO_TEL102_MENU_H
#include <cstring>
// Funcion para el menu de seleccion de dimension y para salir del programa
void dim_menu(int &dim, char dim_verbose[3], bool &ciclo_menu, bool &ciclo_main){
    std::cout << "El vector es 2D o 3D?" << std::endl;
    std::cout << "1. 2D" << std::endl;
    std::cout << "2. 3D" << std::endl;
    std::cout << "\n3. Para Salir" << std::endl;
    std::cin >> dim;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    //solo numero entero
    if(dim==1) {
        std::strcpy(dim_verbose, "2D");
        ciclo_menu = true;
        ciclo_main = true;
    }else if(dim==2){
        std::strcpy(dim_verbose, "3D");
        ciclo_menu = true;
        ciclo_main = true;
    }else if(dim==3) {
        ciclo_menu = false;
        ciclo_main = false;
    }else{
        std::cout << "Opcion no valida" << std::endl;
        ciclo_menu = false;
        ciclo_main = true;
    }
}
// Menu de seleccion de operacion
void func_menu(int &operacion, char op_verbose[20]){
    bool ready = false;
    while(!ready) {
        std::cout << "Que operacion desea realizar?\n" << std::endl;
        std::cout << "1. Suma" << std::endl;
        std::cout << "2. Resta" << std::endl;
        std::cout << "3. Vector Unitario" << std::endl;
        std::cout << "4. Angulo" << std::endl;
        std::cout << "5. Producto punto" << std::endl;
        std::cout << "6. Producto cruz" << std::endl;
        std::cout << "7. Modulo" << std::endl;
        std::cout << "8. PLACEHOLDER" << std::endl;
        std::cout << "9. Producto escalar" << std::endl;
        std::cout << "10. Volver a la seleccion de dimension" << std::endl;
        std::cin >> operacion;
        std::cin.clear();
        std::cin.ignore(1000, '\n'); //solo entero admitido
        if (operacion>=1 && operacion <=10){
            ready = true;
        }
        else{
            std::cout << "Opcion no valida" << std::endl;
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
    // condicional para hacer std::cout de la operacion siempre y cuando sea una operacion y no otra opcion
    if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4
        || operacion == 5 || operacion == 6 || operacion == 7 || operacion == 9)
    {
        std::cout << "Operacion seleccionada: " << op_verbose << std::endl;
    }
}
// Menu para saber si el usuario desea continuar usando el programa
void fin_menu(bool &ciclo_main, bool &ciclo_menu, char dim_verbose[3]){
    std::cout << "\nDesea realizar otra operacion " << dim_verbose <<"? (1 = si, 2 = no (salir), 3 = Cambiar dimension)" << std::endl;
    int temp_continue;
    std::cin >> temp_continue;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if (temp_continue == 1) {
        ciclo_menu = true;
    } else if (temp_continue == 2) {
        std::cout << "Gracias por usar el programa" << std::endl;
        ciclo_menu = false;
        ciclo_main = false;
    } else if(temp_continue == 3){
        ciclo_menu = false;
        ciclo_main = true;
    } else {
        std::cout << "Opcion no valida" << std::endl;
    }
}

#endif //PROYECTO_TEL102_MENU_H
