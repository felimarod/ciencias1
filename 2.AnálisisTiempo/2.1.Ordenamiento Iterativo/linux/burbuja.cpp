#include <ctime>
#include <iostream>

using namespace std;

void burbuja(int a[], int N) {
  int i, j;
  int aux;
  for (i = N - 1; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      if (a[j - 1] > a[j]) {
        aux = a[j];
        a[j] = a[j - 1];
        a[j - 1] = aux;
      }
    }
  }
}

void proceso(int N) {
  unsigned t0, t1;
  int a[N];
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
  }
  t0 = clock(); // Toma el tiempo de inicio
  burbuja(a, N)
  t1 = clock(); // Toma el tiempo de finalización

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
}

int main(int argc, char *argv[]) {
  int i;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 500; i = i + 50) {
    proceso(i);
  }
  return 0;
}
