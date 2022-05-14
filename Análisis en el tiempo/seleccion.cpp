#include <ctime>
#include <iostream>

unsigned t0, t1;

void intercambio(int a[], int pos1, int pos2) {

}

void seleccion(int a[], int N) {
  int i, j, min;
  for (i = 1; i < N; i++) {
    min = i;
    for (j = i + 1; j <= N; j++)
      if (a[j] < a[min])
        min = j;
    intercambio(a, min, j);
  }
}

int main(int argc, char *argv[]) { 
  return 0; 
}
