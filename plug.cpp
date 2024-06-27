#include <iostream>
#include <fstream>
#include <iomanip>

#include "plug.hpp"

struct Fecha {
    int dia;
    int mes;
    int anio;
    int horas;
    int minutos;
    int segundos;
} fecha;

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

using namespace std;

// Definición de la función para limpiar la ventana de la consola
void limpiar_ventana()
{

#ifndef _WIN32
    system("clear");
#else 
    system("cls");
#endif

}

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

bool buscar_profesor(string &usuario, string &contrasena)
{
    ifstream lectura;
    bool encontrado = false;
    lectura.open("./Profesor.txt", ios::in);

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
        }
    }
    
    lectura.close();
    return encontrado;
}

bool buscar_alumno(string &usuario, string &contrasena)
{
    ifstream lectura;
    bool encontrado = false;
    lectura.open("./Alumnos.txt", ios::in);

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

    if (buscar_profesor(usuario, contrasena)) {
        ingresado = true;
    } else if (buscar_alumno(usuario, contrasena)) {
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
    cout << "Curso        : " << profesor.curso << endl;
    cout << "Nombres      : " << profesor.datos_personales.primer_nombre << " " << profesor.datos_personales.segundo_nombre << endl;
    cout << "Apellidos    : " << profesor.datos_personales.apellido_paterno << " " << profesor.datos_personales.apellido_materno << endl;
    cout << "Departamento : " << profesor.departamento << endl;

    cout << "\n[1] Tomar Asistencia" << endl;
    cout << "[2] Ingresar Notas" << endl;
    cout << "[3] Salir" << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc2;

    return opc2;
}


void fecha_hoy()
{
    time_t tiempo = time(NULL);
    struct tm *Fecha;
    Fecha = localtime(&tiempo);

    fecha.segundos =  Fecha->tm_sec;
    fecha.minutos =  Fecha->tm_min;
    fecha.horas =  Fecha->tm_hour;
    fecha.dia =  Fecha->tm_mday;
    fecha.mes =  Fecha->tm_mon + 1;
    fecha.anio =  Fecha->tm_year + 1900;

    cout << fecha.anio << "/" << fecha.mes << "/" << fecha.dia << "  " << fecha.horas << ":" << fecha.minutos;
}

void notas()
{
    fstream Notas;
    string codigo;
    float EP;
    float EC;
    float EF;
    float PF;
    Notas.open("./Notas.txt", ios::in | ios::out);

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
    Asistencia.open("./Asistencia.txt", ios::in | ios::out | ios::app);
    
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