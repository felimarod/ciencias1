#ifndef PILANODO_H
#define PILANODO_H

#include <iostream>

using std::string;
using std::to_string;

template <class T> class Pila {
public:
  Pila();
  ~Pila();
  void meter(T v);
  T sacar();
  bool vacia();
  string pilaEnTexto();

private:
  struct nodo {
    T clave;
    struct nodo *siguiente;
  };
  struct nodo *cabeza, *z;
};

template <class T> Pila<T>::Pila() {
  cabeza = new nodo;
  z = new nodo;
  cabeza->siguiente = z;
  z->siguiente = z;
}

template <class T>
Pila<T>::~Pila() {
  struct nodo *t = cabeza;
  while (t != z) {
    cabeza = t;
    t = t->siguiente;
    delete cabeza;
  }
  delete z;
}

template <class T>
void Pila<T>::meter(T inf) {
  struct nodo *t = new nodo;
  t->clave = inf;
  t->siguiente = cabeza->siguiente;
  cabeza->siguiente = t;
}

template <class T>
T Pila<T>::sacar() {
  T x;
  struct nodo *t = cabeza->siguiente;
  cabeza->siguiente = t->siguiente;
  x = t->clave;
  delete t;
  return x;
}

template <class T>
bool Pila<T>::vacia() {
  return cabeza->siguiente == z;
}

template <class T> string Pila<T>::pilaEnTexto() {
  std::string str = "[ ";
  struct nodo *p = cabeza->siguiente;
  do {
    str += to_string(p->clave);
    str += ", ";
    p = p->siguiente;
  } while (p->siguiente != z);
  str += to_string(p->clave) + " ]";
  return str;
}

#endif
