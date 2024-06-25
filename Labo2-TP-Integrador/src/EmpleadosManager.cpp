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
        cout << "El empleado fue guardado con exito." << endl;
    }
    else
    {
        cout << "No se pudo guardar el empleado." << endl;
    }

}
///LISTAR TODOS LOS EMPLEADOS CARGADOS
void EmpleadosManager::listarEmpleados()
{
    system("cls");
    int cantidad = _empleadoArchivo.getCantidadRegistros();
    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Empleado *empleados;
    empleados = new Empleado[cantidad];

    if(empleados == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _empleadoArchivo.leerTodos(empleados,cantidad);

    for(int i = 0;i<cantidad;i++)
    {
            cout << "--------------------------------" << endl;
            mostrarEmpleado(empleados[i]);
            cout << "--------------------------------" << endl;
    }

delete [] empleados;
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
    int dia, mes, anio;
    //Fecha fechaNacimiento;
    //Fecha fechaAlta;
    int idLegajo;
    int idEmpresa;
    int idArea;
    int idRol;
    float horasTrabajadas;
    float sueldo;
    //Fecha fechaContratacion;
    Fecha fechaBaja;
    bool estado=true;

    idLegajo = _empleadoArchivo.getNuevoID();
    cin.ignore();
    ///TODO: completar la carga de un empleado
    cout << "Ingrese ID de legajo: " << idLegajo << endl;
    cout << "Ingrese nombre: ";
    getline(cin, nombre);
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    cout << "Ingrese DNI: ";
    getline(cin, dni);
    cout << "Ingrese fecha de nacimiento (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    Fecha fechaNacimiento(dia,mes,anio);
    cout << "Ingrese fecha de alta (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    Fecha fechaAlta(dia,mes,anio);
    cout << "Ingrese ID de empresa: ";
    cin >> idEmpresa;
    cout << "Ingrese ID de área: ";
    cin >> idArea;
    cout << "Ingrese ID de rol: ";
    cin >> idRol;
    cout << "Ingrese horas trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese sueldo: ";
    cin >> sueldo;
    cout << "Ingrese fecha de contratación (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    Fecha fechaContratacion(dia,mes,anio);


    return Empleado(nombre,apellido,dni,fechaAlta,idLegajo,idEmpresa,idArea,idRol,horasTrabajadas,sueldo,fechaContratacion,fechaBaja,estado);
}

///TODO: BORRAR
void EmpleadosManager::mostrarEmpleado(Empleado registro)
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
    cout << "ESTADO           : " << (registro.getEstado()? "Activo" : "Baja")<< endl;

}

void EmpleadosManager::bajaEmpleado()
{
    Empleado registro;
    bool estado;
    int idLegajo, posicion;
    cout << "Ingrese el legajo a buscar: ";
    cin >> idLegajo;

    posicion = _empleadoArchivo.buscarID(idLegajo);
    if(posicion >=0)
    {
        registro = _empleadoArchivo.leer(posicion);
        listarEmpleado(registro);
        cout << "-------------------------" << endl;
        cout << "Desea dar de baja el empleado seleccionado? (1-Si/0-No): ";
        cin >> estado;
        registro.setEstado(estado);
        _empleadoArchivo.guardar(posicion,registro);
        cout << "El empleado " << registro.getApellido() <<", " << registro.getNombre() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe un empleado con legajo " << idLegajo << endl;
    }

}

