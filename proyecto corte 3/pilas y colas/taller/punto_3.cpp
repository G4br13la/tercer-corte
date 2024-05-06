#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

/*
c)
    crear un sistema que permite introducir al texto
    que permitya hacer modificaciones
    mostrar la anterior modificacion o volver a la misma
*/

int main()
{
    stack<string> historial;
    string texto;
    string modificacion;
    bool salir = false;
    int opcion;

    cout << "Introdusca su texto: " << endl;
    getline(cin, texto);
    historial.push(texto);

    while (!salir)
    {
        cout << "1. Modificar texto" << endl;
        cout << "2. Mostrar texto" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            cout << "Introdusca su modificacion: " << endl;
            getline(cin, texto);
            historial.push(texto);
            texto = modificacion;
            cout << "Texto modificado" << endl;
            break;
        case 2:
            if (!historial.empty())
            {
                cout << "Texto: " << historial.top() << endl;
            }
            else
            {
                cout << "No hay texto" << endl;
            }
            break;
        case 3:
            salir = true;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
    return 0;
}