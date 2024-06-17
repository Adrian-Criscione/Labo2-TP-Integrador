#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"

class Persona
{
    public:
        ///CONSTRUCTORES
        Persona();
        Persona(std::string nombre, std::string apellido, std::string DNI, Fecha fechaNacimiento);

        ///GETTERS
        std::string getNombre();
        std::string getApellido();
        std::string getDNI();
        Fecha getFechaNacimiento();

        ///SETTERS
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setDNI(std::string DNI);
        void setFechaNacimiento(Fecha fechaNacimiento);

    protected:

    private:
        char _nombre[30];
        char _apellido[30];
        char _DNI[8];
        Fecha _fechaNacimiento;

};

#endif // PERSONA_H
