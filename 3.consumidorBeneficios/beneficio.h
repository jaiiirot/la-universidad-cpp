struct Beneficio
{
    int id;
    char nombre[60];
    bool activo;
    int costo;
};

void consultarBeneficios(int creditos);

int costeBeneficio(int id, int creditos);