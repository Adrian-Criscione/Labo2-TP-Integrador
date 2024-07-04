#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "AreasManager.h"

using namespace std;


void AreasManager::menuArea()
{
    int opcion;
    do
    {
        system("cls");

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        rlutil::setColor(rlutil::LIGHTRED);
        std::cout << "               MENU AREA";
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "                        *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        rlutil::setColor(rlutil::WHITE);
        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "1. AGREGAR AREA" << "              4. ELIMINAR AREA";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "        *" << std::endl;
        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "2. LISTAR AREAS" << "              5. BACKUP ARCHIVO";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "       *" << std::endl;
        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "3. MODIFICAR AREA"<< "            6. RESTORE ARCHIVO";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "      *" << std::endl;
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "0. SALIR";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                                             *" << std::endl;

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;
        rlutil::setColor(rlutil::WHITE);
        std::cout << "Opcion: ";
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
            HacerCopiaSeguridad();
            system("pause");
            break;
        case 6:
            RestaurarCopiaSeguridad();
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

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        rlutil::setColor(rlutil::LIGHTRED);
        std::cout << "               MENU MODIFICAR AREA";
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "              *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        rlutil::setColor(rlutil::WHITE);
        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "1. MODIFICAR NOMBRE";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                                  *" << std::endl;
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "0. SALIR";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                                             *" << std::endl;

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;
        rlutil::setColor(rlutil::WHITE);
        std::cout << "Opcion: ";
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

    if(cantidad >0)
    {
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

        for(int i = 0; i<cantidad; i++)
        {
            if(areas[i].getEstado())
            {

                mostrarArea(areas[i]);
            }
        }
        cout << endl;
        delete [] areas;
    }
    else
    {
        cout << "No hay usuarios para listar." << endl;
        return;
    }

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
        registro.setEstado(estado);
        _areaArchivo.guardar(posicion, registro);
        cout << "El Área " << registro.getNombre() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe un área con ID " << idArea << endl;
    }

}

void AreasManager::HacerCopiaSeguridad()
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
    _areaBkp.vaciar();
    if(_areaBkp.guardar(areas,cantidad))
    {
        cout << "BACKUP REALIZADO CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO EL BACKUP." << endl;
    }
    delete [] areas;
}

void AreasManager::RestaurarCopiaSeguridad()
{
    system("cls");
    int cantidad = _areaBkp.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Area *areas;
    areas = new Area[cantidad];

    if(areas == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _areaBkp.leerTodos(areas,cantidad);
    _areaArchivo.vaciar();
    if(_areaArchivo.guardar(areas,cantidad))
    {
        cout << "RESTAURACION REALIZADA CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO LA RESTAURACION." << endl;
    }
    delete [] areas;
}
