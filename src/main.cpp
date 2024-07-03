#include <iostream>
#include <unistd.h>

#include "plug.hpp"

using namespace std;

int main(void)
{
    int opc;
    
    portada();
    sleep(2);
    
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
                    iniciar_sesion_estudiante(ingresado, intento);
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    int opc1;
                    do {
                        limpiar_ventana();
                        opc1 = submenu1();
                        switch (opc1) {
                            case 1: {
                                limpiar_ventana();
                                mostrar_asistencia();
                                break;
                            }
                            case 2: {
                                limpiar_ventana();
                                mostrar_notas();
                                break;
                            }                 
                            case 3: break;
                            default: {
                                cout << "\n\tOpción no válida" << endl; 
                                cout << "Presione enter para volver selecionar..."; 

                                cin.ignore();
                                cin.get();
                            }
                        }
                    } while (opc1 != 3);
                }
            } break;

            case 2: {
                int intento = 3;
                bool ingresado = false;
                cin.ignore();

                do {
                    limpiar_ventana();
                    iniciar_sesion_profesor(ingresado, intento);
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    int opc2;
                    do {
                        limpiar_ventana();
                        opc2 = submenu2();
                        switch (opc2) {
                            case 1: {
                                limpiar_ventana();
                                registrar_asistencia(); 
                                break;
                            }
                            case 2: {
                                limpiar_ventana();
                                registrar_notas();
                                break;
                            }
                            case 3: break;
                            default: {
                                cout << "\n\tOpción no válida" << endl; 
                                cout << "Presione enter para volver selecionar..."; 

                                cin.ignore();
                                cin.get();
                            }
                        }
                    } while (opc2 != 3);
                }
            } break;

            case 3: {
                int opc3;
                do {
                    limpiar_ventana();
                    opc3 = submenu3();
                    
                    switch (opc3) {
                        case 1: {
                            limpiar_ventana();
                            crear_alumno();
                            break;
                        }
                        case 2: {
                            limpiar_ventana();
                            leer_alumno();
                            break;
                        }
                        case 3: {
                            limpiar_ventana();
                            actualizar_alumno();
                            break;
                        }
                        case 4: {
                            limpiar_ventana();
                            eliminar_alumno();
                        }
                        case 5: break;
                        default: {
                            cout << "\n\tOpción no válida" << endl; 
                            cout << "Presione enter para volver selecionar..."; 
                            cin.ignore();
                            cin.get();
                        }
                    }
                } while (opc3 != 5);
            }

            case 4: break;

            default: {
                cout << "\n\tOpción no válida" << endl; 
                cout << "Presione enter para volver selecionar..."; 
                cin.ignore();
                cin.get();
            }
        }
    } while (opc != 4);
    
    return 0;
}