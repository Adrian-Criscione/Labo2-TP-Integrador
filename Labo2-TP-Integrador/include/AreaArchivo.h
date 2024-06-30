#ifndef AREAARCHIVO_H
#define AREAARCHIVO_H

#include "Area.h"

class AreaArchivo
{
private:
    char _nombre[30];

public:
    AreaArchivo();
    bool guardar(Area registro);
    bool guardar(int indice, Area registro);
    Area leer(int indice);

    void leerTodos(Area registros[], int cantidad);

    int buscarID(int idArea);

    int getCantidadRegistros();
    int getNuevoID();
};

#endif // AREAARCHIVO_H

