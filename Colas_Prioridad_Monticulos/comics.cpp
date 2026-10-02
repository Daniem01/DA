/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "PriorityQueue.h"
using namespace std;

// Representa el comic
struct tElem
{
    int valor;
    int idPila;
};

bool operator<(const tElem &a, const tElem &b)
{
    return a.valor < b.valor;
}

bool operator>(const tElem &a, const tElem &b)
{
    return a.valor > b.valor;
}

bool resuelveCaso()
{
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<vector<int>> pilas(n);
    int minGlobal = INT_MAX;
    int idPilaObj = -1;

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        pilas[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> pilas[i][j];
            if (pilas[i][j] < minGlobal)
            {
                minGlobal = pilas[i][j];
                idPilaObj = i;
            }
        }
    }

    if (pilas[idPilaObj].back() == minGlobal)
    {
        cout << 1 << "\n";
        return true;
    }

    PriorityQueue<tElem> pq;
    for (int i = 0; i < n; ++i)
    {
        if (!pilas[i].empty())
        {
            pq.push({pilas[i].back(), i});
        }
    }

    int turno = 0;
    while (!pq.empty())
    {
        tElem cima = pq.top();
        pq.pop();
        turno++;

        int p = cima.idPila;
        pilas[p].pop_back(); // Retiramos el comic vendido

        // Comprobamos si la nueva cima de esta pila es el cómic buscado
        if (p == idPilaObj && !pilas[p].empty() && pilas[p].back() == minGlobal)
        {
            cout << turno + 1 << "\n";
            return true;
        }

        // Si la pila aún tiene cómics
        if (!pilas[p].empty())
        {
            pq.push({pilas[p].back(), p});
        }
    }

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
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