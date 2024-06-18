#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "EmpresaManager.h"
#include "EmpleadosManager.h"

class AppManager
{
public:
    void menuPrincipal();
private:
    EmpresaManager _em;
    EmpleadosManager _empManager;
};

#endif // APPMANAGER_H
