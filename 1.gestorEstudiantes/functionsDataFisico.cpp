#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
#include "functionsDataFisico.hpp"

Estudiante ValidarEstudiantes(bool &existencia, Estudiante datosEstudiante, string option)
{
    Estudiante validarEstudiante;
    fflush(stdin);
    FILE *archivo = fopen("estudiantes.dat", "rb");
    if (archivo != NULL)
    {
        while (fread(&validarEstudiante, sizeof(Estudiante), 1, archivo) == 1)
        {
            if (option == "InicioSesion")
            {
                if (strcmp(validarEstudiante.email, datosEstudiante.email) == 0 && strcmp(validarEstudiante.password, datosEstudiante.password) == 0)
                {
                    existencia = true;
                    return validarEstudiante;
                }
            }
            if (option == "Registrarse")
            {
                if (strcmp(validarEstudiante.email, datosEstudiante.email) != 0)
                {
                    existencia = true;
                }
                else
                {
                    cout << "ESTE GMAIL DE USUARIO YA ESTA VINCULADO A OTRA CUENTA O YA ESTAS REGISTRADO" << endl;
                    existencia = false;
                }
            }
        }
        fclose(archivo);
    }
    else
    {
        cout << "===============================================" << endl;
        existencia = true;
    }
    return validarEstudiante;
}

void RegistrarEstudiante(Estudiante newDataStudent, Estudiante (*ValidarEstudiantes)(bool &, Estudiante, string))
{
    bool existe = false;
    ValidarEstudiantes(existe, newDataStudent, "Registrarse");

    FILE *archivo = fopen("estudiantes.dat", "a+");
    fflush(stdin);
    if (archivo != NULL && existe)
    {
        newDataStudent.creditos = 1000;
        fwrite(&newDataStudent, sizeof(Estudiante), 1, archivo);
        fclose(archivo);
        cout << "-------" << endl;
        cout << "ESTUDIANTE INGRESADO CORRECTAMENTE" << endl;
        cout << "-------" << endl;
    }
    else
    {
        cout << "NO SE PUEDE REGISTRAR UN MISMO USUARIO" << endl;
    }
}

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
                cout << "ESTOS SON DATOS DE: " << file[i].name << endl;
                cout << ", Nombre: " << file[i].name << ", Apellido: " << file[i].lastname << ", Email: " << file[i].email << ", Pasword: " << file[i].password << ", creditos:" << file[i].creditos << endl;
            };
            fclose(archivoAbrir);
        }
    }
}

bool VerificarEstudiantes(Estudiante student, Estudiante (*ValidarEstudiantes)(bool &, Estudiante, string))
{
    bool ingreso = false;
    Estudiante DataStudent;
    DataStudent = ValidarEstudiantes(ingreso, student, "InicioSesion");
    if (ingreso)
    {
        cout << "ESTOS SON DATOS DE: " << DataStudent.name << endl;
        cout << "Nombre: " << DataStudent.name << "\n Apellido: " << DataStudent.lastname << "\n Email: " << DataStudent.email << "\n Pasword: " << DataStudent.password << "\n creditos:" << DataStudent.creditos << endl;
    }

    return ingreso;
}

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