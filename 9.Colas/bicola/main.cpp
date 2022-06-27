#include "Bicola.h"
#include <iostream>

using namespace std;

int main() {
  Bicola<int> bicola;
  string salida = bicola.vacia() ? "fila vacia": "con contenido";
  cout << salida << endl; 

  bicola.push(3, 'I');
  bicola.imprimirBicola(); // 3

  //salida = bicola.vacia() ? "fila vacia": "con contenido";
  //cout << salida << endl; 

  bicola.push(8, 'D');
  bicola.imprimirBicola(); // 8 3
  
  //bicola.push(10, 'I');
  //bicola.imprimirBicola(); // 8 3 10

  //cout << "Sacando: " << bicola.pop('D') << endl; // 8 3

  //bicola.push(12, 'I');
  //bicola.imprimirBicola(); // 12 8 3

  //cout << "Sacando: " << bicola.pop('I') << endl; // 8 3

  //bicola.imprimirBicola(); // "8 3"
  //bicola.~Bicola();

  return 0;
}
