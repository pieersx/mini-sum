#include <iostream>
#include <fstream>
#include <cstring>
#include <locale.h>

#include "plug.hpp"

using namespace std;

struct Usuario {
    string usuario;
    string contrasena;
};

struct Persona {
    string primer_nombre;
    string segundo_nombre;
    string apellido_paterno;
    string apellido_materno;
};

struct Profesor {
    long codigo;
    Usuario credenciales;
    Persona datos_personales;
    string departamento;
    string curso;
} profesor;

struct Alumno {
    long codigo;
    Usuario credenciales;
    Persona datos_personales;
    string carrera;
    string curso;
} alumno;

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
        lectura >> profesor.credenciales.usuario;
        lectura >> profesor.credenciales.contrasena;
        lectura >> profesor.datos_personales.primer_nombre;
        lectura >> profesor.datos_personales.segundo_nombre;
        lectura >> profesor.datos_personales.apellido_paterno;
        lectura >> profesor.datos_personales.apellido_materno;
        lectura >> profesor.departamento;
        lectura >> profesor.curso;

        if (usuario == profesor.credenciales.usuario && contrasena == profesor.credenciales.contrasena) {
            encontrado = true;
            agregar_espacio(profesor.departamento);
            agregar_espacio(profesor.curso);
            break;
        }
    }
    
    lectura.close();
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

    limpiar_ventana();
    cout << "*******************************************************" << endl;
    cout << "\t\t Bienvenido al sistema \n" << endl;
    cout << "Curso     : " << profesor.curso << endl;
    cout << "Nombres   : " << profesor.datos_personales.primer_nombre << " " << profesor.datos_personales.segundo_nombre << endl;
    cout << "Apellidos : " << profesor.datos_personales.apellido_paterno << " " << profesor.datos_personales.apellido_materno << endl;

    cout << "\n[1] Tomar Asistencia" << endl;
    cout << "[2] Ingresar Notas" << endl;
    cout << "[3] Salir" << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc2;

    return opc2;
}

void asistencia()
{
    fstream Asistencia;
    // long codigo;
    string name1;
    string name2;
    string apellido_paterno;
    string apellido_materno;
    char tmp;
    Asistencia.open(".//Asistencia.txt", ios::in | ios::out);
    
    limpiar_ventana();
    cout << "\t\t Asistencia" << endl;
    cout << "*******************************************************" << endl;
    cout << " Código \t     Nombres y Apellidos \t A|T|F" << endl;
    while (!Asistencia.eof() && Asistencia.good()) {
        Asistencia >> alumno.codigo;
        Asistencia >> alumno.datos_personales.primer_nombre;
        Asistencia >> alumno.datos_personales.segundo_nombre;
        Asistencia >> alumno.datos_personales.apellido_paterno;
        Asistencia >> alumno.datos_personales.apellido_materno;
        Asistencia >> alumno.carrera;
        Asistencia >> alumno.curso;

        cout << alumno.codigo << "\t" << alumno.datos_personales.primer_nombre << " " << alumno.datos_personales.segundo_nombre << " " << alumno.datos_personales.apellido_paterno << " " << alumno.datos_personales.segundo_nombre << "\t ";
        cin >> tmp;
    }
    cin.get();
    cin.get();
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
                    int opc2;
                    do {
                        opc2 = submenu2();

                        switch (opc2) {
                            case 1: {
                                asistencia();
                            } break;

                            case 2: {
                            
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