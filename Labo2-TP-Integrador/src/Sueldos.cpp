#include <iostream>
#include <cstdlib>


using namespace std;

#include "Sueldos.h"

Sueldos::Sueldos():_fechaLiquidacion(1,1,1)
{
    _idSueldo = 0;
    _idLegajo = 0;
    _idEmpresa = 0;
    _horasExtras = 0;
    _sueldo = 0;
    _estado = true;
}

Sueldos::Sueldos(int idSueldo, int idLegajo, int idEmpresa, Fecha fechaLiquidacion, float horasExtras, float sueldo, bool estado)
{
    setIdSueldo(idSueldo);
    setIdLegajo(idLegajo);
    setIdEmpresa(idEmpresa);
    setFechaLiquidacion(fechaLiquidacion);
    setHorasExtras(horasExtras);
    setSueldo(sueldo);
    setEstado(estado);

}

int Sueldos::getIdSueldo()
{
    return _idSueldo;
}

int Sueldos::getIdLegajo()
{
    return _idLegajo;
}

int Sueldos::getIdEmpresa()
{
    return _idEmpresa;
}
Fecha Sueldos::getFechaLiquidacion()
{
    return _fechaLiquidacion;
}

float Sueldos::getHorasExtras()
{
    return _horasExtras;
}

float Sueldos::getSueldo()
{
    return _sueldo;
}
bool Sueldos::getEstado()
{
    return _estado;
}

void Sueldos::setEstado(bool estado)
{
    _estado = estado;
}

void Sueldos::setIdSueldo(int idSueldo)
{
    _idSueldo = idSueldo;
}

void Sueldos::setIdLegajo(int idLegajo)
{
    _idLegajo = idLegajo;
}

void Sueldos::setIdEmpresa(int idEmpresa)
{
    _idEmpresa = idEmpresa;
}
void Sueldos::setFechaLiquidacion(Fecha fechaLiquidacion)
{
    _fechaLiquidacion = fechaLiquidacion;
}

void Sueldos::setHorasExtras(float horasExtras)
{
    _horasExtras = horasExtras;
}

void Sueldos::setSueldo(float sueldo)
{
    _sueldo = sueldo;
}
