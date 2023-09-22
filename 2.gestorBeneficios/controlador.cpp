#include <iostream>
#include "interfaz.hpp"
#include "logica.hpp"
#include "controlador.hpp"

void LISTAR_BENEFICIOS()
{
    system("cls");
    mostrarBeneficios();
    system("pause");
};
void AGREGAR_BENEFICIOS()
{
    system("cls");
    Beneficio newBenefit;
    bool exist = false;
    newBenefit = IngresarDatosBeneficios();
    existeBeneficio(exist, newBenefit);
    if (exist)
    {
        cout << "NO SE PUEDE AGREGAR UN BEENEFICIO CON UN MISMO NOMBRE" << endl;
    }
    else
    {
        agregarBeneficio(newBenefit);
        cout << "Se AGREGO CORRECTAMENTE" << endl;
    }
    system("pause");
};
void ELIMINAR_BENEFICIOS(int countBenefit)
{
    system("cls");
    bool exist = false;
    eliminarBeneficio(countBenefit);
    system("pause");
};
void MODIFICAR_BENEFICIOS()
{
    system("cls");
    string nombre_buscar;
    cin.ignore(10000, '\n');
    cout << "INGRESAR EL NOMBRE DEL BENEFICIOS QUE DESEAS BUSCAR" << endl;
    getline(cin, nombre_buscar);
    modificarBeneficio(nombre_buscar);
    system("pause");
};

void EXIT(bool &condition)
{
    condition = false;
};
void DEFAULT(bool &condition)
{
    cout << "NO EXISTE ESTA OPCION" << endl;
    system("pause");
    condition = false;
};