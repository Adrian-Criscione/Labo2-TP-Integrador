#include <iostream>
#include <cstdlib>
#include <cstring>
#include "EmpresaArchivo.h"

using namespace std;

EmpresaArchivo::EmpresaArchivo()
{
    strcpy(_nombre,"empresas.dat");

}

bool EmpresaArchivo::guardar(Empresa registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre,"ab");

    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Empresa),1,pFile);

    fclose(pFile);

    return resultado;

}

bool EmpresaArchivo::guardar(int indice, Empresa registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre, "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Empresa)*indice,SEEK_SET);

    resultado = fwrite(&registro,sizeof(Empresa),1,pFile);

    fclose(pFile);

    return resultado;

}

Empresa EmpresaArchivo::leer(int indice)
{
    //bool resultado;
    Empresa registro;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre,"rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile,sizeof(Empresa)*indice,SEEK_SET);

    fread(&registro,sizeof(Empresa),1,pFile);

    fclose(pFile);

    return registro;

}

void EmpresaArchivo::leerTodos(Empresa registros[], int cantidad)
{
    FILE *pFile = nullptr;

    pFile = fopen(_nombre, "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros,sizeof(Empresa),cantidad,pFile);

    fclose(pFile);

}

int EmpresaArchivo::buscarID(int idEmpresa)
{
    Empresa registro;
    int pos = 0;
    FILE *pFile;

    pFile = fopen(_nombre,"rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro,sizeof(Empresa),1,pFile))
    {
        if(registro.getIdEmpresa() == idEmpresa)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int EmpresaArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;
    pFile = fopen(_nombre,"rb");

    fseek(pFile,0,SEEK_END);
    tam = ftell(pFile) / sizeof(Empresa);

    fclose(pFile);

    return tam;

}

int EmpresaArchivo::getNuevoID()
{
    int cantidad = getCantidadRegistros();

    if(cantidad>0)
    {
        return leer(cantidad-1).getIdEmpresa()+1;
    }
    else
    {
        return 10;
    }

}

