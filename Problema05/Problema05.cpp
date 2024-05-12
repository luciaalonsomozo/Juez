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
    int gravedad;
    int antiguedad;
    string nombre;
};
bool operator<(const persona & p1, const persona & p2) { //es una cola de maximos
// p2 es más prioritario cuando su gravedad es mayor
//si las gravedades son iguales, p2 es mas prioritario si su antiguedad es mayor
	return (p1.gravedad < p2.gravedad ||(p1.gravedad == p2.gravedad && p1.antiguedad < p2.antiguedad));
}
bool resuelveCaso() {
   
   int eventos;
   // leer los datos de la entrada
   std::cin >> eventos;
   if (eventos == 0)
      return false;
   
   priority_queue<persona> cola;
   // resolver el caso posiblemente llamando a otras funciones
   while(eventos--){
    char accion;
    std::cin >> accion;
    if(accion == 'I'){
        persona p;
        p.antiguedad = eventos;
        std::cin >> p.nombre >> p.gravedad;
        cola.push(p);
    }
    else if (accion == 'A'){
        persona aux = cola.top();
        cola.pop();
        std::cout << aux.nombre << std::endl;
    }
   }
   // escribir la solución
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