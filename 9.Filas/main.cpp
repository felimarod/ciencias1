#include "ListaCircular.h"
#include <iostream>

using std::cout;
using std::endl;
int main(int argc, char *argv[]) {
  ListaCO<int> lista;
  for(int i=20;i >=0; i--){
    lista.insertar(i);
    for(int i=1; i<=lista.tam_lista(); i++){
      std::cout << lista.obtener_elemento(i) << "\t";
    }
    cout << endl;
  }
    //lista.insertar(40);
    //lista.insertar(20);
    //lista.insertar(40);
  for(int i=1; i<=lista.tam_lista(); i++){
    std::cout << lista.obtener_elemento(i) << "\t";
  }
  return 0;
}
