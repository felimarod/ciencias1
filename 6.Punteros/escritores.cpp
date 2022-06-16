#include <cstdlib>
#include <iostream>

using namespace std;

char *Esc[] = {"Pablo Neruda", "Juan Rulfo", "Ernesto Sábato", "Alfonsina Storni"};
char **ApEsc[] = {Esc + 1, Esc, Esc + 3, Esc + 2};
char ***apfin = ApEsc + 1;

int main() {
  cout << (**(ApEsc + 2) + 3) << endl;
  cout << (*(*ApEsc + 1) + 8) << endl;
  cout << (*--*(ApEsc) + 4) << endl;
  cout << (*++apfin[-1] + 6) << endl;
  cout << (*--*++apfin + 2) << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}
