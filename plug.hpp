#ifndef PLUG_HPP_
#define PLUG_HPP_

#include <string.h>

using namespace std;

// Declaración de la función para limpiar la ventana de la consola
void limpiar_ventana();

// Menu principal
int menu();

// Submenu caso 2
int submenu2();

int submenu3();

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

int submenu1();

void mostrar_asistencia();

void mostrar_notas();

void crear_alumno();

void leer_alumno();

void actualizar_alumno();


#endif // PLUG_HPP_