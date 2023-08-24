#pragma once
#include "interfaz.cpp"

// Muestra la navegacion dekl inicio
int Navegacion();

// Solo muestra los datos de un beneficios listado
void MostrarBeneficios(Beneficio);

// Interfaz de INGRESAR_BENEFICIO
Beneficio IngresarDatosBeneficios();

// Seleccionar que quiere hacer.
int MostrarOpcionesModificarBeneficio();
Beneficio MostrarOpcionesModificacion(int, Beneficio);

/*
la funcion "ignore" sirve para limpiar el buffer de entrada
 ya que al apretar el enter este se guarda en el buffer.

 ignore: le pasamos un entero y el simbolo del salto de linea
 para que el ignore elimina los caracteres del buffer, si llega
 a 10000 o se hace un salto de linea.

 cin.ignore(10000, '\n');

 */
