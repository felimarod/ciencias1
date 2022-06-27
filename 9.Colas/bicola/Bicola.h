#ifndef BICOLA_H
#define BICOLA_H

#include "string.h"
#include <iostream>

using namespace std;

template <class T> struct nodo {
  T info;
  nodo *sig;
};

template <class T> class Bicola {
  nodo<T> *cab;
  int tam;

public:
  Bicola() {
    cab = NULL;
    tam = 0;
  }
  bool bicola_vacia();
  int tam_bicola();
  bool eliminar(char lado);
  //bool eliminar(T e);
  void insertar(T inf, char lado);
  string imprimir_bicola();
};


template <class T> bool Bicola<T>::bicola_vacia() {
	return tam == 0;
}


template <class T> int Bicola<T>::tam_bicola() {
	return tam;
}


template <class T> void Bicola<T>::insertar(T inf, char lado) {
  nodo<T> *p = new nodo<T>, *aux;
  p->info = inf;
  p->sig = NULL;
  if (cab == NULL)
    cab = p;
  else {
    if(lado == 'I'){
		aux = cab;
	    while (aux->sig != NULL)
	      aux = aux->sig;
	    aux->sig = p;
  	}else if(lado == 'D'){
  		p->sig = cab;
	    //cab->aux = p;
	    cab = p;
		  }
  }
  tam++;
}


template <class T> string Bicola<T>::imprimir_bicola() {
  std::string str = "[ ";
  nodo<T> *p = cab;
  if(tam_bicola() == 0){
  	str += " ]";
  }else if(tam_bicola() == 1){
  	str += to_string(p->info);
  	str += " ]";
  }else{
  do {
    str += to_string(p->info);
    str += ", ";
    p = p->sig;
  } while (p->sig != NULL);
  		str += to_string(p->info) + " ]";
  }
  return str;
}


template <class T> bool Bicola<T>::eliminar(char lado) {
  if (bicola_vacia())
    return false;
  nodo<T> *p = cab, *aux;
  if (lado == 'I') {
    cab = cab->sig;
    delete p;
  } else if(lado == 'D'){
  	for (int i = 1; i < tam - 1; i++)
      p = p->sig;
    aux = p->sig;
    p->sig = NULL;
    delete aux;
    }
  tam--;
  if(tam == 0){
  	cab = cab->sig;
  	delete p;
  }
  return true;
}
#endif
