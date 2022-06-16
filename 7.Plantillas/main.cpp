#include "Lista.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct estud{
  int cod;
  string nombre;
  double telefono;
};
void probarint(){
  Lista<int> uno;

  if(uno.lista_vacia())
    printf("la lista esta vacia\n");

  for (int i = 1; i < 11; ++i)
    uno.insertar(i);
  cout << "uno = " << uno.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.eliminar(3);
  cout << "uno = " << uno.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.eliminar(9);
  cout << "uno = " << uno.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.insertar(156);
  cout << "uno = " << uno.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.insertar(1489,2);
  cout << "uno = " << uno.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());
}

int main() {
  Lista<char> uno;

  if(uno.lista_vacia())
    printf("la lista esta vacia\n");

  for (int i = 'a'; i <= 'z'; ++i)
    uno.insertar(i);

  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  printf("lista = [\t");
  for(int i=1; i<=uno.tam_lista();i++)
    printf("%c\t", uno.obtener_elemento(i));
  printf("]\n");
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.eliminar(3);
  printf("lista = [\t");
  for(int i=1; i<=uno.tam_lista();i++)
    printf("%c\t", uno.obtener_elemento(i));
  printf("]\n");
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.eliminar(9);
  printf("lista = [\t");
  for(int i=1; i<=uno.tam_lista();i++)
    printf("%c\t", uno.obtener_elemento(i));
  printf("]\n");
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  //uno.insertar(15);
  //uno.insertar('a');
  //printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());
  //for(int i=1; i<uno.tam_lista();i++)
    //printf("uno[%d] = %c\n", i, uno.obtener_elemento(i));

  //uno.insertar(14,2);
  //printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());
  //for(int i=1; i<uno.tam_lista();i++)
    //printf("uno[%d] = %c\n", i, uno.obtener_elemento(i));


  //Lista<float> tres;
  //Lista<estud> cuatro;

  return 0;
}
