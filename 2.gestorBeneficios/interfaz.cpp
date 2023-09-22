#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include "interfaz.hpp"

using namespace std;
/*

 */
struct Beneficio
{
    char nombre[60];
    bool activo;
    int costo;
};
/*

 */
int Navegacion()
{
    int number;
    cout << "===================================" << endl;
    cout << "============ BENEFICIOS ===========" << endl;
    cout << "===================================" << endl;
    cout << "( 1 ) LISTAR BENEFICIOS" << endl;
    cout << "( 2 ) AGREGAR BENEFICIOS" << endl;
    cout << "( 3 ) ELIMINAR BENEFICIOS" << endl;
    cout << "( 4 ) MODIFICAR BENEFICIOS" << endl;
    cout << "( 5 ) SALIR" << endl;
    cout << "===================================" << endl;
    cin >> number;
    return number;
};
/*

 */
void MostrarBeneficios(Beneficio beneficios)
{
    cout << "==============================================" << endl;
    cout << "====== ID DEL BENEFICIO: " << beneficios.nombre << endl;
    cout << "============ NOMBRE: " << beneficios.nombre << endl;
    cout << "============ COSTO: " << beneficios.costo << endl;
    cout << "============ ACTIVO: " << beneficios.activo << endl;
    cout << "==============================================" << endl;
}
/*

 */
Beneficio IngresarDatosBeneficios()
{
    // fflush(stdin);
    Beneficio benefit;
    bool condition = true;
    do
    {
        cin.ignore(10000, '\n');
        system("cls");
        int number;
        cout << "==============================================" << endl;
        cout << "====== INGRESAR EL NOMBRE: ";
        cin.getline(benefit.nombre, 60, '\n');
        cout << "====== INGRESAR EL COSTO: ";
        cin >> benefit.costo;
        // AL INGRESAR UN BENEFICIO AUTOMATICAMENTE ESTA ACTIVO
        benefit.activo = true;
        cout << "==============================================" << endl;
        cout << "LOS DATOS SON CORRECTOS" << endl;
        cout << "( 1 ) SI " << endl;
        cout << "( 2 ) NO " << endl;
        cin >> number;
        switch (number)
        {
        case 1:
            condition = false;
            break;
        case 2:
            cout << "RESET DE LOS DATOS" << endl;
            break;
        default:
            cout << "ESTA OPCION NO EXISTE, SE HARA UN RESET DE LOS DATOS" << endl;
            break;
        }

    } while (condition);
    return benefit;
}
/*

 */
int MostrarOpcionesModificarBeneficio()
{
    int number;
    cout << "===================================" << endl;
    cout << "============ MODIFICAR ===========" << endl;
    cout << "===================================" << endl;
    cout << "( 1 ) NOMBRE" << endl;
    cout << "( 2 ) COSTO" << endl;
    cout << "( 3 ) ESTADO" << endl;
    cout << "( 4 ) SALIR" << endl;
    cout << "===================================" << endl;
    cin >> number;
    return number;
};
/*

 */
Beneficio MostrarOpcionesModificacion(int option, Beneficio dataBenefit)
{
    Beneficio updateBenefit = dataBenefit;
    switch (option)
    {
    case 1:
        cout << "AGREGAR EL NUEVO NOMBRE AL BENEFICIO" << endl;
        char updateName[60];
        cin.ignore(10000, '\n');
        cin.getline(updateName, 60, '\n');
        strcpy(updateBenefit.nombre, updateName);
        break;
    case 2:
        cout << "AGREGAR EL NUEVO COSTO AL BENEFICIO" << endl;
        int costo;
        cin >> costo;
        updateBenefit.costo = costo;
        break;
    case 3:
        cout << "AGREGAR NUEVO ESTADO" << endl;
        cout << "( 0 ) desactivado | ( 1 ) activo" << endl;
        int state;
        cin >> state;
        switch (state)
        {
        case 0:
            cout << "DESACTIVADO" << endl;
            updateBenefit.activo = false;
            break;
        case 1:
            cout << "ACTIVO" << endl;
            updateBenefit.activo = true;
            break;
        default:
            cout << "NO EXISTE ESTA OPCION" << endl;
            cout << "por temas de seguridad se guardara ACTIVO" << endl;
            break;
        }
        break;
    default:
        cout << "CORRECTO" << endl;
        break;
    };
    return updateBenefit;
}