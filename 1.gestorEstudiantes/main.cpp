// llamando al archivo cabecera
#include "interfaz.hpp"
#include "controlador.hpp"
#include <iostream>
using namespace std;

int main()
{
    bool condition = true;
    do
    {
        system("cls");
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
        default:
            DEFAULT(condition);
            break;
        };

    } while (condition);

    return 0;
};