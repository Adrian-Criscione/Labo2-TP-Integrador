#include <iostream>
#include <cstdlib>
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
            modificarEmpresa();
            system("pause");
            break;
        case 4:
            bajaEmpresa();
            system("pause");
            break;
        case 5:
            listarEmpresas();
            system("pause");
            break;
        }
    }
    while(opcion!=0);

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

void EmpresaManager::listarEmpresas()
{
    int cantidad = _empresaArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidad; i++)
    {
        cout << "--------------------------------" << endl;
        mostrarEmpresa(_empresaArchivo.leer(i));
        cout << "--------------------------------" << endl;
    }


}

Empresa EmpresaManager::crearEmpresa()
{
    int idEmpresa;
    string razonSocial;
    string cuit;


    idEmpresa = _empresaArchivo.getNuevoID();
    cout << "Ingrese un ID: " << idEmpresa << endl;

    cin.ignore();
    cout << "Ingrese Razon Social: ";
    getline(cin,razonSocial);

    cout << "Ingrese el CUIT: ";
    getline(cin,cuit);

    return Empresa(idEmpresa,razonSocial,cuit,Fecha(12,6,2024),true);



}

void EmpresaManager::mostrarEmpresa(Empresa registro)
{
    cout << "ID Empresa: " << registro.getIdEmpresa() << endl;
    cout << "Razon Social: " << registro.getRazonSocial() << endl;
    cout << "CUIT: " << registro.getCuit() << endl;
    cout << "Fehca de Alta: " << registro.getFechaAlta().toString() << endl;
    cout << "Estado: " << (registro.getEstado()? "Activo" : "Baja") << endl; // 1 = Activo 0 = Baja

}

void EmpresaManager::modificarEmpresa()
{

}

void EmpresaManager::bajaEmpresa()
{

}

void EmpresaManager::ordenarEmpresaPorNombre(Empresa* empresas, int cantidad)
{

}
