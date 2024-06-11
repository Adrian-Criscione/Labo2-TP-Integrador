#ifndef EMPRESA_H
#define EMPRESA_H
#include "Fecha.h"

class Empresa
{
    public:
        //CONSTRUCTOR
        Empresa(int idEmpresa, char razonSocial[30], char cuit[11], Fecha fechaAlta, Fecha fechaBaja);

        //GETTERS
        int getIdEmpresa();
        std::string getRazonSocial();
        std::string getCuit();
        Fecha getFechaAlta();
        Fecha getFechaBaja();

        //SETTERS
        void setIdEmpresa(int idEmpresa);
        void setRazonSocial(std::string razonSocial);
        void setCuit(std::string cuit);
        void setFechaAlta(Fecha fechaAlta);
        void setFechaBaja(Fecha fechaBaja);



    private:
       int _idEmpresa;
       char _razonSocial[30];
       char _cuit[11];
       Fecha _fechaAlta;
       Fecha _fechaBaja;



};

#endif // EMPRESA_H
