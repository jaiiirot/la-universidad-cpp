// llamando al archivo cabecera
#include "funciones.hpp"
#include "functionsDataFisico.hpp"
#include <iostream>
using namespace std;

int main()
{
    fflush(stdin);
    bool condition = true;
    int cantidadDeEstudiantes = 3;
    Estudiante dataStudent[cantidadDeEstudiantes];

    cout << "Seleccionar una opcion" << endl;
    do
    {
        int number = NavegacionMain();
        switch (number)
        {
        case 1:
            system("cls");
            ValidarEstudiantes(verArchivo);
            system("pause");
            break;
        case 2:
            // dataStudent = CrearEstudiante();
            // system("cls");
            // cout << dataStudent.name << " " << dataStudent.password << endl;
            // GuardarEstudiante(dataStudent);

            dataStudent[0] = {"leidy yhesenia", "chuca", "leidy2218@gmail.com", "jairotumiri"};
            dataStudent[1] = {"thiago moises", "tumiri cuellar", "thiagotc@gmail.com", "thiagotumiri"};
            dataStudent[2] = {"jhon jairo", "tumiri cuellar", "jtumiricuellar@gmail.com", "Leidy2218"};
            GuardarEstudiante(dataStudent, cantidadDeEstudiantes, buscarEstudianteFor);
            // system("pause");
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
