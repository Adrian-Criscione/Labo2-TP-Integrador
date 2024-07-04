#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "AppManager.h"
#include "EmpleadosManager.h"
#include "Area.h"
#include "Empresa.h"
using namespace std;



void EmpleadosManager::menuEmpleado()
{
    AppManager ap;
    int opcion;
    do
    {
        rlutil::cls(); // Limpiar la pantalla

        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        ap.setColorNombreMenu();
        std::cout << "               MENU EMPLEADOS";
        ap.setColorLineas();
        std::cout << "                   *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. AGREGAR EMPLEADO" << "           5. CONSULTAR EMPLEADO";
        ap.setColorIngresoTexto();
        std::cout << "  *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "2. LISTAR EMPLEADOS" << "           6. BACKUP ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "      *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "3. MODIFICAR EMPLEADO" << "         7. RESTORE ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "     *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "4. ELIMINAR EMPLEADO";
        ap.setColorIngresoTexto();
        std::cout << "                                 *" << std::endl;
        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "0. SALIR";
        ap.setColorIngresoTexto();
        std::cout << "                                             *" << std::endl;

        ap.setColorLineas();
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "Opcion: ";
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
            //menuModificarEmpleado();
            cout << "Falta desarrollar. Disculpe las molestias." <<endl;
            system("pause");
            break;
        case 4:
            bajaEmpleado();
            system("pause");
            break;
        case 5:

            ///CONSULTAR EMPLEADO
            cout << "Falta desarrollar. Disculpe las molestias." <<endl;
            system("pause");
            break;
        case 6:
            HacerCopiaSeguridad();
            system("pause");
            break;
        case 7:
            RestaurarCopiaSeguridad();
            system("pause");
            break;
        }
    }
    while(opcion!=0);


}

void EmpleadosManager::menuModificarEmpleado()
{
    /*
        int _idLegajo;
        int _idEmpresa;
        int _idArea;
        //float _horasTrabajadas;
        //float _sueldo;
        Fecha _fechaContratacion;
        Fecha _fechaBaja;
        bool _estado;
    */

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

    mostrarEncabezado();

    for(int i = 0; i<cantidad; i++)
    {

        mostrarEmpleado(empleados[i]);

    }

    delete [] empleados;
}

Empleado EmpleadosManager::crearEmpleado()
{
    string nombre;
    string apellido;
    string dni;
    int dia, mes, anio;

    int idLegajo;
    int idEmpresa;
    int idArea;

    Fecha fechaBaja;
    bool estado=true;

    idLegajo = _empleadoArchivo.getNuevoID();
    cin.ignore();

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
    cout << "Ingrese ID de empresa: ";
    cin >> idEmpresa;
    cout << "Ingrese ID de área: ";
    cin >> idArea;

    ///VALIDACION: existe el idArea cargado en el paso anterior.
    while(_areaArchivo.buscarID(idArea) == -1)
    {
        cout << "ID de Area Incorrecto." << endl;
        cout << "Ingrese ID de área de nuevo: ";
        cin >> idArea;

    }

    cout << "Ingrese fecha de contratación (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    Fecha fechaContratacion(dia,mes,anio);


    return Empleado(nombre,apellido,dni,fechaNacimiento,idLegajo,idEmpresa,idArea,fechaContratacion,fechaBaja,estado);
}
void EmpleadosManager::mostrarEncabezado()
{
    AppManager ap;
    ap.setColorLineas();
    std::cout << "**************************************************************************************************************" << std::endl;

    ap.setColorNombreMenu();
    cout << left << setw(6)  << "ID" << setw(15) << "APELLIDO" << setw(15) << "NOMBRE" << setw(12) << "DNI"
         << setw(20) << "EMPRESA" << setw(20) << "AREA" << setw(12) << "ALTA"<< setw(10) << "ESTADO"<< endl;
    ap.setColorLineas();
    std::cout << "**************************************************************************************************************" << std::endl;
}

void EmpleadosManager::mostrarEmpleado(Empleado registro)
{
    AppManager ap;
    /// para mostrar el nombre del area.

    int posNombreArea = _areaArchivo.buscarID(registro.getIdArea());
    Area nombreArea = _areaArchivo.leer(posNombreArea);
    /// para mostrar el nombre de la empresa
    int posNombreEmpresa = _empresaArchivo.buscarID(registro.getIdEmpresa());
    Empresa nombreEmpresa = _empresaArchivo.leer(posNombreEmpresa);

    ap.setColorDatosListados();
    cout << left << setw(6)  << registro.getIdLegajo() << setw(15) << registro.getApellido() << setw(15) << registro.getNombre() << setw(12) << registro.getDNI()
         << setw(20) << nombreEmpresa.getNombreID()<< setw(20) << nombreArea.getNombreID() << setw(12) << registro.geFechaContratacion().toString()
         << setw(10) << (registro.getEstado()? "Activo" : "Baja")<< endl << endl;
    ap.setColorIngresoTexto();
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
        cout << endl;
        mostrarEncabezado();
        mostrarEmpleado(registro);
        //cout << "-------------------------" << endl;
        cout << "Desea dar de baja el empleado seleccionado? (1-Si/0-No): ";
        cin >> estado;
        registro.setEstado(!estado);
        _empleadoArchivo.guardar(posicion,registro);
        cout << "El empleado " << registro.getApellido() <<", " << registro.getNombre() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe un empleado con legajo " << idLegajo << endl;
    }
}


void EmpleadosManager::HacerCopiaSeguridad()
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
    _empleadoBkp.vaciar();
    if(_empleadoBkp.guardar(empleados,cantidad))
    {
        cout << "BACKUP REALIZADO CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO EL BACKUP." << endl;
    }
    delete [] empleados;

}

void EmpleadosManager::RestaurarCopiaSeguridad()
{
    system("cls");
    int cantidad = _empleadoBkp.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Empleado *empleados;
    empleados = new Empleado[cantidad];

    if(empleados == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _empleadoBkp.leerTodos(empleados,cantidad);
    _empleadoArchivo.vaciar();
    if(_empleadoArchivo.guardar(empleados,cantidad))
    {
        cout << "RESTAURACION REALIZADA CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO LA RESTAURACION." << endl;
    }
    delete [] empleados;
}
