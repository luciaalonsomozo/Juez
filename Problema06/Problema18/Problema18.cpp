
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
bool graphCheck(int u, vector <vector <int> > & adjList, vector<string> &dfs_num, vector<int> & sol) {
    sol.push_back(u);
    bool cycle = false;
    dfs_num[u] = "EXPLORED";
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == "UNVISITED") {
            //dfs_parent[v] = u;
            // Pon cycle |= si quieres parar de explorar el grafo en cuanto se detecte un ciclo.
            cycle = graphCheck(v, adjList, dfs_num, sol) || cycle;
        } else if (dfs_num[v] == "EXPLORED"){
            //if (v != dfs_parent[u]) // Back edge, graph is cyclic (quita esta linea si el grafo es dirigido).
                 cycle = true; // Haz return si quieres parar de explorar el grafo en cuanto se detecte un ciclo.  
        }
    }
dfs_num[u] = "VISITED";
return cycle;

}
//@ <answer>

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int tareas, relaciones;
   std::cin >> tareas;
   if (!cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   std::cin >> relaciones;

   std::vector <vector <int> > graph;

    for(int i = 0; i < relaciones; i++){
        int primera_tarea, segunda_tarea;
        std::cin >> primera_tarea >> segunda_tarea;
        graph[primera_tarea-1].push_back(segunda_tarea); 
    }
   // escribir la solución

    vector<string> dfs_num (tareas, "UNVISITED");
    vector<int>  sol;

    bool sePuede = true;

    for(int i = 0; i < graph.size(); i++){
        if(dfs_num[i] == "UNVISITED"){
            sePuede = sePuede && graphCheck(i, graph, dfs_num, sol);
        }
    }

    if(!sePuede) std::cout << "Imposible" << "\n";
    else {
        for(int i= 0; i < sol.size(); i++){
            std::cout << sol[i] << " ";
        }
        std::cout << "\n";
    }


   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
