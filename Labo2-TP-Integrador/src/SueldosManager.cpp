#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "SueldosManager.h"
#include "Empleado.h"
#include "AppManager.h"
#include "EmpresaArchivo.h"
#include "EmpleadoArchivo.h"
#include "EmpleadosManager.h"
//using namespace std;



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
        ap.setColorTexto();
        std::cout << "Opcion: ";



        ap.setColorIngresoTexto();
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
        case 7:
            menuReportes();
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
void SueldosManager::menuReportes()
{
    AppManager ap;
    int opcion;
    do
    {
        rlutil::cls(); // Limpiar la pantalla

        ap. setColorLineas();
        std::cout << "*********************************************************************" << std::endl;
        std::cout << "*      ";
        ap.setColorNombreMenu();
        std::cout << "               MENU REPORTES";
        ap. setColorLineas();
        std::cout << "                                 *" << std::endl;
        std::cout << "*********************************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. SUELDO ANUAL POR EMPRESA" << "           3. PERSONAL DADO DE BAJA";
        ap.setColorIngresoTexto();
        std::cout << "    *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "2. CANTIDAD HORAS EXTRA POR SECTOR";
        ap.setColorIngresoTexto();
        std::cout << "                                *" << std::endl;
        ap. setColorLineas();
        std::cout << "*********************************************************************" << std::endl;

        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "0. SALIR";
        ap.setColorIngresoTexto();
        std::cout << "                                                          *" << std::endl;

        ap. setColorLineas();
        std::cout << "*********************************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:

            //1. REPORTE ANUAL POR EMPRESA
            ReporteTotalSueldosPorEmpresa();

            break;
        case 2:
            //2. CANTIDAD HORAS EXTRA POR SECTOR
            ReporteHorasExtrasPorEmpleadoYEmpresa();

            break;
        case 3:
            //3. PERSONAL DADO DE BAJA
            ReportePersonalDadoDeBajaPorEmpresa();

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
    AppManager ap;
    Empleado registro;
    int posicion;
    int idSueldo;
    int idLegajo;
    int idEmpresa;
    float horasExtra;
    float sueldo;
    int dia, mes, anio;



    idSueldo = _sueldosArchivo.getNuevoID();
    cout << "Ingrese un ID: " << idSueldo << endl;
    cin.ignore();

    ///VALIDAR QUE EL ID DE LEGAJO NO ESTE DADO DE BAJA
    do{
       cout << "Ingrese el ID de legajo; ";
        cin >> idLegajo;
        cin.ignore();

        posicion = _empleadoArchivo.buscarID(idLegajo);
        registro = _empleadoArchivo.leer(posicion);
         if(registro.getEstado()==false)
         {
             cout << "El Empleado está dado de baja." << endl;
         }
    }while(registro.getEstado()==false);

    ///VALIDACION: existe el idLegfa cargado en el paso anterior.
    while(posicion == -1)
    {
        ap.setColorError();
        cout << "ID de Legajo Incorrecto." << endl;
        ap.setColorTexto();
        cout << "Ingrese ID de Legajo de nuevo: ";
        ap.setColorIngresoTexto();
        cin >> idLegajo;
    }

    cout << "Ingrese el ID de empresa; ";
    cin >> idEmpresa;
    cin.ignore();

    ///TODO: VALIDAR LA EMPRESA CON EL EMPLEADO



    ///VALIDACION: existe el idEmresa cargado en el paso anterior.
    while(_empresaArchivo.buscarID(idEmpresa) == -1)
    {
        ap.setColorError();
        cout << "ID de empresa Incorrecto." << endl;
        ap.setColorTexto();
        cout << "Ingrese ID de empresa de nuevo: ";
        ap.setColorIngresoTexto();
        cin >> idEmpresa;
    }

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
    Fecha fechaLiquidacion(dia,mes,anio);
    return Sueldos(idSueldo,idLegajo,idEmpresa,fechaLiquidacion,horasExtra,sueldo,true);

}

///ESTE METODO LISTA TODAS LAS EMPRESAS CON MEMORIA DINAMICA.
void SueldosManager::listarSueldos()
{
    system("cls");
    int cantidad = _sueldosArchivo.getCantidadRegistros();
    if(cantidad>0)
    {
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
    else
    {
        cout << "No hay registros para listar." << endl;
    }

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
        if(registro.getEstado()==false)
        {
           cout << "El registro ya fue dado de baja." << endl;
           return;
        }
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
/// REPORTES
////////////////////////////////
// SUELDOS PAGADOS POR AÑO

void SueldosManager::ReporteTotalSueldosPorEmpresa()
{
    AppManager ap;
    Sueldos sueldo;
    int idEmpresa;
    int anio;
    ap.setColorTexto();
    cout << "Ingrese el id de la empresa: ";
    ap.setColorIngresoTexto();
    cin >> idEmpresa;
    ap.setColorTexto();
    cout << "Ingrese el año: ";
    ap.setColorIngresoTexto();
    cin >> anio;

    float totalSueldosPorMes[12] = {0.0f};
    int cantidad = _sueldosArchivo.getCantidadRegistros();
    int mes;

    for (int i = 0; i < cantidad; ++i)
    {
        sueldo = _sueldosArchivo.leer(i);


        if (sueldo.getIdEmpresa() == idEmpresa && sueldo.getFechaLiquidacion().getAnio() == anio && sueldo.getEstado())
        {
            mes = sueldo.getFechaLiquidacion().getMes() - 1; // Restamos 1 para ajustar el índice del arreglo (0-11)
            totalSueldosPorMes[mes] += sueldo.getSueldo();
        }
    }

    /// para mostrar el nombre de la empresa
    int posNombreEmpresa = _empresaArchivo.buscarID(sueldo.getIdEmpresa());
    Empresa nombreEmpresa = _empresaArchivo.leer(posNombreEmpresa);


    rlutil::cls();
    ap.setColorTexto();
    std::cout << "Total de sueldos pagados por la empresa con ID ";
    ap.setColorIngresoTexto();
    std::cout << nombreEmpresa.getNombreID();
    ap.setColorTexto();
    std::cout  << " en el año ";
    ap.setColorIngresoTexto();
    cout << anio;
    ap.setColorTexto();
    cout << " por mes:" << std::endl;
    ap.setColorTexto();
    std::cout << "Mes\tTotal Sueldos" << std::endl;


    for (int mes = 0; mes < 12; ++mes)
    {
        ap.setColorTexto();
        std::cout << (mes + 1);
         ap.setColorIngresoTexto();
        std::cout << "\t$" << totalSueldosPorMes[mes] << std::endl;
        cout << endl;
    }

    system("pause");
}

///HORAS EXTRAS DEL EMPLEADO

void SueldosManager::ReporteHorasExtrasPorEmpleadoYEmpresa()
{
    rlutil::cls();

    int cantidadSueldos = _sueldosArchivo.getCantidadRegistros();

    int maxIdEmpresa = 0;
    int maxIdLegajo = 0;
    for (int i = 0; i < cantidadSueldos; ++i)
    {
        Sueldos sueldo = _sueldosArchivo.leer(i);

        if (sueldo.getEstado())
        {

            if (sueldo.getIdEmpresa() > maxIdEmpresa)
            {
                maxIdEmpresa = sueldo.getIdEmpresa();
            }
            if (sueldo.getIdLegajo() > maxIdLegajo)
            {
                maxIdLegajo = sueldo.getIdLegajo();
            }
        }
    }

    //CREAMOS EL ARRAY
    float* horasExtrasPorEmpresa = new float[maxIdEmpresa + 1]();
    float** horasExtrasPorEmpleado = new float*[maxIdEmpresa + 1];

    for (int i = 0; i <= maxIdEmpresa; ++i)
    {
        horasExtrasPorEmpleado[i] = new float[maxIdLegajo + 1]();
    }

    // CARFGO HS EXTRAS

    for (int i = 0; i < cantidadSueldos; ++i)
    {
        Sueldos sueldo = _sueldosArchivo.leer(i);

        if (sueldo.getHorasExtras() > 0 && sueldo.getEstado())
        {
            int idEmpresa = sueldo.getIdEmpresa();
            int idLegajo = sueldo.getIdLegajo();
            horasExtrasPorEmpresa[idEmpresa] += sueldo.getHorasExtras();
            horasExtrasPorEmpleado[idEmpresa][idLegajo] += sueldo.getHorasExtras();
        }
    }

    // RESULTADOS
    rlutil::setColor(rlutil::LIGHTBLUE);
    std::cout << "Horas extras por empresa:" << std::endl;
    rlutil::resetColor();
    std::cout << "ID Empresa\tTotal Horas Extras" << std::endl;

    for (int idEmpresa = 0; idEmpresa <= maxIdEmpresa; ++idEmpresa)
    {
        if (horasExtrasPorEmpresa[idEmpresa] > 0)
        {
            std::cout << idEmpresa << "\t" << horasExtrasPorEmpresa[idEmpresa] << std::endl;

            std::cout << "ID Empleado\tHoras Extras" << std::endl;

            for (int idEmpleado = 0; idEmpleado <= maxIdLegajo; ++idEmpleado)
            {
                if (horasExtrasPorEmpleado[idEmpresa][idEmpleado] > 0)
                {
                    std::cout << idEmpleado << "\t" << horasExtrasPorEmpleado[idEmpresa][idEmpleado] << std::endl;
                }
            }
        }
    }

    // LIBERO MEMORIA
    delete[] horasExtrasPorEmpresa;

    for (int i = 0; i <= maxIdEmpresa; ++i)
    {

        delete[] horasExtrasPorEmpleado[i];
    }
    delete[] horasExtrasPorEmpleado;

    system("pause");
}

/// PERSONAL DADO DE BAJA POR LA EMPRESA (TE HICIERON ACA HERMANO)


void SueldosManager::ReportePersonalDadoDeBajaPorEmpresa()
{
    rlutil::cls();
    EmpleadosManager em;
    int cantidad = _empleadoArchivo.getCantidadRegistros();
    if(cantidad>0)
    {
        ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
        Empleado *empleados;
        empleados = new Empleado[cantidad];

        if(empleados == nullptr)
        {
            cout << "No se pudo obtener la memoria solicitada." << endl;
            return;
        }
        _empleadoArchivo.leerTodos(empleados,cantidad);

        em.mostrarEncabezadoBaja();
        for(int i = 0; i<cantidad; i++)
        {
            if(empleados[i].getEstado()== false)
            {

                em.mostrarEmpleadoBaja(empleados[i]);

            }
        }
        cout << endl;
        delete [] empleados;
    }
    else
    {
        cout << "No hay registros para listar." << endl;
    }


    /*
    // BUSCO LOS REGIS
    int cantidadSueldos = _sueldosArchivo.getCantidadRegistros();

    // BUSCAMOS EL MAXIMO ID DE LA EMPRESA PARA CALCULAR EL TAMAÑO DEL ARRAY
    int maxIdEmpresa = 0;

    for (int i = 0; i < cantidadSueldos; ++i)
    {
        Sueldos sueldo = _sueldosArchivo.leer(i);
        if (sueldo.getIdEmpresa() > maxIdEmpresa && !sueldo.getEstado())
        {
            maxIdEmpresa = sueldo.getIdEmpresa();
        }
    }

    ///CREAS ARRAY PARA ALMACENAR
    int* legajosDadoDeBajaPorEmpresa = new int[maxIdEmpresa + 1]();

    /// LLENAMOS CON EL PERSONAL DADO DE BAJA

    for (int i = 0; i < cantidadSueldos; ++i)
    {
        Sueldos sueldo = _sueldosArchivo.leer(i);
        if (!sueldo.getEstado())
        {
            int idEmpresa = sueldo.getIdEmpresa();
            legajosDadoDeBajaPorEmpresa[idEmpresa] = sueldo.getIdLegajo();
        }
    }

    /// MOSTRAMOS LOS POBRES DESEMPLEADOS

    rlutil::setColor(rlutil::LIGHTBLUE);
    std::cout << "Personal dado de baja por empresa:" << std::endl;
    rlutil::resetColor();
    std::cout << "ID Empresa\tID Legajo" << std::endl;

    for (int idEmpresa = 0; idEmpresa <= maxIdEmpresa; ++idEmpresa)
    {
        if (legajosDadoDeBajaPorEmpresa[idEmpresa] != 0)
        {
            std::cout << idEmpresa << "\t\t" << legajosDadoDeBajaPorEmpresa[idEmpresa] << std::endl;
        }
    }


    delete[] legajosDadoDeBajaPorEmpresa;
*/
    system("pause");
}
