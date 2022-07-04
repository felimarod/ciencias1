//#include "pruebaInt.cpp"
//#include "pruebaChar.cpp"
//#include "pruebaFloat.cpp"
#include "pruebaEstud.cpp"

int main() {

  //probarInt();
  //probarChar();
  //probarFloat();
  probarEstud();
  ListaSimple<Estudiante> *lista;
  lista = getLista();

  printf("Tam lista: %d", lista->getTam());
  return 0;
}
