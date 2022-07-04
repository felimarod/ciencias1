#include <iostream>
#include "ListaSimple.h"

using namespace std;

ListaSimple<int> lista;

void probarInt();
void imprimirLista(){
  cout << "[ ";
  for (int i = 1; i <= lista.getTam(); i++)
    cout << lista.obtenerElemento(i) << " ";
  cout << "]";
  printf("\nEl tamaño de la lista es: %d\n\n", lista.getTam());
}

void probarInt() {

  if (lista.listaVacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia");

  for (int i = 1; i < 11; ++i)
    lista.insertar(i);

  imprimirLista();

  if(lista.eliminar(1)){
    printf("Se Elimino la posición 1\n");
  } else {
    printf("NO se elimino la posición 1\n");
  }
  imprimirLista();

  lista.eliminar(9);
  imprimirLista();

  lista.insertar(156);
  imprimirLista();

  lista.insertar(1489, 2);
  imprimirLista();
  int contiene = 156;
  if(lista.contiene(contiene)){
    printf("la lista tiene el número %d\n", contiene);
  }

  if (lista.listaVacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia\n");
}
