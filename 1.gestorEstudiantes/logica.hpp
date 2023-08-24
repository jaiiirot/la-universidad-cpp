#pragma once
#include "logica.cpp"

// Validar Datos
// Estudiante ValidarEstudiantesRegistro(bool &, Estudiante);
Estudiante existeEstudiante(bool &, Estudiante);

// IniciarSesion/Verificar
void IniciarSesionEstudiante(Estudiante);

// Registro/Guardar
void RegistrarEstudiante(Estudiante);

// Mostrar Estudiante
void MostrarEstudiante(int);
