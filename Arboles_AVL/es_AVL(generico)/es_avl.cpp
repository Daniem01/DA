/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "bintree.h"

struct tDatos
{
    int minimo, maximo, altura;
    bool es_valido;
};

BinTree<int> leeArbol(istream &in)
{
    int valor;
    in >> valor;
    if (valor == -1)
    {
        return BinTree<int>();
    }
    else
    {
        BinTree<int> izq = leeArbol(in);
        BinTree<int> der = leeArbol(in);
        return BinTree<int>(izq, valor, der);
    }
}

tDatos analiza(const BinTree<int> &tree)
{
    tDatos datos;

    if (tree.empty())
    {
        datos.altura = 0;
        datos.es_valido = true;
        return datos;
    }

    tDatos izq = analiza(tree.left());
    tDatos der = analiza(tree.right());

    datos.altura = 1 + max(izq.altura, der.altura);
    datos.es_valido = izq.es_valido && der.es_valido;

    if (!tree.left().empty())
    {
        datos.minimo = izq.minimo;
        if (tree.root() <= izq.maximo)
            datos.es_valido = false;
    }
    else
    {
        datos.minimo = tree.root();
    }

    if (!tree.right().empty())
    {
        datos.maximo = der.maximo;
        if (tree.root() >= der.minimo)
            datos.es_valido = false;
    }
    else
    {
        datos.maximo = tree.root();
    }

    if (abs(izq.altura - der.altura) > 1)
        datos.es_valido = false;

    return datos;
}

void resuelveCaso()
{
    BinTree<int> tree = leeArbol(cin);
    tDatos resultado = analiza(tree);
    cout << (resultado.es_valido ? "SI" : "NO") << "\n";
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

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}