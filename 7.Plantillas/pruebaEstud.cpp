#include <iostream>
#include "ListaSimple.h"

using namespace std;


struct Estudiante{
  int cod;
  string nombre;
  int telefono;
};

ListaSimple<Estudiante> lista;

ListaSimple<Estudiante> *getLista(){
  return &lista;
}
void imprimir(){
  Estudiante *aux;
  cout << "{\n";
  for(int i=1; i<lista.getTam() ; i++){
    cout << "\t{";

    aux = lista.obtenerElemento(i);

    cout << "\tcodigo: " << aux->cod << "\n";
    cout << "\t\tnombre: " <<  aux->nombre << "\n";
    cout << "\t\ttelefono: " << aux->telefono << "\n";
    cout << "\t}\n";
  }
  cout << "}";
  printf("\nEl tamaño de la lista es: %d\n\n", lista.getTam());
}

void probarEstud() {

  if (lista.listaVacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia");

  for (int i = 1; i < 11; ++i){
    Estudiante e;
    e.cod = i;
    e.telefono = 138495;
    e.nombre = "Juan perez";
    lista.insertar(e);
  }

  imprimir();

  Estudiante *aux = lista.obtenerElemento(11);
  if(aux != NULL){
    cout << "Nombre: " << aux->nombre;
    cout << "Codigo: " << aux->cod;
    cout << "Telefono: " << aux->telefono;
  }

  //lista.eliminar(3);
  //cout << "lista: " << lista.lista_en_texto() << endl;
  //printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  //lista.eliminar(9);
  //cout << "lista: " << lista.lista_en_texto() << endl;
  //printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  //Estudiante e;
  //e.nombre = "Diego porque soy un egocentrico";
  //e.cod = 80;
  //e.telefono = NULL;
  //lista.insertar(e);
  //cout << "lista: " << lista.lista_en_texto() << endl;
  //printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  //Estudiante a;
  //a.nombre = "AVioncito";
  //a.cod = 810;
  //a.telefono = NULL;
  //lista.insertar(a, 2);
  //cout << "lista: " << lista.lista_en_texto() << endl;
  //printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  //lista.ordenar();
  //cout << "lista: " << lista.lista_en_texto() << endl;
  //printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  //int numBuscado = 0;
  //printf("La ubicación del número %d es: %d\n\n", numBuscado,
  //lista.busquedaBinaria(numBuscado));
  // cout << "uno = " << uno.lista_en_texto() << endl;
  // printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  if (lista.listaVacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia\n");
}
