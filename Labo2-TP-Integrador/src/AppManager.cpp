#include <iostream>
#include <rlutil.h>
//using namespace std;


#include "AppManager.h"
#include "EmpresaManager.h"
#include "EmpleadosManager.h"
#include "AreasManager.h"
#include "SueldosManager.h"
void AppManager::menuPrincipal()
{
    int opcion;
    do
    {
        /// PARA QUE TODOS LOS CARACTERES SE IMPRIMAN POR DEFECTO EN BLANCO.
        setColorIngresoTexto();
        ////RLUTIL PRUEBA
        rlutil::cls(); // Limpiar la pantalla


        setColorLineas();
        std::cout << "********************************************************" << std::endl;
        std::cout << "*      ";
        setColorNombreMenu();
        std::cout << "               MENU PRINCIPAL";
        setColorLineas();
        std::cout << "                   *" << std::endl;
        std::cout << "********************************************************" << std::endl;
        setColorIngresoTexto();
        std::cout << "* ";
        setColorOpciones();
        std::cout << "1. EMPRESAS" << "              4. REPORTES";
        setColorIngresoTexto();
        std::cout << "                 *" << std::endl;

        std::cout << "* ";
        setColorOpciones();
        std::cout << "2. EMPLEADOS" << "             5. SUELDOS";
        setColorIngresoTexto();
        std::cout << "                  *" << std::endl;

        std::cout << "* ";
        setColorOpciones();
        std::cout << "3. AREAS"<< "                 6. USUARIOS";
        setColorIngresoTexto();
        std::cout << "                 *" << std::endl;

        setColorLineas();
        std::cout << "********************************************************" << std::endl;

        std::cout << "* ";
        setColorOpciones();
        std::cout << "0. SALIR";
        setColorIngresoTexto();
        std::cout << "                                             *" << std::endl;

        setColorLineas();
        std::cout << "********************************************************" << std::endl;
        setColorTexto();
        std::cout << "Opcion: ";

        //// RLUTIL FIN PRUEBA

        setColorIngresoTexto();
        cin >> opcion;

        switch(opcion)
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
            /// MENU SUELDOS
            _sm.menuSueldos();
            system("pause");
            break;
        case 6:
            /// MENU USUARIOS
            _um.menuUsuario();
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
void AppManager::setColorTexto()
{
    rlutil::setColor(rlutil::Color::CYAN);
}
void AppManager::setColorLineas()
{
    rlutil::setColor(rlutil::Color::YELLOW);
}
void AppManager::setColorIngresoTexto()
{
    rlutil::setColor(rlutil::Color::WHITE);
}
void AppManager::setColorNombreMenu()
{
    rlutil::setColor(rlutil::Color::LIGHTRED);
}
void AppManager::setColorOpciones()
{
    rlutil::setColor(rlutil::Color::LIGHTGREEN);
}
void AppManager::setColorDatosListados()
{
    rlutil::setColor(rlutil::Color::LIGHTCYAN);
}
