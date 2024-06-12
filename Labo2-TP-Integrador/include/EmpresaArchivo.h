#ifndef EMPRESAARCHIVO_H
#define EMPRESAARCHIVO_H
#include "Empresa.h"

class EmpresaArchivo
{
public:

    bool guardar(Empresa registro);
    bool guardar(int indice, Empresa registro);
    Empresa leer(int indice);

    void leerTodos(Empresa registros[], int cantidad);

    int buscarID(int idEmpresa);

    int getCantidadRegistros();
    int getNuevoID();
};

#endif // EMPRESAARCHIVO_H
