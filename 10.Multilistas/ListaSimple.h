#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>

template <class T> class ListaSimple {
  public:
    ListaSimple() {
      cab = fin = NULL;
      tam = 0;
    }
    ~ListaSimple(){
      nodo* auxCab;
      while(cab != NULL){
        auxCab = cab->sig;
        delete cab;
        cab = auxCab;
      }
    }
    inline bool listaVacia() { return tam == 0; }
    inline int getTam() { return tam; }
    bool eliminar(int);
    void insertar(T, int);
    void insertar(T);
    T obtenerElemento(int);
    bool contiene(T);

  private:
    struct nodo {
      T info;
      nodo *sig;
    };
    nodo *cab, *fin;
    int tam;
};

template <class T>
void ListaSimple<T>::insertar(T inf) {
  nodo *p = new nodo;
  p->info = inf;
  p->sig = NULL;
  if (cab == NULL)
    cab = fin = p;
  else {
    fin->sig = p;
    fin = p;
  }
  tam++;
}

template <class T>
bool ListaSimple<T>::eliminar(int pos) {
  if (listaVacia() || pos < 1 || pos > tam )
    return false;
  nodo *p = cab, *aux;
  if (pos == 1) {
    cab = cab->sig;
    if (cab == NULL)
      fin = NULL;
    delete p;
  } else {
    for (int i = 1; i < pos - 1; i++)
      p = p->sig;
    aux = p->sig;
    if (pos < tam) {
      p->sig = aux->sig;
    } else if (pos == tam) {
      p->sig = NULL;
      fin = p;
    }
    delete aux;
  }
  tam--;
  return true;
}

template <class T>
void ListaSimple<T>::insertar(T inf, int pos) {
  if (pos > tam)
    insertar(inf);
  else {
    nodo *p = cab, *aux, *nn;
    nn = new nodo;
    nn->info = inf;
    if (pos == 1) {
      nn->sig = cab;
      cab = nn;
    } else if (pos <= tam) {
      for (int i = 1; i < pos - 1; i++)
        p = p->sig;
      aux = p->sig;
      p->sig = nn;
      nn->sig = aux;
    }
    tam++;
  }
}

template <class T>
T ListaSimple<T>::obtenerElemento(int pos) {
  if (pos > 0 || pos <= tam) {
    nodo *p = cab;
    for (int i = 1; i < pos; i++)
      p = p->sig;

    return p->info;
  }
}
template<class T>
bool ListaSimple<T>::contiene(T info){
  nodo *p = cab;
  while(p!= NULL){
    if(p->info == info)
      return true;
    p = p->sig;
  }
  return false;
}

#endif
