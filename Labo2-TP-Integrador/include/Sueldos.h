#ifndef SUELDOS_H
#define SUELDOS_H
#include "Fecha.h"

class Sueldos
{
public:
    Sueldos();
    Sueldos(int idSueldo, int idLegajo, int idEmpresa, Fecha fechaLiquidacion, float horasExtras, float sueldo, bool estado);

    ///GETTERS
    int getIdSueldo();
    int getIdLegajo();
    int getIdEmpresa();
    Fecha getFechaLiquidacion();
    float getHorasExtras();
    float getSueldo();
    bool getEstado();

    ///SETTERS
    void setIdSueldo(int idSueldo);
    void setIdLegajo(int idLegajo);
    void setIdEmpresa(int idEmpresa);
    void setFechaLiquidacion(Fecha fechaLiquidacion);
    void setHorasExtras(float horasExtras);
    void setSueldo(float sueldo);
    void setEstado(bool estado);

private:
    int _idSueldo;
    int _idEmpresa;
    int _idLegajo;
    Fecha _fechaLiquidacion;
    float _horasExtras;
    float _sueldo;
    bool _estado;

};

#endif // SUELDOS_H
