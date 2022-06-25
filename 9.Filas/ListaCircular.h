#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <iostream>

// LISTA CIRCULAR ORDENADA
template <class T> class ListaCO {
public:
  ListaCO();
  ~ListaCO();

  void insertar(T inf);
  T obtener_elemento(int pos);
  bool eliminar(int pos);

  inline bool vacia() { return tam == 0; }
  inline int tam_lista() { return tam; };

private:
  struct nodo {
    T info;
    struct nodo *sig;
  };
  struct nodo *cabeza, *z;
  int tam;
};

template <class T>
ListaCO<T>::ListaCO() {
  cabeza = new nodo;
  z = new nodo;
  cabeza->sig = z;
  z->sig = cabeza;
  tam = 0;
}

template <class T>
ListaCO<T>::~ListaCO() {
  struct nodo *t = cabeza;
  while (t != z) {
    cabeza = t;
    t = t->sig;
    delete cabeza;
  }
  delete z;
}

template <class T>
void ListaCO<T>::insertar(T inf) {
  T aux;
  nodo *nn, *p;
  if (vacia()){
    //printf("buenas");
    cabeza->info = inf;
    tam++;
  } else if (tam == 1){
    aux = cabeza->info;
    if(inf < aux){
      cabeza->info= inf;
      z->info = aux;
    } else z->info = inf;
    tam++;
  } else {
    nn = new nodo;
    nn->info = inf;

    p = cabeza;
    aux = p->info;
    while(inf > aux){
      p = p->sig;
      aux = p->info;
    }
    nn->sig = p->sig;
    p->sig = nn;
    tam++;
  }
  //struct nodo *t = new nodo;
  //t->clave = inf;
  //t->siguiente = cabeza->siguiente;
  //cabeza->siguiente = t;
}

template <class T> 
T ListaCO<T>::obtener_elemento(int pos) {
  if (pos < 1 || pos > tam)
    return NULL;
  else if (pos == 1)
    return cabeza->info;
  else if (pos == tam)
    return z->info;
  else {

  struct nodo *p = cabeza;
  for (int i = 1; i < pos; i++)
    p = p->sig;
  return p->info;
  }
}
template <class T>
bool ListaCO<T>::eliminar(int pos) {
  T x;
  struct nodo *t = cabeza->siguiente;
  cabeza->siguiente = t->siguiente;
  x = t->clave;
  delete t;
  return x;
}

#endif
