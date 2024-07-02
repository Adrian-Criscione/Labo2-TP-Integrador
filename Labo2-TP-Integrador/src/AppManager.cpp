#include <iostream>
#include <rlutil.h>
//using namespace std;


#include "AppManager.h"
#include "EmpresaManager.h"
#include "EmpleadosManager.h"
#include "AreasManager.h"

void AppManager::menuPrincipal()
{
    int option;
    do
    {
        ////RLUTIL PRUEBA
        rlutil::cls(); // Limpiar la pantalla

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        rlutil::setColor(rlutil::LIGHTRED);
        std::cout << "               MENU PRINCIPAL";
        rlutil::setColor(rlutil::YELLOW);
        std::cout << "                   *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        rlutil::setColor(rlutil::WHITE);
        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "1. EMPRESAS" << "              4. REPORTES";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                 *" << std::endl;

        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "2. EMPLEADOS" << "             5. USUARIOS";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                 *" << std::endl;

        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "3. AREAS";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                                             *" << std::endl;

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        std::cout << "0. SALIR";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "                                             *" << std::endl;

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "********************************************************" << std::endl;
        rlutil::setColor(rlutil::WHITE);
        std::cout << "Opcion: ";

        //// RLUTIL FIN PRUEBA


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
        }

    }
    while(option != 0);

}
