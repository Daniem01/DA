
/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include "bintree.h"
using namespace std;

template <class T>
// Struct con los datos necesarios para resolver el problema
struct tDatos
{
    T maximo;
    T minimo;
    int altura;
    bool es_valido;
};

template <class T>
tDatos<T> esAVL(const BinTree<T> &tree)
{
    tDatos<T> datos, izq, der;
    datos.altura = 0;
    datos.es_valido = true;

    // Casos base
    // Arbol vacio
    if (tree.empty())
    {
        return datos;
    }
    else
    {
        // Llamada recursiva para izquierda y derecha
        izq = esAVL(tree.left());
        der = esAVL(tree.right());
        // Calculo altura
        datos.altura = 1 + max(izq.altura, der.altura);
        // Condicion izquierda
        if (!tree.left().empty())
        {
            datos.minimo = izq.minimo;
            if (tree.root() <= izq.maximo)
            {
                datos.es_valido = false;
            }
        }
        else
        {
            datos.minimo = tree.root();
        }
        // Condicion derecha
        if (!tree.right().empty())
        {
            datos.maximo = der.maximo;
            if (tree.root() >= der.minimo)
            {
                datos.es_valido = false;
            }
        }
        else
        {
            datos.maximo = tree.root();
        }
        // Condicion altura
        if (abs(izq.altura - der.altura) > 1)
        {
            datos.es_valido = false;
        }
        // Comprobar si es valido
        if (!izq.es_valido || !der.es_valido)
        {
            datos.es_valido = false;
        }
    }

    return datos;
}

bool resuelveCaso()
{
    char type;
    cin >> type;

    if (!std::cin) // fin de la entrada
        return false;

    if (type == 'N')
    {
        tDatos<int> solucion;
        BinTree<int> tree = read_tree<int>(std::cin);
        solucion = esAVL(tree);
        cout << (solucion.es_valido ? "SI" : "NO") << "\n";
    }
    else
    {
        tDatos<string> solucion;
        BinTree<string> tree = read_tree<string>(std::cin);
        solucion = esAVL(tree);
        cout << (solucion.es_valido ? "SI" : "NO") << "\n";
    }
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
