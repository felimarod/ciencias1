#include <iostream>

using std::cout;
using std::endl;

#ifndef COLA_H
#define COLA_H

/* LIFO */
template <class T> class Cola {
public:
  Cola() { cab = fin = NULL; }
  void push(T inf);
  T pop();
  void imprimirCola();
  ~Cola();

  inline bool colaVacia() { return cab == NULL; }

private:
  struct nodo {
    T info;
    struct nodo *sig;
  };
  nodo *cab, *fin;
};

template <class T> void Cola<T>::push(T inf) {
  nodo *nuevo = new nodo;
  nuevo->info = inf;
  nuevo->sig = NULL;
  if (cab == NULL)
    cab = nuevo;
  else
    fin->sig = nuevo;
  fin = nuevo;
}

template <class T> T Cola<T>::pop() {
  T x;
  nodo *aux = cab;
  cab = aux->sig;
  x = aux->info;
  delete aux;
  return x;
}

template <class T> void Cola<T>::imprimirCola() {
  nodo *aux;
  aux = cab;
  while (aux != NULL) {
    cout << aux->info << " ";
    aux = aux->sig;
  }
  cout << endl;
}

template <class T> Cola<T>::~Cola() {
  nodo *aux;
  while (cab != NULL) {
    aux = cab;
    cab = aux->sig;
    delete aux;
  }
  delete cab;
}

#endif
