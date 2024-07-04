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
    void mostrarEncabezado();
    void mostrarEmpresa(Empresa registro);
    void modificarNombreEmpresa();
    void modificarCuitEmpresa();
    void bajaEmpresa();
    void HacerCopiaSeguridad();
    void RestaurarCopiaSeguridad();
    bool esCuitValido(std::string cuit);



    EmpresaArchivo _empresaArchivo;
    EmpresaArchivo _empresaBkp = EmpresaArchivo("Backup/Empresas.bkp");

};

#endif // EMPRESAMANAGER_H
