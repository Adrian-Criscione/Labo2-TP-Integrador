#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include "Fecha.h"
class Empleado : public Persona
{
    public:
        ///CONSTRUCTORES
        Empleado();
        Empleado(std::string nombre, std::string apellido, std::string DNI, Fecha fechaNacimiento,int idLegado, int idEmpresa, int idArea, Fecha fechaContratacion, Fecha fechaBaja, bool estado);

        ///GETTERS
        int getIdLegajo();
        int getIdEmpresa();
        int getIdArea();

        Fecha geFechaContratacion();
        Fecha getFechaBaja();
        bool getEstado();

        ///SETTERS

        void setIdLegajo(int idLegajo);
        void setIdEmpresa(int idEmpresa);
        void setIdArea(int idArea);
        void setFechaContratacion(Fecha fechaContratacion);
        void setFechaBaja(Fecha fechaBaja);
        void setEstado(bool estado);


    protected:

    private:
        int _idLegajo;
        int _idEmpresa;
        int _idArea;
        //float _horasTrabajadas;
        //float _sueldo;
        Fecha _fechaContratacion;
        Fecha _fechaBaja;
        bool _estado;

};

#endif // EMPLEADO_H
