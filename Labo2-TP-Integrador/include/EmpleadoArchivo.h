#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H

#include "Empleado.h"

class EmpleadoArchivo
{
public:

    bool guardar(Empleado registro);
    bool guardar(int indice, Empleado registro);
    Empleado leer(int indice);

    void leerTodos(Empleado registros[], int cantidad);

    int buscarID(int idLegajo);

    int getCantidadRegistros();
    int getNuevoID();
};

#endif // EMPLEADOARCHIVO_H
