#include <iostream>
#include <stdio.h>

using namespace std;

string arrayToString(int a[], int tam) {
  string aux = "";
  for (int i = 0; i < tam; i++) {
    if (i < tam - 1) {
      aux += to_string(a[i]);
      aux += ", ";
    } else {
      aux += to_string(a[i]);
    }
  }
  return aux;
}
void ordenrapido(int a[], int izq, int der) {
  int i, j, v, aux = 0;
  std::cout << arrayToString(a, 20) << std::endl;
  if (der > izq) {
    v = a[der];
    i = izq - 1;
    j = der;
    for (;;) {
      while (a[++i] < v)
        ;
      while (a[--j] > v)
        ;
      if (i >= j)
        break;
      aux = a[i];
      a[i] = a[j];
      a[j] = aux;
    }
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
    ordenrapido(a, izq, i - 1);
    ordenrapido(a, i + 1, der);
  }
}

void proceso(int N) {

  unsigned t0, t1;
  int a[N];
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
  }
  //std::cout << arrayToString(a, N) << std::endl;
  t0 = clock();

  ordenrapido(a, 0, N - 1);

  t1 = clock();
  //std::cout << arrayToString(a, N) << std::endl;

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
}

int main(int argc, char *argv[]) {
  int i;
  printf("N\tTiempo\n");
  proceso(20);
  //for (i = 50; i <= 1000; i = i + 50) {
    //proceso(i);
  //}
  return 0;
}
