#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
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
    string nombre;
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
    float ponderado;
} alumno;

//FUNCIONES AUXILIARES

void agregar_espacio(string &cambio) {
    for (char &c : cambio) {
        if (c == '_') {
            c = ' ';
        }
    }
}

void quitar_espacio(string &cambio){
    for(char &c : cambio){
        if( c == ' '){
            c = '_';
        }
    }
}

void fecha_hoy() {
    auto ahora = chrono::system_clock::now();
    time_t tiempo_actual = chrono::system_clock::to_time_t(ahora);
    tm *local_time = localtime(&tiempo_actual);
    cout << put_time(local_time, "%d/%m/%Y %H:%M") << endl;
}

//FUNCION PRINCIPAL

int menu() {
    int opc;
    cout << "*******************************************************" << endl;
    cout << "\t\t Bienvenidos al Menu" << endl;
    cout << "\n[1] Alumno" << endl;
    cout << "[2] Profesor" << endl;
    cout << "[3] Registrar" << endl;
    cout << "[4] Salir" << endl;
    cout << "\n\tIngrese una opcion -> ";
    cin >> opc;

    return opc;
}


// INICIAR SESION


bool buscar_alumno(string &usuario, string &contrasena, Alumno &alumno) {

    ifstream lista;
    bool encontrado = false;
    lista.open("./Alumnos.txt"); 

    if (!lista) {
        cout << "Error al abrir el archivo Alumnos.txt" << endl;
    }

    while (!lista.eof() && !encontrado) {
        lista >> alumno.credenciales.usuario;
        lista >> alumno.credenciales.contrasena;
        lista >> alumno.datos_personales.nombre;
        lista >> alumno.datos_personales.apellido_paterno;
        lista >> alumno.datos_personales.apellido_materno;
        lista >> alumno.carrera;
        lista >> alumno.ponderado;

        if (usuario == alumno.credenciales.usuario && contrasena == alumno.credenciales.contrasena) {
            encontrado = true;
            agregar_espacio(alumno.datos_personales.nombre);
            agregar_espacio(alumno.carrera);
        }
    }

    lista.close();
    return encontrado;
}


bool buscar_usuario(string &usuario, string &contrasena, Profesor &profesor) {
    ifstream lectura;
    bool encontrado = false;
    lectura.open("./Profesor.txt"); 

    if (!lectura) {
        cerr << "Error al abrir el archivo Profesor.txt" << endl;
        return false;
    }

    while (!lectura.eof() && !encontrado) {
        lectura >> profesor.credenciales.usuario;
        lectura >> profesor.credenciales.contrasena;
        lectura >> profesor.datos_personales.nombre;
        lectura >> profesor.datos_personales.apellido_paterno;
        lectura >> profesor.datos_personales.apellido_materno;
        lectura >> profesor.departamento;
        lectura >> profesor.curso;

        if (usuario == profesor.credenciales.usuario && contrasena == profesor.credenciales.contrasena) {
            encontrado = true;
            agregar_espacio(profesor.datos_personales.nombre);
            agregar_espacio(profesor.departamento);
            agregar_espacio(profesor.curso);
        }
    }

    lectura.close();
    return encontrado;
}


void iniciar_sesion(bool &ingresado, int &intento, Profesor &profesor, Alumno &alumno) {
    string usuario;
    string contrasena;

    cout << "**********************************************" << endl;
    cout << "\t\tIniciar Sesion " << endl;
    cout << "\n\tUsuario: ";
    cin.ignore(); 
    getline(cin, usuario);
    cout << "\tContrasena: ";
    getline(cin, contrasena);


    if (buscar_usuario(usuario, contrasena, profesor)) {
        ingresado = true;
   }
    else if (buscar_alumno(usuario, contrasena, alumno))
    {   ingresado = true;
    } 
    else {
        intento--;
        cout << "\nUsuario y/o clave son incorrectos" << endl;
        cout << "\nLe quedan " << intento << " intentos" << endl;
        cin.ignore();
    }
}


//FUNCIONES PROFESOR

int submenu2(Profesor &profesor) {
    int opc2;

    limpiar_ventana();

    cout << "*******************************************************" << endl;
    cout << "\t\t Bienvenido al sistema \n" << endl;
    cout << "Curso     : " << profesor.curso << endl;
    cout << "Nombres   : " << profesor.datos_personales.nombre << endl;
    cout << "Apellidos : " << profesor.datos_personales.apellido_paterno << " " << profesor.datos_personales.apellido_materno << endl;

    cout << "\n[1] Tomar Asistencia" << endl;
    cout << "[2] Ingresar Notas" << endl;
    cout << "[3] Salir" << endl;
    cout << "\n\tIngrese una opcion -> ";
    cin >> opc2;
    cin.ignore();

    return opc2;
}



void notas() {
    fstream Notas;
    string nombre, apellido_paterno, apellido_materno;
    float EP, EC, EF, PF;
    long codigo;

    Notas.open("./Notas.txt", ios::in | ios::out);

    if (!Notas) {
        cerr << "Error al abrir el archivo Notas.txt" << endl;
        return;
    }

    limpiar_ventana();

    // Leer todo el contenido del archivo en memoria
    stringstream buffer;
    buffer << Notas.rdbuf();
    Notas.close();

    string nuevo_contenido;
    string linea;

    while (getline(buffer, linea)) {
        istringstream ss(linea);
        ss >> codigo;
        if (ss.fail()) break;

        ss >> nombre >> apellido_paterno >> apellido_materno;

        agregar_espacio(nombre);

        cout << "\n\t\t Ingreso de Notas \t";
        fecha_hoy();
        cout << "****************************************************************" << endl;
        cout << "Alumno: " << codigo << " " << nombre << " " << apellido_paterno << " " << apellido_materno << endl;
        cout << "\nIngrese la nota del examen parcial: ";
        cin >> EP;
        cout << "Ingrese la nota del evaluacion continuas: ";
        cin >> EC;
        cout << "Ingrese la nota del examen final : ";
        cin >> EF;

        PF = (0.3 * EP) + (0.4 * EC) + (0.3 * EF);
        cout << fixed << setprecision(2);
        cout << "\nSu Promedio Final es: " << PF << endl;

        quitar_espacio(nombre);

        // Formatear y agregar la línea con el promedio final
        stringstream ss_output;
        ss_output << left << setw(10) << codigo << " "
                  << setw(20) << nombre << " "
                  << setw(20) << apellido_paterno << " "
                  << setw(20) << apellido_materno << " "
                  << fixed << setprecision(2) << PF << endl;

        nuevo_contenido += ss_output.str();
    }

    // Escribir todo el nuevo contenido en el archivo
    ofstream outputFile("./Notas.txt", ios::trunc);
    outputFile << nuevo_contenido;
    outputFile.close();
}


void asistencia() {
    fstream Asistencia;
    string name1;
    string name2;
    string apellido_paterno;
    string apellido_materno;
    char tmp;

    Asistencia.open("Asistencia.txt", ios::in | ios::out); 

    if (!Asistencia) {
        cerr << "Error al abrir el archivo Asistencia.txt" << endl;
        return;
    }

    limpiar_ventana();

    cout << "\t\t Asistencia \t";
    fecha_hoy();
    cout << "\n****************************************************************" << endl;
    cout << " Codigo \t     Apellidos y Nombres       \t        A|T|F" << endl;

    Asistencia >> alumno.codigo;
    Asistencia >> alumno.datos_personales.nombre;
    Asistencia >> alumno.datos_personales.apellido_paterno;
    Asistencia >> alumno.datos_personales.apellido_materno;

    while (!Asistencia.eof()) {
        cout << left << setw(10) << alumno.codigo << "\t"
             << setw(15) << alumno.datos_personales.apellido_paterno + " " + alumno.datos_personales.apellido_materno + ", "
             << setw(20) << alumno.datos_personales.nombre
             << "\t";
        cin >> tmp;
        Asistencia << " "<<tmp << endl;
        Asistencia >> tmp; 
        Asistencia >> alumno.codigo;
        Asistencia >> alumno.datos_personales.nombre;
        Asistencia >> alumno.datos_personales.apellido_paterno;
        Asistencia >> alumno.datos_personales.apellido_materno;
    }

    cout << "\nAsistencia completada" << endl;
    cin.get();

    Asistencia.close();
}


//FUNCIONES ALUMNO

int submenuA(Alumno &alumno) {
    int opc1;

    cout << "****************************" << endl;
    cout << "\tAlumno de la Universidad Nacional Mayor de San Marcos" << endl;
    cout << "APELLIDO PATERNO: " << alumno.datos_personales.apellido_paterno << endl;
    cout << "APELLIDO MATERNO: " << alumno.datos_personales.apellido_materno << endl;
    cout << "NOMBRES: " << alumno.datos_personales.nombre << endl;
    cout << "Carrera profesional: " << alumno.carrera << endl;
    cout << "Pondero ciclo 24-I: "  << alumno.ponderado <<endl;

    cout << "\n\nDesea buscar informacion especifica de algun curso: "<<endl;
    cout << "1. Asistencia" << endl;
    cout << "2. Notas" << endl;
    cout << "3. Salir al menu: ";
    cin >> opc1;

    return opc1;
}

void asistenciaA(Alumno &alumno) {
    ifstream Asistencia("./Asistencia.txt");

    if (!Asistencia.is_open()) {
        cout << "Error al abrir el archivo Asistencia.txt" << endl;
        return;
    }

    long codigo;
    cout << "\nIngrese su codigo: ";
    cin >> codigo; 

    cout << "\n\nMostrando asistencia en el curso hasta ";
    fecha_hoy();
    cout << endl;
    cout << "A(Asistio), T(Tardanza), F(Falta)" << endl;

    string linea;
    bool encontrado = false;
    char asistencia1, asistencia2;
    
    while (getline(Asistencia, linea)) {
        stringstream ss(linea);
        ss >> alumno.codigo;
        ss >> alumno.datos_personales.nombre;
        ss >> alumno.datos_personales.apellido_paterno;
        ss >> alumno.datos_personales.apellido_materno;
        ss >> asistencia1;

        if (alumno.codigo == codigo) {
            encontrado = true;
            cout << linea << endl;
            break; 
        }
    }

    if (!encontrado) {
        cout << "No se encontro al alumno con el codigo " << codigo << " en el registro de asistencia." << endl;
    }

    cin.ignore();
    cin.get();
    Asistencia.close();
}

void notasA(Alumno &alumno) {
    ifstream NotasA("./Notas.txt");
    if (!NotasA) {
        cout<< "Error al abrir el archivo Asistencia.txt" << endl;
    }
    
    long codigo;

    cout << "\nIngrese su codigo: ";
    cin >> codigo;

    cin.ignore();

    cout << "\n\nMostrando promedio final en el curso hasta "; 
    fecha_hoy();
    cout << endl;

    string linea;
    bool encontrado = false;
    float PF;

    while (getline(NotasA, linea)) {
        stringstream ss(linea);
        ss >> alumno.codigo;
        ss >> alumno.datos_personales.nombre;
        ss >> alumno.datos_personales.apellido_paterno;
        ss >> alumno.datos_personales.apellido_materno;
        ss >> PF ;

        if (alumno.codigo == codigo) {
            cout << linea << endl; 
            encontrado = true;
            break; 
        }
    }

   if (!encontrado) {
        cout << "No se encontro la línea con el codigo " << codigo << endl;
    }

    cin.ignore();
    cin.get();
    NotasA.close();
}


//FUNCIONES REGISTRAR

void actualizar() {
    long buscar_codigo;
    cout << "\nIngrese el codigo del alumno que desea actualizar: ";
    cin >> buscar_codigo;

    fstream archivo("Alumnos.txt", ios::in);
    ofstream archivoTemp("Temp.txt");

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        long codigo;
        string contrasena, nombres, apellido_paterno, apellido_materno, carrera;
        double promedio;

        ss >> codigo >> contrasena >> nombres >> apellido_paterno >> apellido_materno >> carrera >> promedio;
        if (codigo == buscar_codigo) {
            encontrado = true;
            cout << "\n\tDATOS ENCONTRADOS:" << endl;
            cout << "------------------" << endl;

            int opcion;
                cout << "\nSeleccione el dato que desea actualizar:" << endl;
                cout << "1. Contrasenia" << endl;
                cout << "2. Nombres" << endl;
                cout << "3. Apellido paterno" << endl;
                cout << "4. Apellido materno" << endl;
                cout << "5. Carrera profesional" << endl;
                cout << "6. Promedio ponderado" << endl;
                cout << "7. Salir" << endl;
                cout << "Ingrese la opcion: ";
                cin >> opcion;
                cin.ignore();  

                switch (opcion) {
                    case 1:
                        cout << "\nContraseña actual: " << contrasena << endl;
                        cout << "Ingrese la nueva contraseña: ";
                        getline(cin, contrasena);
                        break;
                    case 2:
                        cout << "\nNombres actuales: " << nombres << endl;
                        cout << "Ingrese los nuevos nombres: ";
                        getline(cin, nombres);
                        break;
                    case 3:
                        cout << "\nApellido paterno actual: " << apellido_paterno << endl;
                        cout << "Ingrese el nuevo apellido paterno: ";
                        getline(cin, apellido_paterno);
                        break;
                    case 4:
                        cout << "\nApellido materno actual: " << apellido_materno << endl;
                        cout << "Ingrese el nuevo apellido materno: ";
                        getline(cin, apellido_materno);
                        break;
                    case 5:
                        cout << "\nCarrera profesional actual: " << carrera << endl;
                        cout << "Ingrese la nueva carrera profesional: ";
                        getline(cin, carrera);
                        break;
                    case 6:
                        cout << "\nPromedio ponderado actual: " << promedio << endl;
                        cout << "Ingrese el nuevo promedio ponderado: ";
                        cin >> promedio;
                        cin.ignore();  
                        break;
                    case 7:
                        break;
                    default:
                        cout << "\npcion inválida. Intente de nuevo." << endl;
                        break;
                }

            archivoTemp << codigo << " " << contrasena << " " << nombres << " "
                        << apellido_paterno << " " << apellido_materno << " " << carrera << " " << promedio << endl;

            cout << "\nDatos del alumno actualizados y almacenados." << endl;
            cin.get();

        } else {
            archivoTemp << codigo << " " << contrasena << " " << nombres << " "
                        << apellido_paterno << " " << apellido_materno << " " << carrera << " " << promedio << endl;
        }
    }

    archivo.close();
    archivoTemp.close();

    remove("Alumnos.txt");
    rename("Temp.txt", "Alumnos.txt");

    if (!encontrado) {
        cout << "No se encontró ningún alumno con el código " << buscar_codigo << endl;
    }
}

void eliminar_alumno() {
    long buscar_codigo;
    cout << "\nIngrese el codigo del alumno que desea eliminar: ";
    cin >> buscar_codigo;

    ifstream archivoIn("Alumnos.txt");
    ofstream archivoOut("Temp.txt");

    string linea;
    bool encontrado = false;
    while (getline(archivoIn, linea)) {
        stringstream ss(linea);
        long codigo;
        ss >> codigo;

        if (codigo == buscar_codigo) {
            encontrado = true;
            cout << "Alumno eliminado:" << endl;
            cout << "----------------" << endl;
            cout << "Código: " << codigo << endl;
            continue;
        }

        archivoOut << linea << endl;
    }

    archivoIn.close();
    archivoOut.close();

    remove("Alumnos.txt");
    rename("Temp.txt", "Alumnos.txt");

    if (!encontrado) {
        cout << "\nNo se encontro ningun alumno con el codigo " << buscar_codigo << endl;
    } else {
        cout << "Alumno eliminado correctamente." << endl;
    }
}

void registrar_alumno(){
    Alumno nuevo;

    cin.ignore();
    cout<<endl;
    cout<<"INGRESE LOS DATOS DEL NUEVO ALUMNO:"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Nombres: ";
    getline(cin, nuevo.datos_personales.nombre);
    cout<<"Apellido paterno: ";
    getline(cin, nuevo.datos_personales.apellido_paterno);
    cout<<"Apellido materno: ";
    getline(cin, nuevo.datos_personales.apellido_materno);
    cout<<"Carrera profesional: ";
    getline(cin, nuevo.carrera);
    cout<<"Promedio ponderado: ";
    cin>>nuevo.ponderado;
    cin.ignore();
    cout<<"Ingrese un usuario para el alumno: ";
    getline(cin, nuevo.credenciales.usuario);
    cout<<"Ingrese una contrasena para el alumno: ";
    getline(cin, nuevo.credenciales.contrasena);
	cout<<"Ingrese el codigo del nuevo alumno: ";
	cin>>nuevo.codigo;

    quitar_espacio(nuevo.datos_personales.nombre);
    quitar_espacio(nuevo.carrera);

    ofstream archivo("Alumnos.txt", ios::app);
    if(!archivo.is_open()){
        cout<<"ERROR AL ABRIR EL ARCHIVO."<<endl;
        return;
    }

    archivo<<nuevo.codigo<<" ";
	archivo<<nuevo.credenciales.usuario<<"  ";
    archivo<<nuevo.credenciales.contrasena<<"   ";
    archivo<<nuevo.datos_personales.nombre<<"   ";
    archivo<<nuevo.datos_personales.apellido_paterno<<" "<<nuevo.datos_personales.apellido_materno<<"   ";
    archivo<<nuevo.carrera << "     ";
    archivo<<nuevo.ponderado;

    archivo.close();

    cout<<"\n\nDatos del alumno registrados y almacenados."<<endl;
}

void leer_alumno(){
    ifstream archivo("Alumnos.txt");
    if (!archivo.is_open()){
		cout<<"Error al abrir el archivo Alumnos.txt."<<endl;
        return;
    }

    long codigoAlumno;
    cout<<"Ingrese el codigo del alumno: ";
    cin>>codigoAlumno;

    string linea;
    bool encontrado = false;
    while(getline(archivo, linea)){
        if(linea.find(codigoAlumno) != string::npos){
            cout<<"Estudiante encontrado: "<<endl;
            cout<<linea<<endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        cout<<"Estudiante con codigo "<<codigoAlumno<<" no encontrado."<<endl;
    }
    archivo.close();
}

//ALGORITMO PRINCIPAL

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    Profesor profesor;
    Alumno alumno;

    int opc;
    do {
        limpiar_ventana();
        opc = menu();

        switch (opc) {
            case 1: {
                int intento = 3;
                bool ingresado = false;
                do {
                    limpiar_ventana();
                    iniciar_sesion(ingresado, intento, profesor, alumno);
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    int opc1;
                    opc1 = submenuA(alumno);
                    do {
                         cin.ignore();
                        switch(opc1) {
                            case 1: {
                                limpiar_ventana();
                                asistenciaA(alumno);
                                system("pause");
                                } break;
                            case 2: {
                                limpiar_ventana();
                                notasA(alumno);
                                system("pause");
                               } break;
                            default: 
                                break;
                        }
                    } while (opc1 != 3);
                }
            } break;

            case 2: {
                int intento = 3;
                bool ingresado = false;
                do {
                    limpiar_ventana();
                    iniciar_sesion(ingresado, intento, profesor, alumno);
                } while (intento != 0 && !ingresado);

                if (ingresado) {
                    int opc2;
                    do {
                        cin.ignore();
                        opc2 = submenu2(profesor);

                        switch (opc2) {
                            case 1: {
                                limpiar_ventana();
                                asistencia();
                            } break;
                            case 2: {
                                limpiar_ventana();
                                notas();
                            } break;
                        }
                    } while (opc2 != 3);
                }
            } break;

            case 3: {
                int opcion;
                limpiar_ventana();
                do {
                    cout << "\nMenu:" << endl;
                    cout << "1. Crear un nuevo alumno" << endl;
                    cout << "2. Leer datos de un alumno" << endl;
                    cout << "3. Actualizar datos de un alumno" << endl;
                    cout << "4. Eliminar datos de un alumno" << endl;
                    cout << "5. Para salir al menu principal" <<endl;
                    cout << "\nSeleccione una opcion (1-5): ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            limpiar_ventana();
                            registrar_alumno();
                            break;
                        case 2:
                            limpiar_ventana();
                            leer_alumno();
                            break;
                        case 3:
                            limpiar_ventana();
                            actualizar();
                            break;
                        case 4:
                            limpiar_ventana();
                            eliminar_alumno();
                            break;
                        default:
                            cout << "Opción no válida. Por favor, seleccione una opcion del 1 al 4." << endl;
                            cin.ignore();
                            break;
                    }
                } while (opcion != 5);
            }; break;

            default: break;
        };
    } while(opc != 4);

    return 0;

} 
