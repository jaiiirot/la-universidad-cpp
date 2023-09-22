#include <iostream>
#include <conio.h>
#include <cstring>
#include "logica.hpp"
#include "interfaz.hpp"
using namespace std;
/*

 */
Beneficio existeBeneficio(bool &exist, Beneficio dataBeneficio)
{
    Beneficio itemBeneficio;
    FILE *archivo = fopen("beneficios.dat", "rb");
    if (archivo != NULL)
    {
        while (fread(&itemBeneficio, sizeof(Beneficio), 1, archivo) == 1)
        {
            if (strcmp(itemBeneficio.nombre, dataBeneficio.nombre) == 0)
            {
                exist = true;
            }
            else
            {
                exist = false;
            };
        };
        fclose(archivo);
    };

    return itemBeneficio;
};
/*

 */
void agregarBeneficio(Beneficio dataBenefit)
{
    dataBenefit.id = 1;
    FILE *archivo = fopen("beneficios.dat", "a+b");
    if (archivo != NULL)
    {
        MostrarBeneficios(dataBenefit);
        fwrite(&dataBenefit, sizeof(Beneficio), 1, archivo);
        fclose(archivo);
    }
    else
    {
        cout << "NO SE PUDO AGREGAR EL BENEFICIO" << endl;
    };
};
/*

 */
void eliminarBeneficio(int cantidadBeneficios)
{
    string nombre_buscado;
    cout << "INGRESAR EL NOMBRE DEL BENEFICIO A ELIMINAR" << endl;
    cin.ignore(10000, '\n');
    getline(cin, nombre_buscado);
    Beneficio aux[cantidadBeneficios];
    int count = 0;
    FILE *archivo = fopen("beneficios.dat", "rb");
    if (archivo != NULL)
    {
        Beneficio temp;
        while (fread(&temp, sizeof(Beneficio), 1, archivo) == 1)
        {
            if (temp.nombre != nombre_buscado)
            {
                aux[count] = temp;
                count++;
            }
        }
        fclose(archivo);
    }
    else
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
    }
    archivo = fopen("beneficios.dat", "wb");
    archivo = fopen("beneficios.dat", "a+b");
    if (archivo != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            fwrite(&aux[i], sizeof(Beneficio), 1, archivo);
        }
        fclose(archivo);
    }
}
/*

"strcpy" es una función que se utiliza para copiar cadenas de caracteres
desde una ubicación de memoria fuente a una ubicación de memoria destino.
 .- char* strcpy(char* destino, const char* fuente);
    .-- destino: Puntero al arreglo de caracteres de destino donde se copiará la
                cadena fuente.
    .--fuente: Puntero al arreglo de caracteres fuente que se copiará en el destino.
 */
void modificarBeneficio(string nombre_buscado)
{
    FILE *archivo = fopen("beneficios.dat", "r+b");
    if (archivo != NULL)
    {
        Beneficio dataBenefit;
        bool encontrado = false;
        int count = 0;

        while (!encontrado && fread(&dataBenefit, sizeof(Beneficio), 1, archivo) == 1)
        {
            if (dataBenefit.nombre == nombre_buscado)
            {
                encontrado = true;
                int option;
                MostrarBeneficios(dataBenefit);
                option = MostrarOpcionesModificarBeneficio();
                dataBenefit = MostrarOpcionesModificacion(option, dataBenefit);

                fseek(archivo, sizeof(Beneficio) * count, SEEK_SET);
                fwrite(&dataBenefit, sizeof(Beneficio), 1, archivo);
                cout << "SE ACTUALIZO" << endl;
                count = 0;
            }
            count++;
        }
        if (!encontrado)
        {
            system("cls");
            cout << "NO SE ENCONTRO EL NOMBRE DEL BENEFICIO" << endl;
        }
        fclose(archivo);
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura y escritura." << endl;
    }
};
/*

 */
void mostrarBeneficios()
{
    Beneficio dataBenefit;
    FILE *archivo = fopen("beneficios.dat", "rb");
    if (archivo != NULL)
    {
        cout << "================================" << endl;
        cout << "( 0 ) desactivado | ( 1 ) activo" << endl;
        cout << "================================" << endl;
        while (fread(&dataBenefit, sizeof(dataBenefit), 1, archivo) == 1)
        {
            MostrarBeneficios(dataBenefit);
        };
    }
}
/*

 */
void countBeneficios(int &countBenefit)
{
    Beneficio dataBenefit;
    countBenefit = 0;
    FILE *archivo = fopen("beneficios.dat", "rb");
    if (archivo != NULL)
    {
        while (fread(&dataBenefit, sizeof(dataBenefit), 1, archivo) == 1)
        {
            countBenefit++;
        };
    }
    cout << "=========" << endl;
    cout << "Cantidad de beneficios: " << countBenefit << endl;
    cout << "=========" << endl;
}
