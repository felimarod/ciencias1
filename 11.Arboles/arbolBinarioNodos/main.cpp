#include "ArbBinOrd.cpp"
#include "Cola.h"
#include <iostream>

using namespace std;

int main() {
  arbBinOrd arb;

  if (arb.isEmpty())
    cout << "Esta vacía" << endl;

  arb.insertar(86);
  arb.insertar(65);
  arb.insertar(70);
  arb.insertar(73);
  arb.insertar(93);
  arb.insertar(69);
  arb.insertar(25);
  arb.insertar(66);
  arb.insertar(68);
  arb.insertar(47);
  arb.insertar(62);
  arb.insertar(10);

  arb.eliminar(67);
  Cola<int> c = arb.porNiveles();
  while (!c.colaVacia())
    cout << "\t" << c.pop();
  cout << endl;


  return 0;
}
