#include <iostream>
#include <cstring>
#include "estudiante.h"
#include "beneficio.h"

using namespace std;

int main()
{
    char mail[60];
    char contraseña[60];

    cout << "\t\t\t\tBENEFICIOS UTN" << endl;
    cout << "\t\t\t\t--------------" << endl;

    bool login = false;

    while(!login){
        cout << "\n\tMail: ";
        cin.getline(mail, sizeof(mail));

        cout << "\n\tContraseña: ";
        cin.getline(contraseña, sizeof(contraseña));

        Estudiante estudiante = validarEstudiante(mail, contraseña);

        if (estudiante.creditos == -1){
            cout << "\n\tEl mail o la contraseña son incorrectos. Por favor, ingreselos de nuevo" << endl; 
        }
        else{
            login = true;
            cout << "\n\tBienvenido, "; cout << estudiante.name; cout << " "; cout << estudiante.lastname << endl;
        }
    }

    return 0;
}