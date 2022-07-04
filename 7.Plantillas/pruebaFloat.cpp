#include <iostream>
#include "ListaSimple.h"

ListaSimple<float> lista;

using namespace std;
void imprimirLista(){
  cout << "[ ";
  for (int i = 1; i <= lista.getTam(); i++)
    cout << lista.obtenerElemento(i) << " ";
  cout << "]";
  printf("\nEl tamaño de la lista es: %d\n\n", lista.getTam());
}

void probarFloat() {
  if (lista.listaVacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia");

  for (float i = 1; i < 11; i = i + 0.5)
    lista.insertar(i);

  imprimirLista();

  lista.eliminar(3);
  imprimirLista();

  lista.eliminar(9);
  imprimirLista();

  lista.insertar(156.345);
  imprimirLista();

  lista.insertar(1489.2355, 2);
  imprimirLista();

  if (lista.listaVacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia\n");
}
