#include <iostream>

#include "plug.hpp"

// Definición de la función para limpiar la ventana de la consola
void limpiar_ventana()
{

#ifndef _WIN32
    system("clear");
#else 
    system("cls");
#endif

}