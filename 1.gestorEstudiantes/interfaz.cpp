#include "interfaz.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
using namespace std;
struct Estudiante
{
    char name[25];
    char lastname[25];
    char email[60];
    char password[60];
    int creditos;
    int Id;
};

int NavegacionMain()
{
    int number;
    cout << "====================" << endl;
    cout << "1: Iniciar Sesion" << endl;
    cout << "2: Registrarse" << endl;
    cout << "3: cerrar" << endl;
    cout << "-------------------" << endl;
    cout << "Para realizar una tarea ingresar el numero correspondiente" << endl;
    cout << "====================" << endl;
    cin >> number;
    return number;
};
/*
    La funcion "IngresarDatos" pide los datos al usuario para poder validarlo.
*/
Estudiante IngresarDatos()
{

    Estudiante user;
    bool condition = true;
    int validacionOption;
    cout << "=========================================" << endl;
    cout << "=============== INICIAR SESION ==========" << endl;
    cout << "=========================================" << endl;
    do
    {
        fflush(stdin);
        cout << "ingresar tu email: ";
        cin.getline(user.email, 60, '\n');

        cout << "ingresar tu contrasenia: ";
        cin.getline(user.password, 60, '\n');

        cout << "los datos son correctos?" << endl;
        cout << "1: SI" << endl;
        cout << "2: NO" << endl;
        cout << "=======================================================" << endl;
        cin >> validacionOption;

        switch (validacionOption)
        {
        case 1:
            cout << "CARGANDO.........." << endl;
            condition = false;
            break;
        case 2:
            cout << "RESET FORMULARIO" << endl;
            break;
        default:
            cout << "ESTA OPCION NO EXISTE \n SE RESETEARA LOS DATOS INGRESADOS" << endl;
            break;
        }
    } while (condition);

    return user;
}

Estudiante CrearEstudiante()
{
    Estudiante newUser;
    bool condition = true;

    int option;
    cout << "=======================================================" << endl;
    cout << "Para registrarte ingresa tus datos en la parte de abajo" << endl;
    do
    {
        // funcion que sirve para liberar espacio en el buffer (buffer: espacio de memoria en el que se almacenan datos de manera temporal.)
        fflush(stdin);
        cout << "ingresar solo tu nombre: ";
        cin.getline(newUser.name, 25, '\n');

        cout << "ingresar solo tu apellido: ";
        cin.getline(newUser.lastname, 25, '\n');

        cout << "ingresar tu email: ";
        cin.getline(newUser.email, 60, '\n');

        cout << "ingresar tu contrasenia: ";
        cin.getline(newUser.password, 60, '\n');

        cout << "-----------------" << endl;
        cout << "nombre:" << newUser.name << endl;
        cout << "apellido:" << newUser.lastname << endl;
        cout << "email:" << newUser.email << endl;
        cout << "password:" << newUser.password << endl;
        cout << "-----------------" << endl;

        cout << "los datos son correctos?" << endl;
        cout << "1: SI" << endl;
        cout << "2: NO" << endl;
        cout << "=======================================================" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            condition = false;
            break;
        case 2:
            cout << "RESET FORMULARIO" << endl;
            break;
        default:
            cout << "ESTA OPCION NO EXISTE \n SE RESETEARA LOS DATOS INGRESADOS" << endl;
            break;
        }
    } while (condition);

    return newUser;
};
