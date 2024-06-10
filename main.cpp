#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

#define USER_PROFESOR "Robert"
#define CONTRASENA "Java0910"

typedef struct {
    string curso;
    string nombre;
    string apellido;
    string usuario;
    string contrasena;
} Profesor;

void limpiar_ventana()
{

#ifndef _WIN32
    system("clear");
#else 
    system("cls");
#endif

}

int main()
{
    setlocale(LC_CTYPE, "Spanish");

    int opc;
    Profesor profesor;
    int intento = 3;
    char tmp;

    do {        
        limpiar_ventana();

        cout << "\n[1] Alumno" << endl;
        cout << "[2] Profesor" << endl;
        cout << "[3] Registrar" << endl;
        cout << "[4] Salir" << endl;
        cout << "\n\tIngrese una opción -> ";
        cin >> opc;
        
        switch (opc) {
            case 1: {
                limpiar_ventana();

                cout << "Ingrese su codigo: ";
            } break;

            case 2: {
                bool ingresado = false;
                cin.ignore();
                do {
                    limpiar_ventana();

                    cout << "*************************************************" << endl;
                    cout << "\t\tIniciar Sesión " << endl;
                    cout << "\n\tUsuario: ";
                    getline(cin, profesor.usuario);
                    cout << "\tContraseña: ";
                    getline(cin, profesor.contrasena);
                    
                    if (strcmp(profesor.contrasena.c_str(), CONTRASENA) == 0 && strcmp(profesor.usuario.c_str(), USER_PROFESOR) == 0) {
                        ingresado = true;
                    } else {
                        intento--;
                        cout << "\nUsuario y/o clave son incorrectos" << endl;
                        cout << "\nLe queda " << intento << " intentos" << endl;
                        getchar();
                    }
                } while (intento != 0 && ingresado == false);

                if (ingresado) {
                    limpiar_ventana();
                    cout << "\n\t\tBienvenido al sistema" << endl;             
                }

                cin.ignore();
                cin.get();
            } break;
        }
    } while (opc != 4);
    
    return 0;
}