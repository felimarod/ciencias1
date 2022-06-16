#include <cstdlib>
#include <iostream>

using namespace std;

char *tor[] = {"Rafael", "Leonardo", "Miguel", "Donatello", "Splinter"};
char **bp[] = {tor + 3, tor + 2, tor + 4, tor, tor + 1};
char ***ApFin = bp + 1;

void imprimirPosiciones(){
  cout << "\nImprimir Posiciones\n";
  cout << "***ApFin: " << ApFin << endl;
  for (int i = 0; i < 1; ++i)
    cout << ApFin[i] << "\t";
  cout << endl << endl;
  cout << "**bp: " << bp << endl;
  for (int i = 0; i < 5; ++i)
    cout << bp[i] << "\t";
  cout << endl << endl;
  cout << "*tor: " << tor << endl;
  for (int i = 0; i < 5; ++i)
    cout << tor[i] << "\t";
  cout << endl << endl;

  //cout << "*bp[0]:" << **bp << endl;
  //cout << "tor[0]:" << *tor << endl;
}

int main() {
  //imprimirPosiciones();

  //cout << tor[2] + 4 << endl;      // el
  cout << *(tor + 2) + 4 << endl;    // el

  //cout << ApFin << endl;
  //cout << *ApFin << endl;
  //cout << *ApFin - 1  << endl;
  //cout << *(*ApFin - 1)  << endl;
  //cout << (*ApFin)[-1] + 5 << endl; // rdo
  cout << *(*ApFin - 1) + 5  << endl; // rdo

  ++*ApFin;

  cout << **(bp + 1) + 5 << endl;    // ello
  cout << (*++*--ApFin + 3) << endl; // inter
  cout << *--ApFin[4] + 4 << endl;   // el

  //imprimirPosiciones();
  //system("PAUSE");
  return EXIT_SUCCESS;
}
