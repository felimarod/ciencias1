#include "Cola.h"

#ifndef ARBOLBINORDARREGLO
#define ARBOLBINORDARREGLO

#include <iostream>

using std::cout;
using std::endl;

struct nodo {
  int clave;
  int izq, der;
};

class arBinOrdArreglo {
  nodo *arbol;
  int tam;

public:
  arBinOrdArreglo(int _tam = 13) {
    arbol = new nodo[_tam + 1];
    arbol[0].izq = 0;
    arbol[0].der = 1;
    for (int i = 0; i < _tam; i++) {
      arbol[i].izq = 0;
      arbol[i].der = i + 1;
    }
    arbol[_tam].izq = arbol[_tam].der = 0;
    tam = _tam;
  };
  void insertar(int dato);
  int buscarpadre(int dato, int posBus);
  void eliminar(int dato);
  int buscar_nodo(int dato, int p);
  int getraiz() { return arbol[0].izq; }
  void inorden(int inicio);
  void preorden(int inicio);
  void posorden(int inicio);
  bool Borrarnodo(int dato);
  void imprimirNodos();
  ~arBinOrdArreglo() { delete arbol; }
};

void arBinOrdArreglo::insertar(int dato) {
  int posPadre, posAct, posLibre;
  nodo auxN;
  if (arbol[0].der == 0)
    return;
  arbol[arbol[0].der].clave = dato;
  posLibre = arbol[0].der;
  if (arbol[0].izq == 0) {
    arbol[0].izq = posLibre; /* La raíz va a ser 1 */
  } else {
    posAct = arbol[0].izq; // Se obtiene la posición de la raíz
    while (posAct != 0) {
      posPadre = posAct;
      auxN = arbol[posAct];
      if (dato > auxN.clave)
        posAct = auxN.der;
      else if (dato < auxN.clave)
        posAct = auxN.izq;
    }
    if (dato > arbol[posPadre].clave)
      arbol[posPadre].der = posLibre;
    else if (dato < auxN.clave)
      arbol[posPadre].izq = posLibre;
  }
  arbol[0].der = arbol[posLibre].der; // Pone la nueva posición libre
  arbol[posLibre].der = 0;            // Quita la posición que estaba guardada
  // cout << "--------------------\n";
  // imprimirNodos();
}

void arBinOrdArreglo::imprimirNodos() {
  nodo nodoAct;
  for (int i = 0; i <= tam; i++) {
    nodoAct = arbol[i];
    cout << "Nodo " << i << ":  \t" << nodoAct.clave << "\t" << nodoAct.izq
         << "\t" << nodoAct.der << endl;
  }
}

int arBinOrdArreglo::buscarpadre(int dato, int posBus) {}
void arBinOrdArreglo::eliminar(int dato) {
  int posPadre, posAct, posAnt, posUltIzq, posUlt, auxHijo;
  int hijosNodo = 0; /* Se recorre el arreglo hasta llegar al nodo con el dato */
  posAct = arbol[0].izq; /* Se obtiene la posición de la raíz */
  while (arbol[posAct].clave != dato) {
    posPadre = posAct;
    if (dato > arbol[posAct].clave) posAct = arbol[posAct].der;
    else if (dato < arbol[posAct].clave) posAct = arbol[posAct].izq;
    if (posAct == 0) return;
  }
  if (arbol[posAct].izq != 0) hijosNodo++;
  if (arbol[posAct].der != 0) hijosNodo++;
  if (hijosNodo == 0) {
    if (dato > arbol[posPadre].clave)
      arbol[posPadre].der = 0;
    else if (dato < arbol[posPadre].clave)
      arbol[posPadre].izq = 0;
  } else if (hijosNodo == 1) {
    if (dato > arbol[posPadre].clave)
      arbol[posPadre].der =
          arbol[posAct].der != 0 ? arbol[posAct].der : arbol[posAct].izq;
    else if (dato < arbol[posPadre].clave)
      arbol[posPadre].izq =
          arbol[posAct].der != 0 ? arbol[posAct].der : arbol[posAct].izq;
  } else if (hijosNodo == 2) {
    auxHijo = arbol[arbol[0].izq].izq;
    posAnt = posPadre;
    posUltIzq = posAct;
    posUlt = arbol[posAct].der;
    while (posUlt != 0) {
      posAnt = posUltIzq;
      posUltIzq = posUlt;
      posUlt = arbol[posUlt].izq;
    }
    // cout << "Pos Padre " << posPadre<< endl;
    // cout << "Pos Actual " << posAct<< endl;
    // cout << "Pos Ant " << posAnt << endl;
    // cout << "Pos Ult izq " << posUltIzq<< endl;
    // cout << "Pos Ult " << posUlt<< endl;
    arbol[posAnt].izq = arbol[posUltIzq].der;
    /* Desconectar el padre de reemplazo del hijo de reemplazo */
    /* conectar hijo de reemplazo con el ancestro*/
    if (arbol[posPadre].der == posAct) arbol[posPadre].der = posUltIzq;
    else arbol[posPadre].izq = posUltIzq;

    /* Se copian los hijos del ancestro en el lugar del decendiente */
    arbol[posUltIzq].der = arbol[posAct].der;
    arbol[posUltIzq].izq = arbol[posAct].izq;
    if (dato == arbol[arbol[0].izq].clave) {
      arbol[0].izq = posUltIzq;
      arbol[posUltIzq].izq = auxHijo;
    }
  }
  arbol[posAct].clave = 0;          /* Borra clave que tenía */
  arbol[posAct].izq = 0;            /* Pone Posición Libre */
  arbol[posAct].der = arbol[0].der; /* Pone Posición Libre */
  arbol[0].der = posAct;            /* Agrega a posiciones libres */
}

int arBinOrdArreglo::buscar_nodo(int dato, int p) {
  int posPadre = 0;
  int posAux = p;
  while (arbol[posAux].clave != dato && posAux != 0) {
    posPadre = posAux;
    if (dato > arbol[posAux].clave)
      posAux = arbol[posAux].der;
    else 
      posAux = arbol[posAux].izq;
  }
  if(arbol[posAux].clave == dato) return posAux;
  else return 0;
}

void arBinOrdArreglo::preorden(int inicio) {
  bool visitados[tam];
  int posAux = inicio;
  int sigDer = 0;
  int posMaxDer = inicio;
  do{
    if(!visitados[posAux]) {
      cout << arbol[posAux].clave << "\t";
      visitados[posAux] = true;
    } else if(visitados[posAux]) {
      if(!visitados[arbol[posAux].izq])
        posAux = arbol[posAux].izq;
    }
    if(arbol[posAux].izq == 0 && arbol[posAux].der == 0)
      posAux = inicio;
  } while(sigDer != posMaxDer);
}

void arBinOrdArreglo::inorden(int inicio) {
  //listInorden->push(9);
  //if( listInorden->colaVacia()){
    //cout << "La cola esta vacia" <<endl;
  //} else 
    //cout << "La cola NO esta vacia" <<endl;

  //listInorden->push()
}

void arBinOrdArreglo::posorden(int inicio) {}

#endif /* ifndef ARBOLBINORDARREGLO */
