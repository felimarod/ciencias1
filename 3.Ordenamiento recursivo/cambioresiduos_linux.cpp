#include <iostream>
#include <stdio.h>
#include <string>
//#include <conio.h>
//#include <Windows.h>

using namespace std;

unsigned bits(int x, int k, int j) { return (x >> k) & ~(~0 << j); }

string arrayToString(int a[], int tam){
  string aux = "";
  for(int i = 0; i < tam; i++){
    if( i < tam-1 ){
      aux +=to_string(a[i]);
      aux += ", ";
    } else {
      aux +=to_string(a[i]);
    }
  }
  return aux;
}

void cambioresiduos(int a[], int izq, int der, int b) {
  int i, j, aux;
  if (der > izq && b > 0) {
    //std::cout << arrayToString(a, 20) << std::endl;
    i = izq;
    j = der;
    while (j != i) {
      while (!bits(a[i], b, 1) && i < j)
        i++;
      while (bits(a[j], b, 1) && j > i)
        j--;
      aux = a[i];
      a[i] = a[j];
      a[j] = aux;
    }
    if (!bits(a[i], b, 1))
      j++;
    cambioresiduos(a, izq, j - 1, b - 1);
    cambioresiduos(a, j, der, b - 1);
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

  cambioresiduos(a, 0, N - 1, 4);

  t1 = clock();
  //std::cout << arrayToString(a, N) << std::endl;

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
  // printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main(int argc, char *argv[]) {
  int i;
  printf("N\tTiempo\n");
  proceso(20);
  // for (i = 50; i <= 1000; i = i + 50) {
  // proceso(i);
  //}
  return 0;
}
