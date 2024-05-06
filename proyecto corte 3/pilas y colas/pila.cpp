#include <iostream>
#include <stack>
#include <string>
#include <limits> 
// Definición del struct para representar una película
struct Pelicula {
    std::string nombre;
    int numEstrellas;
};
// g++ pila.cpp -o pila
int main() {
    std::stack<Pelicula> pilaPeliculas;

    for (int i = 0; i < 3; i++) {
        Pelicula nuevaPelicula;
        std::cout << "Ingresa el nombre de la película " << (i + 1) << ": ";
        std::getline(std::cin, nuevaPelicula.nombre);
        std::cout << "Ingresa el número de estrellas para la película " << (i + 1) << ": ";
        std::cin >> nuevaPelicula.numEstrellas;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Agregar la película a la pila
        pilaPeliculas.push(nuevaPelicula);
    }

    // Mostrar las películas en la pila
    std::cout << "\nPelículas en la pila:\n";
    while (!pilaPeliculas.empty()) {
        Pelicula peliculaCima = pilaPeliculas.top();
        std::cout << "Nombre: " << peliculaCima.nombre << "\n";
        std::cout << "Número de estrellas: " << peliculaCima.numEstrellas << "\n\n";
        pilaPeliculas.pop();
    }

    return 0;
}
