#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H 

template <class T>
struct nodo {
  T info;
  struct nodo *sig;
};

#endif /* ifndef ESTRUCTURA_H */
