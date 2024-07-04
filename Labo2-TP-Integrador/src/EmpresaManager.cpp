#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "EmpresaManager.h"
#include "AppManager.h"

using namespace std;

void EmpresaManager::menuEmpresa()
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
        std::cout << "               MENU EMPRESAS";
        ap. setColorLineas();
        std::cout << "                    *" << std::endl;
        std::cout << "********************************************************" << std::endl;

        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. AGREGAR EMPRESA" << "              4. ELIMINAR EMPRESA";
        ap.setColorIngresoTexto();
        std::cout << "  *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "2. LISTAR EMPRESAS" << "              5. BACKUP ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "    *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "3. MODIFICAR EMPRESAS" << "           6. RESTORE ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "   *" << std::endl;
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

void EmpresaManager::menuModificarEmpresa()
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
        std::cout << "               MENU MODIFICAR EMPRESA";
        ap. setColorLineas();
        std::cout << "           *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. MODIFICAR RAZON SOCIAL" << "        2. MODIFICAR CUIT";
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
    AppManager ap;
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
        ///CARGA RAZON SOCIAL
        do
        {
            ap.setColorTexto();
            cout << "Ingrese Razon Social: ";
            ap.setColorIngresoTexto();
            getline(cin,nuevoNombre);
            if(!ap.esStringValido(nuevoNombre,true,false,false)) ///true = permitir espacios / false = no permitir numeros / false = no permitir caracteres especiales
            {
                ap.setColorError();
                cout << "Razon social incorrecta." << endl;
                ap.setColorIngresoTexto();
            }
        }
        while(!ap.esStringValido(nuevoNombre,true,false,false));

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
    //system("cls");
    AppManager ap;
    Empresa registro;
    int idEmpresa, posicion;
    ap.setColorTexto();
    cout << "Ingrese un ID de Empresa a buscar: ";
    ap.setColorIngresoTexto();
    cin >> idEmpresa;
    cin.ignore();
    posicion = _empresaArchivo.buscarID(idEmpresa);

    if(posicion >= 0)
    {
        registro = _empresaArchivo.leer(posicion);
        mostrarEmpresa(registro);
        cout << "----------------------------" << endl;

        string nuevoCuit;

        ///CARGA DEL CUIT
        do
        {
            ap.setColorTexto();
            cout << "Ingrese el CUIT: ";
            ap.setColorIngresoTexto();
            getline(cin,nuevoCuit);
            if(!esCuitValido(nuevoCuit))
            {
                ap.setColorError();
                cout << "Cuit incorrecto." << endl;
                ap.setColorIngresoTexto();

            }
        }
        while(!esCuitValido(nuevoCuit));


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
    if(cantidad >0)
    {
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
    else
    {
        cout << "No hay registros para listar." << endl;
    }
}


Empresa EmpresaManager::crearEmpresa()
{
    AppManager ap;
    int idEmpresa;
    string razonSocial;
    string cuit;
    Fecha fechaAlta;


    idEmpresa = _empresaArchivo.getNuevoID();
    cout << endl;
    ap.setColorTexto();
    cout << "Ingrese un ID: ";
    ap.setColorIngresoTexto();
    cout << idEmpresa << endl;
    cin.ignore();

    ///CARGA RAZON SOCIAL
    do
    {
        ap.setColorTexto();
        cout << "Ingrese Razon Social: ";
        ap.setColorIngresoTexto();
        getline(cin,razonSocial);
        if(!ap.esStringValido(razonSocial,true,false,false)) ///true = permitir espacios / false = no permitir numeros / false = no permitir caracteres especiales
        {
            ap.setColorError();
            cout << "Razon social incorrecta." << endl;
            ap.setColorIngresoTexto();
        }
    }
    while(!ap.esStringValido(razonSocial,true,false,false));

    ///CARGA DEL CUIT
    do
    {
        ap.setColorTexto();
        cout << "Ingrese el CUIT: ";
        ap.setColorIngresoTexto();
        getline(cin,cuit);
        if(!esCuitValido(cuit))
        {
            ap.setColorError();
            cout << "Cuit incorrecto." << endl;
            ap.setColorIngresoTexto();

        }
    }
    while(!esCuitValido(cuit));


    return Empresa(idEmpresa,razonSocial,cuit,fechaAlta,true);

}

void EmpresaManager::mostrarEncabezado()
{
    AppManager ap;

    ap.setColorLineas();
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    ap.setColorNombreMenu();
    cout << left << setw(6)  << "ID" << setw(30) << "RAZON SOCIAL" << setw(15) << "CUIT"
         << setw(12) << "FECHA ALTA" << setw(10) << "ESTADO"<< endl;
    ap.setColorLineas();
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
    cout << endl;
    posicion = _empresaArchivo.buscarID(idEmpresa);
    if(posicion >=0)
    {
        registro = _empresaArchivo.leer(posicion);
        if(registro.getEstado()==false)
        {
           cout << "La empresa ya fue dada de baja." << endl;
           return;
        }
        mostrarEncabezado();
        mostrarEmpresa(registro);

        cout << "Desea dar de baja la empresa? (1-Si/0-No) ";
        cin >> estado;
        if(estado == false)
        {
            return;
        }

        registro.setEstado(!estado);
        _empresaArchivo.guardar(posicion,registro);
        cout << "La Empresa " << registro.getRazonSocial() << " se ha dado de baja." << endl;
    }
    else
    {
        cout << "No existe una empresa con ID. " << idEmpresa << endl;
    }
}

void EmpresaManager::HacerCopiaSeguridad()
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
    _empresaBkp.vaciar();
    if(_empresaBkp.guardar(empresas,cantidad))
    {
        cout << "BACKUP REALIZADO CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO EL BACKUP." << endl;
    }
    delete [] empresas;
}

void EmpresaManager::RestaurarCopiaSeguridad()
{
    system("cls");
    int cantidad = _empresaBkp.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Empresa *empresas;
    empresas = new Empresa[cantidad];

    if(empresas == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _empresaBkp.leerTodos(empresas,cantidad);
    _empresaArchivo.vaciar();
    if(_empresaArchivo.guardar(empresas,cantidad))
    {
        cout << "RESTAURACION REALIZADA CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO LA RESTAURACION." << endl;
    }
    delete [] empresas;

}

///VALIDACION DE CUIT
bool EmpresaManager::esCuitValido(std::string cuit)
{
    int i;
    int cantidad = cuit.length();
    if (cantidad != 11)
    {
        return false; // El CUIT debe tener 11 dígitos
    }

    for (i = 0; i < cantidad; ++i)
    {
        if (!isdigit(cuit[i]))
        {
            return false; // Si algún carácter no es un dígito, el CUIT no es válido
        }
    }

    return true; // Todos los caracteres son dígitos y la longitud es correcta
}


