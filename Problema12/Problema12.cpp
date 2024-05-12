
/*@ <answer>
 *
 * Nombre y Apellidos: Lucía Alonso Mozo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>
  
  Comentario general sobre la solucion:

  Coste de la solucion:
 
 @ </answer> */


//@ <answer>
int maxAmigos(int u, vector<vector <int> > & grafo, vector<bool>& visitados){

    int max = 1; //sumamos el propio nodo visitado
    visitados[u] = true;

    for(int i = 0; i < grafo[u].size(); i++){
        if(!visitados[grafo[u][i]]){
            max += maxAmigos(grafo[u][i], grafo, visitados); //sumamos a su vez los amigos que este tenga
        }
    }

    return max;
    

}
void resuelveCaso() 
{
   
   // leer los datos de la entrada
   int M, N;

   std::cin >> N >> M; //N es el numero de personas en la ciudad, M es numero de personas de pares amigas

    std::vector<vector <int> > grafo(N);

    for(int i = 0; i < M; i++){
        int v1, v2;
        std::cin >> v1 >> v2;
        grafo[v1-1].push_back(v2-1);
        grafo[v2-1].push_back(v1-1);
    }

    std::vector <bool> visitados (N, false);
    int m = maxAmigos(0, grafo, visitados);
    for(int i = 0;  i < visitados.size(); i++){
        if(!visitados[i] && m < N/2) {
            int j = maxAmigos(i, grafo, visitados);
            if(j > m) m = j;
        }
    }

    std::cout << m << "\n";
   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución
}

//@ </answer>

//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() 
{
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in("casos.txt");
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
