#include "Cola.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  // 3 8 5 20 atiende atiende atiende 70 50 atiende
  // atiende 15 23 80 43 92 71 56
  Cola<int> cola;
  cola.push(3);
  cola.push(8);
  cola.push(20);
  cout << "Sale: " << cola.pop() << endl;
  cout << "Sale: " << cola.pop() << endl;
  cout << "Sale: " << cola.pop() << endl;
  cola.push(70);
  cola.push(50);
  cout << "Sale: " << cola.pop() << endl;
  cout << "Sale: " << cola.pop() << endl;
  cola.push(15);
  cola.push(23);
  cola.push(80);
  cola.push(43);
  cola.push(92);
  cola.push(71);
  cola.push(56);

  cola.imprimirCola();

  cola.~Cola();
  return 0;
}
