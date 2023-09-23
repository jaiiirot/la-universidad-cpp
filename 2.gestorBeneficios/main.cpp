#include <iostream>
#include "interfaz.hpp"
#include "logica.hpp"
#include "controlador.hpp"
using namespace std;

int main()
{
    bool condition = true;
    int countBenefit = 0;
    do
    {
        system("cls");
        countBeneficios(countBenefit);
        cout << "SELECCIONAR UNA OPCION" << endl;
        switch (Navegacion())
        {
        case 1:
            LISTAR_BENEFICIOS();
            break;
        case 2: 
            AGREGAR_BENEFICIOS();
            break;
        case 3:
            ELIMINAR_BENEFICIOS(countBenefit);
            break;
        case 4:
            MODIFICAR_BENEFICIOS();
            break;
        case 5:
            EXIT(condition);
            break;
        default:
            DEFAULT(condition);
            break;
        };

    } while (condition);

    return 0;
}
