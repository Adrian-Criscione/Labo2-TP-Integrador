#include <iostream>
using namespace std;


#include "AppManager.h"
#include "EmpresaManager.h"
#include "EmpleadosManager.h"

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
        cout << "3- REPORTES" << endl;
        cout << "4- USUARIOS" << endl;
        cout << "5- CONFIGURACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
            _em.menuEmpresa();

            break;

        case 2:
            _empManager.menuEmpleado();
            ///MENU EMPLEADOS
            system("pause");
            break;

        case 3:
            ///MENU REPORTES
            system("pause");
            break;
        case 4:
            /// MENU USUARIOS
            system("pause");
            break;
        case 5:
            /// MENU CONFIGURACION
            system("pause");
            break;
        }

    }
    while(option != 0);

}
