#include <iostream>
#include <cstring>
#include "beneficio.h"

using namespace std;

void consultarBeneficios(int creditos){ //Obtiene los beneficios que puede comprar el estudiante y los devuelve en un array

	FILE* archivo = fopen("beneficios.dat", "rb");
	Beneficio beneficio;

	cout << "\nBeneficios(Id, Nombre, Costo): \n" << endl;

	if (archivo != NULL){
		while (fread(&beneficio, sizeof(Beneficio), 1, archivo) == 1){//Busca cuantos elemento puede comprar el estudiante o los muestra todos
			if (beneficio.costo < creditos or creditos == -1){
				cout << beneficio.id << "\t" << beneficio.nombre << "\t" << beneficio.costo << endl;
			}
		}
	}

	fclose(archivo);
}

int costeBeneficio(int id, int creditos)
{
	FILE* archivo = fopen("beneficios.dat", "a+b");
	fseek(archivo, 0, SEEK_SET);

	if(archivo != NULL)
	{
		Beneficio beneficio;
		while (fread(&beneficio, sizeof(Beneficio), 1, archivo) == 1) // Verifica que el beneficios exista
		{
			if(beneficio.id == id and beneficio.costo < creditos)
			{
				return beneficio.costo;
			}
			if(beneficio.id > id)
			{
				break;
			}
		}
	}

	return -1;
}
