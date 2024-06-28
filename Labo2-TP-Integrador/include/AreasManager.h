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
    void listarAreas();
    void listarAreas(Area registro);
    Area crearArea();

    void mostrarArea(Area registro);
    void modificarNombreArea();
    void bajaArea();
    void ordenarAreasPorNombre(Area *areas, int cantidad);

    AreaArchivo _areaArchivo;
};

#endif // AREASMANAGER_H

