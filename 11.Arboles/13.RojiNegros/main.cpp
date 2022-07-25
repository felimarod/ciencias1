#include "ArbRojiNegro.cpp"
#include "Cola.h"
#include <iostream>

using namespace std;

int main() {
  arbRojiNegro arb;

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
   //arb.insertar(10);

  Cola<nodoRN *> c = arb.porNiveles();
  // mostrarArbol(c);
  nodoRN *aux;
  cout << "Imprimiendo cola\n";
  while (!c.colaVacia()) {
    aux = c.pop();
    //<< "\tNODO\n"
    aux->pad == NULL ? cout << "RAÍZ" << endl : cout << "NODO" << endl;
    cout << "Clave: " << aux->clave << endl;
    // if (aux->pad != NULL)
    // cout << "Padre: " << aux->pad->clave << endl;
    cout << "Color: " << (aux->color ? "Rojo" : "Negro");
    cout << endl << endl;
  }
  cout << endl;

  // nodoRN *padre = arb.buscarNodo(69)->pad;
  // cout << "Clave del padre de 69: " << padre->clave << endl;

  return 0;
}
