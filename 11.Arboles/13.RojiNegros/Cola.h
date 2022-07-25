#ifndef COLA_H
#define COLA_H

#include <iostream>

template <class T> class Cola {
public:
  Cola() { a = z = NULL; }
  void push(T inf);
  T pop();
  ~Cola();

  inline bool colaVacia() { return a == NULL; }

private:
  struct nodo {
    T info;
    struct nodo *sig;
  };
  nodo *a, *z;
};

template <class T> void Cola<T>::push(T inf) {
  nodo *nuevo;
  nuevo = new nodo;
  nuevo->info = inf;
  nuevo->sig = NULL;
  if (a == NULL) a = nuevo;
  else z->sig = nuevo;
  z = nuevo;
}

template <class T> T Cola<T>::pop() {
  T x;
  nodo *aux = a;
  x = a->info;
  a = a->sig;
  delete aux;
  return x;
}

template <class T> Cola<T>::~Cola() {
  nodo *aux;
  while (a != NULL) {
    aux = a;
    a = aux->sig;
    delete aux;
  }
  delete a;
}

#endif
