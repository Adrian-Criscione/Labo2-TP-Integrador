#ifndef EMPRESAMANAGER_H
#define EMPRESAMANAGER_H
#include "Empresa.h"
#include "EmpresaArchivo.h"

class EmpresaManager
{
    public:

        void menuEmpresa();
        void menuModificarEmpresa();

    private:

        void agregarEmpresa();
        void listarEmpresas();
        void listarEmpresas(Empresa registro);
        Empresa crearEmpresa();

        void mostrarEmpresa(Empresa registro);
        void modificarNombreEmpresa();
        void modificarCuitEmpresa();
        void bajaEmpresa();
        void ordenarEmpresaPorNombre(Empresa *empresas, int cantidad);

        EmpresaArchivo _empresaArchivo;

};

#endif // EMPRESAMANAGER_H
