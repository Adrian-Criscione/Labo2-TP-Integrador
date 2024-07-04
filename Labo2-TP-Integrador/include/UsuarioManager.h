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

    void HacerCopiaSeguridad();
    void RestaurarCopiaSeguridad();

    UsuarioArchivo _usuarioArchivo;
    UsuarioArchivo _usuarioBkp = UsuarioArchivo("Backup/Usuarios.bkp");
};

#endif // USUARIOMANAGER_H
