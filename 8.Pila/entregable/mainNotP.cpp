#include <iostream>
#include "Pila.h" // Trabajar con pilas utilizando arreglos

using std::cin;
using std::cout;
using std::endl;

int main() {
  char c;
  Pila<int> guardar(50);

  cout << "Ejercicio trabajado en clase:\n((((4*2)+((6+3)*5))+((3*10)*(20+3)))*7)" << endl;
  while (cin.get(c) && c != '\n') {
    while (c >= '0' && c <= '9') {
      cout.put(c);
      cin.get(c);
    }
    if (c != '(') cout << ' ';
    if (c == ')') cout.put(guardar.sacar());
    if (c == '+') guardar.meter(c);
    if (c == '*') guardar.meter(c);
  }
  cout << endl;
}
