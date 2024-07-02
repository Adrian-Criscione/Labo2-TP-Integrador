#ifndef AREASMANAGER_H
#define AREASMANAGER_H

#include "Area.h"
#include "AreaArchivo.h"

class AreasManager
{
public:

    void menuArea();
    void menuModificarArea();

private:

    void agregarArea();
    Area crearArea();
    void listarAreas();
    void mostrarEncabezado();
    void mostrarArea(Area registro);

    void modificarNombreArea();
    void bajaArea();

    void HacerCopiaSeguridad();
    void RestaurarCopiaSeguridad();



    AreaArchivo _areaArchivo;
    ///instacion de objeto para backup y restore
    AreaArchivo _areaBkp = AreaArchivo("Backup/Areas.bkp");
};

#endif // AREASMANAGER_H

