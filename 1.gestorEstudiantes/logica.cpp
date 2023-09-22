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
Estudiante existeEstudiante(bool &exist, Estudiante data)
{
    fflush(stdin);
    FILE *archivo = fopen("estudiantes.dat", "rb");
    if (archivo != NULL)
    {
        Estudiante validar;
        while (fread(&validar, sizeof(Estudiante), 1, archivo) == 1)
        {
            if (strcmp(validar.email, data.email) == 0)
            {
                exist = true;
                if (strcmp(validar.password, data.password) == 0)
                {
                    exist = true;
                    return validar;
                }
            }
        }
        fclose(archivo);
    }
    return data;
}
/*
Se define la funcion "Registrar Estudiantes" y se manda como parametros:
    . "newDataStudent" - tipo de dato estructura, donde se obtienen los datos del nuevo usuario para luego poder validar y guardar susa datos.
*/
void RegistrarEstudiante(Estudiante dataStudent)
{
    FILE *archivo = fopen("estudiantes.dat", "rb");
    if (archivo != NULL)
    {
        Estudiante temp;
        fseek(archivo, sizeof(Estudiante), SEEK_END);
        fread(&temp, sizeof(Estudiante), 1, archivo);
        dataStudent.Id = temp.Id + 1;
    }
    else
    {
        dataStudent.Id = 1;
    }
    dataStudent.creditos = 1000;
    archivo = fopen("estudiantes.dat", "a+b");
    if (archivo != NULL)
    {
        fwrite(&dataStudent, sizeof(Estudiante), 1, archivo);
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
    cout << "== ID: " << student.Id << endl;
    cout << "== Nombre: " << student.name << endl;
    cout << "== Apellido: " << student.lastname << endl;
    cout << "== Email: " << student.email << endl;
    cout << "== Contrasenia: " << student.password << endl;
    cout << "== Creditos: " << student.creditos << endl;
    cout << "===========================================" << endl;
    cout << "===========================================" << endl;
}