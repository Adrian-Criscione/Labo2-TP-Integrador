#ifndef AREAARCHIVO_H
#define AREAARCHIVO_H

#include "Area.h"

class AreaArchivo
{
private:
    std::string _nombre;

public:
    AreaArchivo();
    AreaArchivo(std::string nombre);
    bool guardar(Area registro);
    bool guardar(int indice, Area registro);

    ///METODOS PARA EL BACKUP Y RESTORE
    bool guardar(Area *registros, int cantidadRegistros);
    void vaciar();
    void leerTodos(Area registros[], int cantidad);

    Area leer(int indice);
    void setNombreArchivo(std::string nombre);


    int buscarID(int idArea);

    int getCantidadRegistros();
    int getNuevoID();
};

#endif // AREAARCHIVO_H

