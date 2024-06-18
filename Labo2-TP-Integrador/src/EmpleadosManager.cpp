#include <iostream>
#include <cstdlib>
#include "EmpleadosManager.h"

using namespace std;



void EmpleadosManager::menuEmpleado()
{
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU EMPLEADOS -------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR EMPLEADO " << endl;
        cout << "2- LISTAR TODOS LOS EMPLEADOS" << endl;
        cout << "3- MODIFICAR EMPLEADO" << endl;
        cout << "4- ELIMINAR EMPLEADO" << endl;
        cout << "5- CONSULTAR EMPLEADO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            agregarEmpleado();
            system("pause");
            break;
        case 2:
            listarEmpleados();
            system("pause");
            break;
        case 3:
            menuModificarEmpleado();
            system("pause");
            break;
        case 4:
            bajaEmpleado();
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

void EmpleadosManager::menuModificarEmpleado()
{

}

void EmpleadosManager::agregarEmpleado()
{
    if(_empleadoArchivo.guardar(crearEmpleado()))
    {
        cout << "La empresa fue guardada con exito." << endl;
    }
    else
    {
        cout << "No se pudo guardar la empresa." << endl;
    }

}
///LISTAR TODOS LOS EMPLEADOS CARGADOS
void EmpleadosManager::listarEmpleados()
{
    int cantidad = _empleadoArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidad; i++)
    {
        cout << "--------------------------------" << endl;
        mostrarEmpleado(_empleadoArchivo.leer(i));
        cout << "--------------------------------" << endl;
    }
}

void EmpleadosManager::listarEmpleado(Empleado registro)
{
    cout << "ID LEGAJO        : " << registro.getIdLegajo() << endl;
    cout << "APELLIDO         : " << registro.getApellido() << endl;
    cout << "NOMBRE           : " << registro.getNombre() << endl;
    cout << "DNI              : " << registro.getDNI() << endl;
    cout << "AREA             : " << registro.getIdArea() << endl;
    cout << "ROL              : " << registro.getIdRol() << endl;
    cout << "HORAS TRABAJADAS : " << registro.getHorasTrabajadas() << endl;
    cout << "SUELDO           : " << registro.getSueldo() << endl;
    cout << "FECHA DE ALTA    : " << registro.geFechaContratacion().toString() << endl;
    cout << "ESTADO           : " << registro.getEstado() << endl;

}

Empleado EmpleadosManager::crearEmpleado()
{
        string nombre;
        string apellido;
        string dni;
        Fecha fechaAlta;
        int idLegajo;
        int idEmpresa;
        int idArea;
        int idRol;
        float horasTrabajadas;
        float sueldo;
        Fecha fechaContratacion;
        Fecha fechaBaja;
        bool estado;

        idLegajo = _empleadoArchivo.getNuevoID();
        ///TODO: completar la carga de un empleado.
}

void EmpleadosManager::mostrarEmpleado(Empleado registro)
{

}

void EmpleadosManager::bajaEmpleado()
{

}

