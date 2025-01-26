#include <iostream>
#include <vector>
#include "DicPaginas.h"
#include "Interprete.h"

#define findepagina "findepagina"

using namespace std;


//Toma una cadena de caracteres y la devuelve con los valores normalizados
std::string Interprete::normalizar(string cadena)
{
    string palabraNormalizada;	//Cadena vacía que almacenará el resultado de la transformación
    size_t i = 0; 	//Contador entero suficientemente grande como para manejar la cantidad de elementos

    while (i<cadena.length())
    {
        char byte1 = cadena[i]; //1º byte
        if (byte1 == '\xC3')  	//Si el 1º byte es xC3, se necesita 2º byte para interpretarlo
        {
            char byte2 = cadena[i+1];	//2º byte
            switch (byte2)  			//en función del 2º byte estamos en un caracter especial u otro
            {
            case '\xA1':    // á
            case '\x81':	//Á
                palabraNormalizada.push_back('a');
                break;

            case '\xA9':	// é
            case '\x89':    // É
                palabraNormalizada.push_back('e');
                break;

            case '\xAD':	// í
            case '\x8D':    // Í
                palabraNormalizada.push_back('i');
                break;

            case '\xB3':	// ó
            case '\x93':    // Ó
                palabraNormalizada.push_back('o');
                break;

            case '\xBA':	// ú
            case '\x9A':    // Ú
            case '\xBC':    // ü
            case '\x9C':    // Ü
                palabraNormalizada.push_back('u');
                break;

            case '\xB1':	// ñ |
            case '\x91':    // Ñ
                palabraNormalizada.push_back('\xC3');
                palabraNormalizada.push_back('\xB1');
                break;

            default:
                //por si hay una letra de 2 bytes que no haya que cambiar â, à, è, ì...
                palabraNormalizada.push_back('\xC3');	// '\xC3' señala caracter especial
                palabraNormalizada.push_back(byte2);	// 'byte2' añade byte2
                break;
            }
            i = i+2; //letra codificada en 2 bytes
        }
        else
        {
            palabraNormalizada.push_back(tolower(byte1));
            i++;	//letra codificada en 1 byte

        }

    }

    return palabraNormalizada;
}

void Interprete::INSERTAR()
{
    Pagina nueva;
    nueva.leer();
    dic.insertar(nueva);
    int npalabras = 0;
    string palabra;
    while(cin >> palabra && normalizar(palabra) != findepagina)
    {
        npalabras++;
    }
    cout << dic.getNumElem() << ". ";
    nueva.escribir();
    cout << npalabras << " palabras" << endl;
}

void Interprete::BUSCA_URL() {
    string url;
    cin >> url;


    Pagina* pagina = dic.consultar(url);
    cout << "u " << url << endl;
	//Existe
    if (pagina != nullptr) {
        cout << "1. ";
        pagina->escribir();
        cout << "Total: 1 resultados" << endl;
    } else {
       //No existe
        cout << "Total: 0 resultados" << endl;
    }
}

void Interprete::BUSCA_PAL()
{
    string palabra;
    cin >> palabra;
    cout << "b " << normalizar(palabra) << endl;
    cout << "Total: 0 resultados" << endl;
}

void Interprete::AND()
{
    string palabra;
    vector<string> palabras;

    while (cin.peek() != '\n' && cin >> palabra)
    {
        palabras.push_back(palabra);
    }

    cout << "a";
    for (string palabra : palabras)
    {
        cout << " " << normalizar(palabra);
    }
    cout << endl;

    cout << "Total: 0 resultados" << endl;
}

void Interprete::OR()
{
    string palabra;
    vector<string> palabras;

    while (cin.peek() != '\n' && cin >> palabra)
    {
        palabras.push_back(palabra);
    }

    cout << "o";
    for (string palabra : palabras)
    {
        cout << " " << normalizar(palabra);
    }
    cout << endl;

    cout << "Total: 0 resultados" << endl;
}

void Interprete::AUTOCOMPLETAR()
{
    string prefijo;
    cin >> prefijo;
    cout << "p " << normalizar(prefijo) <<endl;
    cout << "Total: 0 resultados" << endl;
}

void Interprete::Interpretar(char comando) {

        switch (comando)
        {
        case 'i': // insertar
            INSERTAR();
            break;
        case 'u': // búsqueda por url
            BUSCA_URL();
            break;
        case 'b': //búsqueda por palabra
            BUSCA_PAL();
            break;
        case 'a': //and
            AND();
            break;
        case 'o': //or
            OR();
            break;
        case 'p': //autocompletar
            AUTOCOMPLETAR();
            break;
        case 's': // salir
            cout << "Saliendo..." << endl;
            exit(0);
            break;
        default:
            cout << "Comando incorrecto, intentelo de nuevo" << endl;
            break;
        }
}
