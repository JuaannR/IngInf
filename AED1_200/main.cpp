//#include "Intrerprete.h"
#include <iostream>
#include "Interprete.h"
using namespace std;

int main ()
{
    Interprete interprete;
    char comando;
    while (cin >> comando) {
        interprete.Interpretar(comando);
    }
}
