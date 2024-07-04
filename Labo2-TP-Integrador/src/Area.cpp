#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Area.h"

// Constructor por defecto
Area::Area()
{
    _idArea = 0;
    strcpy(_nombre, "");
    _estado = true;
}

// Constructor con parámetros
Area::Area(int idArea, std::string nombre, bool estado)
{
    setIdArea(idArea);
    setNombre(nombre);
    setEstado(estado);
}

// Getter para _idArea
int Area::getIdArea()
{
    return _idArea;
}

// Getter para _nombre
std::string Area::getNombre()
{
    return _nombre;
}

// Setter para _idArea
void Area::setIdArea(int idArea)
{
    _idArea = idArea;
}

// Setter para _nombre
void Area::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
bool Area::getEstado()
{
    return _estado;
}

void Area::setEstado(bool estado)
{
    _estado = estado;
}

std::string Area::getNombreID()
{
    return getNombre() + " (" + std::to_string(_idArea) +")";
}
std::string Area::toString()
{
    return std::to_string(_idArea) + ", " + std::string(_nombre);
}
