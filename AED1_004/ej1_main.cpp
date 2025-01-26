#include <iostream>
using namespace std;

int main() {
    string palabra;
    int contador = 0;
    while (cin >> palabra)
    {
        cout << ++contador << ". " << palabra << endl;
    }
    return 0;
}
