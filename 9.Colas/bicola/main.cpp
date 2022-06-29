#include "Bicola.h"

using std::cout;
using std::endl;

Bicola<int> bicola;

void muestraListaYTamanio();
void agregar(int n, char orden);
void atender(char orden);
void bicola_vacia();

int main() {
  bicola_vacia();
//Queue P;
//P.enqueue(3,I); // 3
//P.enqueue(8,D); // 8 3
//P.enqueue(10,I); // 8 3 10
//P.dequeue(D); // 8 3
//P.enqueue(12, D); // 12 8 3
//P.dequeue(I); // 8 3
//P.imprimir(I); // "8 3"
  agregar(3, 'I');
  agregar(8, 'D');
  agregar(10, 'I');
  atender('D');
  agregar(12, 'D');
  atender('I');
  //atender('D');
  //atender('I');
  //agregar(26, 'I');
  //atender('I');
  //agregar(57, 'D');
  //agregar(1, 'I');

  bicola_vacia();

  return 0;
}

void muestraListaYTamanio() {
  printf("Tamaño: %d\t\t\t", bicola.tam_bicola());
  cout << "Lista: " << bicola.bicola_to_string() << endl << endl;
}

void agregar(int n, char orden) {
  string orientacion = orden=='I'?"izquierda":"derecha" ;

  cout << "Agregar " << n << " a la "<< orientacion << endl;
  bicola.push(n, orden);
  muestraListaYTamanio();
}

void atender(char orden) {
  cout << "Atiende por " << orden << ": " << bicola.pop(orden) << endl;
  muestraListaYTamanio();
}

void bicola_vacia() {
  if (bicola.bicola_vacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia\n");
}
