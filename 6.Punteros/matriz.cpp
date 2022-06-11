#include <cstdlib>
#include <iostream>

using namespace std;

void LlenadoMatriz(int Q[][5]) {
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 5; j++) {
      Q[i][j] = 0;
    }
}

int main() {
  int M[4][5], *Pm, i, j;
  Pm = M[0];
  LlenadoMatriz(M);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      cout << *Pm << " ";
      Pm = Pm + 1;
    }
    cout << endl;
  }

  cout << endl;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 5; j++)
      M[i][j] = i * j;

  // Pm = M[0];
  // for (i = 0; i < 4; i++) {
  // for (j = 0; j < 5; j++) {
  // cout << *Pm << " ";
  // Pm = Pm + 1;
  //}
  // cout << endl;
  //}
  // cout << endl;

  for (int counter = 0; counter < 20; counter++) {
    if (counter % 5 == 0)
      cout << endl;
    cout << *(*M + counter) << " ";
  }

  // system("PAUSE");
  return EXIT_SUCCESS;
}
