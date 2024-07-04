#ifndef FECHA_H
#define FECHA_H
#include <iostream>


class Fecha
{
public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    //setter
    int getDia();
    int getMes();
    int getAnio();

    void fechaPorDefecto();
    //void mostrar();
    std::string toString();
    bool esBisiesto();
    //void AgregarDias(int dias);
    //void prueba();

private:
    int _dia;
    int _mes;
    int _anio;

    //void AgregarDia();
    //void RestarDia();

};

#endif // FECHA_H
