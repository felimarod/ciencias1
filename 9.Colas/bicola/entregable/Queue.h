#include <iostream>

using std::to_string;
using std::cout;

#ifndef QUEUE_H
#define QUEUE_H

#define IZQ 'I'
#define DER 'D'

template <class T>
class Queue {
public:
  Queue() { cab = fin = NULL; tam = 0; }
  ~Queue();
  inline bool isEmpty() { return tam == 0; }
  inline int getTam() { return tam; }
  void enqueue(T, char);
  T dequeue(char);
  void printQueue(char);

private:
  struct nodo {
    T info;
    nodo *sig, *ant;
  };
  nodo *cab, *fin;
  int tam;
};

template <class T>
Queue<T>::~Queue<T>(){
  nodo *aux;
  do {
    aux = cab->sig;
    delete cab;
    cab = aux;
  } while ( cab != NULL );
}

template <class T>
void Queue<T>::enqueue(T inf, char lado) {
  nodo *nuevo = new nodo;
  nuevo->info = inf;
  nuevo->ant = NULL;
  nuevo->sig = NULL;
  if (isEmpty()) {
    cab = nuevo;
    fin = nuevo;
  } else {
    if (lado == IZQ) {
      /* ... fin nuevo */
      fin->sig = nuevo;
      nuevo->ant = fin;
      fin = nuevo;
    } else if (lado == DER) {
      /* nuevo cab ... */
      nuevo->sig = cab;
      cab->ant = nuevo;
      cab = nuevo;
    }
  }
  tam++;
}

template <class T>
T Queue<T>::dequeue(char lado) {
  T info;
  nodo *aux;
  if ( tam == 0 )
    return NULL;
  else if (tam == 1) {
    info = cab->info;
    aux = cab;
    cab = NULL;
    fin = NULL;
  } else if (lado == IZQ) {
    info = cab->info;

    aux = cab;
    cab = cab->sig;
    cab->ant = NULL;
  } else if (lado == DER) {
    info = fin->info;

    aux = fin;
    fin = aux->ant;
    fin->sig = NULL;
  }
  delete aux;
  tam--;
  return info;
}

template <class T>
void Queue<T>::printQueue(char lado) {
  cout << "[ ";
  nodo *p;
  if ( lado == IZQ ){
    p = cab;
    while (p != NULL) {
      cout << to_string(p->info) + ' ';
      p = p->sig;
    }
  } else if ( lado == DER ) {
    p = fin;
    while (p != NULL) {
      cout << to_string(p->info) + ' ';
      p = p->ant;
    }
  }
  cout << "]\n";
}

#endif
