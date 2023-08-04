// llamando al archivo cabecera
#include "funciones.hpp"
#include "functionsDataFisico.hpp"
#include <iostream>
using namespace std;

int main()
{
    fflush(stdin);
    bool condition = true;
    Estudiante dataStudent;

    cout << "Seleccionar una opcion" << endl;
    do
    {
        int number = NavegacionMain();
        cout << number << endl;
        // system("cls");
        switch (number)
        {
        case 1:
            system("cls");
            ValidarEstudiantes(verArchivo);
            system("pause");
            break;
        case 2:
            dataStudent = CrearEstudiantes();
            system("cls");
            cout << dataStudent.name << " " << dataStudent.password << endl;
            GuardarEstudiante(dataStudent);
            system("pause");
            break;
        case 3:
            cout << "SE SALIO EXITOSAMENTE" << endl;

            // TEST DEBUSCAR ESTUDIANTE
            buscarEstudianteA("jhon");
            cout << "============" << endl;
            // cout << buscarEstudianteB("jhon");
            //------------------------
            system("pause");
            condition = false;
            break;
        default:
            cout << "ESTA OPCION NO EXISTE" << endl;
            system("pause");
            break;
        };
    } while (condition);

    return 0;
};
