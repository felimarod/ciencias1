#include "Cola.h"

#ifndef ARBOLBINORDARREGLO
#define ARBOLBINORDARREGLO 

struct nodo {
  int clave;
  int izq, der;
};

class arbinordArreglo {
  nodo *arbol;
  Cola<int> *listInorden, *listPreorden, *listPosorden;

public:
  arbinordArreglo(int tam) {
    arbol = new nodo[tam];
    for (int i = 0; i < tam; ++i) {
      arbol[i].izq = arbol[i].der = NULL;
    }
  };
  void insertar(int dato);
  int buscarpadre(int dato, int posBus);
  void eliminar(int dato);
  int buscar_nodo(int dato, int *p);
  int getraiz() { return arbol[0].izq; }
  void inorden(int inicio);
  void preorden(int inicio);
  void posorden(int inicio);
  bool Borrarnodo(int dato);
  ~arbinordArreglo() { delete arbol; }
};

#endif /* ifndef ARBOLBINORDARREGLO */
