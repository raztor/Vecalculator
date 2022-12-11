#ifndef PROYECTO_TEL102_MENU_H
#define PROYECTO_TEL102_MENU_H
#include <cstring>
#include <iostream>

// Funcion para el menu de seleccion de dimension y para salir del programa
void dim_menu(int &dim, char dim_verbose[3], bool &ciclo_menu, bool &ciclo_main);

// Menu de seleccion de operacion
void func_menu(int &operacion, char op_verbose[20]);

// Menu para saber si el usuario desea continuar usando el programa
void fin_menu(bool &ciclo_main, bool &ciclo_menu, char dim_verbose[3]);


#endif //PROYECTO_TEL102_MENU_H
