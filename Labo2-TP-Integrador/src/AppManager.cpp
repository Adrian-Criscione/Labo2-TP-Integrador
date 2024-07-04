#include <iostream>
#include <rlutil.h>
#include <string>
//using namespace std;


#include "AppManager.h"
#include "EmpresaManager.h"
#include "EmpleadosManager.h"
#include "AreasManager.h"
#include "SueldosManager.h"
void AppManager::menuPrincipal()
{
    rlutil::hidecursor();
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
        std::cout << "               MENÚ PRINCIPAL";
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
            _sm.menuReportes();
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
void AppManager::setColorError()
{
    rlutil::setColor(rlutil::Color::RED);
}

bool AppManager::esStringValido( std::string& stringCargado, bool permitirEspacios = false, bool permitirNumeros = false, bool permitirCaracteresEspeciales = false)
{
    if (stringCargado.empty())
    {
        return false; // La cadena no puede estar vacía
    }
    int cantidad = stringCargado.length();

    for (int i = 0; i < cantidad; ++i)
    {
        if (permitirEspacios && stringCargado[i] == ' ')
        {
            continue;
        }
        if (permitirNumeros && isdigit(stringCargado[i]))
        {
            continue;
        }
        if (permitirCaracteresEspeciales && ispunct(stringCargado[i]))
        {
            continue;
        }
        if (!isalpha(stringCargado[i]))
        {
            return false; // Si algún carácter no es alfabético y no está permitido, la cadena no es válida
        }
    }

    return true; // Todos los caracteres cumplen con los criterios especificados
}



