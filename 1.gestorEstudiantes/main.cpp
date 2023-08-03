#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>

using namespace std;

struct Estudiantes
{
    string name;
    string lastname;
    string email;
    string password;
};

// Mostrar Opciones
void NavegacionMain();
void NavegacionRegistrarse();

// Crear/registrarse
void CrearEstudiantes();
string CrearDatos(Estudiantes);
// Validar/iniciar sesion
void ValidarEstudiantes()
{
    cout << "Vamos a validad tus datos" << endl;
}

int main()
{
    cout << "Seleccionar una opcion" << endl;
    bool condition = true;
    do
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
    } while (condition);

    return 0;
};

void CrearEstudiantes()
{
    Estudiantes NuevoUsuario;
    bool condition = true;
    do
    {
        string validacion;
        char name[20];
        char lastname[20];
        int validacionOption;
        cout << "=======================================================" << endl;
        cout << "=======================================================" << endl;
        cout << "Para registrarte ingresa tus datos en la parte de abajo" << endl;

        cout << "ingresar solo tu nombre: ";
        cin.getline(name, sizeof(name), '\n');

        cout << "ingresar solo tu apellido: ";
        cin.getline(lastname, sizeof(lastname), '\n');

        cout << "ingresar tu email: ";
        getline(cin, NuevoUsuario.email);

        cout << "ingresar tu contraseña: ";
        getline(cin, NuevoUsuario.email);

        cout << "-----------------" << endl;
        cout << "nombre:" << name << endl;
        cout << "apellido:" << lastname << endl;
        cout << "email:" << NuevoUsuario.name << endl;
        cout << "apellido:" << NuevoUsuario.name << endl;
        cout << "-----------------" << endl;

        cout << "los datos son correctos?" << endl;
        cout << "1: SI" << endl;
        cout << "2: NO" << endl;
        cin >> validacionOption;
        if (validacionOption == 1)
        {
            condition = false;
        }
        else
        {
            condition = true;
        };
    } while (condition);
};