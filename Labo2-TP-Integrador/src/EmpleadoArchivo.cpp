#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "EmpleadoArchivo.h"

EmpleadoArchivo::EmpleadoArchivo()
{
    _nombre = "Datos/empleados.dat";
}
EmpleadoArchivo::EmpleadoArchivo(std::string nombre)
{
    setNombreArchivo(nombre);
}
void EmpleadoArchivo::setNombreArchivo(std::string nombre)
{
    _nombre = nombre;
}

bool EmpleadoArchivo::guardar(Empleado registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"ab");

    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Empleado),1,pFile);

    fclose(pFile);

    return resultado;

}

bool EmpleadoArchivo::guardar(int indice, Empleado registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Empleado)*indice,SEEK_SET);

    resultado = fwrite(&registro,sizeof(Empleado),1,pFile);

    fclose(pFile);

    return resultado;

}

Empleado EmpleadoArchivo::leer(int indice)
{
    //bool resultado;
    Empleado registro;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile,sizeof(Empleado)*indice,SEEK_SET);

    fread(&registro,sizeof(Empleado),1,pFile);

    fclose(pFile);

    return registro;
}

void EmpleadoArchivo::leerTodos(Empleado registros[], int cantidad)
{
    FILE *pFile = nullptr;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros,sizeof(Empleado),cantidad,pFile);

    fclose(pFile);


}

int EmpleadoArchivo::buscarID(int idLegajo)
{
    Empleado registro;
    int pos = 0;
    FILE *pFile;

    pFile = fopen(_nombre.c_str(),"rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro,sizeof(Empleado),1,pFile))
    {
        if(registro.getIdLegajo() == idLegajo)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int EmpleadoArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;
    pFile = fopen(_nombre.c_str(),"rb");
    if(pFile == nullptr)
    {
        return -1;
    }
    fseek(pFile,0,SEEK_END);
    tam = ftell(pFile) / sizeof(Empleado);

    fclose(pFile);

    return tam;
}

int EmpleadoArchivo::getNuevoID()
{
    int cantidad = getCantidadRegistros();

    if(cantidad>0)
    {
        return leer(cantidad-1).getIdLegajo()+1;
    }
    else
    {
        return 10;
    }

}
bool EmpleadoArchivo::guardar(Empleado* registros, int cantidadRegistros)
{
    FILE *pFile = nullptr;
    int resultado = 0;
    pFile = fopen(_nombre.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(registros,sizeof(Empleado),cantidadRegistros,pFile);
    fclose(pFile);
    return resultado == cantidadRegistros;
}

void EmpleadoArchivo::vaciar()
{
    FILE *pFile;
    pFile = fopen(_nombre.c_str(),"wb");
    if(pFile == nullptr)
    {
        return;
    }

    fclose(pFile);

}
