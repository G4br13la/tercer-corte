#include <iostream>
#include <queue>
#include <string>
#include <limits> 

// Definición del struct para representar una película
struct Pelicula {
    std::string nombre;
    int numEstrellas;
};

int main() {
    std::queue<Pelicula> colaPeliculas;

    for (int i = 0; i < 3; i++) {
        Pelicula nuevaPelicula;
        std::cout << "Ingresa el nombre de la película " << (i + 1) << ": ";
        std::getline(std::cin, nuevaPelicula.nombre);
        std::cout << "Ingresa el número de estrellas para la película " << (i + 1) << ": ";
        std::cin >> nuevaPelicula.numEstrellas;

        // Limpieza de Buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Agregar la película a la cola
        colaPeliculas.push(nuevaPelicula);
    }

    // Mostrar las películas en la cola en el orden en que se ingresaron
    std::cout << "\nPelículas en la cola (orden de entrada):\n";
    while (!colaPeliculas.empty()) {
        Pelicula peliculaFrente = colaPeliculas.front();
        std::cout << "Nombre: " << peliculaFrente.nombre << "\n";
        std::cout << "Número de estrellas: " << peliculaFrente.numEstrellas << "\n\n";
        colaPeliculas.pop();
    }

    return 0;
}
