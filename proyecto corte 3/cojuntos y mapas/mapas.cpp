#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<int, string> frutas;
    frutas[1] = "arandanos"; // agregar un elemento a nuestro mapa de string e int
    frutas[2] = "uvas";
    frutas[3] = "cerezas";
    frutas[4] = "sandias";

    for (const auto &par : frutas)
    {
        int clave = par.first; // para acceder al índice o clave del mapa se utiliza
        string valor = par.second;
        cout << "clave: " << clave << " valor: " << valor << endl;
    }

    string nombre = "cerezas";

    auto it = frutas.find(3); // buscamos el elemento en el mapa que tiene como clave el número 3

    if (it != frutas.end())
    {
        cout << "La fruta con ese índice es: " << it->second << endl;
    }
    else
    {
        cout << "No existe una fruta con ese índice" << endl;
    }

    string fruit = "uvas";
    frutas.erase(fruit); // eliminamos una fruta por su nombre

    return 0;
}
