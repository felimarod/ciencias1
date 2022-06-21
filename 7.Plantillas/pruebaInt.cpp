#include "Lista.h"

void probarInt() {
  Lista<int> lista;

  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia");

  for (int i = 1; i < 11; ++i)
    lista.insertar(i);

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
