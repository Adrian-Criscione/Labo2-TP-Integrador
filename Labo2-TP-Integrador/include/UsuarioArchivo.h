#ifndef USUARIOARCHIVO_H
#define USUARIOARCHIVO_H

#include "Usuario.h"
#include <iostream>

using namespace std;

class UsuarioArchivo
{
public:
    UsuarioArchivo();
    bool guardar(Usuario registro);
    bool guardar(int indice, Usuario registro);
    Usuario leer(int indice);

    void leerTodos(Usuario registros[], int cantidad);

    int buscarID(int idUsuario);

    int getCantidadRegistros();
    int getNuevoID();

    ///METODOS COMENTADOS BREVEMENTE
    //void hacerBackup(const char* nombreBackup);
    //void restaurarBackup(const char* nombreBackup);
private:
    char _nombre[30];
};

#endif // USUARIOARCHIVO_H
