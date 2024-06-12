#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Empresa.h"
using namespace std;


Empresa::Empresa():_fechaAlta(1,1,1),_fechaBaja(1,1,1)
{
    _idEmpresa = 0;
    strcpy(_razonSocial,"");
    strcpy(_cuit,"");

}

Empresa::Empresa(int idEmpresa, char razonSocial[30], char cuit[11], Fecha fechaAlta, Fecha fechaBaja)
{
    setIdEmpresa(idEmpresa);
    setRazonSocial(razonSocial);
    setCuit(cuit);
    setFechaAlta(fechaAlta);
    setFechaBaja(fechaBaja);

}

int Empresa::getIdEmpresa()
{
    return _idEmpresa;
}

string Empresa::getRazonSocial()
{
    return _razonSocial;
}

string Empresa::getCuit()
{
    return _cuit;
}

Fecha Empresa::getFechaAlta()
{
    return _fechaAlta;
}

Fecha Empresa::getFechaBaja()
{
    return _fechaBaja;
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

void Empresa::setFechaBaja(Fecha fechaBaja)
{
    _fechaBaja = fechaBaja;

}
