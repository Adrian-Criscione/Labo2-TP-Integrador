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
    void ordenarAreasPorNombre(Area *areas, int cantidad);

    AreaArchivo _areaArchivo;
};

#endif // AREASMANAGER_H

