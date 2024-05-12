
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
struct tarea{
    int inicio;
    int fin;
    int periodo = 0;
};
bool operator<(tarea const& t1, tarea const& t2){ //t2 es mas prioritario si su comienzo es anterior. Si ambos comienzos son iguales, t2 es mas prioritario si termina antes
    return (t1.inicio > t2.inicio || t1.inicio == t2.inicio && t2.fin < t1.fin);
}
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N, M, T;
   std::cin >> N;
   if (!cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   std::cin >> M >> T;

    priority_queue<tarea> cola;
   for(int i = 0; i < N; i++){
        tarea aux;
        std::cin >> aux.inicio >> aux.fin;
        aux.periodo = 0;
        if (aux.inicio < T) { //si no, no la vamos a comprobar
			cola.push(aux);
		}
   }

   for(int j = 0; j < M; j++){
        tarea aux;
        int periodo;
        std::cin >> aux.inicio >> aux.fin >> aux.periodo;
         if (aux.inicio < T) { //si no, no la vamos a comprobar
			cola.push(aux);
		   }
        //while (aux.inicio < T) { //no tiene sentido meter la tarea si no la vamos a comprobar
			//cola.push(aux); //hay que añadirla tantas veces como comprobaciones
			//aux.inicio += periodo;
			//aux.fin += periodo;
	}
   // escribir la solución

   int i = 0;
   bool conflicto = false;

   while(!conflicto && cola.size() > 1 && i < T) {
      tarea aux1 = cola.top();
      i = aux1.inicio;
      cola.pop();
      tarea aux2 = cola.top();
      if(aux2.inicio < aux1.fin && aux2.inicio < T) conflicto = true;
      else{
         if(aux1.periodo > 0){
            aux1.inicio += aux1.periodo;
            aux1.fin += aux1.periodo;
            cola.push(aux1);
         }
      }
   }
   
   if(conflicto) std::cout << "SI\n";
   else std::cout << "NO\n";
   
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
