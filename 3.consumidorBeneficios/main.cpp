#include <iostream>
#include <cstring>
#include "estudiante.h"
#include "beneficio.h"

using namespace std;

int main()
{
    Estudiante estudiante;

    char mail[60];
    char contraseña[60];
    int id;
    int coste;

    cout << "\t\t\t\tBENEFICIOS UTN" << endl;
    cout << "\t\t\t\t--------------" << endl;

    bool login = false;

    while(!login){
        cout << "\n\tMail: ";
        cin.getline(mail, sizeof(mail));

        cout << "\n\tContraseña: ";
        cin.getline(contraseña, sizeof(contraseña));

        estudiante = validarEstudiante(mail, contraseña);

        if (estudiante.creditos == -1){
            cout << "\n\tEl mail o la contraseña son incorrectos. Por favor, ingreselos de nuevo" << endl; 
        }
        else{
            login = true;
            cout << "\n\tBienvenido, "; cout << estudiante.name; cout << " "; cout << estudiante.lastname << endl;
        }
    }

    cout << "\nA continuacion se le mostrara los beneficios a los que puede acceder: " << endl;

    consultarBeneficios(estudiante.creditos);

    cout << "\nSeleccione el Id del beneficio al que desea acceder: ";
    cin >> id;

    coste = costeBeneficio(id, estudiante.creditos);

    if(coste != -1)
    {
        estudiante.creditos -= coste;
        modificarEstudiante(estudiante);
        cout << "\nEl beneficio ha sido adquirido con exito" << endl;
    }
    else
    {
        cout << "\nEl beneficio al que quiso acceder no se encuentra disponible o no existe" << endl;
    }

    return 0;
}