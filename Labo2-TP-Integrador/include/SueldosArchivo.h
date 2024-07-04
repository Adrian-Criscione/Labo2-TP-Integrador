#ifndef SUELDOSARCHIVO_H
#define SUELDOSARCHIVO_H
#include "Sueldos.h"

class SueldosArchivo
{
public:
    SueldosArchivo();
    SueldosArchivo(std::string nombre);
    bool guardar(Sueldos registro);
    bool guardar(int indice, Sueldos registro);

    Sueldos leer(int indice);

    ///METODOS PARA EL BACKUP Y RESTORE
    bool guardar(Sueldos *sueldos, int cantidadRegistros);
    void vaciar();
    void leerTodos(Sueldos registros[], int cantidad);


    void setNombreArchivo(std::string nombre);
    int buscarID(int idSueldos);

    int getCantidadRegistros();
    int getNuevoID();


private:
    std::string _nombre;
};

#endif // SUELDOSARCHIVO_H
