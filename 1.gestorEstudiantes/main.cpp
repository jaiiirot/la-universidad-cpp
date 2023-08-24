// llamando al archivo cabecera
#include "interfaz.hpp"
#include "controlador.hpp"
#include <iostream>
using namespace std;

int main()
{
    bool condition = true;
    int countData = 0;
    do
    {
        cantidadDeEstudiantes(countData);
        cout << "SELECIONAR UNA OPCION" << endl;
        switch (NavegacionMain())
        {
        case 1:
            INICIARSESION();
            break;
        case 2:
            REGISTRARSE();
            break;
        case 3:
            EXIT(condition);
            break;
        case 4:
            MOSTRARESTUDIANTES(countData);
            break;
        default:
            DEFAULT(condition);
            break;
        };

    } while (condition);

    return 0;
};