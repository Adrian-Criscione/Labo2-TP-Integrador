#ifndef SUELDOS_H
#define SUELDOS_H
#include "Fecha.h"

class Sueldos
{
    public:
        Sueldos();

        int getIdSueldo();
        int getIdLegajo();


    private:
        int _idSueldo;
        int _idLegajo;
        Fecha _fechaLiquidacion;
        float _horasExtras;
        float _sueldo;

};

#endif // SUELDOS_H
