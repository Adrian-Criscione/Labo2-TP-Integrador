#ifndef EMPLEADOSMANAGER_H
#define EMPLEADOSMANAGER_H
#include "Empleado.h"
#include "EmpleadoArchivo.h"

class EmpleadosManager
{
    public:
        void menuEmpleado();
        void menuModificarEmpleado();


    private:
        void agregarEmpleado();
        void listarEmpleados();
        void listarEmpleado(Empleado registro);
        Empleado crearEmpleado();

        void mostrarEmpleado(Empleado registro);
        //void modificarNombreNombre();
        //void modificarCuitEmpresa();
        void bajaEmpleado();
        //void ordenarEmpresaPorNombre(Empresa *empresas, int cantidad);

        EmpleadoArchivo _empleadoArchivo;
};

#endif // EMPLEADOSMANAGER_H
