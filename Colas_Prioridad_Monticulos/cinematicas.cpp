
/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct tImagen
{
    long long minutoEnvio;
    long long tiempoProceso;
};

long long procesaImagenes(const vector<tImagen> &imagenes, PriorityQueue<long long> &queue)
{
    long long tiempo = 0, esperaMAX = 0;

    for (int i = 0; i < imagenes.size(); i++)
    {
        long long puesto = queue.top();
        queue.pop();

        long long espera = puesto - imagenes[i].minutoEnvio;
        if (espera < 0)
            espera = 0;

        if (espera > esperaMAX)
            esperaMAX = espera;

        tiempo += (imagenes[i].minutoEnvio + imagenes[i].tiempoProceso);

        long long inicio = max(puesto, imagenes[i].minutoEnvio);
        puesto = inicio + imagenes[i].tiempoProceso;

        queue.push(puesto);
    }

    return esperaMAX;
}

bool resuelveCaso()
{
    int S;
    long long R;
    vector<tImagen> imagenes;

    cin >> R >> S;
    if (!std::cin) // fin de la entrada
        return false;

    // Procesamos la entrada
    for (int i = 0; i < R; i++)
    {
        tImagen imagenNueva;
        cin >> imagenNueva.minutoEnvio;
        cin >> imagenNueva.tiempoProceso;

        imagenes.push_back(imagenNueva);
    }

    // Creamos la cola
    vector<long long> tiempos;
    for (int j = 0; j < S; j++)
    {
        long long nuevoTiempo = 0;
        tiempos.push_back(nuevoTiempo);
    }
    PriorityQueue queue(tiempos);

    long long resul = procesaImagenes(imagenes, queue);
    cout << resul << endl;

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
