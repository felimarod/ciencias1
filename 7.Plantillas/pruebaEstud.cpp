#include <iostream>
#include "Lista.h"

//template <class T>
struct Estudiante{
  //T id;
  int cod;
  char *nombre;
  double telefono;
};

void probarEstud() {
  Estudiante e;
  Lista<Estudiante> lista;

  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia");

  for (int i = 1; i < 11; ++i){
    e.cod = i;
    e.telefono = 138495;
    e.nombre = "Juan perez";
    lista.insertar(e);
  }


  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.eliminar(3);
  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.eliminar(9);
  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.insertar(156);
  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.insertar(1489, 2);
  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.ordenar();
  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  int numBuscado = 0;
  printf("La ubicación del número %d es: %d\n\n", numBuscado,
         lista.busquedaBinaria(numBuscado));
  // cout << "uno = " << uno.lista_en_texto() << endl;
  // printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());
  
  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia\n");
}
