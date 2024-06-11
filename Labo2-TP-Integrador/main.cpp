#include <iostream>
#include "Empresa.h"
#include "Fecha.h"
using namespace std;

int main()
{
    int idEmpresa;
    char razonSocial[30];
    char cuit[11];
    Fecha fechaAlta;
    Fecha fechaBaja;

    fechaAlta.setAnio(2024);
    Empresa prueba(idEmpresa,razonSocial,cuit,fechaAlta,fechaBaja);

    cout << prueba.getFechaAlta().getAnio();
    return 0;
}
