
#include "Pagina.h"
using namespace std;


void Pagina::leer()
{
    cin >> relevancia >> url;
    cin.ignore();
    getline(cin, titulo);
}
void Pagina::escribir()
{
        cout << url << ", " << titulo << ", Rel. " << relevancia << endl;
}
std::string Pagina::getURL()
{
    return url;
}
