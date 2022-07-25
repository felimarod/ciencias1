#include <iostream>
#include "Cola.h"

using std::cout;
using std::endl;

int main() {
  Cola<int> c;
  c.push(1);
  c.push(2);
  c.push(3);
  c.push(4);
  c.push(5);
  c.push(6);
  
  while(!c.colaVacia()){
    cout << c.pop() << "\t";
  }
  cout << endl;
  if(c.colaVacia())
    cout << "la COLA esta vacia";
  else
    cout << "la COLA NO esta vacia";
  
  return 0;
}
