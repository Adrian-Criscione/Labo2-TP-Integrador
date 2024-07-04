#ifndef SUELDOSMANAGER_H
#define SUELDOSMANAGER_H
#include "Sueldos.h"
#include "SueldosArchivo.h"
#include "EmpleadoArchivo.h"
#include "EmpresaArchivo.h"


class SueldosManager
{
public:

    void menuSueldos();
    void menuModificarSueldos();

private:

    void agregarSueldo();
    Sueldos crearSueldo();
    void listarSueldos();
    void mostrarEncabezado();
    void mostrarSueldos(Sueldos registro);
    void modificarHorasExtra();
    void modificarSueldo();
    void bajaSueldo();
    void HacerCopiaSeguridad();
    void RestaurarCopiaSeguridad();

    SueldosArchivo _sueldosArchivo;
    SueldosArchivo _sueldosBkp = SueldosArchivo("Backup/Sueldos.bkp");
    EmpleadoArchivo _empleadoArchivo;
    EmpresaArchivo _empresaArchivo;
};

#endif // SUELDOSMANAGER_H
