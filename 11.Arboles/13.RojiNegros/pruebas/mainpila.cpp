#include <iostream>
#include "PilaArr.h"

using std::cout;
using std::endl;

int main() {
  Pila<int> p;
  p.meter(1);
  p.meter(2);
  p.meter(3);
  p.meter(4);
  p.meter(5);
  p.meter(6);
  
  while(!p.vacia()){
    cout << p.sacar() << "\t";
  }
  cout << endl;
  if(p.vacia())
    cout << "la pila esta vacia";
  else
    cout << "la pila NO esta vacia";
  
  return 0;
}
