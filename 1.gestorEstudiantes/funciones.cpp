#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>

using namespace std;

struct Estudiantes
{
    char name[25];
    char lastname[25];
    string email;
    string password;
};

Estudiantes CrearEstudiantes()
{
    Estudiantes NuevoUsuario;
    bool condition = true;
    do
    {
        int validacionOption;
        cout << "=======================================================" << endl;
        cout << "Para registrarte ingresa tus datos en la parte de abajo" << endl;

        fflush(stdin);
        cout << "ingresar solo tu nombre: ";
        cin.getline(NuevoUsuario.name, 25, '\n');

        cout << "ingresar solo tu apellido: ";
        cin.getline(NuevoUsuario.lastname, 25, '\n');

        cout << "ingresar tu email: ";
        cin >> NuevoUsuario.email;

        cout << "ingresar tu contraseña: ";
        cin >> NuevoUsuario.password;

        cout << "-----------------" << endl;
        cout << "nombre:" << NuevoUsuario.name << endl;
        cout << "apellido:" << NuevoUsuario.lastname << endl;
        cout << "email:" << NuevoUsuario.email << endl;
        cout << "apellido:" << NuevoUsuario.password << endl;
        cout << "-----------------" << endl;

        cout << "los datos son correctos?" << endl;
        cout << "1: SI" << endl;
        cout << "2: NO" << endl;
        cin >> validacionOption;
        if (validacionOption == 1)
        {

            condition = true;
        }
        else
        {
            condition = true;
        };
    } while (condition);

    return NuevoUsuario;
};

void ValidarEstudiantes()
{
    cout << "Vamos a validad tus datos" << endl;
}

void NavegacionMain(bool &condition)
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
    if (number == 1)
    {
        ValidarEstudiantes();
        condition = false;
    }
    else if (number == 2)
    {
        CrearEstudiantes();
        condition = false;
    }
    else
    {
        condition = false;
    };
};
