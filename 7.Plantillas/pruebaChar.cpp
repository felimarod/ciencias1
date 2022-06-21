#include "Lista.h"

void probarChar() {
  Lista<char> uno;
  if (uno.lista_vacia())
    printf("la lista esta vacia\n");

  for (int i = 'a'; i <= 'z'; ++i)
    uno.insertar(i);

  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  printf("lista = [\t");
  for (int i = 1; i <= uno.tam_lista(); i++)
    printf("%c\t", uno.obtener_elemento(i));
  printf("]\n");
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.eliminar(3);
  printf("lista = [\t");
  for (int i = 1; i <= uno.tam_lista(); i++)
    printf("%c\t", uno.obtener_elemento(i));
  printf("]\n");
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());

  uno.eliminar(9);
  printf("lista = [\t");
  for (int i = 1; i <= uno.tam_lista(); i++)
    printf("%c\t", uno.obtener_elemento(i));
  printf("]\n");
  printf("El tamaño de la lista es: %d\n\n", uno.tam_lista());
}
