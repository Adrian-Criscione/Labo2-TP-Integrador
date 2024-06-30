#ifndef EMPRESAARCHIVO_H
#define EMPRESAARCHIVO_H
#include "Empresa.h"

class EmpresaArchivo
{
public:
    EmpresaArchivo();
    bool guardar(Empresa registro);
    bool guardar(int indice, Empresa registro);
    Empresa leer(int indice);

    void leerTodos(Empresa registros[], int cantidad);

    int buscarID(int idEmpresa);

    int getCantidadRegistros();
    int getNuevoID();
private:
    char _nombre[30];
};

#endif // EMPRESAARCHIVO_H
