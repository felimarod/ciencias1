#ifndef PILAARR_H
#define PILAARR_H

#include <iostream>

template <class T> class Pila {
  T *pila;
  int p;

public:
  Pila(int max = 100) {
    pila = new T[max];
    p = 0;
  }
  ~Pila() { delete pila; }
  inline void meter(T v) { pila[p++] = v; }
  inline T sacar() {
    if (p != 0) {
      T d = pila[--p];
      pila[p] = NULL;
      return d;
    } else
      return NULL;
  }
  inline T peek(){ return pila[p -1]; }
  inline int vacia() { return p == 0; }
};

#endif
