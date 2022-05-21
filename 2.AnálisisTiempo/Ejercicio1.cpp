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

void seleccion(int a[], int N) {
  int i, j, min;
  int aux;
  for (i = 0; i < N; i++) {
    min = i;
    for (j = i + 1; j < N; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    aux = a[i];
    a[i] = a[min];
    a[min] = aux;
  }
}

void insercion(int a[], int N) {
  int i, j;
  int v;
  for (i = 1; i < N; i++) {
    j = i;
    v = a[j];
    while (a[j - 1] > v && j > 0) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
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
	
  // seleccion(a, N);
  //  insercion(a, N);
  burbuja(a, N);

  QueryPerformanceCounter(&t_fin);
  segundos = performancecounter_diff(&t_fin, &t_ini);
  
  printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main(int argc, char *argv[]) {
  int i;
  printf("N\tTiempo\n");
  for (i = 50; i <= 500; i = i + 50) {
    proceso(i);
  }
  return 0;
}
