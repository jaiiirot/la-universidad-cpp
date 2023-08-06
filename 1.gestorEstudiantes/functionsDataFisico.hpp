#pragma once
#include "functionsDataFisico.cpp"

// Validar Datos
Estudiante ValidarEstudiantes(bool &, Estudiante, string);

// IniciarSesion/Verificar
bool VerificarEstudiantes(Estudiante, Estudiante (*)(bool &, Estudiante, string));

// Registro/Guardar
void RegistrarEstudiante(Estudiante, Estudiante (*)(bool &, Estudiante, string));

// Mostrar Estudiante
void MostrarEstudiante(int);
