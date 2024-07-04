#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "SueldosManager.h"
#include "Empleado.h"
#include "AppManager.h"
using namespace std;



void SueldosManager::menuSueldos()
{
    AppManager ap;
    int opcion;
    do
    {
        rlutil::cls(); // Limpiar la pantalla

        ap. setColorLineas();
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        ap.setColorNombreMenu();
        std::cout << "               MENU SUELDOS";
        ap. setColorLineas();
        std::cout << "                     *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. AGREGAR SUELDO" << "              4. ELIMINAR SUELDO";
        ap.setColorIngresoTexto();
        std::cout << "    *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "2. LISTAR SUELDOS" << "              5. BACKUP ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "     *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "3. MODIFICAR SUELDO" << "            6. RESTORE ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "    *" << std::endl;
        ap. setColorLineas();
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "0. SALIR";
        ap.setColorIngresoTexto();
        std::cout << "                                             *" << std::endl;

        ap. setColorLineas();
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "Opcion: ";

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            agregarSueldo();
            system("pause");
            break;
        case 2:
            listarSueldos();
            system("pause");
            break;
        case 3:
            menuModificarSueldos();
            system("pause");
            break;
        case 4:
            bajaSueldo();
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
    while(opcion!=0);

}

void SueldosManager::menuModificarSueldos()
{
    AppManager ap;
    int opcion;
    do
    {
        rlutil::cls(); // Limpiar la pantalla

        ap. setColorLineas();
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        ap.setColorNombreMenu();
        std::cout << "               MENU MODIFICAR SUELDO";
        ap. setColorLineas();
        std::cout << "            *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. MODIFICAR HORAS EXTRA" << "       2. MODIFICAR SUELDO";
        ap.setColorIngresoTexto();
        std::cout << "   *" << std::endl;
        ap. setColorLineas();
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "0. SALIR";
        ap.setColorIngresoTexto();
        std::cout << "                                             *" << std::endl;

        ap. setColorLineas();
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            modificarHorasExtra();
            system("pause");
            break;
        case 2:
            modificarSueldo();
            system("pause");
            break;
        }
    }
    while(opcion!=0);

}

void SueldosManager::agregarSueldo()
{
    if(_sueldosArchivo.guardar(crearSueldo()))
    {
        cout << "El sueldo se ha guardado con exito." << endl;
    }
    else
    {
        cout << "No se pudo guardar el sueldo." << endl;
    }

}

Sueldos SueldosManager::crearSueldo()
{
    int idSueldo;
    int idLegajo;
    int idEmpresa;
    float horasExtra;
    float sueldo;
    int dia, mes, anio;
    Fecha fechaLiquidacion;


    idSueldo = _sueldosArchivo.getNuevoID();
    cout << "Ingrese un ID: " << idSueldo << endl;
    cin.ignore();
    cout << "Ingrese el ID de legajo; ";
    cin >> idLegajo;
    cin.ignore();
    cout << "Ingrese el ID de empresa; ";
    cin >> idEmpresa;
    cin.ignore();
    cout << "Ingrese día: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el Año: ";
    cin >> anio;
    cout << "Ingrese las horas extras: ";
    cin >> horasExtra;
    cout << "Ingrese el sueldo: ";
    cin >> sueldo;

    return Sueldos(idSueldo,idLegajo,idEmpresa,fechaLiquidacion,horasExtra,sueldo,true);

}

///ESTE METODO LISTA TODAS LAS EMPRESAS CON MEMORIA DINAMICA.
void SueldosManager::listarSueldos()
{
    system("cls");
    int cantidad = _sueldosArchivo.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Sueldos *sueldosVec;
    sueldosVec = new Sueldos[cantidad];

    if(sueldosVec == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _sueldosArchivo.leerTodos(sueldosVec,cantidad);

    mostrarEncabezado();
    for(int i = 0; i<cantidad; i++)
    {
        if(sueldosVec[i].getEstado())
        {

            mostrarSueldos(sueldosVec[i]);

        }
    }
    cout << endl;
    delete [] sueldosVec;

}

void SueldosManager::mostrarEncabezado()
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(6)  << "ID" << setw(6) << "LEGAJO" << setw(15) << "NOMBRE" << setw(15) << "APELLIDO" << setw(15)
         << "EMPRESA" << setw(12) << "FECHA LIQUIDACION" << setw(15) << "HORAS EXTRA" << setw(15) << "SUELDO" << setw(10) << "ESTADO"<< endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

}

void SueldosManager::mostrarSueldos(Sueldos registro)
{
    /// para mostrar el nombre del empleado.
    int posNombreEmpleado = _empleadoArchivo.buscarID(registro.getIdLegajo());
    Empleado nombreEmpleado = _empleadoArchivo.leer(posNombreEmpleado);

    /// para mostrar el nombre de la empresa.
    int posNombreEmpresa = _empresaArchivo.buscarID(registro.getIdEmpresa());
    Empresa nombreEmpresa = _empresaArchivo.leer(posNombreEmpresa);

    cout << left << setw(6)  << registro.getIdSueldo() << setw(6) << registro.getIdLegajo() << setw(15) << nombreEmpleado.getNombre() << setw(15) << nombreEmpleado.getApellido()
         << setw(15) << nombreEmpresa.getNombreID() << setw(12) << registro.getFechaLiquidacion().toString() << setw(15) << registro.getHorasExtras()
         << setw(15) << registro.getSueldo() << setw(10) << (registro.getEstado()? "Activo" : "Baja")<< endl;

}

void SueldosManager::modificarHorasExtra()
{
    system("cls");
    Sueldos registro;
    int idSueldo, posicion;
    cout << "Ingrese un ID de Sueldo a buscar: ";
    cin >> idSueldo;
    cin.ignore();
    posicion = _sueldosArchivo.buscarID(idSueldo);

    if(posicion >= 0)
    {
        registro = _sueldosArchivo.leer(posicion);
        mostrarSueldos(registro);
        cout << "----------------------------" << endl;

        float  horasExtra;
        cout << "Ingrese la nueva cantidad de horas extra: ";
        cin >> horasExtra;
        cin.ignore();
        registro.setHorasExtras(horasExtra);
        _sueldosArchivo.guardar(posicion,registro);
        cout << "Las Horas Extras se han modificado con exito." << endl;
    }
    else
    {
        cout << "No existe el ID de sueldo solicitadoo: " << idSueldo << endl;
    }

}

void SueldosManager::modificarSueldo()
{
    system("cls");
    Sueldos registro;
    int idSueldo, posicion;
    cout << "Ingrese un ID de Sueldo a buscar: ";
    cin >> idSueldo;
    cin.ignore();
    posicion = _sueldosArchivo.buscarID(idSueldo);

    if(posicion >= 0)
    {
        registro = _sueldosArchivo.leer(posicion);
        mostrarSueldos(registro);
        cout << "----------------------------" << endl;

        float  sueldoNuevo;
        cout << "Ingrese la nueva cantidad de horas extra: ";
        cin >> sueldoNuevo;
        cin.ignore();
        registro.setSueldo(sueldoNuevo);
        _sueldosArchivo.guardar(posicion,registro);
        cout << "El nuevo sueldo se ha modificado con exito." << endl;
    }
    else
    {
        cout << "No existe el ID de sueldo solicitadoo: " << idSueldo << endl;
    }



}

void SueldosManager::bajaSueldo()
{
    Sueldos registro;
    bool estado;
    int idSueldo, posicion;
    cout << "Ingrese el ID a buscar: ";
    cin >> idSueldo;

    posicion = _sueldosArchivo.buscarID(idSueldo);
    if(posicion >=0)
    {
        registro = _sueldosArchivo.leer(posicion);
        mostrarSueldos(registro);
        cout << "-------------------------" << endl;
        cout << "Desea dar de baja el sueldo? (1-Si/0-No) ";
        cin >> estado;
        registro.setEstado(!estado);
        _sueldosArchivo.guardar(posicion,registro);
        cout << "El sueldo con ID " << registro.getIdSueldo() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe una sueldo con ID " << idSueldo << endl;
    }

}

void SueldosManager::HacerCopiaSeguridad()
{
    system("cls");
    int cantidad = _sueldosArchivo.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Sueldos *sueldosVec;
    sueldosVec = new Sueldos[cantidad];

    if(sueldosVec == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _sueldosArchivo.leerTodos(sueldosVec,cantidad);
    _sueldosBkp.vaciar();
    if(_sueldosBkp.guardar(sueldosVec,cantidad))
    {
        cout << "BACKUP DE SUELDOS REALIZADO CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO EL BACKUP DE SUELDOS." << endl;
    }
    delete [] sueldosVec;

}

void SueldosManager::RestaurarCopiaSeguridad()
{
    system("cls");
    int cantidad = _sueldosBkp.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Sueldos *sueldosVec;
    sueldosVec = new Sueldos[cantidad];

    if(sueldosVec == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _sueldosBkp.leerTodos(sueldosVec,cantidad);
    _sueldosArchivo.vaciar();
    if(_sueldosArchivo.guardar(sueldosVec,cantidad))
    {
        cout << "RESTAURACION REALIZADA CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO LA RESTAURACION." << endl;
    }
    delete [] sueldosVec;

}

