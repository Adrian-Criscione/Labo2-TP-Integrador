#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Empresa.h"
//using namespace std;


Empresa::Empresa():_fechaAlta(1,1,1)
{
    _idEmpresa = 0;
    strcpy(_razonSocial,"");
    strcpy(_cuit,"");
    _estado = true;

}

Empresa::Empresa(int idEmpresa, std::string razonSocial, std::string cuit, Fecha fechaAlta, bool estado)//: _fechaAlta
{
    setIdEmpresa(idEmpresa);
    setRazonSocial(razonSocial);
    setCuit(cuit);
    setFechaAlta(fechaAlta);
    estado = true;

}

int Empresa::getIdEmpresa()
{
    return _idEmpresa;
}

std::string Empresa::getRazonSocial()
{
    return _razonSocial;
}

std::string Empresa::getCuit()
{
    return _cuit;
}

Fecha Empresa::getFechaAlta()
{
    return _fechaAlta;
}

bool Empresa::getEstado()
{
    return _estado;
}

void Empresa::setIdEmpresa(int idEmpresa)
{
    _idEmpresa = idEmpresa;

}

void Empresa::setRazonSocial(std::string razonSocial)
{
    strcpy(_razonSocial,razonSocial.c_str());

}

void Empresa::setCuit(std::string cuit)
{
    strcpy(_cuit,cuit.c_str());

}

void Empresa::setFechaAlta(Fecha fechaAlta)
{
    _fechaAlta = fechaAlta;

}

void Empresa::setEstado(bool estado)
{
    _estado = estado;

}
