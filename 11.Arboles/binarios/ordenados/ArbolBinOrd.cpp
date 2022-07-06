#ifndef ARBOLBINORD
#define ARBOLBINORD

#include "Cola.h"

struct nodo {
  int clave;
  nodo *izq, *der;
};

class arbolBinOrd {
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

void arbolBinOrd::insertar(int dato) {
  nodo *nPadre = NULL;
  nodo *nAct = raiz;

  nodo *newN;
  newN->clave = dato;
  newN->izq = newN->der = NULL;

  if(raiz == NULL) {
    raiz = newN;
    return;
  }

  while(nAct != NULL){
    nPadre = nAct;
    if(dato > nAct->clave){
      nAct = nAct->der;
    } else if (dato < nAct->clave){
      nAct= nAct->izq;
    }
  }
  if(dato > nPadre->clave){
    nPadre->der = newN;
  } else if (dato < nPadre->clave){
    nPadre->izq = newN;
  }
}
nodo arbolBinOrd::*buscarpadre(int dato, nodo *p) {}
void arbolBinOrd::eliminar(int dato) {}
nodo arbolBinOrd::*buscar_nodo(int dato, nodo **padre) {}
void arbolBinOrd::inorden(nodo *inicio) {}
void arbolBinOrd::preorden(nodo *inicio) {}
void arbolBinOrd::posorden(nodo *inicio) {}

#endif /* ifndef ARBOLBINORD */
