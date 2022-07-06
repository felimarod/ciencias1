#include "ArbolBinOrdArreglo.cpp"

int main() {
  arBinOrdArreglo arb;
  //arb.imprimirNodos();
  arb.insertar(100);
  arb.insertar(150);
  arb.insertar(50);
  arb.insertar(30);
  arb.insertar(75);
  arb.insertar(125);
  arb.insertar(170);
  arb.insertar(10);
  arb.insertar(60);
  arb.insertar(90);
  arb.insertar(180);
  arb.insertar(140);
  arb.insertar(160);
  //arb.imprimirNodos();
  arb.eliminar(10);
  arb.eliminar(125);
  arb.eliminar(50);
  arb.imprimirNodos();
  return 0;
}
