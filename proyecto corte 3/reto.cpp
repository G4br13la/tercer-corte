#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

// miembro, fecha, destino y actividades
// diagrama de flujo que le explique al usuario el manejo del sistema

class Destino
{
private:
    string nombre; // nombre del destino
    string fechas; // fechas en las que se puede visitar el destino
    // int dia_llegada; // dia en que llegara el vuelo a este destino
    // int mes_llegada; // mes en que  llegara el vuelo a este destino
    // int dia_salida;  // dia que se va del destino
    // int mes_salida;  // mes que se va del destino
public:
    Destino(const string &n, string fechas) // int d_l, int m_l, int d_s, int m_s)
    {
        nombre = n;
        this->fechas = fechas;
        // dia_llegada = d_l;
        // mes_llegada = m_l;
        // dia_salida = d_s;
        // mes_salida = m_s;
    }

    void setNombre(const string &nombre)
    {
        this->nombre = nombre;
    }

    void setFechas(string &nuevasFechas)
    {
        this->fechas = nuevasFechas;
    }

    const string getNombre()
    {
        return nombre;
    }
    const string getFechas()
    {
        return fechas;
    }

    void imprimirDestino()
    {
        cout << "Nombre del destino: " << nombre << endl;
        cout << "Dias disponibles para visitarlo son: " << fechas << endl;
    }

    void Dias_de_viaje()
    {
        for (size_t i = 0; i < fechas.length(); i++)
        {
            if ((i != 0 && fechas[i] == fechas[i - 1]) || (i + 1 == fechas.length() && fechas[i] == fechas[i - 2]))
            {
                if ((i != 0 && fechas[i] == fechas[i - 1]) || (i + 1 == fechas.length()))
                    throw invalid_argument("Los dias deben ser diferentes");
            }
        }
    }

    // const string &getNombre() const
    // {
    //     return nombre;
    // }
    // void setNombre(const string &n)
    // {
    //     nombre = n;
    // }
    // int getDiaLlegada() const
    // {
    //     return dia_llegada;
    // }
    // int getMesLlegada() const
    // {
    //     return mes_llegada;
    // }
};

typedef set<Destino> SetDeDestinos;
SetDeDestinos setDeDestinos;

class Actividad
{
protected:
    int diaSemana;      // dia en la semana (0-6)
    string descripcion; // descripción de la actividad
public:
    Actividad(int d, const string &descr) : diaSemana(d), descripcion(descr) {}

    int getDia() const
    {
        return diaSemana;
    }
    const string &getDescripccion() const
    {
        return descripcion;
    }

    int getFecha()
    {
        return fecha;
    }

    void setDiaSemana(int d)
    {
        diaSemana = d;
    }

    void setDescripcion(string acti)
    {
        descripcion = acti;
    }

    void setFecha(int f)
    {
        fecha = f;
    }
};
typedef vector<Actividad *> VecDeActividades;
VecDeActividades vecDeActividades;

class VisitaMuseo : public Actividad
{
public:
    VisitaMuseo() {}
    virtual void imprimir() const override
    {
        cout << "Visitamos el museo de arte moderno" << endl;
    }
};

class Excursion : public Actividad
{
private:
    string lugar;

public:
    Excursion(const string &lug)
    {
        lugar = lug;
    }
    virtual void imprimir() const override
    {
        cout << "Hacemos una excursión a " << lugar << endl;
    }
    void setLugar(const string &nuevo_lugar)
    {
        lugar = nuevo_lugar;
    }
};

void agregarActividad(VecDeActividades &v, Actividad *act)
{
    v.push_back(act);
}

bool operator<(const Actividad &a1, const Actividad &a2)
{
    return a1.getFecha() < a2.getFecha();
}

// Función que devuelve la actividad más cercana al día indicado en parámetro
Actividad *buscarCercana(const VecDeActividades &vecActs, int dia)
{
    if (!vecActs.empty())
    {
        Actividad *res = vecActs; // Res es un puntero a la primera actividad del vector
        for (auto act : vecActs)
            if (dia > act.getFecha())
                res = &act;
        return res;
    }
    else
        return nullptr;
}
