#ifndef PLUG_HPP_
#define PLUG_HPP_

#include <string.h>

using namespace std;

// Declaración de la función para limpiar la ventana de la consola
void limpiar_ventana();

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

// Quitar "_" y agregar espacio " "
void agregar_espacio(string &cambio);

void quitar_espacio(string &cambio);

// Funcion buscar archivo profesor.txt
bool buscar_profesor(string &usuario, string &contrasena);

// Funcion buscar archivo alumno.txt
bool buscar_estudiante(string &usuario, string &contrasena);

// Funcion de iniciar sesion
void iniciar_sesion_estudiante(bool &ingresado, int &intento);

void iniciar_sesion_profesor(bool &ingresado, int &intento);

// Mostrar la fecha actual de hoy
void fecha_hoy();

// Funcion mostrar notas 
void notas();

// Funcion registrar asistencias
void asistencia();

// Mostrar las asitencias de los alumnos
void mostrar_asistencia();

// Mostrar las notas de los alumnos
void mostrar_notas();

// CRUD -> Crear un nuevo alumno
void crear_alumno();

// CRUD -> Leer un nuevo alumno
void leer_alumno();

// CRUD -> Actualizar un nuevo alumno
void actualizar_alumno();

// CRUD -> Eliminar un nuevo alumno
void eliminar_alumno();

#endif // PLUG_HPP_