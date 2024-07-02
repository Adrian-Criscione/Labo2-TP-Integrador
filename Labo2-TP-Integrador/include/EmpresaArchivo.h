#ifndef EMPRESAARCHIVO_H
#define EMPRESAARCHIVO_H
#include "Empresa.h"

class EmpresaArchivo
{
public:
    EmpresaArchivo();
    EmpresaArchivo(std::string nombre);
    bool guardar(Empresa registro);
    bool guardar(int indice, Empresa registro);

    Empresa leer(int indice);

    ///METODOS PARA EL BACKUP Y RESTORE
    bool guardar(Empresa *empresas, int cantidadRegistros);
    void vaciar();
    void leerTodos(Empresa registros[], int cantidad);


    void setNombreArchivo(std::string nombre);
    int buscarID(int idEmpresa);

    int getCantidadRegistros();
    int getNuevoID();


private:
    std::string _nombre;
};

#endif // EMPRESAARCHIVO_H
