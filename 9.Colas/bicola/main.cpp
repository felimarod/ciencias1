#include <iostream>
#include "Bicola.h"

//using namespace std;


int main() {
  Bicola<int> bicola;
  if (bicola.bicola_vacia())
    printf("la lista esta vacia\n");

  bicola.insertar(3, 'I');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola()); 


  bicola.insertar(8, 'D');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());

  
  bicola.insertar(10, 'I');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());


  bicola.eliminar('D');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());

  
  bicola.insertar(12, 'D');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());


  bicola.eliminar('I');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());
	

  bicola.eliminar('I');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());


  bicola.eliminar('D');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());
  
  bicola.insertar(26, 'I');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());

  bicola.insertar(57, 'D');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());

  bicola.insertar(1, 'I');
  cout << "lista: " << bicola.imprimir_bicola() << endl;
  printf("El tamano de la lista es: %d\n\n", bicola.tam_bicola());


  if (bicola.bicola_vacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia\n");

  return 0;
}
