#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

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
	LARGE_INTEGER t_ini, t_fin;
  double segundos;
  int a[N];
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
  }

	QueryPerformanceCounter(&t_ini);
  burbuja(a, N);
  QueryPerformanceCounter(&t_fin);

  segundos = performancecounter_diff(&t_fin, &t_ini);
  
  printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main(int argc, char *argv[]) {
  int i;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 500; i = i + 50) {
    proceso(i);
  }
  return 0;
}
