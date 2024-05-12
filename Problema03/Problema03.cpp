
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
long long int costeMin(priority_queue <long long int, vector<long long int>, greater<long long int> > & cola){
    long long int coste = 0;

    if(cola.size() == 1) return 0;
    while(cola.size() > 1 ){
        long long int num = cola.top();
        cola.pop();
        long long int num2 = cola.top();
        cola.pop();
        cola.push(num + num2);
        coste += num + num2;
    }
    return coste;
    /*
    int resultado = cola.top(); //nunca va a entrar una cola vacía
    int cadaOp = 0;
    cola.pop();
    if(cola.empty()) return 0; //no se suma nada, la cola tiene un único numero
    while(!cola.empty()){
        resultado += cola.top();
        cadaOp += resultado;
        cola.pop();
    } */

}
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int numeros;
   std::cin >> numeros;
   if (numeros == 0)
      return false;
   long long int valor;
   priority_queue<long long int, vector<long long int>, greater<long long int> > cola_de_min; //Se trata de una cola de minimos
   for(int i = 0; i < numeros; i++){
        std::cin >> valor;
        cola_de_min.push(valor);
   }

   long long int resultado = costeMin(cola_de_min);

   std::cout << resultado << std::endl;

   // resolver el caso posiblemente llamando a otras funciones
   
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
