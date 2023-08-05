#pragma once
// Archivos de cabecera
#include "funciones.cpp"

// Mostrar Opciones
int NavegacionMain();

// Crear/registrarse
Estudiante CrearEstudiante();
string CrearDatos(Estudiante);

// Validar/iniciar sesion

void ValidarEstudiantes(Estudiante (*importEstudiante)());
