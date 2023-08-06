// llamando al archivo cabecera
#include "funciones.hpp"
#include "functionsDataFisico.hpp"
#include <iostream>
using namespace std;

int main()
{
    bool condition = true;
    int cantidadDeDatos = 1;
    cout << "Seleccionar una opcion" << endl;
    Estudiante DataStudent;
    do
    {
        cantidadDeEstudiantes(cantidadDeDatos);
        switch (NavegacionMain())
        {
        case 1:
            system("cls");
            DataStudent = IngresarDatos();
            if (VerificarEstudiantes(DataStudent, ValidarEstudiantes))
            {
                cout << "SE INGRESO EXITOSAMENTE" << endl;
            };
            system("pause");
            break;
        case 2:
            DataStudent = CrearEstudiante();
            system("cls");
            RegistrarEstudiante(DataStudent, ValidarEstudiantes);
            system("pause");
            break;
        case 3:
            cout << "SE SALIO EXITOSAMENTE" << endl;
            system("pause");
            condition = false;
            break;
        case 4:
            MostrarEstudiante(cantidadDeDatos);
            system("pause");
            break;
        default:
            cout << "ESTA OPCION NO EXISTE" << endl;
            system("pause");
            condition = false;
            break;
        };
    } while (condition);

    return 0;
};