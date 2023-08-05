#include <iostream>
#include <fstream>
using namespace std;
#include "functionsDataFisico.hpp"

void GuardarEstudiante(Estudiante student[], int cantidad, int (*buscarEstudianteFor)(const char *, int))
{

    FILE *archivo = fopen("estudiantes.dat", "wb");
    for (int i = 0; i < cantidad; i++)
    {
        system("cls");
        fflush(stdin);
        if (archivo != NULL)
        {
            fwrite(&student[i], sizeof(Estudiante), cantidad, archivo);
            fclose(archivo);
            cout << "Archivo creado exitosamente." << endl;
            cout << "======================" << endl;
        }
        else
        {
            cout << "No se pudo crear el archivo." << endl;
        }
    };

    Estudiante file[cantidad];
    FILE *archivoAbrir = fopen("estudiantes.dat", "rb");
    if (archivoAbrir != NULL)
    {
        // SE HACE LA IGUALCACION YA QUE SI ESTA BIEN DEVUELVE LA CANTIDAD QUE SE REPITIO PERO SI ESTA MAL SALE UN NUMERO NEGATIVO
        int estado = fread(&file, sizeof(Estudiante), cantidad, archivoAbrir);
        cout << estado << endl;
        if (estado != cantidad)
        {
            cout << "ERROR AL ABRIR" << endl;
        }
        else
        {
            cout << cantidad << endl;
            cout << estado << endl;
            // Estos son los datos
            for (int i = 0; i < cantidad; i++)
            {
                cout << "ESTOS SON DATOS DE: " << file[i].name << endl;
                cout << "Nombre: " << file[i].name << ", Apellido: " << file[i].lastname << ", Email: " << file[i].email << ", Pasword: " << file[i].password << endl;
            };
            fclose(archivoAbrir);
        }

        system("pause");
        system("cls");
        char buscarANombre[30];
        cout << "ingresa el nombre qui quieres buscar" << endl;
        cin.getline(buscarANombre, 30, '\n');
        int response = buscarEstudianteFor(buscarANombre, cantidad);
        cout << response << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}

// void GuardarEstudiante(Estudiante student)
// {
//     FILE *archivo = fopen("estudiantes_binarios.dat", "wb");
//     if (archivo != NULL)
//     {
//         fwrite(&student, sizeof(Estudiante), 1, archivo);
//         fclose(archivo);
//         cout << "Archivo creado exitosamente." << endl;
//     }
//     else
//     {
//         cout << "No se pudo crear el archivo." << endl;
//     }
// }

Estudiante verArchivo()
{
    Estudiante file;
    Estudiante dataFile;
    FILE *archivo = fopen("estudiantes.dat", "rb");
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

// TEESTEETETETET

/* Estudiante verArchivo()
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
 */

int buscarEstudianteFor(const char *nombreBuscado, int cantidad)
{
    int vueltas = 0;
    FILE *archivo = fopen("estudiantes.dat", "rb");
    if (archivo != NULL)
    {
        Estudiante estudiante;
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
        {
            if (strcmp(estudiante.name, nombreBuscado) == 0)
            {
                system("pause");
                system("cls");
                cout << "==================================" << endl;
                cout << "Estudiante encontrado:" << endl;
                cout << "nombre: " << estudiante.name << endl;
                cout << "apellido: " << estudiante.lastname << endl;
                cout << "email: " << estudiante.email << endl;
                cout << "password: " << estudiante.password << endl;
                fclose(archivo);
                return 0;
            }
            else
            {
                vueltas++;
                if (vueltas == cantidad)
                {
                    cout << "No existe: " << nombreBuscado << endl;
                }
            }
        }
        fclose(archivo);
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
    return -1;
}