/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>
#include "IndexPQ.h"
using namespace std;

struct tPar
{
    int prio;
    string nombre;
};

bool operator<(tPar const &a, tPar const &b)
{
    if (a.prio != b.prio)
        return a.prio > b.prio;
    return a.nombre < b.nombre;
}

bool resuelveCaso()
{
    int casos;
    cin >> casos;
    if (!cin) // fin de la entrada
        return false;

    // Como mucho hay un país nuevo por evento
    IndexPQ<tPar> queue(casos);
    map<string, int> mapa;

    for (int i = 0; i < casos; i++)
    {
        string pais;
        cin >> pais;

        if (pais == "?")
        {
            auto p = queue.top();
            cout << p.prioridad.nombre << " " << p.prioridad.prio << '\n';
        }
        else
        {
            int puntos;
            cin >> puntos;

            // País nuevo: se registra y se mete en la cola
            if (mapa.count(pais) == 0)
            {
                int id = mapa.size();
                mapa[pais] = id;
                queue.push(id, {puntos, pais});
            }
            // País existente: se suman los puntos y se actualiza
            else
            {
                int id = mapa[pais];
                tPar actual = queue.priority(id);
                actual.prio += puntos;
                queue.update(id, actual);
            }
        }
    }
    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}