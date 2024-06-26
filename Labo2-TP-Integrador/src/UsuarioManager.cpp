#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "UsuarioManager.h"

using namespace std;

void UsuarioManager::menuUsuario()
{
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------- MENU USUARIO --------" << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR USUARIO " << endl;
        cout << "2- LISTAR TODOS LOS USUARIOS" << endl;
        cout << "3- MODIFICAR USUARIO" << endl;
        cout << "4- BAJA USUSARIO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
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
        }
    }
    while(opcion != 0);
}

void UsuarioManager::menuModificarUsuario()
{
    int opcion;
    do
    {
        system("cls");

        cout << "-------------------------------------" << endl;
        cout << "------ MENU MODIFICAR USUARIO -------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1- MODIFICAR NOMBRE" << endl;
        cout << "2- MODIFICAR CLAVE" << endl;
        cout << "3- MODIFICAR NIVEL DE ACCESO" << endl;
        cout << "-------------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
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
        cout << "Nombre de usuario modificado con �xito." << endl;
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
        cout << "Clave del usuario modificada con �xito." << endl;
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
        cout << "Nivel de acceso del usuario modificado con �xito." << endl;
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
        cout << "Estado del usuario modificado con �xito." << endl;
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
        cout << "El usuario fue guardado con �xito." << endl;
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
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << left
         << setw(6)  << " ID" << setw(15) << " APELLIDO" << setw(15) << " NOMBRE"
         << setw(12) << " DNI" << setw(12) << " USUARIO" << setw(12) << " CLAVE"
         << setw(10)  << " ACCESO" << setw(10) << " ESTADO" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
}

void UsuarioManager::mostrarUsuario(Usuario registro)
{
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
    /*
    cout << "ID Usuario: " << registro.getIdUsuario() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "DNI: " << registro.getDNI() << endl;
    cout << "Nombre de Usuario: " << registro.getUsuario() << endl;
    cout << "Clave: " << registro.getClave() << endl;
    cout << "Nivel de Acceso: " << registro.getAccesoNivel() << endl;
    cout << "Estado: " << (registro.getEstado() ? "Activo" : "Inactivo") << endl;
    */
}
