#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

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
  int a[N];
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
  }

  // Start measuring time
  struct timespec begin, end;
  clock_gettime(CLOCK_REALTIME, &begin);

  // seleccion(a, N);
  //  insercion(a, N);
  burbuja(a, N);

  // Stop measuring time and calculate the elapsed time
  clock_gettime(CLOCK_REALTIME, &end);
  long seconds = end.tv_sec - begin.tv_sec;
  long nanoseconds = end.tv_nsec - begin.tv_nsec;
  double elapsed = seconds + nanoseconds * 1e-9;

  cout << N << "\t" << elapsed << endl;
}

int main(int argc, char *argv[]) {
  int i;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 500; i = i + 50) {
    proceso(i);
  }
  return 0;
}
