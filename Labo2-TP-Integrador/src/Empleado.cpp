#include <iostream>
#include <cstdlib>


using namespace std;

#include "Empleado.h"

Empleado::Empleado() : Persona()
{
    _idLegajo = 0;
    _idEmpresa = 0;
    _idArea = 0;
    _horasTrabajadas = 0.0f;
    _sueldo = 0.0f;
    _fechaContratacion =Fecha();
    _fechaBaja = Fecha();
    _estado = true;
}
Empleado::Empleado(std::string nombre, std::string apellido, std::string DNI, Fecha fechaNacimiento, int idLegajo, int idEmpresa, int idArea, float horasTrabajadas, float sueldo, Fecha fechaContratacion, Fecha fechaBaja, bool estado) : Persona(nombre,apellido, DNI, fechaNacimiento)
{
    setIdLegajo(idLegajo);
    setIdEmpresa(idEmpresa);
    setIdArea(idArea);
    setHorasTrabajadas(horasTrabajadas);
    setSueldo(sueldo);
    setFechaContratacion(fechaContratacion);
    setFechaBaja(fechaBaja);
    setEstado(estado);


}
int Empleado::getIdLegajo()
{
    return _idLegajo;
}

int Empleado::getIdEmpresa()
{
    return _idEmpresa;

}

int Empleado::getIdArea()
{
    return _idArea;
}


float Empleado::getHorasTrabajadas()
{
    return _horasTrabajadas;

}

float Empleado::getSueldo()
{
    return _sueldo;

}

Fecha Empleado::geFechaContratacion()
{
    return _fechaContratacion;

}

Fecha Empleado::getFechaBaja()
{
    return _fechaBaja;

}

bool Empleado::getEstado()
{
    return _estado;

}

void Empleado::setIdLegajo(int idLegajo)
{
    _idLegajo = idLegajo;
}

void Empleado::setIdEmpresa(int idEmpresa)
{
    _idEmpresa = idEmpresa;

}

void Empleado::setIdArea(int idArea)
{
    _idArea = idArea;
}


void Empleado::setHorasTrabajadas(float horasTrabajadas)
{
    _horasTrabajadas = horasTrabajadas;

}

void Empleado::setSueldo(float sueldo)
{
    _sueldo = sueldo;

}

void Empleado::setFechaContratacion(Fecha fechaContratacion)
{
    _fechaContratacion = fechaContratacion;

}

void Empleado::setFechaBaja(Fecha fechaBaja)
{
    _fechaBaja = fechaBaja;

}

void Empleado::setEstado(bool estado)
{
    _estado = estado;
}
