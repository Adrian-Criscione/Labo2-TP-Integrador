#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "EmpresaManager.h"

using namespace std;

void EmpresaManager::menuEmpresa()
{
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU EMPRESA -------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR EMPRESA " << endl;
        cout << "2- LISTAR TODAS LAS EMPRESAS" << endl;
        cout << "3- MODIFICAR EMPRESA" << endl;
        cout << "4- ELIMINAR EMPRESA" << endl;
        cout << "5- LISTAR ORDENADOS POR NOMBRE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            agregarEmpresa();
            system("pause");
            break;
        case 2:
            listarEmpresas();
            system("pause");
            break;
        case 3:
            menuModificarEmpresa();
            system("pause");
            break;
        case 4:
            bajaEmpresa();
            system("pause");
            break;
        case 5:
            //listarEmpresas();

            cout << "Falta desarrollar." <<endl;
            system("pause");
            break;
        }
    }
    while(opcion!=0);

}

void EmpresaManager::menuModificarEmpresa()
{
    int opcion;
    do
    {
        system("cls");

        cout << "--------------------------------------" << endl;
        cout << "------ MENU MODIFICAR EMPRESA -------- " << endl;
        cout << "--------------------------------------" << endl;
        cout << "1- MODIFICAR NOMBRE" << endl;
        cout << "2- MODIFICAR CUIT" << endl;
        cout << "--------------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            modificarNombreEmpresa();
            system("pause");
            break;
        case 2:
            modificarCuitEmpresa();
            system("pause");
            break;
        }
    }
    while(opcion!=0);
}

void EmpresaManager::modificarNombreEmpresa()
{
    system("cls");
    Empresa registro;
    int idEmpresa, posicion;
    cout << "Ingrese un ID de Empresa a buscar: ";
    cin >> idEmpresa;
    cin.ignore();
    posicion = _empresaArchivo.buscarID(idEmpresa);

    if(posicion >= 0)
    {
        registro = _empresaArchivo.leer(posicion);
        mostrarEmpresa(registro);
        cout << "----------------------------" << endl;

        string nuevoNombre;
        cout << "Ingrese la nueva razon social: ";
        getline(cin,nuevoNombre);
        registro.setRazonSocial(nuevoNombre);
        _empresaArchivo.guardar(posicion,registro);
        cout << "Razon social modificada con exito." << endl;
    }
    else
    {
        cout << "No existe una empresa con ID " << idEmpresa << endl;
    }

}

void EmpresaManager::modificarCuitEmpresa()
{
    system("cls");
    Empresa registro;
    int idEmpresa, posicion;
    cout << "Ingrese un ID de Empresa a buscar: ";
    cin >> idEmpresa;
    cin.ignore();
    posicion = _empresaArchivo.buscarID(idEmpresa);

    if(posicion >= 0)
    {
        registro = _empresaArchivo.leer(posicion);
        mostrarEmpresa(registro);
        cout << "----------------------------" << endl;

        string nuevoCuit;
        cout << "Ingrese el nuevo CUIT de la empresa: ";
        getline(cin,nuevoCuit);
        registro.setCuit(nuevoCuit);
        _empresaArchivo.guardar(posicion,registro);
        cout << "CUIT de empresa "<< registro.getRazonSocial() <<" modificada con exito." << endl;
    }
    else
    {
        cout << "No existe una empresa con ID " << idEmpresa << endl;
    }


}


void EmpresaManager::agregarEmpresa()
{
    if(_empresaArchivo.guardar(crearEmpresa()))
    {
        cout << "La empresa fue guardada con exito." << endl;
    }
    else
    {
        cout << "No se pudo guardar la empresa." << endl;
    }


}
///ESTE METODO LISTA TODAS LAS EMPRESAS CON MEMORIA DINAMICA.
void EmpresaManager::listarEmpresas()
{

    system("cls");
    int cantidad = _empresaArchivo.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Empresa *empresas;
    empresas = new Empresa[cantidad];

    if(empresas == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _empresaArchivo.leerTodos(empresas,cantidad);

    mostrarEncabezado();
    for(int i = 0; i<cantidad; i++)
    {
        if(empresas[i].getEstado())
        {

            mostrarEmpresa(empresas[i]);

        }
    }
    cout << endl;
    delete [] empresas;

}

Empresa EmpresaManager::crearEmpresa()
{
    int idEmpresa;
    string razonSocial;
    string cuit;
    Fecha fechaAlta;


    idEmpresa = _empresaArchivo.getNuevoID();
    cout << "Ingrese un ID: " << idEmpresa << endl;

    cin.ignore();
    cout << "Ingrese Razon Social: ";
    getline(cin,razonSocial);

    cout << "Ingrese el CUIT: ";
    getline(cin,cuit);

    return Empresa(idEmpresa,razonSocial,cuit,fechaAlta,true);

}

void EmpresaManager::mostrarEncabezado()
{

    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(6)  << "ID" << setw(30) << "RAZON SOCIAL" << setw(15) << "CUIT"
         << setw(12) << "FECHA ALTA" << setw(10) << "ESTADO"<< endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
}
void EmpresaManager::mostrarEmpresa(Empresa registro)
{
    cout << setw(6)<< registro.getIdEmpresa() << setw(30) << registro.getRazonSocial()
         << setw(15)<< registro.getCuit() << setw(12) << registro.getFechaAlta().toString()
         << setw(10) << (registro.getEstado()? "Activo" : "Baja") << endl; // 1 = Activo 0 = Baja
}


void EmpresaManager::bajaEmpresa()
{
    Empresa registro;
    bool estado;
    int idEmpresa, posicion;
    cout << "Ingrese el ID a buscar: ";
    cin >> idEmpresa;

    posicion = _empresaArchivo.buscarID(idEmpresa);
    if(posicion >=0)
    {
        registro = _empresaArchivo.leer(posicion);
        mostrarEmpresa(registro);
        cout << "-------------------------" << endl;
        cout << "Desea dar de baja la empresa? (0-Si/1-No) ";
        cin >> estado;
        registro.setEstado(estado);
        _empresaArchivo.guardar(posicion,registro);
        cout << "La Empresa " << registro.getRazonSocial() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe una empresa con ID " << idEmpresa << endl;
    }
}

void EmpresaManager::ordenarEmpresaPorNombre(Empresa* empresas, int cantidad)
{

}
