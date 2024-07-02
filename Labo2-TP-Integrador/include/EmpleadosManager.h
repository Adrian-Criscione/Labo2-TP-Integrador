#ifndef EMPLEADOSMANAGER_H
#define EMPLEADOSMANAGER_H
#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include "AreaArchivo.h"

class EmpleadosManager
{
public:
    void menuEmpleado();
    void menuModificarEmpleado();


private:
    void agregarEmpleado();
    void listarEmpleados();
    //void listarEmpleado(Empleado registro);
    Empleado crearEmpleado();

    void mostrarEncabezado();
    void mostrarEmpleado(Empleado registro);
    //void modificarNombreNombre();

    void HacerCopiaSeguridad();
    void RestaurarCopiaSeguridad();

    void bajaEmpleado();
    //void ordenarEmpresaPorNombre(Empresa *empresas, int cantidad);

    EmpleadoArchivo _empleadoArchivo;
    EmpleadoArchivo _empleadoBkp = EmpleadoArchivo("Backup/Empleados.bkp");
    AreaArchivo _areaArchivo;
};

#endif // EMPLEADOSMANAGER_H
