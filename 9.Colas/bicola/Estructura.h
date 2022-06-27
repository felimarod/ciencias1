#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H 

template <class T>
struct nodo {
  T val;
  struct nodo<T> *sig, *ant;
};

#endif /* ifndef ESTRUCTURA_H */
