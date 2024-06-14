#include <iostream>
#include <fstream>
#include <string.h>
#include <locale.h>

#include "plug.hpp"

using namespace std;

struct Profesor {
    long codigo;
    string usuario;
    string contrasena;
    string nombre1;
    string nombre2;
    string apellido_paterno;
    string apellido_materno;
    string departamento;
    string curso;
} profesor;

struct Alumno {
    long codigo;
    string usuario;
    string contrasena;
    string nombre1;
    string nombre2;
    string apellido_paterno;
    string apellido_materno;
    string carrera;    
} profesor;

int menu()
{
    int opc;
    cout << "*******************************************************" << endl;
    cout << "\t\t Bienvenidos al Menú" << endl;
    cout << "\n[1] Alumno" << endl;
    cout << "[2] Profesor" << endl;
    cout << "[3] Registrar" << endl;
    cout << "[4] Salir" << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc;

    return opc;
}

void agregar_espacio(string &cambio)
{
    int i = 0;
    while (cambio[i] != '\0') {
        if (cambio[i] == '_') {
            cambio[i] = ' ';
        }
        i++;
    }
}

bool buscar_usuario(string &usuario, string &contrasena)
{
    ifstream lectura;
    bool encontrado = false;
    lectura.open(".//Profesor.txt", ios::in);

    while (lectura.good() && !lectura.eof() && !encontrado) {
        lectura >> profesor.usuario;
        lectura >> profesor.contrasena;
        lectura >> profesor.nombre1;
        lectura >> profesor.nombre2;
        lectura >> profesor.apellido_paterno;
        lectura >> profesor.apellido_materno;
        lectura >> profesor.departamento;
        lectura >> profesor.curso;

        if (usuario == profesor.usuario && contrasena == profesor.contrasena) {
            encontrado = true;
            agregar_espacio(profesor.departamento);
            agregar_espacio(profesor.curso);
            break;
        }
    }
    return encontrado;
}

void iniciar_sesion(bool &ingresado, int &intento)
{
    string usuario;
    string contrasena;

    cout << "**********************************************" << endl;
    cout << "\t\tIniciar Sesión " << endl;
    cout << "\n\tUsuario: ";
    getline(cin, usuario);
    cout << "\tContraseña: ";
    getline(cin, contrasena);

    if (buscar_usuario(usuario, contrasena)) {
        ingresado = true;
    } else {
        intento--;
        cout << "\nUsuario y/o clave son incorrectos" << endl;
        cout << "\nLe queda " << intento << " intentos";
        cin.get();
    }
}

int submenu2()
{
    int opc2;
    cout << "\n[1] Tomar Asistencia" << endl;
    cout << "[2] Ingresar Notas" << endl;
    cout << "[3] Salir" << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc2;

    return opc2;
}

void asistencia()
{
    ifstream Asistencia;

}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

    int opc;    
    do {        
        limpiar_ventana();    
        opc = menu();

        switch (opc) {
            case 1: {
                limpiar_ventana();

                cout << "Ingrese su codigo: ";
            } break;

            case 2: {
                string usuario;
                string contrasena;
                
                int intento = 3;
                bool ingresado = false;
                cin.ignore();
                
                do {
                    limpiar_ventana();
                    iniciar_sesion(ingresado, intento);
                } while (intento != 0 && ingresado == false);

                if (ingresado) {
                    limpiar_ventana();
                    cout << "*******************************************************" << endl;
                    cout << "\t\t Bienvenido al sistema \n" << endl;
                    cout << "Curso     : " << profesor.curso << endl;
                    cout << "Nombres   : " << profesor.nombre1 << " " << profesor.nombre2 << endl;
                    cout << "Apellidos : " << profesor.apellido_paterno << " " << profesor.apellido_materno << endl;
                    
                    int opc2;
                    do {
                        opc2 = submenu2();
                        switch (opc2) {
                            case 1: {
                                
                            } break;
                        }
                    } while (opc2 != 3);
                }

                cin.ignore();
                cin.get();
            } break;
        }
    } while (opc != 4);
    
    return 0;
}