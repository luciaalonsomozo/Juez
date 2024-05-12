
/*@ <answer>
 *
 * Nombre y Apellidos: Lucía Alonso Mozo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

  Comentario general sobre la solucion:

  Coste de la solucion:

 @ </answer> */

//@ <answer>
struct persona{
    int tiempo;
    int caja;
};

bool operator <(persona const& p1, persona const& p2){ //p2 es mas prioritario si tiene menos tiempo esperando, a tiempos iguales, el que tenga la minima caja.
    return (p1.tiempo > p2.tiempo || p1.tiempo == p2.tiempo && p2.caja < p1.caja);
}
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N, C;
   std::cin >> N >> C;
   if (N == 0 && C == 0)
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<persona> cajas;

   if(N > C){
        std::cout << C + 1 << "\n";
        int i = 1;
        while(i <= C){ //no hace falta que lo insertemos porque ya sabemos que va a ir a la siguiente caja vacía
            persona aux;
            std::cin >> aux.tiempo;
            i++;
        }
        return true;
   }
   int i = 1;
   while(i <= N){
        persona aux;
        std::cin >> aux.tiempo;
        aux.caja = i;
        cajas.push(aux);
        i++;
   }
   int tiempo_transcurrido = 0;
   while(i <= C){
       persona aux = cajas.top();
       cajas.pop();
       tiempo_transcurrido = aux.tiempo;
       persona nueva_cola;
       std::cin >> nueva_cola.tiempo;
       nueva_cola.tiempo += aux.tiempo; //tiempo en el que va a salir de la cola
       nueva_cola.caja = aux.caja;
       cajas.push(nueva_cola);
       i++;
   }

   std::cout << cajas.top().caja << "\n";



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
