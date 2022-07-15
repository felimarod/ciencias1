#include <iostream>

using std::cout;
using std::endl;

#ifndef COLASDEPRIORIDAD
#define COLASDEPRIORIDAD

class monticulo {
  int *Arr, tam, PosAct;

public:
  monticulo(int _tam) {
    Arr= new int[_tam + 1];
    PosAct = 1;
    for (int i = 0; i < _tam; i++) {
      Arr[i] = 0;
    }
    tam = _tam;
  };
  ~monticulo() { delete Arr; }
  bool insertar(int);
  int atender();
  void imprimirArreglo();
  bool monticulo_lleno();
};

bool monticulo::insertar(int dato) {
  int auxPos = PosAct;
  if(monticulo_lleno())
    return false;
  else if (auxPos == 1) {
    Arr[PosAct++] = dato;
  } else {
    while (dato > Arr[auxPos / 2] && auxPos / 2 != 0) {
      Arr[auxPos] = Arr[auxPos / 2];
      auxPos /= 2;
    }
    Arr[auxPos] = dato;
    PosAct = PosAct == tam ? 0 : PosAct + 1;
  }
  return true;
}
int monticulo::atender() {
  int va; // Valor atendido
  int uv; // Ultimo valor
  int auxPos = 1;
  if (Arr[1] == 0)
    return 0;
  else {
    va = Arr[1]; // Guarda el valor a retornar
    Arr[1] = 0; // Vuelve 0 el valor de la raíz
    if (PosAct == 0) PosAct = tam;
    else PosAct--;
    uv = Arr[PosAct]; // Guarda el último valor
    Arr[PosAct] = 0; // Vuelve 0 el último valor
    do {
      if (uv < Arr[auxPos * 2]) {
        Arr[auxPos] = Arr[auxPos * 2];
        auxPos = auxPos * 2;
        Arr[auxPos] = 0;
      } else if (uv < Arr[auxPos * 2 + 1]) {
        Arr[auxPos] = Arr[auxPos * 2 + 1];
        auxPos = auxPos * 2 + 1;
        Arr[auxPos] = 0;
      }
    } while (auxPos * 2 + 1 <= tam && (uv < Arr[auxPos * 2] ||
                                       uv < Arr[auxPos * 2 + 1]));
    cout << endl;
    Arr[auxPos] = uv;
    return va;
  }
}

void monticulo::imprimirArreglo() {
  for (int i = 1; i <= tam; i++)
    cout << "Posicion " << i << ":  \t" << Arr[i] << endl;
}

bool monticulo::monticulo_lleno() { return PosAct == 0; }
#endif /* ifndef COLASDEPRIORIDAD */
