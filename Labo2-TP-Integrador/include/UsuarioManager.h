#ifndef USUARIOMANAGER_H
#define USUARIOMANAGER_H

#include "Usuario.h"
#include "UsuarioArchivo.h"

class UsuarioManager
{
public:
    void menuUsuario();
    void menuModificarUsuario();


private:
    void agregarUsuario();
    void listarUsuarios();


    void modificarNombreUsuario();
    void modificarClaveUsuario();
    void modificarNivelAccesoUsuario();

    void bajaUsuario();

    Usuario crearUsuario();
    void mostrarEncabezado();
    void mostrarUsuario(Usuario registro);

    UsuarioArchivo _usuarioArchivo;
};

#endif // USUARIOMANAGER_H
