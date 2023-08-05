#pragma once
#include "functionsDataFisico.cpp"

// Guardar estudiante
// void GuardarEstudiante(Estudiante);
void GuardarEstudiante(Estudiante[], int, int (*buscarEstudianteFor)(const char *, int));

Estudiante verArchivo();

// A MODIFICAR
int buscarEstudianteA(const char *);
int buscarEstudianteFor(const char *, int);

// int buscarEstudianteB(char *);