#ifndef ARBROJINEGRO
#define ARBROJINEGRO

#include "Cola.h"
#include "PilaArr.h"
#include <iostream>

struct nodoRN {
  int clave;
  nodoRN *izq, *der, *pad;
  bool color;
};

class arbRojiNegro {
  nodoRN *A;
  void ajustarSupresionRN(nodoRN *);
  void rotaIzq(nodoRN *);
  void rotaDer(nodoRN *);

public:
  arbRojiNegro() { A = NULL; }
  ~arbRojiNegro() {
    Cola<nodoRN *> cola = preorden();
    nodoRN *aux;
    while (!cola.colaVacia()) {
      delete cola.pop();
    }
  }
  void insertar(int);
  void acomodar(nodoRN *);
  void eliminar(int);
  bool isEmpty() { return A == NULL; }
  Cola<nodoRN *> preorden();
  Cola<nodoRN *> inorden();
  Cola<nodoRN *> posorden();
  Cola<nodoRN *> porNiveles();

  /* Opcional */
  nodoRN *buscarNodo(int);
  // nodoRN *buscarPadre(nodoRN *);
};

void arbRojiNegro::rotaIzq(nodoRN *p) {
  /*       a
         p
      pi   pd
    a  b  c d

          a
        pd
      p   d
    pi  c
   a  b
  */
  nodoRN *a = p->pad;
  nodoRN *pd = p->der;
  nodoRN *c = pd->izq;
  if (pd != NULL) {
    if (a != NULL) {
      if (a->der == p)
        a->der = pd;
      else
        a->izq = pd;
    }
    pd->izq = p;
    p->pad = pd;

    p->der = c;
    if (c != NULL)
      c->pad = p;
    pd->pad = a;
    if (a == NULL) {
      A = pd;
    }
  }
}

void arbRojiNegro::rotaDer(nodoRN *p) {
  /*     p
      pi   pd
    a  b  c d

       pi
      a   p
        b   pd
           c  d
  */

  nodoRN *a = p->pad;
  nodoRN *pi = p->izq;
  nodoRN *b = pi->der;
  if (pi != NULL) {
    if (a != NULL) {
      if (a->der == p)
        a->der = pi;
      else
        a->izq = pi;
    }
    pi->der = p;
    p->pad = pi;

    p->izq = b;
    if (b != NULL)
      b->pad = p;
    pi->pad = a;
    if (a == NULL)
      A = pi;
  }
}

void arbRojiNegro::insertar(int dato) {
  nodoRN *a, *p;

  nodoRN *x = new nodoRN;
  x->clave = dato;
  x->izq = x->der = NULL;
  x->color = true;

  a = NULL;
  p = A;

  if (A == NULL) {
    A = x;
    x->pad = NULL;
  } else {
    while (p != NULL) {
      a = p;
      if (dato < p->clave)
        p = p->izq;
      else
        p = p->der;
    }
    x->pad = a;
    if (dato < a->clave)
      a->izq = x;
    else
      a->der = x;
  }
  acomodar(x);
}
void arbRojiNegro::acomodar(nodoRN *x) {
  nodoRN *t, *a;
  if (A == x) {
    x->color = false;
    return;
  }
  // while (x->pad != NULL && x->pad->color) {
  while ((x->pad != NULL && x->pad != A) && x->pad->color) {
    /* Si el padre existe y es rojo */
    a = x->pad->pad;
    // std::cout << x->clave << std::endl;
    // if (x->clave == 47)
    // std::cout << a->izq->clave << std::endl;
    // std::cout << x->pad->clave << std::endl;
    if (a->izq == x->pad) {
      /* Si el padre esta a la izquierda */
      if (a->der != NULL && a->der->color) {
        /* Si el tío existe */
        t = a->der;
        /* CASO 1
         * Si el padre y el tio son rojos*/
        // std::cout << "Caso 1 con x: " << x->clave << std::endl;
        x->pad->color = false;
        t->color = false;
        a->color = true;
        x = a;
      } else {
        /* Si el tío NO existe */
        /* El tio de x es negro */
        if (x->pad->der == x) {
          /* CASO 2
           * Si el tío es negro y tanto x como su tío son hijos del mismo lado
           */
          // std::cout << "Caso 2 con x: " << x->clave << std::endl;
          x = x->pad;
          rotaIzq(x);
        }
        /* CASO 3
         * Si el tío es negro y es hijo del lado contrario de su tío */
        // std::cout << "Caso 3 con x: " << x->clave << std::endl;
        x->pad->color = false;
        a->color = true;
        rotaDer(a);
      }
    } else {
      /* CASOS SIMETRICOS */
      // std::cout << "SIMETRICO ";
      if (a->izq != NULL && a->izq->color) {
        t = a->izq;
        /* CASO 1
         * Si el padre y el tio son rojos*/
        // std::cout << "Caso 1 con x: " << x->clave << std::endl;
        x->pad->color = false;
        t->color = false;
        a->color = true;
        x = a;
      } else {
        /* El tio de x es negro */
        if (x->pad->izq == x) {
          /* CASO 2
           * Si el tío es negro y tanto x como su tío son hijos del mismo lado
           */
          // std::cout << "Caso 2 con x: " << x->clave << std::endl;
          x = x->pad;
          rotaDer(x);
        }
        /* CASO 3
         * Si el tío es negro y es hijo del lado contrario de su tío */
        // std::cout << "Caso 3 con x: " << x->clave << std::endl;
        x->pad->color = false;
        a->color = true;
        rotaIzq(a);
      }
    }
  }
  A->color = false;
}

void arbRojiNegro::eliminar(int dato) {
  nodoRN *p = NULL, *x = A, *ui = NULL;
  int hijosNodo = 0; /* Cantidad de hijos del nodo a eliminar*/
  while (x->clave != dato && x != NULL) {
    if (dato < x->clave)
      x = x->izq;
    else
      x = x->der;
  }
  if (x != NULL) {
    p = x->pad;
    hijosNodo = (x->izq != NULL ? 1 : 0) + (x->der != NULL ? 1 : 0);
    std::cout << "Hijos del nodo a eliminar: " << hijosNodo << std::endl;
    // if (x->izq != NULL) hijosNodo++;
    // if (x->der != NULL) hijosNodo++;

    if (hijosNodo == 0) {
      if (x->color) {
        if (x == p->izq) {
          p->izq = NULL;
        } else {
          p->der = NULL;
        }
        delete x;
      } else {
        acomodar(x);
        delete x;
      }
    } else if (hijosNodo == 1) {
      if (x == p->izq)
        p->izq = x->der != NULL ? x->der : x->izq;
      else
        p->der = x->der != NULL ? x->der : x->izq;
      delete x;
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
      ajustarSupresionRN(x);
      delete x;
    }
  }
}

void arbRojiNegro::ajustarSupresionRN(nodoRN *x) {
  /* Ciclo principal */
  nodoRN *w;
  while (x != A && !x->color) {
    if (x == x->pad->izq) {
      w = x->pad->der;
      if (w->color) {
        /* CASO 1 */
        w->color = false;
        x->pad->color = true;
        rotaIzq(x->pad);
        w = x->pad->der;
      }
      if (!w->der->color && !w->izq->color) {
        /* CASO 2 */
        w->color = true;
        x = x->pad;
      } else {
        if (!w->der->color) {
          /* CASO 3 */
          w->izq->color = false;
          w->color = false;
          rotaDer(w);
          w = x->pad->der;
        }
        /* CASO 4 */
        w->color = x->pad->color;
        x->pad->color = false;
        w->der->color = false;
        rotaIzq(x->pad);
        x = A;
      }
    } else {
      w = x->pad->izq;
      if (w->color) {
        /* CASO 1 */
        w->color = false;
        x->pad->color = true;
        rotaDer(x->pad);
        w = x->pad->izq;
      }
      if (!w->der->color && !w->izq->color) {
        /* CASO 2 */
        w->color = true;
        x = x->pad;
      } else {
        if (!w->izq->color) {
          /* CASO 3 */
          w->der->color = false;
          w->color = false;
          rotaIzq(w);
          w = x->pad->izq;
        }
        /* CASO 4 */
        w->color = x->pad->color;
        x->pad->color = false;
        w->izq->color = false;
        rotaDer(x->pad);
        x = A;
      }
    }
  }
  x->color = false;
}

nodoRN *arbRojiNegro::buscarNodo(int n) {
  nodoRN *d; /*Devolver*/
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

Cola<nodoRN *> arbRojiNegro::preorden() {
  nodoRN *n = A;
  Cola<nodoRN *> c;
  Pila<nodoRN *> p;
  if (n == NULL)
    return c;
  p.meter(n);
  while (!p.vacia()) {
    n = p.sacar();
    c.push(n);
    if (n->der != NULL)
      p.meter(n->der);
    if (n->izq != NULL)
      p.meter(n->izq);
  }
  return c;
}

Cola<nodoRN *> arbRojiNegro::inorden() {
  Pila<nodoRN *> p;
  Cola<nodoRN *> c;
  nodoRN *n = A;
  // std::cout << "Creando cola\t";
  while (!p.vacia() || n != NULL) {
    if (n != NULL) {
      p.meter(n);
      n = n->izq;
    } else {
      n = p.sacar();
      // Lo que quiera
      c.push(n);
      n = n->der;
    }
  }
  return c;
}

Cola<nodoRN *> arbRojiNegro::posorden() {
  Pila<nodoRN *> p;
  Cola<nodoRN *> c;
  nodoRN *n = A, *lnv = NULL, *peekNode;
  while (!p.vacia() || n != NULL) {
    if (n != NULL) {
      p.meter(n);
      n = n->izq;
    } else {
      peekNode = p.peek();
      if (peekNode->der != NULL && lnv != peekNode->der)
        n = peekNode->der;
      else {
        c.push(peekNode);
        lnv = p.sacar();
      }
    }
  }
  return c;
}

Cola<nodoRN *> arbRojiNegro::porNiveles() {
  Cola<nodoRN *> c;
  Cola<nodoRN *> r;
  nodoRN *n;
  c.push(A);
  while (!c.colaVacia()) {
    n = c.pop();
    r.push(n);
    if (n->izq != NULL)
      c.push(n->izq);
    if (n->der != NULL)
      c.push(n->der);
  }
  return r;
}

#endif /* ifndef ARBROJINEGRO */
