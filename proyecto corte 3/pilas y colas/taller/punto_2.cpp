#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

/*
b)
    crear una estructura de mercado
    permite ver la lista e ir sacando los elemenros del mercado desde el primero hgasta el ultimo
*/

struct Mercado
{
    string procucto;
    // double costo;
};

void crear_lista(queue<Mercado> productos)
{
    Mercado mercado = productos.front();
    cout << "ingrese su producto para la lista: " << endl;
    cin >> mercado.procucto;
    productos.push(mercado);
    cout << "producto ingresado." << endl;
    cout << " " << endl;
}

void mostrar_producto(queue<Mercado> productos)
{
    while (!productos.empty())
    {
        Mercado primer_producto = productos.front();
        cout << "Nombre del producto: " << primer_producto.procucto << endl;
        productos.pop();
    }
}

void sacar_productos(queue<Mercado> producto)
{
    Mercado primer_producto = producto.front();
    string producto_sacar;
    cout << "ingrese el producto que desea sacar de la lista: " << endl;
    cin >> producto_sacar;
    if (primer_producto.empty())
    {
        cout << "no hay productos en la lista" << endl;
    }
    else
    {
        bool producto_encontrado = false;
        for (int i = 0; i < primer_producto.size(); i++)
        {
            producto.pop();
            if (primer_producto.procucto == producto_sacar)
            {
                cout << "Se a sacdo el producto: " << producto_sacar << endl;
                producto_encontrado = true;
            }
        }
        if (!producto_encontrado)
        {
            cout << "producto no encontrado" << endl;
        }
    }

    // while (!primer_producto.empty())
    // {
    //     for (const auto producto_sacar : producto)
    //     {
    //         if (producto_sacar == primer_producto)
    //         {
    //             primer_producto.pop();
    //         }
    //         else
    //         {
    //             cout << "producto no encontrado" << endl;
    //         }
    //     }
    // }
}

int main()
{
    queue<Mercado> productos;
    crear_lista(productos);
    // mostrar_producto(productos);
    // sacar_productos(productos);

    return 0;
}
