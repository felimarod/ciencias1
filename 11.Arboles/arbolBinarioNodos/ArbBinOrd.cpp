#ifndef ARBBINORD
#define ARBBINORD

#include "Cola.h"
#include "PilaArr.h"
#include <iostream>

struct nodo {
  int clave;
  nodo *izq, *der;
};

class arbBinOrd {
  nodo *A;

public:
  arbBinOrd() { A = NULL; }
  //~arbRojiNegro() { delete A; }
  void insertar(int);
  void eliminar(int);
  bool isEmpty() { return A == NULL; }
  Cola<int> preorden();
  Cola<int> inorden();
  Cola<int> posorden();
  Cola<int> porNiveles();

  /* Opcional */
  nodo *buscarNodo(int);
  nodo *buscarPadre(int);
};

void arbBinOrd::insertar(int dato) {
  nodo *p = NULL;
  nodo *nAct = A;

  nodo *x = new nodo;
  x->clave = dato;
  x->izq = x->der = NULL;

  if (A == NULL) {
    A = x;
  } else {
    while (nAct != NULL) {
      p = nAct;
      if (dato < nAct->clave)
        nAct = nAct->izq;
      else
        nAct = nAct->der;
    }
    if (dato < p->clave)
      p->izq = x;
    else
      p->der = x;
  }
}
void arbBinOrd::eliminar(int dato) {
  nodo *p = NULL, *x = A, *ui = NULL;
  int hijosNodo = 0; /* Cantidad de hijos dle nodo a eliminar*/
  while (x->clave != dato && x != NULL) {
    //std::cout << dato << " vs " << x->clave << std::endl;
    p = x;
    if (dato < x->clave)
      x = x->izq;
    else if (dato > x->clave)
      x = x->der;
    //else 
      //break;
  }

  if (x->izq != NULL)
    hijosNodo++;
  if (x->der != NULL)
    hijosNodo++;

  if (hijosNodo == 0) {
    if (x == p->izq)
      p->izq = NULL;
    else
      p->der = NULL;
  } else if (hijosNodo == 1) {
    if (x == p->izq)
      p->izq = x->der != NULL ? x->der : x->izq;
    else
      p->der = x->der != NULL ? x->der : x->izq;
  } else if (hijosNodo == 2) {
    ui = x->der;
    while (ui->izq != NULL) {
      p = ui;
      ui = ui->izq;
    }
    /* Cambiar valor del nodo con el del nodo de reemplazo */
    x->clave = ui->clave;
    /* Se pasa el hijo derecho de x reemplazara a x como hijo izquierdo del
     * padre */
    if (ui == x->der)
      x->der = ui->der;
    else
      p->izq = ui->der;
    x = ui;
  }
  delete x;
}

nodo *arbBinOrd::buscarNodo(int n) {
  nodo *d; /*Devolver*/
  if (A == NULL)
    return NULL;
  else {
    d = A;
    while (d != NULL && d->clave != n) {
      if (n < d->clave)
        d = d->izq;
      else
        d = d->der;
    }
    if (d->clave == n)
      return d;
    else
      return NULL;
  }
}

nodo *arbBinOrd::buscarPadre(int dato) {
  nodo *aux = A, *p = NULL;
  while (aux->clave != dato && aux != NULL) {
    p = aux;
    if (dato < aux->clave)
      aux = aux->izq;
    else
      aux = aux->der;
  }
  if (aux->clave == dato)
    return p;
  else
    return NULL;
}

Cola<int> arbBinOrd::preorden() {
  nodo *n = A;
  Cola<int> c;
  Pila<nodo *> p;
  if (n == NULL)
    return c;
  p.meter(n);
  while (!p.vacia()) {
    n = p.sacar();
    c.push(n->clave);
    if (n->der != NULL)
      p.meter(n->der);
    if (n->izq != NULL)
      p.meter(n->izq);
  }
  return c;
}

Cola<int> arbBinOrd::inorden() {
  Pila<nodo *> p;
  Cola<int> c;
  nodo *n = A;
  std::cout << "Creando cola\t";
  while (!p.vacia() || n != NULL) {
    if (n != NULL) {
      p.meter(n);
      n = n->izq;
    } else {
      n = p.sacar();
      // Lo que quiera
      c.push(n->clave);
      n = n->der;
    }
  }
  return c;
}

Cola<int> arbBinOrd::posorden() {
  Pila<nodo *> p;
  Cola<int> c;
  nodo *n = A, *lnv = NULL, *peekNode;
  while (!p.vacia() || n != NULL) {
    if (n != NULL) {
      p.meter(n);
      n = n->izq;
    } else {
      peekNode = p.peek();
      if (peekNode->der != NULL && lnv != peekNode->der)
        n = peekNode->der;
      else {
        c.push(peekNode->clave);
        lnv = p.sacar();
      }
    }
  }
  return c;
}

Cola<int> arbBinOrd::porNiveles() {
  Cola<nodo *> c;
  Cola<int> r;
  nodo *n;
  c.push(A);
  while (!c.colaVacia()) {
    n = c.pop();
    r.push(n->clave);
    if (n->izq != NULL)
      c.push(n->izq);
    if (n->der != NULL)
      c.push(n->der);
  }
  return r;
}
#endif /* ifndef ARBBINORD */
