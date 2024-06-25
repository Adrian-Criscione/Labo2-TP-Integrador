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
        Empresa crearEmpresa();
        void listarEmpresas();
        void mostrarEmpresa(Empresa registro);
        void modificarNombreEmpresa();
        void modificarCuitEmpresa();
        void bajaEmpresa();
        void ordenarEmpresaPorNombre(Empresa *empresas, int cantidad);

        EmpresaArchivo _empresaArchivo;

};

#endif // EMPRESAMANAGER_H
