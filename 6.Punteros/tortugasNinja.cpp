#include <cstdlib>
#include <iostream>

using namespace std;

char *tor[] = {"Rafael", "Leonardo", "Miguel", "Donatello", "Splinter"};
char **bp[] = {tor + 3, tor + 2, tor + 4, tor, tor + 1};
char ***ApFin = bp + 1;

int main() {
  cout << *(tor + 2) + 4 << endl;
  cout << *(*ApFin - 1) + 5 << endl;
  ++*ApFin;
  cout << **(bp + 1) + 5 << endl;
  cout << (*++*--ApFin + 3) << endl;
  cout << *--ApFin[4] + 4 << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}
