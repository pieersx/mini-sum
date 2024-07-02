#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <unistd.h>

#include "plug.hpp"

#define PATH_ALUMNO "./Alumnos.txt"
#define PATH_PROFESOR "./Profesor.txt"
#define PATH_ASISTENCIA "./Asistencia.txt"
#define PATH_NOTAS "./Notas.txt"

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

struct Estudiante {
    long codigo;
    Usuario credenciales;
    Persona datos_personales;
    string carrera;
    string curso;
} estudiante;

using namespace std;

void limpiar_ventana()
{

#ifndef _WIN32
    system("clear");
#else 
    system("cls");
#endif

}

void portada()
{
    cout << R"(
                                                          #####                                                                                                                                        
                                                                #####                                                                                                                                  
                                       ######                       ####                                                                                                                               
                              ##################                       #####                                                                                                                           
                          #####          ####                             #####                                                                                                                        
                       ###               ##                                  ####                         ##     ###                                                                                   
                    ###                 #                                      ####                   #########  ###             ##                                                                    
                  ##                   ##       ##                               ####                 ###   ###                 ###                                                                    
                ##                     ###################                        ####                #####     ####  ###############   #######  ##############   ########                             
              ##                    ##########################                      ####               ########  ###  ####      ###    ###   ###  ###  ###  ####       ###                             
             #                    ##############################                     ####                   ###  ###   #######  ###   ##########  ###  ###  ####  ########                             
            #                  ###################################        #           ####           ###    ###  ###  ##   ###  ###    ####       ###  ###  #### ####  ###                             
                              ###########################       ####       #           ####          #########  ##### #######   ######  ######## ##### #### ##### #########                            
                          #####################                             #           ####                                                                                                           
                       ### ################                          ##     ##           ###                                                                                                           
                     ###  ##############                            ####     ##          ####                                                                                                          
                   ###   ##############          ##############   ######     ##           ###                                                                                                          
       #          ###    #############      ################ ############     ##          ####            ###                    ##                                                                    
                 ###    ##############    ################################    ##           ###       ######  ######             ####                               ####                                
      #         ###     #############    #################################    ##           ###        ####    ###                                                   ###                                
      #         ###    ##############     ################################    ###          ####       ####    ####  #### ####  #####    #####    #####          #######    #####                       
      #        ####    ###############          ###########################   ###          ####       ####    ####   #########  ####  #### ### #### ####      #########  #### ####                     
      #        ####    ###################           ######################   ###          ####       ####    ####   ###  ####  #### ####      ###   ####     ###   ### ##########                     
      #       #####    #########################         ##################  ####          ###         ###    ###    ###  ####  #### ####      ###   ###      ###   ### ####                           
      ##      #####    ################################     ##############   ###          ####         #########     ###  ####  ####  ######## #########      #########  ########                      
      ##      #####    ##################################    #############  ####          ####           #####      ##### #### ######   #####     ####          ### ####   #####                       
       #       #####    ###################################   ############ #####         ####                                                                                                          
       ##      ######   #################################     ###########  ####          ####                                                                                                          
        ##      ######   ####### #####################       #################          ####                                                                                                           
         #      #######   ####                              ##################         #####                                                                                                           
         ###     #######   ##                             ###################         #####                                                          ##                       ###                      
          ###     ########  #                          ####################          #####           ######     ######             ##              ###                        ####                     
           ###     ######### ###                 #########################          #####              #####    #####              ##                                         ####                     
             ##     ####################################################          #####                #####   ######   #######  ####### #### #### ####   ####### #### #####  ####  #######            
              ###     #################################################          #####                 ###### #######   ##  ####  ####     ### ### #### ####  ###  ###  ####  ####  ##   ###           
                ###     #############################################          #####                   ### ##### ####    #######  ####     ###     #### ####       ###  ####  ####   #######           
                 ####     ########################################           ######                    ###  ###  ####  #### ####  ####     ###     #### ####       ###  ####  #### ####  ###           
                   ####     ###################################           #######                    ######     ###### ##########  ##### #######  ###### ########  ########## ##### #########          
                     #####     ############################             #######                                                                                                                        
                        #####        ################               ########                                                                                                                           
                           #######                             ##########                                                                                                                              
                               ###########              #############                                                                                                                                  
                                    ############################                                                                                                                                       
                                              ########                                                                                                                                                 
                                                                                                                                                                                                       
    )";
}

int menu()
{
    int opc;
    
    portada();
    cout << "*******************************************************" << endl;
    cout << "\t\t Bienvenidos al SUM" << endl;
    cout << "\n[1] Estudiante" << endl;
    cout << "[2] Profesor" << endl;
    cout << "[3] Registrar" << endl;
    cout << "[4] Salir" << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc;

    return opc;
}

int submenu1() 
{
    int opc;

    cout << "************************************************************************" << endl;
    cout << "\tEstudiante de la Universidad Nacional Mayor de San Marcos\n" << endl;
    cout << "Curso     : " << estudiante.curso << endl;
    cout << "Nombres   : " << estudiante.datos_personales.primer_nombre << " " << estudiante.datos_personales.segundo_nombre << endl;
    cout << "Apellidos : " << estudiante.datos_personales.apellido_paterno << " " << estudiante.datos_personales.apellido_materno << endl;
    cout << "Carrera   : " << estudiante.carrera << endl;
    // cout << "Pondero ciclo 24-I: "  << estudiante.ponderado <<endl;

    cout << "\n[1] Asistencia" << endl;
    cout << "[2] Notas" << endl;
    cout << "[3] Salir " << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc;

    return opc;
}

int submenu2()
{
    int opc;

    cout << "************************************************************************" << endl;
    cout << "\tProfesor de la Universidad Nacional Mayor de San Marcos \n" << endl;
    cout << "Curso        : " << profesor.curso << endl;
    cout << "Nombres      : " << profesor.datos_personales.primer_nombre << " " << profesor.datos_personales.segundo_nombre << endl;
    cout << "Apellidos    : " << profesor.datos_personales.apellido_paterno << " " << profesor.datos_personales.apellido_materno << endl;
    cout << "Departamento : " << profesor.departamento << endl;

    cout << "\n[1] Tomar Asistencia" << endl;
    cout << "[2] Ingresar Notas" << endl;
    cout << "[3] Salir" << endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc;

    return opc;
}

int submenu3()
{
    int opc;
    cout << "************************************************************************" << endl;
    cout << "\t\t\tBienvenido Super Usuario\n" << endl;
    cout << "[1] Crear un nuevo alumno" << endl;
    cout << "[2] Leer datos de un alumno" << endl;
    cout << "[3] Actualizar datos de un alumno" << endl;
    cout << "[4] Eliminar datos de un alumno" << endl;
    cout << "[5] Salir" <<endl;
    cout << "\n\tIngrese una opción -> ";
    cin >> opc;

    return opc;
}

int submenu4()
{
    int opc;
    cout << "****************************************************************************" << endl;
    cout << "\t\tSeleccione el dato que desea actualizar" << endl;
    cout << "[1] Usuario" << endl;
    cout << "[2] Contraseña" << endl;
    cout << "[3] Nombres" << endl;
    cout << "[4] Apellidos" << endl;
    cout << "[5] Carrera Profesional" << endl;
    cout << "[6] Asignatura" << endl;
    cout << "[7] Salir y Guardar" << endl;
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

void quitar_espacio(string &cambio)
{
    int i = 0;
    while (cambio[i] != '\0') {
        if (cambio[i] == ' ') {
            cambio[i] = '_';
        }
        i++;
    }
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
    
    printf("%02d/%02d/%d %02d:%02d:%02d\n", fecha.dia, fecha.mes, fecha.anio, fecha.horas, fecha.minutos, fecha.segundos);
}

void iniciar_sesion_estudiante(bool &ingresado, int &intento)
{
    string usuario;
    string contrasena;

    cout << "**********************************************" << endl;
    cout << "\t\tIniciar Sesión " << endl;
    cout << "\n\tUsuario: ";
    getline(cin, usuario);
    cout << "\tContraseña: ";
    getline(cin, contrasena);

    if (buscar_estudiante(usuario, contrasena)) {
        ingresado = true;    
    } else {
        intento--;
        cout << "\nUsuario y/o clave son incorrectos" << endl;
        cout << "\nLe queda " << intento << " intentos";
        cin.ignore();
    }
}

void iniciar_sesion_profesor(bool &ingresado, int &intento)
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
    } else {
        intento--;
        cout << "\nUsuario y/o clave son incorrectos" << endl;
        cout << "\nLe queda " << intento << " intentos";
        cin.ignore();
    }
}

bool buscar_profesor(string &usuario, string &contrasena)
{
    bool encontrado = false;
    ifstream Profesor(PATH_PROFESOR, ios::in);

    while (Profesor.good() && !Profesor.eof() && !encontrado) {
        Profesor >> profesor.credenciales.usuario;
        Profesor >> profesor.credenciales.contrasena;
        Profesor >> profesor.datos_personales.primer_nombre;
        Profesor >> profesor.datos_personales.segundo_nombre;
        Profesor >> profesor.datos_personales.apellido_paterno;
        Profesor >> profesor.datos_personales.apellido_materno;
        Profesor >> profesor.departamento;
        Profesor >> profesor.curso;

        if (usuario == profesor.credenciales.usuario && contrasena == profesor.credenciales.contrasena) {
            encontrado = true;
            agregar_espacio(profesor.departamento);
            agregar_espacio(profesor.curso);
        }
    }
    
    Profesor.close();
    return encontrado;
}

bool buscar_estudiante(string &usuario, string &contrasena)
{
    bool encontrado = false;
    ifstream Alumno(PATH_ALUMNO, ios::in);

    if (!Alumno.is_open()) {
        cout << "\nNo se pudo abrir el archivo " << PATH_ALUMNO <<  " para lectura" << endl;
        return -1;
    }

    while (Alumno.good() && !Alumno.eof() && !encontrado) {
        Alumno >> estudiante.credenciales.usuario;
        Alumno >> estudiante.credenciales.contrasena;
        Alumno >> estudiante.datos_personales.primer_nombre;
        Alumno >> estudiante.datos_personales.segundo_nombre;
        Alumno >> estudiante.datos_personales.apellido_paterno;
        Alumno >> estudiante.datos_personales.apellido_materno;
        Alumno >> estudiante.carrera;
        Alumno >> estudiante.curso;

        if (usuario == estudiante.credenciales.usuario && contrasena == estudiante.credenciales.contrasena) {
            encontrado = true;
            agregar_espacio(estudiante.carrera);
            agregar_espacio(estudiante.curso);
        }
    }
    
    Alumno.close();
    return encontrado;
}

void mostrar_asistencia()
{
    ifstream Asistencia;
    string codigo;
    char asistencia[16];
    bool encontrado = false;
    // float asistencias = 0;
    float contador = 0;
    float contador2 = 0;
    float contador3 = 0;
    Asistencia.open("./Asistencia.txt", ios::in);
    
    
    cout << "\t\t\tMis Asistencias\t\t\t"; fecha_hoy(); cout << endl;
    cout << "\n\t   Asignaturas \t\t\t A(Asistio) / T(Tardanza) / F(Falta) ";
    cout << "\n****************************************************************************" << endl;

    while (!Asistencia.eof() && Asistencia.good() && !encontrado) {
        Asistencia >> codigo;
        Asistencia >> estudiante.datos_personales.primer_nombre;
        Asistencia >> estudiante.datos_personales.segundo_nombre;
        Asistencia >> estudiante.datos_personales.apellido_paterno;
        Asistencia >> estudiante.datos_personales.apellido_materno;

        for (int i = 0; i < 16; ++i) {
            Asistencia >> asistencia[i];
            if (asistencia[i] == 'A') {
                contador++;
            } else if (asistencia[i] == 'T') {
                contador2++;
            } else if (asistencia[i] == 'F') {
                contador3++;
            }
        }    

        if (codigo == estudiante.credenciales.usuario) {
            encontrado = true;
        }
    }

    cout << estudiante.curso << " : \t\t" << contador << "%\t" <<  contador2 << "%\t" << contador3 << "%\t" << endl;
    // cout << contador << endl;
    cout << "\n\n\nPresione enter para volver" << endl;

    cin.ignore();
    cin.get();
}

void mostrar_notas()
{
    string codigo;
    bool encontrado = false;
    float EP, EC, EF, PF;

    ifstream Notas(PATH_NOTAS, ios::in);

    cout << "\t\t\tReporte de Evaluaciones \t\t"; fecha_hoy(); cout << endl;
    cout << "\n\t   Asignaturas \t\t\t\t Calificación";
    cout << "\n****************************************************************************" << endl;

    while (!Notas.eof() && Notas.good() && !encontrado) {
        Notas >> codigo;
        Notas >> estudiante.datos_personales.primer_nombre;    
        Notas >> estudiante.datos_personales.segundo_nombre;   
        Notas >> estudiante.datos_personales.apellido_paterno;   
        Notas >> estudiante.datos_personales.apellido_materno; 
        Notas >> EP >> EC >> EF >> PF;

        if (codigo == estudiante.credenciales.usuario) {
            encontrado = true;
        }
    }
    cout << "\t\t\t\t\tExamen Parcial: " << EP << endl;
    cout << estudiante.curso << "\t\tEvaluaciones Continuas e Informes: " << EC << endl;
    cout << "\t\t\t\t\tExamen Final: " << EF << endl;
    cout << "\n\t\t\t\t\tPromedio Final: " << PF << endl;

    cin.ignore();
    cin.get();
}

void registrar_notas()
{
    string codigo;
    float EP;
    float EC;
    float EF;
    float PF = 0;
    fstream Notas(PATH_NOTAS, ios::in | ios::out);

    Notas >> codigo;
    Notas >> estudiante.datos_personales.primer_nombre;
    Notas >> estudiante.datos_personales.segundo_nombre;
    Notas >> estudiante.datos_personales.apellido_paterno;
    Notas >> estudiante.datos_personales.apellido_materno;

    while (Notas.good() && !Notas.eof()) {
        limpiar_ventana();
        cout << "\t\t Ingresos de Calificaciones \t"; fecha_hoy();
        cout << "\n****************************************************************" << endl;        
        cout << "Estudiante: " << codigo << endl;
        cout << "Asignatura: " << profesor.curso << endl;
        cout << "\nCalificación de Examen Parcial: ";
        cin >> EP;
        cout << "Calificación de Evaluaciones Continuas e Informes: ";
        cin >> EC;
        cout << "Calificación de Examen Final: ";
        cin >> EF;

        if ((EP >= 0 && EP <= 20) && (EC >= 0 && EC <= 20) && (EF >= 0 && EF <= 20)) {
            PF = (0.3*EP) + (0.4*EC) + (0.3*EF);
            cout << fixed << setprecision(3);
            cout << "\nCalificación Promedio Final es: " << (int)(PF+0.5) << endl;
            cout << "\n\n\tCalificaciones Correctas " << endl;
            cout << "Presione enter para el siguiente estudiante !..." << endl;
            cin.ignore();
            cin.get();

            Notas << " " << EP << " " << EC << " " << EF << " " << EF;
            Notas >> codigo;
            Notas >> estudiante.datos_personales.primer_nombre;
            Notas >> estudiante.datos_personales.segundo_nombre;
            Notas >> estudiante.datos_personales.apellido_paterno;
            Notas >> estudiante.datos_personales.apellido_materno;
        } else {
            cout << "\nVuelve a ingresar denuevo, las notas deben ser de rango [0-20]" << endl;

            cin.ignore();
            cin.get();
        }
    }
    
    cout << "\nIngreso de notas de completado" << endl;
    
    cin.ignore();
    cin.get();
}

void registrar_asistencia()
{
    string name1;
    string name2;
    string apellido_paterno;
    string apellido_materno;
    char tmp;

    fstream Asistencia(PATH_ASISTENCIA, ios::in | ios::out);
    
    cout << "\t\t Asistencia \t\t\t"; fecha_hoy(); 
    cout << "\n****************************************************************" << endl;
    cout << " Código \t     Apellidos y Nombres       \t        A|T|F" << endl;  

    Asistencia >> estudiante.codigo;
    Asistencia >> estudiante.datos_personales.primer_nombre;
    Asistencia >> estudiante.datos_personales.segundo_nombre;
    Asistencia >> estudiante.datos_personales.apellido_paterno;
    Asistencia >> estudiante.datos_personales.apellido_materno;

    while (!Asistencia.eof() && Asistencia.good()) {
        cout << left << setw(10) << estudiante.codigo << "\t" 
             << setw(15) << estudiante.datos_personales.apellido_paterno + " " +  estudiante.datos_personales.apellido_materno + ", " 
             << setw(20) << estudiante.datos_personales.primer_nombre + " " + estudiante.datos_personales.segundo_nombre 
             << "\t";
        cin >> tmp;
        
        Asistencia << " " << tmp;
        Asistencia >> estudiante.codigo;
        Asistencia >> estudiante.datos_personales.primer_nombre;
        Asistencia >> estudiante.datos_personales.segundo_nombre;
        Asistencia >> estudiante.datos_personales.apellido_paterno;
        Asistencia >> estudiante.datos_personales.apellido_materno;
    }
    cout << "\nAsistencia completada" << endl;

    cin.ignore();
    cin.get();
}

void crear_alumno()
{
    ofstream Alumno(PATH_ALUMNO, ios::out | ios::app);
    ofstream Asistencia(PATH_ASISTENCIA, ios::out | ios::app);
    ofstream Notas(PATH_NOTAS, ios::out | ios::app);

    cin.ignore();
    cout << "\n****************************************************************************" << endl;
    cout << "\t\t    Ingrese los datos del nuevo alumno" << endl;
    cout << "\n\tIngrese un Usuario: ";
    getline(cin, estudiante.credenciales.usuario);

    cout << "\tIngrese una Contraseña: ";
    getline(cin, estudiante.credenciales.contrasena);

    cout << "\n\tNombres: ";
    getline(cin, estudiante.datos_personales.primer_nombre);
    // getline(cin, estudiante.datos_personales.segundo_nombre);

    cout << "\tApellidos: ";
    getline(cin, estudiante.datos_personales.apellido_paterno);
    // getline(cin, estudiante.datos_personales.apellido_materno);

    cout << "\tCarrera Profesional: ";
    getline(cin, estudiante.carrera);

    cout << "\tIngrese la Asignatura: ";
    getline(cin, estudiante.curso);

    quitar_espacio(estudiante.carrera);
    quitar_espacio(estudiante.curso);

    Alumno << "\n" << estudiante.credenciales.usuario << "   ";
    Alumno << estudiante.credenciales.contrasena << "   ";
    Alumno << estudiante.datos_personales.primer_nombre << "   ";
    // Alumno << estudiante.datos_personales.segundo_nombre << "   ";
    Alumno << estudiante.datos_personales.apellido_paterno << "   ";
    // Alumno << estudiante.datos_personales.apellido_materno << "   ";
    Alumno << estudiante.carrera << "   ";
    Alumno << estudiante.curso;

    Asistencia << "\n" << estudiante.credenciales.usuario << "   ";
    Asistencia << estudiante.datos_personales.primer_nombre << "   ";
    Asistencia << estudiante.datos_personales.apellido_paterno << "   ";

    Notas << "\n" << estudiante.credenciales.usuario << "   ";
    Notas << estudiante.datos_personales.primer_nombre << "   ";
    Notas << estudiante.datos_personales.apellido_paterno << "   ";

    cout << "\n\nDatos del alumno registrados y almacenados." << endl;
    
    Alumno.close();

    cin.get();
}

void leer_alumno()
{
    ifstream Alumno;
    string codigo;
    string nombres;
    string apellidos;
    bool encontrado = false;
    Alumno.open("./Alumnos.txt", ios::in);

    cin.ignore();
    cout << "\n****************************************************************************" << endl;    
    cout << "\t\tIngrese los datos para leer al estudiante" << endl;    

    cout << "\nIngrese Código del estudiante   : ";
    getline(cin, codigo);
    
    cout << "Ingrese Nombres del estudiante  : ";
    getline(cin, nombres);

    cout << "Ingrese Apellidos del estudiante: ";
    getline(cin, apellidos);    

    while (!Alumno.eof() && Alumno.good() && !encontrado) {
        Alumno >> estudiante.credenciales.usuario;
        Alumno >> estudiante.credenciales.contrasena;
        Alumno >> estudiante.datos_personales.primer_nombre;
        Alumno >> estudiante.datos_personales.segundo_nombre;
        Alumno >> estudiante.datos_personales.apellido_paterno;
        Alumno >> estudiante.datos_personales.apellido_materno;
        Alumno >> estudiante.carrera;
        Alumno >> estudiante.curso;

        agregar_espacio(estudiante.carrera);
        agregar_espacio(estudiante.curso);

        if (codigo == estudiante.credenciales.usuario && 
            nombres == estudiante.datos_personales.primer_nombre + " " + estudiante.datos_personales.segundo_nombre &&
            apellidos == estudiante.datos_personales.apellido_paterno + " " + estudiante.datos_personales.apellido_materno) {
            encontrado = true;
        }
    }
    
    if (encontrado) {
        cout << "\n****************************************************************************" << endl;
        cout << "\t\t\tEstudiante Encontrado" << endl;
        cout << "\nCódigo del Estudiante    : " << estudiante.credenciales.usuario << endl;
        cout << "Nombres del Estudiante   : " << estudiante.datos_personales.primer_nombre << " " <<  estudiante.datos_personales.segundo_nombre << endl;
        cout << "Apellidos del Estudiante : " << estudiante.datos_personales.apellido_paterno << " " << estudiante.datos_personales.apellido_materno << endl;
        cout << "Carrera del Estudiante   : " << estudiante.carrera << endl;
        cout << "Asignatura del Estudiante: " << estudiante.curso << endl;
    } else {
        cout << "\nNo se encontro al estudiante\n";
    }

    cout << "\nPresione enter para volver..." << endl;

    Alumno.close();
    cin.get();
}

void actualizar_alumno()
{
    ifstream Actualizar;
    ofstream Actualizar_Temporal;
    string codigo;
    string nombres;
    string apellidos;
    bool encontrado = false;
    Actualizar.open("./Alumnos.txt", ios::in);
    Actualizar_Temporal.open("./Alumnos Temporal.txt", ios::out);

    cin.ignore();
    cout << "\n****************************************************************************" << endl;    
    cout << "\t\tIngrese los datos para actualizar al estudiante" << endl;    

    cout << "\nIngrese Código del estudiante   : ";
    getline(cin, codigo);
    
    cout << "Ingrese Nombres del estudiante  : ";
    getline(cin, nombres);

    cout << "Ingrese Apellidos del estudiante: ";
    getline(cin, apellidos);

    Actualizar >> estudiante.credenciales.usuario;
    Actualizar >> estudiante.credenciales.contrasena;
    Actualizar >> estudiante.datos_personales.primer_nombre;
    Actualizar >> estudiante.datos_personales.segundo_nombre;
    Actualizar >> estudiante.datos_personales.apellido_paterno;
    Actualizar >> estudiante.datos_personales.apellido_materno;
    Actualizar >> estudiante.carrera;
    Actualizar >> estudiante.curso;

    while (!Actualizar.eof() && Actualizar.good()) {
        agregar_espacio(estudiante.carrera);
        agregar_espacio(estudiante.curso);

        if (codigo == estudiante.credenciales.usuario &&
            (nombres == estudiante.datos_personales.primer_nombre + " " + estudiante.datos_personales.segundo_nombre ||
            apellidos == estudiante.datos_personales.apellido_paterno + " " + estudiante.datos_personales.apellido_materno)) {
            encontrado = true;

            int opc;
            do {
                limpiar_ventana();

                cout << "\n****************************************************************************" << endl;
                cout << "\t\t\t  Estudiante Encontrado" << endl;  
                opc = submenu4();

                switch (opc) {
                    case 1: {
                        cin.ignore();
                        limpiar_ventana();

                        cout << "\nUsuario actual          : " << estudiante.credenciales.usuario << endl;
                        cout << "Ingrese el nuevo usuario: ";
                        getline(cin, codigo);

                        cout << "\nDatos del estudiante actualizados y almacenados." << endl;
                        cin.get();

                        break;
                    }
                    case 2: {
                        cin.ignore();
                        limpiar_ventana();

                        cout << "\nContraseña actual          : " << estudiante.credenciales.contrasena << endl;
                        cout << "Ingrese la nueva contraseña: ";
                        getline(cin, estudiante.credenciales.contrasena);

                        cout << "\nDatos del estudiante actualizados y almacenados." << endl;
                        cin.get();

                        break;
                    }
                    case 3: {
                        cin.ignore();
                        limpiar_ventana();

                        cout << "\nNombres actual            : " << estudiante.datos_personales.primer_nombre << " " << estudiante.datos_personales.segundo_nombre << endl;
                        cout << "Ingrese los nuevos nombres: ";
                        getline(cin, nombres);

                        cout << "\nDatos del estudiante actualizados y almacenados." << endl;
                        cin.get();

                        break;
                    }
                    case 4: {
                        cin.ignore();
                        limpiar_ventana();

                        cout << "\nApellidos actual            : " << estudiante.datos_personales.apellido_paterno << " " << estudiante.datos_personales.apellido_materno << endl;
                        cout << "Ingrese los nuevos apellidos: ";
                        getline(cin, apellidos);

                        cout << "\nDatos del estudiante actualizados y almacenados." << endl;
                        cin.get();

                        break;
                    }
                    case 5: {
                        cin.ignore();
                        limpiar_ventana();

                        cout << "\nCarrera actual          : " << estudiante.carrera << endl;
                        cout << "Ingrese la nueva carrera: ";
                        getline(cin, estudiante.carrera);

                        cout << "\nDatos del estudiante actualizados y almacenados." << endl;
                        cin.get();

                        break;
                    }
                    case 6: {
                        cin.ignore();
                        limpiar_ventana();

                        cout << "\nAsignatura actual          : " << estudiante.curso << endl;
                        cout << "Ingrese la nueva asignatura: ";
                        getline(cin, estudiante.curso);

                        cout << "\nDatos del estudiante actualizados y almacenados." << endl;
                        cin.get();

                        break;
                    }
                    case 7: break;

                    default: {
                        cout << "\n\t   Opción no válida" << endl; 
                        cout << "Presione enter para volver selecionar..."; 
                        cin.ignore();
                        cin.get();

                        break;
                    }
                }
            } while (opc != 7);

            quitar_espacio(estudiante.carrera);
            quitar_espacio(estudiante.curso);

            Actualizar_Temporal << codigo << "   ";
            Actualizar_Temporal << estudiante.credenciales.contrasena << "   ";
            Actualizar_Temporal << nombres << "   ";
            Actualizar_Temporal << apellidos << "   ";
            Actualizar_Temporal << estudiante.carrera << "   ";
            Actualizar_Temporal << estudiante.curso << endl;

        } else {
            quitar_espacio(estudiante.carrera);
            quitar_espacio(estudiante.curso);

            Actualizar_Temporal << estudiante.credenciales.usuario << "   ";
            Actualizar_Temporal << estudiante.credenciales.contrasena << "   ";
            Actualizar_Temporal << estudiante.datos_personales.primer_nombre << " ";
            Actualizar_Temporal << estudiante.datos_personales.segundo_nombre << "   ";
            Actualizar_Temporal << estudiante.datos_personales.apellido_paterno << " ";
            Actualizar_Temporal << estudiante.datos_personales.apellido_materno << "   ";
            Actualizar_Temporal << estudiante.carrera << "   ";
            Actualizar_Temporal << estudiante.curso << endl;
        }

        Actualizar >> estudiante.credenciales.usuario;
        Actualizar >> estudiante.credenciales.contrasena;
        Actualizar >> estudiante.datos_personales.primer_nombre;
        Actualizar >> estudiante.datos_personales.segundo_nombre;
        Actualizar >> estudiante.datos_personales.apellido_paterno;
        Actualizar >> estudiante.datos_personales.apellido_materno;
        Actualizar >> estudiante.carrera;
        Actualizar >> estudiante.curso;       
    }

    if (!encontrado) {
        cout << "\nNo se encontró ningún estudiante con esos datos" << endl;
    }

    Actualizar.close();
    Actualizar_Temporal.close();
    remove("./Alumnos.txt");
    rename("./Alumnos Temporal.txt", "./Alumnos.txt");

    cin.get();
}

void eliminar_alumno() 
{
    ifstream Alummno;
    ofstream Alummno_Temporal;
    string codigo;
    string nombres;
    string apellidos;
    bool encontrado;

    Alummno.open("./Alumnos.txt", ios::in);
    Alummno_Temporal.open("./Alumnos Temporal.txt", ios::out);

    cin.ignore();
    cout << "\n****************************************************************************" << endl;    
    cout << "\t\tIngrese los datos para eliminar al estudiante" << endl;    

    cout << "\nIngrese Código del estudiante   : ";
    getline(cin, codigo);
    
    cout << "Ingrese Nombres del estudiante  : ";
    getline(cin, nombres);

    cout << "Ingrese Apellidos del estudiante: ";
    getline(cin, apellidos);

    Alummno >> estudiante.credenciales.usuario;
    Alummno >> estudiante.credenciales.contrasena;
    Alummno >> estudiante.datos_personales.primer_nombre;
    Alummno >> estudiante.datos_personales.segundo_nombre;
    Alummno >> estudiante.datos_personales.apellido_paterno;
    Alummno >> estudiante.datos_personales.apellido_materno;
    Alummno >> estudiante.carrera;
    Alummno >> estudiante.curso;

    while (!Alummno.eof() && Alummno.good()) {
        agregar_espacio(estudiante.carrera);
        agregar_espacio(estudiante.curso);

        if (codigo == estudiante.credenciales.usuario && 
            (nombres == estudiante.datos_personales.primer_nombre + " " + estudiante.datos_personales.segundo_nombre ||
            apellidos == estudiante.datos_personales.apellido_paterno + " " + estudiante.datos_personales.apellido_materno)) {
            encontrado = true;
        } else {
            quitar_espacio(estudiante.carrera);
            quitar_espacio(estudiante.curso);

            Alummno_Temporal << estudiante.credenciales.usuario << "   ";
            Alummno_Temporal << estudiante.credenciales.contrasena << "   ";
            Alummno_Temporal << estudiante.datos_personales.primer_nombre << " ";
            Alummno_Temporal << estudiante.datos_personales.segundo_nombre << "   ";
            Alummno_Temporal << estudiante.datos_personales.apellido_paterno << " ";
            Alummno_Temporal << estudiante.datos_personales.apellido_materno << "   ";
            Alummno_Temporal << estudiante.carrera << "   ";
            Alummno_Temporal << estudiante.curso << endl;
        }

        Alummno >> estudiante.credenciales.usuario;
        Alummno >> estudiante.credenciales.contrasena;
        Alummno >> estudiante.datos_personales.primer_nombre;
        Alummno >> estudiante.datos_personales.segundo_nombre;
        Alummno >> estudiante.datos_personales.apellido_paterno;
        Alummno >> estudiante.datos_personales.apellido_materno;
        Alummno >> estudiante.carrera;
        Alummno >> estudiante.curso;
    }

    if (encontrado) {
        cout << "\nEstudiante eliminado del sistema" << endl;
    } else {
        cout << "\nNo se encontró ningún estudiante con esos datos" << endl;
    }

    Alummno.close();
    Alummno_Temporal.close();
    remove("./Alumnos.txt");
    rename("./Alumnos Temporal.txt", "./Alumnos.txt");

    cin.get();
}