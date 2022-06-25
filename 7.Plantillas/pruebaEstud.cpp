#include <iostream>
#include <string>
#include "Lista.h"

//template <class T>
struct Estudiante{
  //T id;
  int cod;
  char *nombre;
  int telefono;
};

string objetosEnLista(Lista<Estudiante> lista){
  Estudiante aux;
  //cout << "lista: " << lista.lista_en_texto() << endl;
  string salida = "{\n";
  for(int i=1; i<lista.tam_lista() ; i++){
    salida += "\t{";

    aux = lista.obtener_elemento(i);

    salida += "\tcodigo: " + to_string(aux.cod) + "\n";
    string salidat = aux.nombre;
    salida += "\t\tnombre: " + salidat + "\n";
    salida += "\t\ttelefono: " + to_string(aux.telefono) + "\n";
    salida += "\t}\n";
  }
  salida += "}";
  return salida;
}

void probarEstud() {
  Lista<Estudiante> lista;

  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia");

  for (int i = 1; i < 11; ++i){
    Estudiante e;
    e.cod = i;
    e.telefono = 138495;
    e.nombre = "Juan perez";
    lista.insertar(e);
    //printf("Se agrego el estudiante %d\n", i);
  }

  //std::cout << objetosEnLista(lista) << std::endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  Estudiante aux = lista.obtener_elemento(1234);
  printf("Nombre: %c, codigo: %d, telefono: %d", aux.nombre,aux.cod,aux.telefono);

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
  
  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else 
    printf("La lista NO esta vacia\n");
}
