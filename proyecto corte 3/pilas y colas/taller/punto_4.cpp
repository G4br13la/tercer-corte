#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
/*
d)
    sistema que permita llevar un orden en las impreciones de una oficina
    mostrar lo que se imprime
    mostrar lo que falta imprimnir
*/

struct Impreciones
{
    queue<string> impreciones;
    queue<string> impreciones_pendientes;
};

void agregar_impreciones(Impresiones sistema, string documento)
{
    sistema.impreciones.push(documento);
    cout << "se agrego el documento a la lista de impresiones." << endl;
}

void mostrar_imprecion(Impreciones sistema)
{

    cout << "impresiones relizadas: " << end;
    if (sistema.impreciones.empty())
    {
        cout << "no hay documentos para imprimir." << endl;
    }
    else
    {
        while (!sistema.impreciones.empty())
        {
            cout << "imprimiendo documento: " << sistema.impreciones.front() << endl;
            sistema.impreciones.pop();
        }
    }

    cout << "impresiones pendientes." << endl;
    if (sistema.impreciones_pendientes.empty())
    {
        cout << "no hay documentos para imprimir." << endl;
    }
    else
    {
        while (!sistema.impreciones_pendientes.empty())
        {
            cout << "imprimiendo documento: " << sistema.impreciones_pendientes.front() << endl;
            sistema.impreciones_pendientes.pop();
        }
    }
}

void imprimir(Impreciones sistema)
{
    if (sistema.impreciones_pendientes.empty())
    {
        cout << "no hay documentos pendientes." << endl;
    }
    else
    {
        string documento = sistema.impreciones_pendientes.front();
        documento.pop();
        sistema.impreciones.push(documento);
        cout << "se ha impreso el documento." << endl;
    }
}

int main()
{
    Impreciones sistema;
    agregar_impreciones(sistema, "Documento 1");
    mostrar_imprecion(sistema);
    imprimir(sistema);
}