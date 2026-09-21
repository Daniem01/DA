
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

struct tCaja
{
    int numCaja;
    int tiempo;
};

bool operator<(const tCaja &uno, const tCaja &otro)
{
    if (uno.tiempo != otro.tiempo)
        return uno.tiempo < otro.tiempo;
    return uno.numCaja < otro.numCaja;
}

int cual_caja(PriorityQueue<tCaja> &queue, vector<int> productos)
{
    int i = 0;
    while (i < productos.size())
    {
        int cliente = productos[i];

        tCaja caja = queue.top();
        queue.pop();

        caja.tiempo += cliente;
        queue.push(caja);

        i++;
    }
    tCaja isma = queue.top();

    return isma.numCaja;
}

bool resuelveCaso()
{
    int n, c;
    vector<int> productos_cliente;
    vector<tCaja> cajas;

    cin >> n >> c;
    if (n == 0)
        return false;

    // Montamos el vector de productos
    for (int i = 0; i < c; i++)
    {
        int productos;
        cin >> productos;
        productos_cliente.push_back(productos);
    }

    // Montamos el vecto de las cajas
    for (int j = 0; j < n; j++)
    {
        tCaja caja;
        caja.numCaja = j + 1;
        caja.tiempo = 0;

        cajas.push_back(caja);
    }

    // Resolucion problema
    PriorityQueue queue(cajas);
    int resul = cual_caja(queue, productos_cliente);
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
