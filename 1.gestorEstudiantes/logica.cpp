#include <iostream>
#include <conio.h>
#include <cstdio>
using namespace std;
#include "logica.hpp"

/*
Se define la funcion "ExisteEstudiante" y se manda como parametros:
    . "existencia" - dato bool mandado por referencia, para que se verifique la existencia del alumno en el archivo.
    . "datosEstudiante" - data Estudiante, contenedor de los datos a verificar.
*/
Estudiante existeEstudiante(bool &exist, Estudiante datosEstudiante)
{
    fflush(stdin);
    Estudiante validarEstudiante;
    FILE *archivo = fopen("estudiantes.dat", "rb");
    if (archivo != NULL)
    {
        while (fread(&validarEstudiante, sizeof(Estudiante), 1, archivo) == 1)
        {
            if (strcmp(validarEstudiante.email, datosEstudiante.email) == 0 && strcmp(validarEstudiante.password, datosEstudiante.password) == 0)
            {
                exist = true;
            }
            else
            {
                exist = false;
            }
        }
        fclose(archivo);
    }

    return validarEstudiante;
}
/*
Se define la funcion "Registrar Estudiantes" y se manda como parametros:
    . "newDataStudent" - tipo de dato estructura, donde se obtienen los datos del nuevo usuario para luego poder validar y guardar susa datos.
*/
void RegistrarEstudiante(Estudiante newDataStudent)
{
    cout << newDataStudent.password << endl;
    cout << newDataStudent.creditos << endl;
    FILE *archivo = fopen("estudiantes.dat", "ab");
    if (archivo != NULL)
    {
        fwrite(&newDataStudent, sizeof(Estudiante), 1, archivo);
        fclose(archivo);
    }
    else
    {
        cout << "==========================" << endl;
        cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
        cout << "==========================" << endl;
    }
}
/*

*/
void IniciarSesionEstudiante(Estudiante student)
{
    cout << "===========================================" << endl;
    cout << "===========================================" << endl;
    cout << "ESTOS SON DATOS DE: " << student.name << endl;
    cout << "===========================================" << endl;
    cout << "== Nombre: " << student.name << endl;
    cout << "== Apellido: " << student.lastname << endl;
    cout << "== Email: " << student.email << endl;
    cout << "== Contrasenia: " << student.password << endl;
    cout << "== Creditos: " << student.creditos << endl;
    cout << "===========================================" << endl;
    cout << "===========================================" << endl;
}
/*

*/
void MostrarEstudiante(int cantidadDeDatos)
{
    system("cls");
    Estudiante file[cantidadDeDatos];
    FILE *archivoAbrir = fopen("estudiantes.dat", "rb");
    if (archivoAbrir != NULL)
    {

        int estado = fread(&file, sizeof(Estudiante), cantidadDeDatos, archivoAbrir);
        if (estado != cantidadDeDatos)
        {
            cout << "ERROR AL ABRIR" << endl;
        }
        else
        {
            for (int i = 0; i < cantidadDeDatos; i++)
            {
                cout << "=====================================" << endl;
                cout << "ESTOS SON DATOS DE: " << file[i].name << endl;
                cout << " Nombre: " << file[i].name << endl;
                cout << " Apellido: " << file[i].lastname << endl;
                cout << " Email: " << file[i].email << endl;
                cout << " Pasword: " << file[i].password << endl;
                cout << " creditos:" << file[i].creditos << endl;
                cout << "=====================================" << endl;
            };
            fclose(archivoAbrir);
        }
    }
}
/*

*/
void cantidadDeEstudiantes(int &cantidadDeDatos)
{
    system("cls");
    FILE *archivo = fopen("estudiantes.dat", "rb");
    if (archivo != NULL)
    {
        cantidadDeDatos = 0;
        Estudiante estudiante;
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
        {
            cantidadDeDatos++;
        }
        fclose(archivo);
    }
    cout << "-------" << endl;
    cout << " | " << cantidadDeDatos << " | " << endl;
    cout << "-------" << endl;
};