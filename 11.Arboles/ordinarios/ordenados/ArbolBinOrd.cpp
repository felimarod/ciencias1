#ifndef ARBOLBINORD
#define ARBOLBINORD 

#include "estructura.h"
#include "Cola.h"


class arbolBinOrd {
private:
struct nodo {
  int clave;
  nodo *izq, *der;
};
  nodo *raiz;
  Cola<int> *listInorden, *listPreorden, *listPosorden;

public:
  arbolBinOrd() {
    raiz = NULL;
    listInorden = new Cola<int>;
    listPreorden = new Cola<int>;
    listPosorden = new Cola<int>;
  }
  void insertar(int dato);
  nodo *buscarpadre(int dato, nodo *p);
  void eliminar(int dato);
  nodo *buscar_nodo(int dato, nodo **padre);
  void inorden(nodo *inicio);
  void preorden(nodo *inicio);
  void posorden(nodo *inicio);
};
void arbolBinOrd::insertar(int dato){
  if(raiz == NULL){
    raiz = new nodo;
    raiz->clave = dato;
  }

}

#endif /* ifndef ARBOLBINORD */
