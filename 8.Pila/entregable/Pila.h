#ifndef PILAARR_H
#define PILAARR_H

#include <string>

using std::string;
using std::to_string;

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
  inline T sacar() { return pila[--p]; }
  inline int vacia() { return !p; }
  string pilaEnTexto();
};

template <class T> string Pila<T>::pilaEnTexto() {
  string str = "[ ";
  int i = p - 1;
  while (i >= 0) {
    str += to_string(pila[i]);
    if (i-- == 0)
      str += " ]";
    else
      str += ", ";
  }
  return str;
}
#endif
