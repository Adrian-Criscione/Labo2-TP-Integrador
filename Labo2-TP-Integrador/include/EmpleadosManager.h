#ifndef EMPLEADOSMANAGER_H
#define EMPLEADOSMANAGER_H
#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include "AreaArchivo.h"
#include "EmpresaArchivo.h"

class EmpleadosManager
{
public:
    void menuEmpleado();
    void menuModificarEmpleado();
    void mostrarEmpleadoBaja(Empleado registro);
    void mostrarEncabezadoBaja();
private:
    void agregarEmpleado();
    void listarEmpleados();
    Empleado crearEmpleado();
    void mostrarEmpleado(Empleado registro);
    void mostrarEncabezado();



    void modificarNombre();
    void modificarApellido();
    void modificarDNI();
    void modificarFechaNac();
    void modificarArea();
    void modificarFechaContratacion();
    bool esDNIValido(std::string dni);
    void HacerCopiaSeguridad();
    void RestaurarCopiaSeguridad();

    void bajaEmpleado();
    //void ordenarEmpresaPorNombre(Empresa *empresas, int cantidad);

    EmpleadoArchivo _empleadoArchivo;
    EmpleadoArchivo _empleadoBkp = EmpleadoArchivo("Backup/Empleados.bkp");
    AreaArchivo _areaArchivo;
    EmpresaArchivo _empresaArchivo;
};

#endif // EMPLEADOSMANAGER_H
