#include <iostream>

using std::cout;
using std::endl;

#ifndef COLASDEPRIORIDAD
#define COLASDEPRIORIDAD

struct nodo {
  int clave;
};

class monticulo {
  nodo *colas;
  int *Arr, tam;

public:
  monticulo(int _tam) {
    colas = new nodo[_tam + 1];
    colas[0].clave = 1;
    for (int i = 1; i < _tam; i++) {
      colas[i].clave = 0;
    }
    tam = _tam;
  };
  ~monticulo() { delete colas; }
  void insertar(int dato);
  int atender();
  void imprimirArreglo();
  bool monticulo_lleno();
};

void monticulo::insertar(int dato) {
  int auxPos = colas[0].clave;
  if (auxPos == 1) {
    colas[auxPos].clave = dato;
    colas[0].clave++;
  } else if (auxPos != 0) {
    while (dato > colas[auxPos / 2].clave && auxPos / 2 != 0) {
      colas[auxPos].clave = colas[auxPos / 2].clave;
      auxPos /= 2;
    }
    colas[auxPos].clave = dato;
    colas[0].clave = colas[0].clave == tam ? 0 : colas[0].clave + 1;
  }
}
int monticulo::atender() {
  int va; // Valor atendido
  int uv; // Ultimo valor
  int auxPos = 1;
  if (colas[1].clave == 0)
    return 0;
  else {
    va = colas[1].clave; // Guarda el valor a retornar
    colas[1].clave = 0; // Vuelve 0 el valor de la raíz
    if (colas[0].clave == 0) colas[0].clave = tam;
    else colas[0].clave--;
    uv = colas[colas[0].clave].clave; // Guarda el último valor
    colas[colas[0].clave].clave = 0; // Vuelve 0 el último valor
    do {
      if (uv < colas[auxPos * 2].clave) {
        colas[auxPos].clave = colas[auxPos * 2].clave;
        auxPos = auxPos * 2;
        colas[auxPos].clave = 0;
      } else if (uv < colas[auxPos * 2 + 1].clave) {
        colas[auxPos].clave = colas[auxPos * 2 + 1].clave;
        auxPos = auxPos * 2 + 1;
        colas[auxPos].clave = 0;
      }
    } while (auxPos * 2 + 1 <= tam && (uv < colas[auxPos * 2].clave ||
                                       uv < colas[auxPos * 2 + 1].clave));
    cout << endl;
    colas[auxPos].clave = uv;
    return va;
  }
}

void monticulo::imprimirArreglo() {
  for (int i = 0; i <= tam; i++)
    cout << "Posicion " << i << ":  \t" << colas[i].clave << endl;
}

bool monticulo::monticulo_lleno() { return colas[tam].clave != 0; }
#endif /* ifndef COLASDEPRIORIDAD */
