#include <iostream>
#include "AppManager.h"
#include <iomanip>
#include <locale>
#include "Fecha.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    AppManager app;
    app.menuPrincipal();

    return 0;
}
