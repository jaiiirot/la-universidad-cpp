#pragma once
#include "logica.cpp"

// Validar la existencia del beneficio
Beneficio existeBeneficio(bool &, Beneficio);

// Contador de beneficios
void countBeneficios(int &);
// Mostrar Todos los beneficios
void mostrarBeneficios();

// Agregar beneficio
void agregarBeneficio(Beneficio);
// Eliminar beneficio
void eliminarBeneficio(int);
// Moidificar beneficio
void modificarBeneficio(string);

/* se denomina primitiva de la funcion F(x) en un intervalo real "i", incluido ampliamente en el conjunto */