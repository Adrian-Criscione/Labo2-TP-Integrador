#ifndef EMPRESAMANAGER_H
#define EMPRESAMANAGER_H
#include "Empresa.h"
#include "EmpresaArchivo.h"

class EmpresaManager
{
    public:

        void menuEmpresa();

    private:

        void agregarEmpresa();
        void listarEmpresas();
        Empresa crearEmpresa();
        void mostrarEmpresa(Empresa registro);
        void modificarEmpresa();
        void bajaEmpresa();
        void ordenarEmpresaPorNombre(Empresa *empresas, int cantidad);

        EmpresaArchivo _empresaArchivo;

};

#endif // EMPRESAMANAGER_H
