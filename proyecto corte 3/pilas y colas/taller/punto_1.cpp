#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// trello: pagina para el proyecto

/*
a)
    - realizar un programa que le permita a un usuario crear una estructura de llamadas telefonicas reciente.
    - mostrar esa lista de llamadas desde la mas reciente a la mas antigua.
*/

struct Llamadas
{
    string nombre;
    int numero;
    int fecha;
    int hora;
};

void registro_llamadas(stack<Llamadas> llamada)
{
    Llamadas contacto = llamada.top();
    Llamadas nuevallamada;

    cout << "Ingrese el nombre del contacto: " << endl;
    cin >> contacto.nombre;
    cout << "Ingrese el numero del contacto: " << endl;
    cin >> contacto.numero;
    cout << "Ingrese la fecha de la llamada: " << endl;
    cin >> contacto.fecha;
    cout << "Ingrese la hora de la llamada: " << endl;
    cin >> contacto.hora;

    llamada.push(nuevallamada);
}

void mostrar_llamadas(stack<Llamadas> lista_llamadas)
{
    cout << "\nLlamadas en la pila:\n";
    while (!lista_llamadas.empty())
    {
        Llamadas llamadas = lista_llamadas.top();
        cout << "Nombre: " << llamadas.nombre << "\n";
        cout << "Número del contacto: " << llamadas.numero << "\n\n";
        cout << "Fecha de la llamada: " << llamadas.fecha << "\n\n";
        cout << "Hora de la llamada: " << llamadas.hora << "\n\n";
        lista_llamadas.pop();
    }
}

int main()
{
    stack<Llamadas> llamadas;

    registro_llamadas(llamadas);
    mostrar_llamadas(llamadas);

    return 0;
}
