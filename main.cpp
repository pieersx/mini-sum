#include <iostream>
#include <fstream>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <chrono>
#include <ctime>

// #include "plug.hpp"

using namespace std;

void limpiar_ventana()
{

#ifndef _WIN32
    system("clear");
#else 
    system("cls");
#endif

}

struct Fecha {
    int dia;
    int mes;
    int anio;
    int hora;
    int minutos;
    int segundos;
};

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
        cin.ignore();
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

void fecha_hoy()
{
    auto ahora = chrono::system_clock::now();
    time_t tiempo_actual = chrono::system_clock::to_time_t(ahora);
    tm *local_time = localtime(&tiempo_actual);
    cout << put_time(local_time, "%d/%m/%Y %H:%M") << endl;
}

void notas()
{
    fstream Notas;
    string codigo;
    float EP;
    float EC;
    float EF;
    float PF;
    Notas.open(".//Notas.txt", ios::in | ios::out);

    limpiar_ventana();
    Notas >> codigo;
    while (Notas.good() && !Notas.eof()) {        
        cout << "\t\t Ingreso de Notas \t";
        fecha_hoy();
        cout << "****************************************************************" << endl;        
        cout << "Alumno: " << codigo << endl;
        cout << "\nIngrese la nota del examen parcial: ";
        cin >> EP;
        cout << "Ingrese la nota del evaluación continuas: ";
        cin >> EC;
        cout << "Ingrese la nota del examen final : ";
        cin >> EF;

        PF = (0.3*EP) + (0.4*EC) + (0.3*EF);
        cout << fixed << setprecision(3);
        cout << "\nSu Promedio Final es: " << PF << endl;
        cin.ignore();
        cin.get();
        limpiar_ventana();

        Notas >> codigo;
    }
    
    
}

void asistencia()
{
    fstream Asistencia;
    string name1;
    string name2;
    string apellido_paterno;
    string apellido_materno;
    char tmp;
    Asistencia.open(".//Asistencia.txt", ios::in | ios::out);
    
    limpiar_ventana();
    cout << "\t\t Asistencia \t";
    fecha_hoy(); 
    cout << "\n****************************************************************" << endl;
    cout << " Código \t     Apellidos y Nombres       \t        A|T|F" << endl;  

    Asistencia >> alumno.codigo;
    Asistencia >> alumno.datos_personales.primer_nombre;
    Asistencia >> alumno.datos_personales.segundo_nombre;
    Asistencia >> alumno.datos_personales.apellido_paterno;
    Asistencia >> alumno.datos_personales.apellido_materno;

    while (!Asistencia.eof() && Asistencia.good()) {
        cout << left << setw(10) << alumno.codigo << "\t" 
             << setw(15) << alumno.datos_personales.apellido_paterno + " " +  alumno.datos_personales.apellido_materno + ", " 
             << setw(20) << alumno.datos_personales.primer_nombre + " " + alumno.datos_personales.segundo_nombre 
             << "\t";
             cin >> tmp;

        Asistencia >> alumno.codigo;
        Asistencia >> alumno.datos_personales.primer_nombre;
        Asistencia >> alumno.datos_personales.segundo_nombre;
        Asistencia >> alumno.datos_personales.apellido_paterno;
        Asistencia >> alumno.datos_personales.apellido_materno;

        if (Asistencia.eof()) {
            cout << "\nAsistencia completada" << endl;
            cin.get();
            cin.get();
        }
    }    
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
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    int opc2;
                    do {
                        opc2 = submenu2();

                        switch (opc2) {
                            case 1: {
                                asistencia();
                            } break;
                            case 2: {
                                notas();
                            } break;
                        }
                    } while (opc2 != 3);
                }
            } break;

            default: {
                cout << "\n\t\tError: Opción no válida" << endl; 
                cout << "\nPresione enter para volver"; 
                cin.ignore();
                cin.get();
            }
        }
    } while (opc != 4);
    
    return 0;
}