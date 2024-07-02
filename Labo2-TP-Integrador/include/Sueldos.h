#ifndef SUELDOS_H
#define SUELDOS_H
#include "Fecha.h"

class Sueldos
{
    public:
        Sueldos();
        Sueldos(int idSueldo, int idLegajo, Fecha fechaLiquidacion, float horasExtras, float sueldo);

        ///GETTERS
        int getIdSueldo();
        int getIdLegajo();
        Fecha getFechaLiquidacion();
        float getHorasExtras();
        float getSueldo();

        ///SETTERS
        void setIdSueldo(int idSueldo);
        void setIdLegajo(int idLegajo);
        void setFechaLiquidacion(Fecha fechaLiquidacion);
        void setHorasExtras(float horasExtras);
        void setSueldo(float sueldo);

    private:
        int _idSueldo;
        int _idLegajo;
        Fecha _fechaLiquidacion;
        float _horasExtras;
        float _sueldo;

};

#endif // SUELDOS_H
