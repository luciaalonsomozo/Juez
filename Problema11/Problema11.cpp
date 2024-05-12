
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

bool graphCheck(int u, vector<vector <int> > &adjList, vector<string> &dfs_num, vector<int> &dfs_parent) {
    bool cycle = false;
    dfs_num[u] = "EXPLORED";
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == "UNVISITED") {
            dfs_parent[v] = u;
            // Pon cycle |= si quieres parar de explorar el grafo en cuanto se detecte un ciclo.
            cycle = graphCheck(v, adjList, dfs_num, dfs_parent) || cycle;
        } else if (dfs_num[v] == "EXPLORED"){
            if (v != dfs_parent[u]) // Back edge, graph is cyclic (quita esta linea si el grafo es dirigido).
                  return true;
        }
   }
   dfs_num[u] = "VISITED";
   return cycle;
}

void dfs(int u, std::vector <bool> & visited, vector<vector< int> > & grafo){
   visited[u] = true;
   for(int v: grafo[u]){
      if(!visited[v]){
         dfs(v, visited, grafo);
      }
   }
}
bool resuelveCaso() {
   
   int vertices, aristas;
   // leer los datos de la entrada
   std::cin >> vertices;
   if (!cin)  // fin de la entrada
      return false;
   
   std::cin >> aristas;
   
   std::vector<vector <int> > grafo (vertices); //size por defecto

   for(int i = 0; i < aristas; i++){
        int v1, v2;
        std::cin >> v1 >> v2;
        grafo[v1].push_back(v2);
        grafo[v2].push_back(v1);
   }
   // escribir la solución
   bool libre = true;
   if(vertices - 1 != aristas) libre = false;

   vector<string> v (vertices, "UNVISITED"); //visitados, explorados o no
   vector<int> w( vertices); //nodo del que viene en el ciclo
   
   vector<bool> visitados (vertices);
   visitados.assign(visitados.size(), false);
   dfs(0, visitados, grafo);

   bool conexo = true;
   for(int i = 0; i < visitados.size(); i++){
      if(!visitados[i]) conexo = false;
   }
   libre = !graphCheck(0, grafo, v, w) && conexo;

   if(libre) std::cout << "SI" << "\n";
   else std::cout << "NO" << "\n";

   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
/*
int main(){
     while (resuelveCaso());
    return 0;
}
*/
int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in("casos.txt");
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
