#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "Persona.h"

Persona::Persona()
{

    strcpy(_nombre,"");
    strcpy(_apellido,"");
    strcpy(_DNI,"");
    _fechaNacimiento = Fecha();

}
Persona::Persona(std::string nombre, std::string apellido, std::string DNI, Fecha fechaNacimiento)
{
    setNombre(nombre);
    setApellido(apellido);
    setDNI(DNI);
    setFechaNacimiento(fechaNacimiento);

}

string Persona::getNombre()
{
    return _nombre;

}

string Persona::getApellido()
{
    return _apellido;
}

string Persona::getDNI()
{
    return _DNI;
}

Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}

void Persona::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str());
}

void Persona::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}

void Persona::setDNI(std::string DNI)
{
    strcpy(_DNI,DNI.c_str());

}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}
