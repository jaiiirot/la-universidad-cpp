#include <iostream>
#include "interfaz.hpp"
#include "logica.hpp"
#include "controlador.hpp"

void INICIARSESION()
{
    system("cls");
    Estudiante dataUser;
    dataUser = IngresarDatos();
    bool condition = false;
    dataUser = existeEstudiante(condition, dataUser);

    if (condition)
    {
        IniciarSesionEstudiante(dataUser);
    }
    else
    {
        cout << "CORREO INVALIDO" << endl;
    }
    system("pause");
}

void REGISTRARSE()
{
    system("cls");
    Estudiante dataUser;
    bool condition = false;
    dataUser = CrearEstudiante();
    dataUser.creditos = 1000;

    existeEstudiante(condition, dataUser);
    if (!condition)
    {
        RegistrarEstudiante(dataUser);
        cout << "-------" << endl;
        cout << "ESTUDIANTE INGRESADO CORRECTAMENTE" << endl;
        cout << "-------" << endl;
    }
    else
    {
        cout << "NO SE PUEDE REGISTRAR UN MISMO USUARIO" << endl;
    }
    system("pause");
}

void EXIT(bool &condition)
{
    cout << "SE SALIO EXITOSAMENTE" << endl;
    system("pause");
    condition = false;
}

void MOSTRARESTUDIANTES(int countData)
{
    MostrarEstudiante(countData);
    system("pause");
}
void DEFAULT(bool &condition)
{
    cout << "ESTA OPCION NO EXISTE" << endl;
    system("pause");
    condition = false;
}