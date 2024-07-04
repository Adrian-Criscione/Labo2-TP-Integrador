#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#include "Fecha.h"

void Fecha::fechaPorDefecto()
{
    ///carga la fecha de sistema si se carga mal la fecha
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon+1;
    _anio = f->tm_year+1900;

}



Fecha::Fecha()
{
    fechaPorDefecto();
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
    if (_dia <= 0 || _mes <= 0 || _anio <= 0 || _mes > 12)
    {
        fechaPorDefecto();
    }
    else
    {
        int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (esBisiesto())
        {
            dias[1]++;
        }

        if (_dia > dias[_mes-1])
        {
            fechaPorDefecto();
        }
    }


}


int Fecha::getDia()
{
    return _dia;

}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}




string Fecha::toString()
{
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}


bool Fecha::esBisiesto()
{
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0)
    {
        return true;
    }
    return false;
}


