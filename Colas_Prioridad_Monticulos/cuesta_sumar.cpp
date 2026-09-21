
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

long long int esfuerzoMinimo(PriorityQueue<long long int> &queue)
{
    long long int resul = 0, suma, a, b;

    while (queue.size() > 1)
    {
        // Cogemos los primeros valores
        a = queue.top();
        queue.pop();
        b = queue.top();
        queue.pop();

        // Sumamos y actualizamos resul y devolvemos la suma a la cola
        suma = a + b;
        resul += suma;
        queue.push(suma);
    }
    return resul;
}

bool resuelveCaso()
{
    vector<long long int> valores;
    int num, valor;
    long long int resul;

    // Lectura de datos
    cin >> num;
    if (num == 0)
        return false;

    for (int i = 0; i < num; i++)
    {
        cin >> valor;
        valores.push_back(valor);
    }

    // Resolucion del problema
    PriorityQueue queue(valores);
    resul = esfuerzoMinimo(queue);
    cout << resul << endl;

    return true;
}

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
