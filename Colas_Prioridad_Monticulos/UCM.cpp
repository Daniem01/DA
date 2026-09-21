
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

struct tUsuario
{
    long long id;
    long long periodo;
    long long proximoEnvio;
};

bool operator<(const tUsuario &uno, const tUsuario &otro)
{
    if (uno.proximoEnvio != otro.proximoEnvio)
        return uno.proximoEnvio < otro.proximoEnvio;
    return uno.id < otro.id;
}

long long proximo(PriorityQueue<tUsuario> &queue)
{
    tUsuario usuario = queue.top();
    long long resul = usuario.id;

    queue.pop();
    usuario.proximoEnvio += usuario.periodo;
    queue.push(usuario);

    return resul;
}

bool resuelveCaso()
{
    tUsuario usuario;
    int num_casos, k;
    vector<tUsuario> vectorUsuarios;

    cin >> num_casos;
    if (num_casos == 0)
        return false;

    // Lectura de datos
    for (int i = 0; i < num_casos; i++)
    {
        cin >> usuario.id;
        cin >> usuario.periodo;
        usuario.proximoEnvio = usuario.periodo;
        vectorUsuarios.push_back(usuario);
    }
    cin >> k;

    // Resolucion del problema
    PriorityQueue queue(vectorUsuarios);
    for (int j = 0; j < k; j++)
    {
        long long salida = proximo(queue);
        cout << salida << endl;
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
