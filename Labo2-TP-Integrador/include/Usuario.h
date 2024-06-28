#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"
#include <string>

class Usuario : public Persona
{
public:
    // Constructores
    Usuario();
    Usuario(std::string nombre, std::string apellido, std::string DNI, Fecha fechaNacimiento,int idUsuario, std::string usuario, float clave, int accesoNivel, bool estado);

    // Getters
    int getIdUsuario();
    std::string getUsuario();
    float getClave();
    int getAccesoNivel();
    bool getEstado();

    // Setters
    void setIdUsuario(int idUsuario);
    void setUsuario(std::string usuario);
    void setClave(float clave);
    void setAccesoNivel(int accesoNivel);
    void setEstado(bool estado);


private:
    int _idUsuario;
    char _usuario[12];
    float _clave;
    int _accesoNivel;
    bool _estado;
};

#endif // USUARIO_H
