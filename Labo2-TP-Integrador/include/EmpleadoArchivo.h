#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H

#include "Empleado.h"

class EmpleadoArchivo
{

public:
    EmpleadoArchivo();
    EmpleadoArchivo(std::string nombre);
    bool guardar(Empleado registro);
    bool guardar(int indice, Empleado registro);
    Empleado leer(int indice);

    ///METODOS PARA EL BACKUP Y RESTORE
    bool guardar(Empleado *registros, int cantidadRegistros);
    void vaciar();
    void leerTodos(Empleado registros[], int cantidad);

    int buscarID(int idLegajo);
    void setNombreArchivo(std::string nombre);
    int getCantidadRegistros();
    int getNuevoID();
private:
    std::string _nombre;
};

#endif // EMPLEADOARCHIVO_H
