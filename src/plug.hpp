#ifndef PLUG_HPP_
#define PLUG_HPP_

#include <string.h>

using namespace std;




/* 
    Funciones para el menú
*/

// Menu principal
int menu();

// Submenu caso 1
int submenu1();

// Submenu caso 2
int submenu2();

// Submenu caso 3
int submenu3();

// Submenu caso 4
int submenu4();




/* 
    Funciones personales
*/

// Declaración de la función para limpiar la ventana de la consola para windows y sistemas POSIX
void limpiar_ventana();

// Portada del SUM
void portada();

// Quitar "_" y agregar espacio " "
void agregar_espacio(string &cambio);

// Quitar " " y agregar espacio "_"
void quitar_espacio(string &cambio);

// Mostrar la fecha actual de hoy
void fecha_hoy();




/* 
    Funciones para Estudiante
*/

// Funcion de iniciar sesion alumno
void iniciar_sesion_estudiante(bool &ingresado, int &intento);

// Funcion de iniciar sesion profesor
void iniciar_sesion_profesor(bool &ingresado, int &intento);

// Mostrar las asitencias de los alumnos
void mostrar_asistencia();

// Mostrar las notas de los alumnos
void mostrar_notas();




/* 
    Funciones para Profesor
*/

// Funcion buscar archivo profesor.txt
bool buscar_profesor(string &usuario, string &contrasena);

// Funcion buscar archivo alumno.txt
bool buscar_estudiante(string &usuario, string &contrasena);

// Funcion registrar asistencias
void registrar_asistencia();

// Funcion registrar notas 
void registrar_notas();




/* 
    Funciones CRUD
*/

// CRUD -> Crear un nuevo alumno
void crear_alumno();

// CRUD -> Leer un nuevo alumno
void leer_alumno();

// CRUD -> Actualizar un nuevo alumno
void actualizar_alumno();

// CRUD -> Eliminar un nuevo alumno
void eliminar_alumno();




#endif // PLUG_HPP_