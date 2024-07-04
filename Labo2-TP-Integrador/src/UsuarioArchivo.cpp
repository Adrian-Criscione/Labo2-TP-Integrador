#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "UsuarioArchivo.h"

UsuarioArchivo::UsuarioArchivo()
{
    _nombre = "Datos/Usuarios.dat";
}
UsuarioArchivo::UsuarioArchivo(std::string nombre)
{
    setNombreArchivo(nombre);
}

bool UsuarioArchivo::guardar(Usuario* usuarios, int cantidadRegistros)
{
    FILE *pFile = nullptr;
    int resultado = 0;
    pFile = fopen(_nombre.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(usuarios,sizeof(Usuario),cantidadRegistros,pFile);
    fclose(pFile);
    return resultado == cantidadRegistros;

}

void UsuarioArchivo::vaciar()
{
    FILE *pFile;
    pFile = fopen(_nombre.c_str(),"wb");
    if(pFile == nullptr)
    {
        return;
    }

    fclose(pFile);

}
void UsuarioArchivo::setNombreArchivo(std::string nombre)
{
    _nombre = nombre;
}


bool UsuarioArchivo::guardar(Usuario registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"ab");

    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Usuario),1,pFile);

    fclose(pFile);

    return resultado;

}
///SE UTILIZA PARA MODIFICAR EL ARCHIVO
bool UsuarioArchivo::guardar(int indice, Usuario registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Usuario)*indice,SEEK_SET);

    resultado = fwrite(&registro,sizeof(Usuario),1,pFile);

    fclose(pFile);

    return resultado;

}

Usuario UsuarioArchivo::leer(int indice)
{
    Usuario registro;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile,sizeof(Usuario)*indice,SEEK_SET);

    fread(&registro,sizeof(Usuario),1,pFile);

    fclose(pFile);

    return registro;
}

void UsuarioArchivo::leerTodos(Usuario registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros,sizeof(Usuario),cantidad,pFile);

    fclose(pFile);
}

int UsuarioArchivo::buscarID(int idUsuario)
{
    Usuario registro;
    int pos = 0;
    FILE *pFile;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while (fread(&registro, sizeof(Usuario), 1, pFile))
    {
        if (registro.getIdUsuario() == idUsuario)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int UsuarioArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;
    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return -1;
    }
    fseek(pFile,0,SEEK_END);
    tam = ftell(pFile) / sizeof(Usuario);

    fclose(pFile);

    return tam;
}

int UsuarioArchivo::getNuevoID()
{
    int cantidad = getCantidadRegistros();
    if (cantidad > 0)
    {
        return leer(cantidad - 1).getIdUsuario() + 1;
    }
    else
    {
        return 1;
    }
}

