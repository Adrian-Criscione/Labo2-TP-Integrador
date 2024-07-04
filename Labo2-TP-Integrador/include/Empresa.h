#ifndef EMPRESA_H
#define EMPRESA_H
#include "Fecha.h"

class Empresa
{
public:
    //CONSTRUCTOR
    Empresa();
    Empresa(int idEmpresa, std::string razonSocial, std::string cuit, Fecha fechaAlta, bool estado);

    //GETTERS
    int getIdEmpresa();
    std::string getRazonSocial();
    std::string getCuit();
    Fecha getFechaAlta();
    bool getEstado();
    std::string getNombreID();
    std::string toString();
    //SETTERS
    void setIdEmpresa(int idEmpresa);
    void setRazonSocial(std::string razonSocial);
    void setCuit(std::string cuit);
    void setFechaAlta(Fecha fechaAlta);
    void setEstado(bool estado);



private:
    int _idEmpresa;
    char _razonSocial[30];
    char _cuit[11];
    Fecha _fechaAlta;
    bool _estado;


};

#endif // EMPRESA_H
