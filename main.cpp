#include <iostream>
#include <fstream>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <ctime>
#include <chrono>

#include "plug.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int opc;    
    do {        
        limpiar_ventana();    
        opc = menu();

        switch (opc) {
            case 1: {
                int intento = 3;
                bool ingresado = false;
                cin.ignore();
                do {
                    limpiar_ventana();
                    iniciar_sesion(ingresado, intento);
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    limpiar_ventana();
                    cin.get();
                }
            } break;

            case 2: {
                int intento = 3;
                bool ingresado = false;
                cin.ignore();
                do {
                    limpiar_ventana();
                    iniciar_sesion(ingresado, intento);
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    int opc2;
                    do {
                        opc2 = submenu2();
                        switch (opc2) {
                            case 1: asistencia(); break;
                            case 2: notas(); break;
                        }
                    } while (opc2 != 3);
                }
            } break;

            default: {
                cin.ignore();
                cin.get();
                cout << "\n\t\tError: Opción no válida" << endl; 
                cout << "\nPresione enter para volver"; 
                cin.ignore();
                cin.get();
            }
        }
    } while (opc != 4);
    
    return 0;
}