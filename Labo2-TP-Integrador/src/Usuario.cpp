#include "Usuario.h"
#include <cstring>

Usuario::Usuario() : Persona()
{
    _idUsuario = 0;
    strcpy(_usuario,"");
    _clave = 0;
    _accesoNivel = 0;
    _estado = true;
}

Usuario::Usuario(std::string nombre, std::string apellido, std::string DNI, Fecha fechaNacimiento,int idUsuario, std::string usuario, float clave, int accesoNivel, bool estado) : Persona(nombre,apellido,DNI, fechaNacimiento)
{
    setIdUsuario(idUsuario);
    setUsuario(usuario);
    setClave(clave);
    setAccesoNivel(accesoNivel);
    setEstado(estado);

}

int Usuario::getIdUsuario()
{
    return _idUsuario;
}

std::string Usuario::getUsuario()
{
    return _usuario;
}

float Usuario::getClave()
{
    return _clave;
}

int Usuario::getAccesoNivel()
{
    return _accesoNivel;
}

bool Usuario::getEstado()
{
    return _estado;
}

void Usuario::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}

void Usuario::setUsuario(std::string usuario)
{
    strcpy(_usuario, usuario.c_str());
}

void Usuario::setClave(float clave)
{
    _clave = clave;
}

void Usuario::setAccesoNivel(int accesoNivel)
{
    _accesoNivel = accesoNivel;
}

void Usuario::setEstado(bool estado)
{
    _estado = estado;
}
