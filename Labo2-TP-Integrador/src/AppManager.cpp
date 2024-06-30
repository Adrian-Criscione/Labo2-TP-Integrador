#include <iostream>
using namespace std;


#include "AppManager.h"
#include "EmpresaManager.h"
#include "EmpleadosManager.h"
#include "AreasManager.h"

void AppManager::menuPrincipal()
{
    int option;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- EMPRESAS " << endl;
        cout << "2- EMPLEADOS" << endl;
        cout << "3- AREAS" << endl;
        cout << "4- REPORTES" << endl;
        cout << "5- USUARIOS" << endl;
        cout << "6- CONFIGURACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
            ///MENU EMPRESA
            _em.menuEmpresa();
            system("pause");
            break;

        case 2:
            ///MENU EMPLEADOS
            _empManager.menuEmpleado();
            system("pause");
            break;

        case 3:
            ///MENU AREA
            _am.menuArea();
        case 4:
            ///MENU REPORTES
            system("pause");
            break;

        case 5:
            /// MENU USUARIOS
            _um.menuUsuario();
            system("pause");
            break;
        case 6:
            /// MENU CONFIGURACION
            system("pause");
            break;
        }

    }
    while(option != 0);

}
