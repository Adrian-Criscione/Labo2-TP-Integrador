#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "AreasManager.h"

using namespace std;


void AreasManager::menuArea()
{
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU AREA -------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR AREA " << endl;
        cout << "2- LISTAR TODAS LAS AREAS" << endl;
        cout << "3- MODIFICAR AREA" << endl;
        cout << "4- ELIMINAR AREA" << endl;
        cout << "5- LISTAR ORDENADAS POR NOMBRE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opción: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            agregarArea();
            system("pause");
            break;
        case 2:
            listarAreas();
            system("pause");
            break;
        case 3:
            menuModificarArea();
            system("pause");
            break;
        case 4:
            bajaArea();
            system("pause");
            break;
        case 5:
            //ordenarAreasPorNombre();
            cout << "Falta desarrollar." << endl;
            system("pause");
            break;
        }
    }
    while(opcion != 0);
}

void AreasManager::menuModificarArea()
{
    int opcion;
    do
    {
        system("cls");

        cout << "--------------------------------------" << endl;
        cout << "------ MENU MODIFICAR AREA -------- " << endl;
        cout << "--------------------------------------" << endl;
        cout << "1- MODIFICAR NOMBRE" << endl;
        cout << "--------------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            modificarNombreArea();
            system("pause");
            break;
        }
    }
    while(opcion != 0);
}

void AreasManager::modificarNombreArea()
{
    system("cls");
    Area registro;
    int idArea, posicion;
    cout << "Ingrese un ID de Area a buscar: ";
    cin >> idArea;
    cin.ignore();
    posicion = _areaArchivo.buscarID(idArea);

    if(posicion >= 0)
    {
        registro = _areaArchivo.leer(posicion);
        mostrarArea(registro);
        cout << "----------------------------" << endl;

        string nuevoNombre;
        cout << "Ingrese el nuevo nombre: ";
        getline(cin, nuevoNombre);
        registro.setNombre(nuevoNombre);
        _areaArchivo.guardar(posicion, registro);
        cout << "Nombre de área modificado con exito." << endl;
    }
    else
    {
        cout << "No existe un area con ID " << idArea << endl;
    }
}

void AreasManager::agregarArea()
{
    if(_areaArchivo.guardar(crearArea()))
    {
        cout << "El area fue guardada con éxito." << endl;
    }
    else
    {
        cout << "No se pudo guardar el area." << endl;
    }
}

void AreasManager::listarAreas()
{
    system("cls");
    int cantidad = _areaArchivo.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Area *areas;
    areas = new Area[cantidad];

    if(areas == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _areaArchivo.leerTodos(areas,cantidad);

    mostrarEncabezado();


    for(int i = 0;i<cantidad;i++)
    {
        if(areas[i].getEstado())
        {

            mostrarArea(areas[i]);
        }
    }
    cout << endl;
delete [] areas;

}

Area AreasManager::crearArea()
{
    int idArea;
    string nombre;
    bool estado = true;
    idArea = _areaArchivo.getNuevoID();
    cout << "Ingrese un ID: " << idArea << endl;

    cin.ignore();
    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    return Area(idArea, nombre, estado);
}
void AreasManager::mostrarEncabezado()
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(6)  << " ID" << setw(15) << " AREA" << setw(10) << " ESTADO" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

}
void AreasManager::mostrarArea(Area registro)
{
        cout << left <<" "
         << setw(6) << registro.getIdArea()
         << setw(15) << registro.getNombre()
         << setw(10)  << (registro.getEstado() ? "Activo" : "Baja")
         << endl;
}

void AreasManager::bajaArea()
{
    /*
    Area registro;
    int idArea, posicion;
    bool estado;
    cout << "Ingrese el ID a buscar: ";
    cin >> idArea;

    posicion = _areaArchivo.buscarID(idArea);
    if(posicion >=0)
    {
        registro = _areaArchivo.leer(posicion);
        mostrarArea(registro);
        cout << "-------------------------" << endl;
        cout << "Desea dar de baja el área? (0-Si/1-No) ";
        cin >> estado;
        registro.se(estado);
        _areaArchivo.guardar(posicion, registro);
        cout << "El Área " << registro.getNombre() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe un área con ID " << idArea << endl;
    }
    */
}

void AreasManager::ordenarAreasPorNombre(Area *areas, int cantidad)
{
    // Implementar ordenamiento por nombre (si se requiere)
}

