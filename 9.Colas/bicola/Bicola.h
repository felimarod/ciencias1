#include <iostream>

using std::string; using std::to_string;
using std::cout; using std::endl;

#ifndef BICOLA_H
#define BICOLA_H

#define IZQ 'I'
#define DER 'D'

template <class T>
class Bicola {
public:
  Bicola() { cab = NULL; fin = NULL; tam = 0; }
  ~Bicola();
  inline bool bicola_vacia() { return tam == 0; }
  inline int tam_bicola() { return tam; }
  T pop(char lado);
  void push(T inf, char lado);
  string bicola_to_string();

private:
  struct nodo {
    T info;
    nodo *sig, *ant;
  };
  nodo *cab, *fin;
  int tam;
};

template <class T>
Bicola<T>::~Bicola<T>(){
  nodo *aux;
  do {
    cout << "Eliminando " << cab->info << endl;
    aux = cab->sig;
    delete cab;
    cab = aux;
  } while ( cab != NULL );
}

template <class T>
void Bicola<T>::push(T inf, char lado) {
  nodo *nuevo = new nodo;
  nuevo->info = inf;
  nuevo->ant = NULL;
  nuevo->sig = NULL;
  if (bicola_vacia()) {
    cab = nuevo;
    fin = nuevo;
  } else {
    if (lado == 'I') {
      /* ... fin nuevo */
      fin->sig = nuevo;
      nuevo->ant = fin;
      fin = nuevo;
    } else if (lado == 'D') {
      /* nuevo cab ... */
      nuevo->sig = cab;
      cab->ant = nuevo;
      cab = nuevo;
    }
  }
  tam++;
}

template <class T>
string Bicola<T>::bicola_to_string() {
  string str = "[ ";
  nodo *p = cab;
  while (p != NULL) {
    str += to_string(p->info) + " ";
    p = p->sig;
  }
  str += "]";
  return str;
}

template <class T>
T Bicola<T>::pop(char lado) {
  T info;
  nodo *aux;
  if (bicola_vacia())
    return NULL;
  else if (tam == 1) {
    info = cab->info;
    aux = cab;
    cab = NULL;
    fin = NULL;
  } else if (lado == 'I') {
    info = cab->info;

    aux = cab;
    cab = cab->sig;
    cab->ant = NULL;
  } else if (lado == 'D') {
    info = fin->info;

    aux = fin;
    fin = aux->ant;
    fin->sig = NULL;
  }
  delete aux;
  tam--;
  return info;
}

#endif
