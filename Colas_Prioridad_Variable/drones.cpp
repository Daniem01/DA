
/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

void horasDeVuelo(vector<int> &vuelos, PriorityQueue<int, std::greater<int>> &queueA, PriorityQueue<int, std::greater<int>> &queueB, int N)
{
    while (!queueA.empty() && !queueB.empty())
    {
        // Escogemos las pilas para cada dron
        int i = 0, horas = 0;
        int pilaA, pilaB;
        vector<int> a;
        vector<int> b;

        while (i < N && !queueA.empty() && !queueB.empty())
        {
            pilaA = queueA.top();
            queueA.pop();
            pilaB = queueB.top();
            queueB.pop();

            // Calculamos las horas de vuelo de cada dron y las sumamos
            if (pilaA > pilaB)
            {
                pilaA -= pilaB;
                horas += pilaB;
                a.push_back(pilaA);
            }
            else if (pilaA < pilaB)
            {
                pilaB -= pilaA;
                horas += pilaA;
                b.push_back(pilaB);
            }
            else
            {
                horas += pilaA;
            }
            i++;
        }

        // Guardamos el resultado de esta sesion y guardamos las pilas con carga
        vuelos.push_back(horas);
        for (int i : a)
        {
            queueA.push(i);
        }
        for (int j : b)
        {
            queueB.push(j);
        }
    }
}

bool resuelveCaso()
{
    int N, A, B;
    vector<int> pilasA;
    vector<int> pilasB;
    vector<int> vuelos;

    cin >> N >> A >> B;
    if (!std::cin) // fin de la entrada
        return false;

    // Vector Pilas A
    for (int i = 0; i < A; i++)
    {
        int nuevaPila;
        cin >> nuevaPila;

        pilasA.push_back(nuevaPila);
    }

    // Vector Pilas B
    for (int j = 0; j < B; j++)
    {
        int nuevaPila;
        cin >> nuevaPila;

        pilasB.push_back(nuevaPila);
    }

    PriorityQueue<int, std::greater<int>> queueA(pilasA);
    PriorityQueue<int, std::greater<int>> queueB(pilasB);

    horasDeVuelo(vuelos, queueA, queueB, N);
    for (int h : vuelos)
    {
        cout << h << " ";
    }
    cout << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}