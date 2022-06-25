#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using std::to_string;
using std::string;

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
  //bool eliminar(T e);
  void insertar(T inf, int pos);
  void insertar(T inf);
  T obtener_elemento(int pos);
  string lista_en_texto();
  void ordenar();
  int busquedaBinaria(T valor);

private:
  void quickSort(int izq, int der);
  nodo<T> *get_nodo(int pos);
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
template <class T> nodo<T> *Lista<T>::get_nodo(int pos) {
  nodo<T> *p = cab;
  for (int i = 1; i < pos; i++)
    p = p->sig;
  return p;
}

template <class T> void Lista<T>::ordenar() { quickSort(1, tam); }

template <class T> void Lista<T>::quickSort(int izq, int der) {
  int i, j;
  T v, aux;
  if (obtener_elemento(der) > obtener_elemento(izq)) {
    v = obtener_elemento(der);
    i = izq - 1;
    j = der;
    for (;;) {
      while (obtener_elemento(++i) < v) ;
      while (obtener_elemento(--j) > v) ;
      if (i >= j)
        break;
      aux = get_nodo(i)->info;
      get_nodo(i)->info = get_nodo(j)->info;
      get_nodo(j)->info = aux;
    }
    aux = get_nodo(i)->info;
    get_nodo(i)->info = get_nodo(der)->info;
    get_nodo(der)->info = aux;
    quickSort(izq, i - 1);
    quickSort(i + 1, der);
  }
}

/**
 * Buscar el primer elemento con el valor indicado
 */
template<class T>
int Lista<T>::busquedaBinaria(T valor) {
  int primero = 1, ultimo = tam, medio;
  medio = (primero + ultimo) / 2;
  while (primero <= ultimo) {
    if (get_nodo(medio)->info == valor) 
      return medio;
    else if (get_nodo(medio)->info < valor)
      primero = medio + 1;
    else if (get_nodo(medio)->info > valor)
      ultimo = medio - 1;
    medio = (primero + ultimo) / 2;
  }
  return NULL;
}
#endif
