
/*@ <answer>
 *
 * Nombre y Apellidos: Daniem Martín del Castillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "TreeSet_AVL_plantilla.h"
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{
   int valores, m;

   Set<int> arbol;
   // leer los datos de la entrada
   cin >> valores;
   if (valores == 0)
      return false;

   // Insertamos valores
   for (int i = 0; i < valores; i++)
   {
      int valor;
      cin >> valor;
      arbol.insert(valor);
   }

   // Leemos M y hacemos el kesimo de cada uno
   cin >> m;
   for (int j = 0; j < m; j++)
   {
      int k, sol;
      cin >> k;
      try
      {
         sol = arbol.kesimo(k);
         cout << sol << endl;
      }
      catch (std::out_of_range &)
      {
         cout << "??" << endl;
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
