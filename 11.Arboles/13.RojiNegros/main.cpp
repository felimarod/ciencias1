#include "ArbRojiNegro.cpp"
#include "Cola.h"
#include <iostream>

using namespace std;

int main() {
  nodoRN *aux = NULL;
  arbRojiNegro arb;

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

  Cola<nodoRN *> c = arb.porNiveles();
  cout << endl << "Imprimiendo POR NIVELES\n";
  while (!c.colaVacia()) {
    aux = c.pop();
    cout << (aux->pad == NULL ? "RAÍZ:" : "NODO:") << "{";
    // if (aux->izq != NULL) cout << "\tIzq: " << aux->izq->clave ;
    // if (aux->der != NULL) cout << " \tDer: " << aux->der->clave ;
    cout << "\tClave: " << aux->clave;
    cout << "\tColor: " << (aux->color ? "Rojo" : "Negro");
    if (aux->pad != NULL)
      cout << "\tPadre: " << aux->pad->clave;
    cout << " }" << endl;
  }

  Cola<nodoRN *> d = arb.preorden();
  cout << endl << "Imprimiendo PREORDEN\n";
  while (!d.colaVacia()) {
    aux = d.pop();
    cout << (aux->pad == NULL ? "RAÍZ:" : "NODO:") << "{";
    // if (aux->izq != NULL) cout << "\tIzq: " << aux->izq->clave ;
    // if (aux->der != NULL) cout << " \tDer: " << aux->der->clave ;
    cout << "\tClave: " << aux->clave;
    cout << "\tColor: " << (aux->color ? "Rojo" : "Negro");
    if (aux->pad != NULL)
      cout << "\tPadre: " << aux->pad->clave;
    cout << " }" << endl;
  }

  arb.eliminar(10); 
  arb.eliminar(93); 

  Cola<nodoRN *> e = arb.inorden();
  cout << endl << "Imprimiendo INORDEN\n";
  while (!e.colaVacia()) {
    aux = e.pop();
    cout << (aux->pad == NULL ? "RAÍZ:" : "NODO:") << "{";
    // if (aux->izq != NULL) cout << "\tIzq: " << aux->izq->clave ;
    // if (aux->der != NULL) cout << " \tDer: " << aux->der->clave ;
    cout << "\tClave: " << aux->clave;
    cout << "\tColor: " << (aux->color ? "Rojo" : "Negro");
    if (aux->pad != NULL)
      cout << "\tPadre: " << aux->pad->clave;
    cout << " }" << endl;
  }

  Cola<nodoRN *> f = arb.posorden();
  cout << endl << "Imprimiendo POSORDEN\n";
  while (!f.colaVacia()) {
    aux = f.pop();
    cout << (aux->pad == NULL ? "RAÍZ:" : "NODO:") << "{";
    // if (aux->izq != NULL) cout << "\tIzq: " << aux->izq->clave ;
    // if (aux->der != NULL) cout << " \tDer: " << aux->der->clave ;
    cout << "\tClave: " << aux->clave;
    cout << "\tColor: " << (aux->color ? "Rojo" : "Negro");
    if (aux->pad != NULL)
      cout << "\tPadre: " << aux->pad->clave;
    cout << " }" << endl;
  }
  return 0;
}
