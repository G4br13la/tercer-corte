#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    /* Permiten almacenar y organizar datos de manera eficiente.
    Los conjuntos son colecciones de elementos únicos sin un orden definido.
    Los mapas asocian claves únicas con valores. */

    // Usamos la clase set declarando el conjunto
    set<string> frutas; // Este es un conjunto de cadenas de texto, no permite repetir ninguna cadena.
                        // Si intentamos agregar una que ya existe en el conjunto, se ignora

    /* Operaciones comunes:
       insert(): agregar elemento
       erase(): eliminar elemento
       find(): buscar elemento (devuelve iterador)
       count(): cuántas veces aparece un elemento en el conjunto
       empty(): ¿está vacío o no?
       size(): cuántos elementos tiene el conjunto */

    frutas.insert("arandanos"); // Agrega "manzana" a los frutas
    frutas.insert("uvas");
    frutas.insert("cerezas");
    frutas.insert("sandias");

    cout << "conjunto de frutas: " << endl;
    for (const string &fruta : frutas)
    {                                  // Recorrer todos los elementos del conjunto
        cout << "- " << fruta << endl; // Imprimir cada uno de ellos
    }

    frutas.insert("mango");

    cout << "conjunto de frutas: " << endl;
    for (const string &fruta : frutas)
    {                                  // Recorrer todos los elementos del conjunto
        cout << "- " << fruta << endl; // Imprimir cada uno de ellos
    }

    frutas.erase("cerezas");

    cout << "conjunto de frutas: " << endl;
    for (const string &fruta : frutas)
    {                                  // Recorrer todos los elementos del conjunto
        cout << "- " << fruta << endl; // Imprimir cada uno de ellos
    }

    // vector<string>frutas_vector(furtas.beguin(), fritas.end())

    string buscar = "arandanos";
    string buscar2 = "cerezas";

    auto iterador = frutas.find(buscar);
    auto iterador = frutas.find(buscar2);

    if (iterador != frutas.end())
    {
        cout << "Se encontró " << buscar << "en el conjunto de frutas" << endl;
    }
    else
    {
        cout << "No se encontró " << buscar << "en el conjunto de frutas" << endl;
    }

    if (iterador != frutas.end())
    {
        cout << "Se encontró " << buscar2 << "en el conjunto de frutas" << endl;
    }
    else
    {
        cout << "No se encontró " << buscar2 << "en el conjunto de frutas" << endl;
    }

    // tamaño
    frutas.size();
    // vaciar
    frutas.empty();
    // limpiar
    frutas.clear();

    // conjjunto de canciones de reproducion, van a tener 3 reprucuciones luego agregan una mas y eliminan dos y buscan una.

    set<string> canciones;

    canciones.insert("viva la vida"); // Agrega "manzana" a los canciones
    canciones.insert("yellow");
    canciones.insert("fix you");

    // se agrega una
    canciones.insert("paradice");

    // eliminar dos
    canciones.erase("yellow");
    canciones.erase("fix you");

    /*se busca una*/

    string buscarcancion = "yellow";

    auto iterador = canciones.find(buscarcancion);

    if (iterador != canciones.end())
    {
        cout << "Se encontró " << buscarcancion << "en el conjunto de canciones" << endl;
    }
    else
    {
        cout << "No se encontró " << buscarcancion << "en el conjunto de canciones" << endl;
    }

    // tamaño
    canciones.size();
    // vaciar
    canciones.empty();
    // limpiar
    canciones.clear();

    set<int> conjuntoA = {1, 2, 3, 4, 5};
    set<int> conjuntoB = {4, 5, 6, 7, 8};

    // union
    set<int> union = conjuntoA;
    union.insert(conjuntoB.begin(), conjuntoB.end());
    cout << "union: " << endl;
    for (int elemento : union)
    {
        cout << elemento << " ";
    }

    // intersección
    conjuntoA.union(conjuntoB);

    for (auto elemento : conjuntoA)
    {
        if (conjuntoB.count(elemento))
        {
            interseccion.insert(elemnto);
        }
        cout << elemento << " ";
    }
    cout << endl;

    for (int elemento : interseccion)
    {
        cout << elemento << " ";
    }

    // diferencia
    conjuntoA.difference(conjuntoB);

    for (auto i : conjuntoA)
    {
        if (!conjuntoB.count(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
