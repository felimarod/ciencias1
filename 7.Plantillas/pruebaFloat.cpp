#include "Lista.h"

void probarFloat() {

  Lista<float> lista;

  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia");

  for (float i = 1; i < 11; i = i + 0.5)
    lista.insertar(i);

  printf("lista: %s", lista.lista_en_texto().c_str());
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.eliminar(3);
  printf("lista: %s", lista.lista_en_texto().c_str());
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.eliminar(9);
  printf("lista: %s", lista.lista_en_texto().c_str());
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.insertar(156.345);
  printf("lista: %s", lista.lista_en_texto().c_str());
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  lista.insertar(1489.2355, 2);
  printf("lista: %s", lista.lista_en_texto().c_str());
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  /**lista.ordenar();
  cout << "lista: " << lista.lista_en_texto() << endl;
  printf("El tamaño de la lista es: %d\n\n", lista.tam_lista());

  int numBuscado = 0;
  printf("La ubicación del número %d es: %d\n\n", numBuscado,
         lista.busquedaBinaria(numBuscado));
  */
  /// cout << "uno = " << uno.lista_en_texto() << endl;
  // printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  if (lista.lista_vacia())
    printf("la lista esta vacia\n");
  else
    printf("La lista NO esta vacia\n");
}
int main(int argc, char *argv[])
{
  probarFloat();
  return 0;
}
