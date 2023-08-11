#include <iostream>
#include "interfaz.hpp"

struct Beneficios
{
    char nombre[50];
    int costo;
}

interfaz::interfaz(){};

void interfaz::MostrarBeneficios()
{
    Beneficios beneficios;
    std::cout << " ======================================= " << std::endl;
    for (int i = 0; i < 100; i++)
    {
        std::cout << (i + 1) << beneficios << std::endl;
    }
}
