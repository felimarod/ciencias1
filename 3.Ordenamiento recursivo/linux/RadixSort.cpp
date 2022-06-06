#include <iostream>
#include <string.h>
#include <windows.h>

int N = 50;
int *A, **C;

using namespace std;


/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


void radixSort(int);
void proceso();
//void imprimir();

int main() {

	printf("N\tTiempo\n");
	for (; N <= 1000; N += 50) {
		proceso();
	}
	for(int i = 0; i < N; i++)
		delete C[i];
	delete []C;

  return 0;
}

//void imprimir() {
//	std::cout << "Imprimiendo lista" << std::endl;
//  for (int i = 0; i < N; ++i) {
//   std::cout << A[i] << "\t";
//  }
//  cout << endl;
//}


void proceso() {
	LARGE_INTEGER t_ini, t_fin;
  double segundos;
	
  unsigned t0, t1;
  A = new int[N];
  C = new int *[N];

  for (int i = 0; i < N; i++) {
    C[i] = new int[10];
  }

  for (int j = 0; j < N; j++) {
    A[j] = N-(j+1);
  }
  	QueryPerformanceCounter(&t_ini);
	
	radixSort(10);

  	QueryPerformanceCounter(&t_fin);
  segundos = performancecounter_diff(&t_fin, &t_ini);
 
   printf("%d\t%.16g\n", N, segundos * 1000.0);

}

void radixSort(int r) {
  int i, j, x, d, flag = 0, p = -1;
  d = r / 10;
  for (i = 0; i < N; ++i) {
    for (j = 0; j < 10; j++) {
      C[i][j] = -1;
    }
  }
  for (i = 0; i < N; ++i) {
    x = A[i] % r;
    int m = x / d;
    if (m > 0)
      flag = 1;
    C[i][m] = A[i];
  }
  for (j = 0; j < 10; j++) {
    for (i = 0; i < N; i++) {
      if (C[i][j] != -1) {
        p++;
        A[p] = C[i][j];
      }
    }
  }
  if (flag == 1) {
    radixSort(r * 10);
  }
}

