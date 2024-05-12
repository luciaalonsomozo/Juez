
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

struct registro{
    long long int momento; //instante de tiempo en el que le toca ser atendido
    int id;
    long long int periodo;
};

//Como lo hacemos con una cola de prioridad maximos, el operator < va a decir cuando b es mas prioritario.
//b es mas prioritario cuando su momento es menor, es decir, le toca ser atendido antes.
bool operator < (registro const& a, registro const& b){ 
    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}
/*@ <answer>

  Comentario general sobre la solucion:

  Coste de la solucion:

 @ </answer> */

//@ <answer>

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int numUsuarios;
   std::cin >> numUsuarios;
   if (numUsuarios == 0)
      return false;
   
   priority_queue <registro> cola;
   for(int i = 0; i < numUsuarios; i++){ //coste numUsuarios*log(numUsuarios)
        registro aux;
        std::cin >> aux.id >> aux.periodo;
        aux.momento = aux.periodo;
        cola.push(aux); //coste log(numUsuarios)
   }
   int envios;
   std::cin >> envios;
   while(envios--){ //O(klognumUsuarios)
        auto aux = cola.top(); //cte
        cola.pop(); //log(numUsuarios)
        std::cout << aux.id << '\n';
        aux.momento += aux.periodo;
        cola.push(aux); //log(numUsuarios)
   }

//orden Total numUsuarios*log(numUsuarios) + k*log(numUsuarios)
   std::cout << "---\n";
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
