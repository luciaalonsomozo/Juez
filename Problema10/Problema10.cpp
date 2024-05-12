
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

  Comentario general sobre la solucion:

  Coste de la solucion:

 @ </answer> */

//@ <answer>
struct instr{
    int integrantes;
    int partituras = 1;
};

bool operator < (instr const& i1, instr const& i2){ //devuelve cierto cuando i2 es mas prioritario
   int division2 = i2.integrantes/ i2.partituras;
   int division1 = i1.integrantes/i1.partituras;
   if(i2.integrantes % i2.partituras != 0){
       division2++; 
   }
   if(i1.integrantes % i1.partituras != 0){
       division1++; 
   }
    return (division2 > division1);
}
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int p, n;
    std::cin >> p;
   if (!cin)  // fin de la entrada
      return false;
   std::cin >> n;
   priority_queue<instr> num_instrumentos;
   // resolver el caso posiblemente llamando a otras funciones
   for(int i = 0; i < n; i++){
        instr aux;
        std::cin >> aux.integrantes;
        num_instrumentos.push(aux);
   }
   int pRestantes = p - n;
   while(pRestantes--){
        instr top = num_instrumentos.top();
        num_instrumentos.pop();
        top.partituras++;
        num_instrumentos.push(top);
   }

    instr sol = num_instrumentos.top();
    int solucion = sol.integrantes / sol.partituras;
    if(sol.integrantes % sol.partituras != 0)
        solucion++;
   std::cout << solucion << "\n";
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

