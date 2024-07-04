#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <rlutil.h>
#include "UsuarioManager.h"
#include "AppManager.h"

using namespace std;

void UsuarioManager::menuUsuario()
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
        std::cout << "               MENU USUARIO";
        ap. setColorLineas();
        std::cout << "                     *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. AGREGAR USUARIO" << "              4. BAJA USUSARIO";
        ap.setColorIngresoTexto();
        std::cout << "     *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "2. LISTAR USUARIOS" << "              5. BACKUP ARCHIVO";
        ap.setColorIngresoTexto();
        std::cout << "    *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "3. MODIFICAR USUARIO" << "            6. RESTORE ARCHIVO";
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
            agregarUsuario();
            system("pause");
            break;
        case 2:
            listarUsuarios();
            system("pause");
            break;
        case 3:
            menuModificarUsuario();
            system("pause");
            break;
        case 4:
            bajaUsuario();
            system("pause");
            break;
        case 5:
            ///backup
            system("pause");
            break;
        case 6:
            ///restore
            system("pause");
            break;
        }
    }
    while(opcion != 0);
}

void UsuarioManager::menuModificarUsuario()
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
        std::cout << "               MENU MODIFICAR USUARIO";
        ap. setColorLineas();
        std::cout << "           *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "1. MODIFICAR USUARIO" << "             2. MODIFICAR CLAVE";
        ap.setColorIngresoTexto();
        std::cout << "  *" << std::endl;
        ap.setColorIngresoTexto();
        std::cout << "* ";
        ap.setColorOpciones();
        std::cout << "3. MODIFICAR NIVEL DE ACCESO";
        ap.setColorIngresoTexto();
        std::cout << "                         *" << std::endl;
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
            modificarNombreUsuario();
            system("pause");
            break;
        case 2:
            modificarClaveUsuario();
            system("pause");
            break;
        case 3:
            modificarNivelAccesoUsuario();
            system("pause");
            break;
        }
    }
    while(opcion != 0);
}

void UsuarioManager::modificarNombreUsuario()
{
    system("cls");
    Usuario usuario;
    int idUsuario, posicion;
    cout << "Ingrese el ID del Usuario a buscar: ";
    cin >> idUsuario;
    cin.ignore();
    posicion = _usuarioArchivo.buscarID(idUsuario);

    if (posicion >= 0)
    {
        usuario = _usuarioArchivo.leer(posicion);
        mostrarUsuario(usuario);
        cout << "-----------------------------" << endl;

        string nuevoNombre;
        cout << "Ingrese el nuevo nombre del usuario: ";
        getline(cin, nuevoNombre);
        usuario.setNombre(nuevoNombre);
        _usuarioArchivo.guardar(posicion, usuario);
        cout << "Nombre de usuario modificado con éxito." << endl;
    }
    else
    {
        cout << "No existe un usuario con ID " << idUsuario << endl;
    }
}

void UsuarioManager::modificarClaveUsuario()
{
    system("cls");
    Usuario usuario;
    int idUsuario, posicion;
    cout << "Ingrese el ID del Usuario a buscar: ";
    cin >> idUsuario;
    cin.ignore();
    posicion = _usuarioArchivo.buscarID(idUsuario);

    if (posicion >= 0)
    {
        usuario = _usuarioArchivo.leer(posicion);
        mostrarUsuario(usuario);
        cout << "-----------------------------" << endl;

        float nuevaClave;
        cout << "Ingrese la nueva clave del usuario: ";
        cin >> nuevaClave;
        usuario.setClave(nuevaClave);
        _usuarioArchivo.guardar(posicion, usuario);
        cout << "Clave del usuario modificada con éxito." << endl;
    }
    else
    {
        cout << "No existe un usuario con ID " << idUsuario << endl;
    }
}

void UsuarioManager::modificarNivelAccesoUsuario()
{
    system("cls");
    Usuario usuario;
    int idUsuario, posicion;
    cout << "Ingrese el ID del Usuario a buscar: ";
    cin >> idUsuario;
    cin.ignore();
    posicion = _usuarioArchivo.buscarID(idUsuario);

    if (posicion >= 0)
    {
        usuario = _usuarioArchivo.leer(posicion);
        mostrarUsuario(usuario);
        cout << "-----------------------------" << endl;

        int nuevoNivelAcceso;
        cout << "Ingrese el nuevo nivel de acceso del usuario: ";
        cin >> nuevoNivelAcceso;
        usuario.setAccesoNivel(nuevoNivelAcceso);
        _usuarioArchivo.guardar(posicion, usuario);
        cout << "Nivel de acceso del usuario modificado con éxito." << endl;
    }
    else
    {
        cout << "No existe un usuario con ID " << idUsuario << endl;
    }
}

void UsuarioManager::bajaUsuario()
{
    system("cls");
    Usuario usuario;
    int idUsuario, posicion;
    cout << "Ingrese el ID del Usuario a buscar: ";
    cin >> idUsuario;
    cin.ignore();
    posicion = _usuarioArchivo.buscarID(idUsuario);

    if (posicion >= 0)
    {
        usuario = _usuarioArchivo.leer(posicion);
        mostrarUsuario(usuario);
        cout << "-----------------------------" << endl;

        bool nuevoEstado;
        cout << "Ingrese el nuevo estado del usuario (1: activo, 0: inactivo): ";
        cin >> nuevoEstado;
        usuario.setEstado(nuevoEstado);
        _usuarioArchivo.guardar(posicion, usuario);
        cout << "Estado del usuario modificado con éxito." << endl;
    }
    else
    {
        cout << "No existe un usuario con ID " << idUsuario << endl;
    }
}

void UsuarioManager::agregarUsuario()
{
    if (_usuarioArchivo.guardar(crearUsuario()))
    {
        cout << "El usuario fue guardado con éxito." << endl;
    }
    else
    {
        cout << "No se pudo guardar el usuario." << endl;
    }
}

void UsuarioManager::listarUsuarios()
{
    system("cls");
    int cantidad = _usuarioArchivo.getCantidadRegistros();

    if(cantidad >0)
    {
        Usuario* usuarios = new Usuario[cantidad];
        if (usuarios == nullptr)
        {
            cout << "No se pudo obtener la memoria solicitada." << endl;
            return;
        }

        _usuarioArchivo.leerTodos(usuarios, cantidad);

        mostrarEncabezado();
        for (int i = 0; i < cantidad; i++)
        {
            if (usuarios[i].getEstado())
            {


                mostrarUsuario(usuarios[i]);

            }
        }

        delete[] usuarios;
    }
    else
    {
        cout << "No hay usuarios para listar." << endl;
        return;
    }

}

Usuario UsuarioManager::crearUsuario()
{
    int idUsuario;
    string nombre, apellido, dni, nombreUsuario;
    int dia, mes, anio;
    float clave;
    int accesoNivel;
    bool estado = true;

    idUsuario = _usuarioArchivo.getNuevoID();
    cout << "ID asignado: " << idUsuario << endl;

    cin.ignore();
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nombre);
    cout << "Ingrese el apellido del usuario: ";
    getline(cin, apellido);
    cout << "Ingrese el DNI del usuario: ";
    getline(cin, dni);
    cout << "Ingrese fecha de nacimiento (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    Fecha fechaNacimiento(dia,mes,anio);
    cin.ignore();
    cout << "Ingrese el nombre de usuario: ";
    getline(cin, nombreUsuario);
    cout << "Ingrese la clave del usuario: ";
    cin >> clave;
    cin.ignore();
    cout << "Ingrese el nivel de acceso del usuario: ";
    cin >> accesoNivel;

    return Usuario(nombre,apellido,dni,fechaNacimiento,idUsuario,nombreUsuario,clave,accesoNivel,estado);

}
void UsuarioManager::mostrarEncabezado()
{
    AppManager ap;
    ap. setColorLineas();
    std::cout << "******************************************************************************************************" << std::endl;
    ap.setColorNombreMenu();
    cout << left
         << setw(6)  << " ID" << setw(15) << " APELLIDO" << setw(15) << " NOMBRE"
         << setw(12) << " DNI" << setw(12) << " USUARIO" << setw(12) << " CLAVE"
         << setw(10)  << " ACCESO" << setw(10) << " ESTADO" << endl;
    ap. setColorLineas();
    std::cout << "******************************************************************************************************" << std::endl;
    ap.setColorIngresoTexto();
}

void UsuarioManager::mostrarUsuario(Usuario registro)
{
    AppManager ap;
    ap.setColorDatosListados();
    cout << left <<" "
         << setw(6) << registro.getIdUsuario()
         << setw(15) << registro.getApellido()
         << setw(15) << registro.getNombre()
         << setw(12) << registro.getDNI()
         << setw(12) << registro.getUsuario()
         << setw(12) << registro.getClave()
         << setw(10)  << registro.getAccesoNivel()
         << setw(10)  << (registro.getEstado() ? "Activo" : "Baja")
         << endl;
}
void UsuarioManager::HacerCopiaSeguridad()
{
    system("cls");
    int cantidad = _usuarioArchivo.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Usuario *usuarios;
    usuarios = new Usuario[cantidad];

    if(usuarios == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _usuarioArchivo.leerTodos(usuarios,cantidad);
    _usuarioBkp.vaciar();
    if(_usuarioBkp.guardar(usuarios,cantidad))
    {
        cout << "BACKUP REALIZADO CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO EL BACKUP." << endl;
    }
    delete [] usuarios;

}

void UsuarioManager::RestaurarCopiaSeguridad()
{
    system("cls");
    int cantidad = _usuarioBkp.getCantidadRegistros();

    ///UTILIZACION DE MEMORIA DINAMICA PARA LISTAR LAS EMPRESAS
    Usuario *usuarios;
    usuarios = new Usuario[cantidad];

    if(usuarios == nullptr)
    {
        cout << "No se pudo obtener la memoria solicitada." << endl;
        return;
    }
    _usuarioBkp.leerTodos(usuarios,cantidad);
    _usuarioArchivo.vaciar();
    if(_usuarioArchivo.guardar(usuarios,cantidad))
    {
        cout << "RESTAURACION REALIZADA CORRECTAMENTE." << endl;
    }
    else
    {
        cout << "FALLO LA RESTAURACION." << endl;
    }
    delete [] usuarios;

}
