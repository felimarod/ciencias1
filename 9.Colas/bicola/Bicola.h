#include "Estructura.h"
#include <iostream>

using std::cout;
using std::endl;

#ifndef BICOLA_H
#define BICOLA_H 

#define IZQ 'I'
#define DER 'D'

template<class T>
class Bicola {
  public:
    Bicola(){
      cab = fin = 0;
      //cout << "Entra al constructor" << endl
           //<< "cab: " << cab << endl
           //<< "fin: " << fin << endl;
    }
    void push(T val, char sentido);
    T pop(char sentido);
    void imprimirBicola();
    inline bool vacia(){ return cab == 0 && fin == 0 ; }
    ~Bicola();
  private:
    nodo<T> *cab, *fin;
};


template<class T>
void Bicola<T>::push(T val, char sentido) {
  nodo<T> *nuevo;
  nuevo->val = val;
  if( vacia() ) {
    nuevo->ant = nuevo->sig = cab = fin = nuevo;
  } else {
    if ( sentido == IZQ ) {
      /* cab ... fin nuevo */
      nuevo->ant = fin;
      fin->sig = nuevo;
      fin = nuevo;
    } else if ( sentido == DER ) {
      /* nuevo cab ... fin*/
      nuevo->sig = cab;
      cab->ant = nuevo;
      cab = nuevo;
    }
    //fin->sig = cab;
  }
}

template<class T>
T Bicola<T>::pop(char sentido) {
  nodo<T> *aux;
  T val;
  if ( sentido == IZQ ) {
    aux = cab;
    cab = cab->sig;
    cab->ant = 0;
  } else if ( sentido == DER ) {
    aux = fin;
    fin = fin->ant;
    fin->sig = NULL;
  }
  val = aux->val;
  delete aux;
  return val;
}

template<class T>
void Bicola<T>::imprimirBicola() {
  nodo<T> *aux = cab;
  cout << "Imprmiendo de Izauierda a Derecha:" << endl
       << aux->val << " ";
  while ( aux->sig != cab ) {
    aux = aux->sig;
    cout << aux->val << " ";
  }
  cout << endl;
}

template <class T>
Bicola<T>::~Bicola() {
  nodo<T> *aux;
  while ( cab->sig != cab ) {
    aux = cab;
    cab = aux->sig;
    delete aux;
  }
  cout << endl;
  delete cab;
}
#endif /* ifndef BICOLA_h */
