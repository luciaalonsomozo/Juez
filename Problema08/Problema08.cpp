
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
    long long int edad_primero;
    int parejas;
   std::cin >> edad_primero >> parejas;;
   if (edad_primero == 0 && parejas == 0)
      return false;
   
   //greater<int> como comparador indica que es más prioritario el que mayor sea, es decir, el máximo.
   priority_queue<long long int, vector<long long int>, std::greater <long long int> > derecha; //los más mayores que el centro (el primer elemento debe ser el mayor)
  //less<int> como comparador indica que es mas prioritario el que menor sea, es decir, el mínimo.
   priority_queue<long long int, vector<long long int>, std::less <long long int> > izquierda; //los más pequeños que el centro (el primer elemento debe ser el menor)
   
   long long int centro;
   centro = edad_primero;

   // resolver el caso posiblemente llamando a otras funciones
   while(parejas--){ //las edades de cada pájaro que entra son distintas
        long long int edad1, edad2;
        std::cin >> edad1 >> edad2;
        if(edad1 > centro && edad2 > centro){
            izquierda.push(centro);
            derecha.push(edad1);
            derecha.push(edad2);
            centro = derecha.top();
            derecha.pop();
           /*
            izquierda.push(centro);
            if(derecha.top() < min(edad1, edad2)){
               centro = derecha.top();
               derecha.pop();
               derecha.push(edad1);
               derecha.push(edad2);
            }
            else{
               centro = min({edad1, edad2);
               derecha.push(max({edad1, edad2));
            }
            */
        }
        else if(edad1 < centro && edad2 < centro){
         derecha.push(centro);
         izquierda.push(edad1);
         izquierda.push(edad2);
         centro = izquierda.top();
         izquierda.pop();
        }
         /*
            derecha.push(centro);
            if(izquierda.top() > max(edad1, edad)){
               centro = izquierda.top();
               izquierda.pop();
               izquierda.push(edad1);
               izquierda.push(edad2);
            }
            else{
               centro = max(edad1, edad2);
               izquierda.push(min(edad1, edad2));
            }
        }*/
        else{
            derecha.push(max(edad1, edad2));
            izquierda.push(min(edad1, edad2));
        }
        std::cout << centro;
        if(parejas != 0){
            std::cout << " ";
        }
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
