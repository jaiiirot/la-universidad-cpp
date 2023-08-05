#include "funciones.hpp"
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
};

int NavegacionMain()
{
    int number;
    cout << "====================" << endl;
    cout << "1: iniciar Sesion" << endl;
    cout << "2: Registrarse" << endl;
    cout << "3: cerrar" << endl;
    cout << "-------------------" << endl;
    cout << "Para realizar una tarea ingresar el numero correspondiente" << endl;
    cout << "====================" << endl;
    cin >> number;
    return number;
};

Estudiante CrearEstudiante()
{
    Estudiante newUser;
    bool condition = true;

    int validacionOption;
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
        cin >> validacionOption;

        switch (validacionOption)
        {
        case 1:
            cout << "REGISTRO EXITO" << endl;
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



void ValidarEstudiantes(Estudiante (*verArchivo)())
{
    fflush(stdin);
    Estudiante file = verArchivo();
    cout << "datos: " << file.name << file.lastname << file.email << file.password << endl;
}