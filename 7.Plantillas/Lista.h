#ifndef LISTA_H
#define LISTA_H

#include "string.h"
#include <iostream>

using namespace std;

template <class T> struct nodo {
  T info;
  nodo *sig;
};

template <class T> class Lista {
  nodo<T> *cab;
  int tam;

public:
  Lista() {
    cab = NULL;
    tam = 0;
  }
  bool lista_vacia();
  int tam_lista();
  bool eliminar(int pos);
  void insertar(T inf, int pos);
  void insertar(T inf);
  T obtener_elemento(int pos);
  string lista_en_texto();
};

template <class T> bool Lista<T>::lista_vacia() { return tam == 0; }

template <class T> int Lista<T>::tam_lista() { return tam; }

template <class T> void Lista<T>::insertar(T inf) {
  nodo<T> *p = new nodo<T>, *aux;
  p->info = inf;
  p->sig = NULL;
  if (cab == NULL)
    cab = p;
  else {
    aux = cab;
    while (aux->sig != NULL)
      aux = aux->sig;
    aux->sig = p;
  }
  tam++;
}

template <class T> bool Lista<T>::eliminar(int pos) {
  if (lista_vacia() || pos > tam || pos < 1)
    return false;
  nodo<T> *p = cab, *aux;
  if (pos == 1) {
    cab = cab->sig;
    delete p;
  } else {
    for (int i = 1; i < pos - 1; i++)
      p = p->sig;
    aux = p->sig;
    if (pos < tam) {
      p->sig = aux->sig;
      delete aux;
    } else if (pos == tam) {
      p->sig = NULL;
      delete aux;
    }
  }
  tam--;
  return true;
}

template <class T> void Lista<T>::insertar(T inf, int pos) {
  nodo<T> *p = cab, *aux, *nn;
  if (pos > tam)
    insertar(inf);
  else {
    nn = new nodo<T>;
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
template <class T> T Lista<T>::obtener_elemento(int pos) {
  if (pos < 1 || pos > tam)
    return NULL;

  nodo<T> *p = cab;
  for (int i = 1; i < pos; i++)
    p = p->sig;
  return p->info;
}

template <class T> string Lista<T>::lista_en_texto() {
  string str = "[ ";
  nodo<T> *p = cab;
  do {
    str += to_string(p->info) + ", ";
    p = p->sig;
  } while (p->sig != NULL);
  str += to_string(p->info) + " ]";
  return str;
}

#endif
