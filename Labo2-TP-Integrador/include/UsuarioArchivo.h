#ifndef USUARIOARCHIVO_H
#define USUARIOARCHIVO_H

#include "Usuario.h"
#include <iostream>

using namespace std;

class UsuarioArchivo
{
public:
    UsuarioArchivo();
    UsuarioArchivo(std::string nombre);
    bool guardar(Usuario registro);
    bool guardar(int indice, Usuario registro);
    Usuario leer(int indice);

    void leerTodos(Usuario registros[], int cantidad);
    bool guardar(Usuario *usuarios, int cantidadRegistros);
    void vaciar();
    void setNombreArchivo(std::string nombre);


    int buscarID(int idUsuario);

    int getCantidadRegistros();
    int getNuevoID();

private:
    std::string _nombre;
};

#endif // USUARIOARCHIVO_H
