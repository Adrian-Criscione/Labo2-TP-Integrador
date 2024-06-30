#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "EmpresaManager.h"
#include "EmpleadosManager.h"
#include "UsuarioManager.h"
#include "AreasManager.h"
class AppManager
{
public:
    void menuPrincipal();
private:
    EmpresaManager _em;
    EmpleadosManager _empManager;
    UsuarioManager _um;
    AreasManager _am;
};

#endif // APPMANAGER_H
