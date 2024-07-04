#include <iostream>
#include <cstdlib>
#include "AreaArchivo.h"
#include <cstring>

AreaArchivo::AreaArchivo()
{
    _nombre = "Datos/areas.dat";
}
AreaArchivo::AreaArchivo(std::string nombre)
{
    setNombreArchivo(nombre);
}
void AreaArchivo::setNombreArchivo(std::string nombre)
{
    _nombre = nombre;
}

bool AreaArchivo::guardar(Area registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "ab");

    if (pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&registro, sizeof(Area), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool AreaArchivo::guardar(int indice, Area registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb+");

    if (pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Area) * indice, SEEK_SET);

    resultado = fwrite(&registro, sizeof(Area), 1, pFile);

    fclose(pFile);

    return resultado;
}
bool AreaArchivo::guardar(Area* registros, int cantidadRegistros)
{
    FILE *pFile = nullptr;
    int resultado = 0;
    pFile = fopen(_nombre.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(registros,sizeof(Area),cantidadRegistros,pFile);
    fclose(pFile);
    return resultado == cantidadRegistros;
}

void AreaArchivo::vaciar()
{
    FILE *pFile;
    pFile = fopen(_nombre.c_str(),"wb");
    if(pFile == nullptr)
    {
        return;
    }

    fclose(pFile);

}

Area AreaArchivo::leer(int indice)
{
    Area registro;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb");

    if (pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile, sizeof(Area) * indice, SEEK_SET);

    fread(&registro, sizeof(Area), 1, pFile);

    fclose(pFile);

    return registro;
}

void AreaArchivo::leerTodos(Area registros[], int cantidad)
{
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb");

    if (pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(Area), cantidad, pFile);

    fclose(pFile);
}

int AreaArchivo::buscarID(int idArea)
{
    Area registro;
    int pos = 0;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb");

    if (pFile == nullptr)
    {
        return -1;
    }

    while (fread(&registro, sizeof(Area), 1, pFile))
    {
        if (registro.getIdArea() == idArea)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int AreaArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;
    pFile = fopen(_nombre.c_str(), "rb");
    if(pFile == nullptr)
    {
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    tam = ftell(pFile) / sizeof(Area);

    fclose(pFile);

    return tam;

}

int AreaArchivo::getNuevoID()
{
    int cantidad = getCantidadRegistros();

    if (cantidad > 0)
    {
        return leer(cantidad - 1).getIdArea() + 1;
    }
    else
    {
        return 1;
    }
}

