#include <iostream>
using namespace std;


#include "AppManager.h"

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
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            //_pm.menu(); BORRAR
            cout << "INGRESO A LA OPCION DE EMPRESAS." << endl;
            system("pause");
            break;

        case 2:
            //_catman.menu(); BORRAR
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
