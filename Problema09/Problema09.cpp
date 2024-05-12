
/*@ <answer>
 *
 * Nombre y Apellidos: Lucía Alonso Mozo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

/*@ <answer>

  Comentario general sobre la solucion:

  Coste de la solucion:

 @ </answer> */

//@ <answer>

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N, A, B;
   std::cin >> N;
   if (!cin)  // fin de la entrada
      return false;
   std::cin >> A >> B;

   priority_queue<int> menosV; //cola de prioridades de voltaje 1,5 de maximos
   priority_queue<int> masV; //cola de prioridad de 9V maximos
   // resolver el caso posiblemente llamando a otras funciones
   
   int horas;
   for(int i = 0; i < A; i++){
      std::cin >> horas;
      masV.push(horas);
   }

   for(int i = 0; i < B; i++){
      std::cin >> horas;
      menosV.push(horas);
   }
   
   

   while(!menosV.empty() && !masV.empty()){
      vector<pair<int,int> > v; //<1,5V, 9V>
      int i = 0;
      while(!menosV.empty() && !masV.empty() && i < N){
         pair<int, int> aux;
         aux.first = menosV.top();
         aux.second = masV.top();
         v.push_back(aux);
         menosV.pop();
         masV.pop();
         i++;
      }

      int horasVoladas = 0;

      for(int i = 0; i < v.size(); i++){
         int menosVV = v[i].first;
         int masVV = v[i].second;
         horasVoladas += min(menosVV, masVV);
         if(min(menosVV, masVV) != menosVV){
            menosV.push(menosVV - masVV);
         }
         else if(min(menosVV, masVV) != masVV){
            masV.push(masVV - menosVV);
         }
      }

      std::cout << horasVoladas << " ";
   }
   std::cout << "\n";
   // escribir la solución

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
