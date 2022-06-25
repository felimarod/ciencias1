#include "PilaArr.h" // Trabajar con pilas utilizando arreglos
//#include "PilaNodo.h" // Trabajar con pilas utilizando la estructura nodo
#include <iostream>

using namespace std;

void pasaNotacionPolaca();
void realizarOperaciones();

int main() {
  cout << "((((4*2)+((6+3)*5))+((3*10)*(20+3)))*7)" << endl;
  //cout << "4 2 * 6 3 + 5 * + 3 10 * 20 3 + * + 7 *" << endl;
  //cout << "5201" << endl << endl;
  pasaNotacionPolaca();
  realizarOperaciones();
}

void pasaNotacionPolaca() {
  char c;
  Pila<int> guardar(50);
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

void realizarOperaciones() {
  char c;
  Pila<int> acc(50);
  int x; 
  while (cin.get(c) && c != '\n') {
    x = 0;
    while (c == ' ')
      cin.get(c);
    if( c >= '0' && c <= '9' )
      while (c >= '0' && c <= '9') {
        x = 10 * x + (c - '0');
        cin.get(c);
      }
    else if (c == '+')
      x = acc.sacar() + acc.sacar();
    else if (c == '*')
      x = acc.sacar() * acc.sacar();
    acc.meter(x);
  }
  cout << acc.sacar() << endl;
}
