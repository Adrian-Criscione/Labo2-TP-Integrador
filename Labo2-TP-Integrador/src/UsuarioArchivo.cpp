#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "UsuarioArchivo.h"

UsuarioArchivo::UsuarioArchivo()
{
    strcpy(_nombre,"usuarios.dat");
}
bool UsuarioArchivo::guardar(Usuario registro)
{
    bool resultado;
    FILE *pFile = nullptr;

    pFile = fopen(_nombre,"ab");

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

    pFile = fopen(_nombre, "rb+");

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

    pFile = fopen(_nombre,"rb");

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

    pFile = fopen(_nombre,"rb");

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

    pFile = fopen(_nombre,"rb");

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
    pFile = fopen(_nombre,"rb");

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

///METODOS COMENTADOS POR EL MOMENTO ( NO ESTAN MAL, PERO HAY QUE CORREGIR LA LOGICA DE TODO EL ARCHIVO EN GENERAL
/*
void UsuarioArchivo::hacerBackup(const char* nombreBackup)
{
    const char* nombreArchivo = "usuarios.dat";

    FILE* pFile = fopen(nombreArchivo, "rb");
    if (!pFile) {
        cerr << "Error al abrir el archivo original para backup." << endl;
        return;
    }

    FILE* pBackup = fopen(nombreBackup, "wb");
    if (!pBackup) {
        cerr << "Error al crear el archivo de backup." << endl;
        fclose(pFile);
        return;
    }

    Usuario registro;
    while (fread(&registro, sizeof(Usuario), 1, pFile))
    {
        fwrite(&registro, sizeof(Usuario), 1, pBackup);
    }

    fclose(pFile);
    fclose(pBackup);
}

void UsuarioArchivo::restaurarBackup(const char* nombreBackup)
{
    FILE* pBackup = fopen(nombreBackup, "rb");
    if (!pBackup) {
        cerr << "Error al abrir el archivo de backup." << endl;
        return;
    }

    const char* nombreArchivo = "usuarios.dat";

    FILE* pFile = fopen(nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al crear el archivo original para restaurar." << endl;
        fclose(pBackup);
        return;
    }

    Usuario registro;
    while (fread(&registro, sizeof(Usuario), 1, pBackup))
    {
        fwrite(&registro, sizeof(Usuario), 1, pFile);
    }

    fclose(pFile);
    fclose(pBackup);
}
*/
