#include <iostream>
#include <cstring>
#include "estudiante.h"

using namespace std;

Estudiante validarEstudiante(const char* mail, const char* contraseña){ //Valida que el mail y la contraseña ingresadas existan en el archivo "estudiantes.dat"
	FILE* archivo = fopen("estudiantes.dat", "rb");
	Estudiante estudiante;
	bool encontrado = false;
	if (archivo != NULL){
		while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1){
			if (strcmp(estudiante.email, mail) == 0 and strcmp(estudiante.password, contraseña) == 0){
				encontrado = true;
				break;
			}
		}
		fclose(archivo);
	}
	if (!encontrado){
		estudiante.creditos = -1;
	}
	return estudiante;
}

void modificarEstudiante(Estudiante estudiante)
{
	FILE* archivo = fopen("estudiantes.dat", "r+b");

	if(archivo != NULL)
	{
		fseek(archivo, (estudiante.id - 1) * sizeof(Estudiante), SEEK_SET); // Desplaza el puntero hasta la posicion del estudiante a modificar

		fwrite(&estudiante, sizeof(Estudiante), 1, archivo); // Modifica al estudiante objetivo
	}
	else
	{
		cout << "Error en la creacion / lectura del archivo" << endl;
	}

	fclose(archivo);
}