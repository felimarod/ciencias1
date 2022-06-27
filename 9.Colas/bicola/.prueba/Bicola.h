#include "Estructura.h"
#include <iostream>

#ifndef BICOLA_H
#define BICOLA_H

#define IZQ 'I'
#define DER 'D'

using std::cout;
using std::endl;

template<class T>
class Bicola {
  public:
    Bicola(){
      cab = fin = 0;
    }
    void push(T val, char sentido);
    void imprimirBicola();
    inline bool vacia(){ return cab == 0 && fin == 0 ; }
  private:
    nodo<T> *cab, *fin;
};


template<class T>
void Bicola<T>::push(T val, char ord) {
  struct nodo<T> *nuevo;
  nuevo->val = val;
  if ( vacia() ){
    cab = fin = nuevo->sig = nuevo->ant = nuevo;
  } else {
    nuevo->sig = cab;
    nuevo->ant = fin;
    cab->ant = nuevo;
    fin->sig = nuevo;
    if(ord == IZQ){
      // cab ... fin nuevo
      fin = nuevo;
    } else if (ord == DER){
      // nuevo cab ... fin
      cab = nuevo;
    }
  }
}

template<class T>
void Bicola<T>::imprimirBicola() {
  nodo<T> *aux = cab;
  cout << aux->val << " ";
  while( aux->sig != cab ){
    aux = aux->sig;
    cout << aux->val << " ";
  }
  cout << endl;
}

#endif /* ifndef BICOLA_h */
