#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Departamento
{
    string capital;
    string clima;
}

map<string, Departamento>
    MapaColombia;

vector<string> obtenerCiudadesConClima(const MapaColombia &mapa, const string &clima)
{
    vector<string> ciudades;
    for (const auto &par : mapa)
    {
        if (par.second.clima == clima)
        {
            ciudades.push_back(par.second.capital);
        }
    }
    return ciudades;
}