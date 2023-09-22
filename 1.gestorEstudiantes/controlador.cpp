#include <iostream>
#include "interfaz.hpp"
#include "logica.hpp"
#include "controlador.hpp"

/*
    Esta es la funcion "IniciarSesion"
    system("cls"): borrar lo que estaba antes en el terminal.
    Estudiante dataUser: tipo de dato Estudiante, sirve para manejar los datos de un usuario existente.
    dataUser = IngresarDatos():
    if(condition}{...} : si es true: inicia sesion °°°° false: muestra "correo invalido "
*/
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
    existeEstudiante(condition, dataUser);
    if (condition)
    {
        cout << "NO SE PUEDE REGISTRAR UN MISMO USUARIO" << endl;
    }
    else
    {
        RegistrarEstudiante(dataUser);
        cout << "-------" << endl;
        cout << "ESTUDIANTE REGISTRADO CORRECTAMENTE" << endl;
        cout << "-------" << endl;
    }
    system("pause");
}

void EXIT(bool &condition)
{
    cout << "SE SALIO EXITOSAMENTE" << endl;
    system("pause");
    condition = false;
}

void DEFAULT(bool &condition)
{
    cout << "ESTA OPCION NO EXISTE" << endl;
    system("pause");
    condition = false;
}