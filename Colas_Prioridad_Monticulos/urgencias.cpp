
/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "PriorityQueue.h"
using namespace std;

struct tPaciente
{
    string nombre;
    long long dolencia;
    int tiempoEspera;
};

bool operator<(const tPaciente &uno, const tPaciente &otro)
{
    if (uno.dolencia != otro.dolencia)
        return uno.dolencia > otro.dolencia;
    else
        return uno.tiempoEspera < otro.tiempoEspera;
}

bool resuelveCaso()
{
    int numCasos;
    char tipo;
    vector<tPaciente> listaEspera;
    PriorityQueue queue(listaEspera);

    cin >> numCasos;
    if (numCasos == 0)
        return false;

    for (int i = 0; i < numCasos; i++)
    {
        cin >> tipo;
        if (tipo == 'I')
        {
            tPaciente nuevoPaciente;
            cin >> nuevoPaciente.nombre;
            cin >> nuevoPaciente.dolencia;
            nuevoPaciente.tiempoEspera = i;

            queue.push(nuevoPaciente);
        }
        else
        {
            tPaciente atendiendo = queue.top();
            queue.pop();
            cout << atendiendo.nombre << endl;
        }
    }
    cout << "---" << endl;

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
