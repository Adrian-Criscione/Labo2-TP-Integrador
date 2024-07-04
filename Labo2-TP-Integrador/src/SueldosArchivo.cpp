#include <iostream>
#include <cstdlib>
#include "SueldosArchivo.h"

using namespace std;



SueldosArchivo::SueldosArchivo()
{
    _nombre = "Datos/sueldos.dat";
}

SueldosArchivo::SueldosArchivo(std::string nombre)
{
    setNombreArchivo(nombre);
}

bool SueldosArchivo::guardar(Sueldos registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"ab");

    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Sueldos),1,pFile);

    fclose(pFile);

    return resultado;
}

bool SueldosArchivo::guardar(int indice, Sueldos registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Sueldos)*indice,SEEK_SET);

    resultado = fwrite(&registro,sizeof(Sueldos),1,pFile);

    fclose(pFile);

    return resultado;

}

Sueldos SueldosArchivo::leer(int indice)
{
    Sueldos registro;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile,sizeof(Sueldos)*indice,SEEK_SET);

    fread(&registro,sizeof(Sueldos),1,pFile);

    fclose(pFile);

    return registro;

}

bool SueldosArchivo::guardar(Sueldos* sueldos, int cantidadRegistros)
{
    FILE *pFile = nullptr;
    int resultado = 0;
    pFile = fopen(_nombre.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(sueldos,sizeof(Sueldos),cantidadRegistros,pFile);
    fclose(pFile);
    return resultado == cantidadRegistros;
}

void SueldosArchivo::vaciar()
{
    FILE *pFile;
    pFile = fopen(_nombre.c_str(),"wb");
    if(pFile == nullptr)
    {
        return;
    }

    fclose(pFile);

}

void SueldosArchivo::leerTodos(Sueldos registros[], int cantidad)
{
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros,sizeof(Sueldos),cantidad,pFile);

    fclose(pFile);

}

void SueldosArchivo::setNombreArchivo(std::string nombre)
{
    _nombre = nombre;
}

int SueldosArchivo::buscarID(int idSueldos)
{
    Sueldos registro;
    int pos = 0;
    FILE *pFile;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro,sizeof(Sueldos),1,pFile))
    {
        if(registro.getIdSueldo() == idSueldos)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int SueldosArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;
    pFile = fopen(_nombre.c_str(),"rb");
    if(pFile == nullptr)
    {
        return -1;
    }
    fseek(pFile,0,SEEK_END);
    tam = ftell(pFile) / sizeof(Sueldos);

    fclose(pFile);

    return tam;
}

int SueldosArchivo::getNuevoID()
{
    int cantidad = getCantidadRegistros();

    if(cantidad>0)
    {
        return leer(cantidad-1).getIdSueldo()+1;
    }
    else
    {
        return 10;
    }

}
