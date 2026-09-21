
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

struct tCandidato
{
    int num;
    int votos;
    double coeficiente;
    int escaños;
};

bool operator<(const tCandidato &uno, const tCandidato &otro)
{
    if (uno.coeficiente != otro.coeficiente)
        return uno.coeficiente > otro.coeficiente;
    else if (uno.votos != otro.votos)
        return uno.votos > otro.votos;
    else
        return uno.num < otro.num;
}

void calcula_coeficiente(tCandidato &candidato)
{
    double uno = 1;

    candidato.coeficiente = candidato.votos / (uno + candidato.escaños);
}

vector<int> calcula_escaños(PriorityQueue<tCandidato> &queue, int num_candidatos, int num_escaños)
{
    vector<int> resul;
    int reparto = 0;

    for (int i = 0; i < num_candidatos; i++)
    {
        resul.push_back(0);
    }

    while (reparto < num_escaños)
    {
        tCandidato elegido = queue.top();
        queue.pop();

        elegido.escaños++;
        resul[elegido.num]++;
        reparto++;
        calcula_coeficiente(elegido);
        queue.push(elegido);
    }

    return resul;
}

bool resuelveCaso()
{
    int c, n;
    vector<tCandidato> candi;
    vector<int> resul;

    cin >> c >> n;
    if (c == 0)
        return false;

    for (int i = 0; i < c; i++)
    {
        tCandidato candidato;
        candidato.num = i;
        candidato.escaños = 0;
        cin >> candidato.votos;
        calcula_coeficiente(candidato);

        candi.push_back(candidato);
    }

    PriorityQueue partidos(candi);
    resul = calcula_escaños(partidos, c, n);

    for (int j = 0; j < c; j++)
    {
        cout << resul[j] << " ";
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
