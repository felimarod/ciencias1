#include <iostream>
#include "ListaSimple.h"

ListaSimple<char> uno;

using namespace std;

void imprimirLista(){
  cout << "[ ";
  for (int i = 1; i <= uno.getTam(); i++)
    cout << uno.obtenerElemento(i) << " ";
  cout << "]";
  printf("\nEl tamaño de la lista es: %d\n\n", uno.getTam());
}

void probarChar() {
  if (uno.listaVacia())
    printf("la lista esta vacia\n");

  for (int i = 'a'; i <= 'z'; ++i)
    uno.insertar(i);

  imprimirLista();

  uno.eliminar(3);
  imprimirLista();

  uno.eliminar(9);
  imprimirLista();
}
