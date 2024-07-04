#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "AreasManager.h"
#include "AppManager.h"
using namespace std;


void AreasManager::menuArea()
{
    AppManager ap;
    int opcion;
    do
    {
        system("cls");

        ap.setColorLineas();

        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        ap.setColorNombreMenu();
        std::cout << "               MENU AREA";
        ap.setColorLineas();
        std::cout << "                        *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. AGREGAR AREA" << "              4. ELIMINAR AREA";
        ap.setColorIngresoTexto();
        std::cout << "        *" << std::endl;
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "2. LISTAR AREAS" << "              5. BACKUP ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "       *" << std::endl;
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "3. MODIFICAR AREA"<< "            6. RESTORE ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "      *" << std::endl;
        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "0. SALIR";
        ap.setColorIngresoTexto();
        std::cout << "                                             *" << std::endl;

        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;
        ap.setColorTexto();
        std::cout << "Opcion: ";



        ap.setColorIngresoTexto();
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
    AppManager ap;
    int opcion;
    do
    {
        system("cls");

        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        ap.setColorNombreMenu();
        std::cout << "               MENU MODIFICAR AREA";
        ap.setColorLineas();
        ap.setColorLineas();
        std::cout << "              *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. MODIFICAR NOMBRE";
        ap.setColorIngresoTexto();
        std::cout << "                                  *" << std::endl;
        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "0. SALIR";
        ap.setColorIngresoTexto();
        std::cout << "                                             *" << std::endl;

        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;
        ap.setColorTexto();
        std::cout << "Opcion: ";

        ap.setColorIngresoTexto();
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
    AppManager ap;
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
        mostrarEncabezado();
        mostrarArea(registro);


        string nuevoNombre;
        do
        {
            ap.setColorTexto();
            cout << "Ingrese nombre del area: ";
            ap.setColorIngresoTexto();
            getline(cin,nuevoNombre);
            if(!ap.esStringValido(nuevoNombre,false,false,false)) ///false = permitir espacios / false = no permitir numeros / false = no permitir caracteres especiales
            {
                ap.setColorError();
                cout << "Nombre del area incorrecto." << endl;
                ap.setColorIngresoTexto();
            }
        }
        while(!ap.esStringValido(nuevoNombre,false,false,false));



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

    }

}

Area AreasManager::crearArea()
{
    AppManager ap;
    int idArea;
    string nombre;
    bool estado = true;
    idArea = _areaArchivo.getNuevoID();

    cout << "Ingrese un ID: ";
    ap.setColorIngresoTexto();
    cout << idArea << endl;
    cin.ignore();
    /*rlutil::setColor(rlutil::CYAN);
    cout << "Ingrese Nombre: ";
    ap.setColorIngresoTexto();
    getline(cin, nombre);*/

    ///CARGA NOMBRE DEL AREA
    do
    {
        ap.setColorTexto();
        cout << "Ingrese nombre del area: ";
        ap.setColorIngresoTexto();
        getline(cin,nombre);
        if(!ap.esStringValido(nombre,false,false,false)) ///false = permitir espacios / false = no permitir numeros / false = no permitir caracteres especiales
        {
            ap.setColorError();
            cout << "Nombre del area incorrecto." << endl;
            ap.setColorIngresoTexto();
        }
    }
    while(!ap.esStringValido(nombre,false,false,false));


    return Area(idArea, nombre, estado);
}
void AreasManager::mostrarEncabezado()
{
    AppManager ap;
    ap. setColorLineas();
    std::cout << "*********************************************************************" << std::endl;
    std::cout << "      ";
    ap.setColorNombreMenu();
    cout << left << setw(6)  << " ID" << setw(20) << " AREA" << setw(10) << " ESTADO" << endl;
    ap. setColorLineas();
    std::cout << "*********************************************************************" << std::endl;



}
void AreasManager::mostrarArea(Area registro)
{
    cout << left <<"       "
         << setw(6) << registro.getIdArea()
         << setw(20) << registro.getNombre()
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
        if(registro.getEstado()==false)
        {
            cout << "El area ya fue dado de baja." << endl;
            return;
        }
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
