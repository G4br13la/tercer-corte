#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Departamento
{
private:
    string capital;
    string clima;

public:
    Departamento() {}
    Departamento(string capital, string clima)
    {
        this->capital = capital;
        this->clima = clima;
    }
    string getCapital() const
    {
        return capital;
    }
    string getClima() const
    {
        return clima;
    }
    void setCapital(string capital)
    {
        this->capital = capital;
    }
    void setClima(string clima)
    {

        this->clima = clima;
    }

    Departamento getCapitalClima(string nombre_departamento, map<string, Departamento> mapaColombia)
    {
        Departamento departamento;
        departamento = mapaColombia.find(nombre_departamento)->second;
        return departamento;
    }

    vector<string> getCapitalesByClima(string clima, map<string, Departamento> mapaColombia)
    {
        vector<string> capitales;
        for (auto &capital : mapaColombia)
        {
            if (capital.second.getClima() == clima)
            {
                capitales.push_back(capital.second.getCapital());
            }
            // cout << capital.first << endl;
            // cout << capital.second.getCapital() << endl;
            // cout << capital.second.getClima() << endl;
        }
        return capitales;
    }
};

int main()
{
    map<string, Departamento> mapaColombia;
    Departamento departamento;

    departamento.setCapital("Bogota");
    departamento.setClima("medio");
    mapaColombia.insert(make_pair("Bogota", departamento));

    departamento.setCapital("Leticia");
    departamento.setClima("frio");
    mapaColombia.insert(make_pair("Amazonas", departamento));

    departamento.setCapital("medellin");
    departamento.setClima("caliente");
    mapaColombia.insert(make_pair("antioquia", departamento));

    departamento.setCapital("arauca");
    departamento.setClima("frio");
    mapaColombia.insert(make_pair("arauca", departamento));

    departamento.setCapital("barranquilla");
    departamento.setClima("medio");
    mapaColombia.insert(make_pair("atlantico", departamento));

    departamento.setCapital("cartagena de indias");
    departamento.setClima("caliente");
    mapaColombia.insert(make_pair("bolivar", departamento));

    cout << "ingrese el departamento que quiere buscar: " << endl;
    string dep;
    cin >> dep;

    Departamento departamento_respuesta;

    departamento.getCapitalClima(dep, mapaColombia);
    departamento_respuesta = departamento.getCapitalClima(dep, mapaColombia);

    cout << " " << endl;
    cout << "La capital del departamento es: " << departamento_respuesta.getCapital() << endl;
    cout << "El clima del departamento es: " << departamento_respuesta.getClima() << endl;
    cout << " " << endl;

    cout << "ingrese el clima que quiere buscar: " << endl;
    string clima;
    cin >> clima;
    vector<string> capitales_de_respuesta;
    capitales_de_respuesta = departamento.getCapitalesByClima(clima, mapaColombia);

    cout << " " << endl;
    cout << "los capitales con clima " << clima << " son: " << endl;

    for (auto respuesta : capitales_de_respuesta)
    {
        cout << respuesta << endl;
    }
}