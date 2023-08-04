#include <iostream>
using namespace std;
#include "functionsDataFisico.hpp"

void GuardarEstudiante(Estudiante student)
{
    FILE *archivo = fopen("estudiantes_binarios.dat", "wb");
    if (archivo != NULL)
    {
        fwrite(&student, sizeof(Estudiante), 1, archivo);
        fclose(archivo);
        cout << "Archivo creado exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo crear el archivo." << endl;
    }
}

Estudiante verArchivo()
{
    Estudiante file;
    Estudiante dataFile;
    FILE *archivo = fopen("estudiantes_binarios.dat", "rb");
    if (archivo != NULL)
    {
        // SE HACE LA IGUALCACION YA QUE SI ESTA BIEN DEVUELVE LA CANTIDAD QUE SE REPITIO PERO SI ESTA MAL SALE UN NUMERO NEGATIVO
        int estado = fread(&file, sizeof(Estudiante), 1, archivo);
        if (estado != 1)
        {
            cout << "ERROR AL ABRIR" << endl;
        }
        else
        {
            dataFile = file;
            fclose(archivo);
        }
    }
    else
    {
        cout << "datos: " << &file << " " << sizeof(&file) << endl;
        cout << "No se pudo abrir el archivo para lectura." << endl;
        dataFile = {};
    }
    return dataFile;
}

int buscarEstudianteA(const char *nombreBuscado)
{
    FILE *archivo = fopen("estudiantes_binarios.dat", "rb");
    if (archivo != NULL)
    {
        Estudiante estudiante;
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
        {
            if (strcmp(estudiante.name, nombreBuscado) == 0)
            {
                cout << "Estudiante encontrado:" << endl;
                cout << "nombre: " << estudiante.name << endl;
                cout << "apellido: " << estudiante.lastname << endl;
                cout << "email: " << estudiante.email << endl;
                cout << "password: " << estudiante.password << endl;
                fclose(archivo);
                return 1;
            }
        }
        fclose(archivo);
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
    return 0;
}

// int buscarEstudianteB(char *codigoBuscado)
// {
//     FILE *archivo = fopen("estudiantes_binarios.dat", "rb");
//     if (archivo != NULL)
//     {
//         Estudiante estudiante;
//         fseek(archivo, *codigoBuscado * sizeof(Estudiante), SEEK_SET);
//         if (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
//         {
//             cout << "Estudiante encontrado:" << endl;
//             cout << "nombre: " << estudiante.name << endl;
//             cout << "apellido: " << estudiante.lastname << endl;
//             cout << "email: " << estudiante.email << endl;
//             cout << "password: " << estudiante.password << endl;
//             fclose(archivo);
//             return 1;
//         }
//         fclose(archivo);
//     }
//     else
//     {
//         cout << "No se pudo abrir el archivo para lectura." << endl;
//     }
//     return 0;
// }