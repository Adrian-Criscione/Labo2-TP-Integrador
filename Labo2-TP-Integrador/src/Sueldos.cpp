#include <iostream>
#include <cstdlib>


using namespace std;

#include "Sueldos.h"

Sueldos::Sueldos():_fechaLiquidacion(1,1,1)
{
    _idSueldo = 0;
    _idLegajo = 0;
    _horasExtras = 0;
    _sueldo = 0;
}

Sueldos::Sueldos(int idSueldo, int idLegajo, Fecha fechaLiquidacion, float horasExtras, float sueldo)
{
    setIdSueldo(idSueldo);
    setIdLegajo(idLegajo);
    setFechaLiquidacion(fechaLiquidacion);
    setHorasExtras(horasExtras);
    setSueldo(sueldo);

}

int Sueldos::getIdSueldo()
{
    return _idSueldo;
}

int Sueldos::getIdLegajo()
{
    return _idLegajo;
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

void Sueldos::setIdSueldo(int idSueldo)
{
    _idSueldo = idSueldo;
}

void Sueldos::setIdLegajo(int idLegajo)
{
    _idLegajo = idLegajo;
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
