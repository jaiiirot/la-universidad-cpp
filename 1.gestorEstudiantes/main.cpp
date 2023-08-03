#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
// llamando al archivo cabecera
#include "funciones.hpp"
using namespace std;

int main()
{
    cout << "Seleccionar una opcion" << endl;
    bool condition = true;
    do
    {
        NavegacionMain(condition);

    } while (condition);
    

    return 0;
};
