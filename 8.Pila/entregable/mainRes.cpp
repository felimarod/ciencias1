#include <iostream>
#include "Pila.h" // Trabajar con pilas utilizando arreglos

using std::cin; using std::cout;

int main() {
  char c;
  Pila<int> acc(50);
  int x; 

  cout << "Conversión de ejercicio trabajado en clase:\n4 2 * 6 3 + 5 * + 3 10 * 20 3 + * + 7 *\n";

  while (cin.get(c) && c != '\n') {
    x = 0;
    while (c == ' ') cin.get(c);
    if( c >= '0' && c <= '9' )
      while (c >= '0' && c <= '9') {
        x = 10 * x + (c - '0');
        cin.get(c);
      }
    else if (c == '+') x = acc.sacar() + acc.sacar();
    else if (c == '*') x = acc.sacar() * acc.sacar();
    acc.meter(x);
  }

  cout << acc.sacar() << "\n";
  return 0;
}
