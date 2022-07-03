#include <iostream>

using std::cout;

#ifndef BICOLA_H
#define BICOLA_H

#define IZQ 'I'
#define DER 'D'

template <class T>
class Queue {
  public:
    Queue() { cab = fin = NULL; tam = 0; }
    ~Queue();
    inline bool isEmpty() { return tam == 0; }
    inline int getTam() { return tam; }
    T dequeue(char lado);
    void enqueue(T, char);
    void show(char);

  private:
    struct nodo {
      T info;
      nodo *sig, *ant;
    };
    nodo *cab, *fin;
    int tam;
};

template <class T>
Queue<T>::~Queue(){
  nodo *p;
  do {
    /* cout << "Eliminando " << cab->info <<endl; */
    p = cab->sig;
    delete cab;
    cab = p;
  }while(p != NULL);

}

template <class T>
T Queue<T>::dequeue(char lado) {
  T info;
  nodo *aux;
  if (tam == 0)
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

template <class T>
void Queue<T>::enqueue(T inf, char lado) {
  nodo *nuevo = new nodo;
  nuevo->info = inf;
  nuevo->ant = NULL;
  nuevo->sig = NULL;
  if (tam == 0) {
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
void Queue<T>::show(char lado) {
  cout << "[ ";
  nodo *p;
  if ( lado == IZQ ){
    p = cab;
    while (p != NULL) {
      cout << p->info << " ";
      p = p->sig;
    }

  } else if ( lado == DER ) {
    p = fin;
    while (p != NULL) {
      cout << p->info << " ";
      p = p->ant;
    }
  }
  cout << "]\n";
}

#endif
