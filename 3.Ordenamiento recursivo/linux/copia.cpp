#include <iostream>
#include <string.h>

int const MAX=1000;
int N = 1000;
int *A, **C;

using namespace std;

string arrayToString(int[], int);
void radixSort(int);
void proceso();
//void imprimir();

int main() {
  proceso();
   //for (; N <= 1000; N+=50) 
     //proceso();

	for(int i = 0; i < N; i++)
		delete C[i];
	delete []C;

  return 0;
}
//void imprimir() {
  //std::cout << "Imprimiendo lista" << std::endl;
  //for (int i = 0; i < MAX; ++i) {
    //std::cout << A[i] << "\t";
  //}
  //cout << endl;
//}
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

void proceso() {
  unsigned t0, t1;
  A = new int[N];
  C = new int *[MAX];

  for (int i = 0; i < MAX; i++) {
    C[i] = new int[10];
  }

  for (int j = N; j > 0; j--) {
    A[N - j] = j;
  }
   std::cout << arrayToString(A, N) << std::endl;
  //imprimir();
  t0 = clock();
  radixSort(10);

  t1 = clock();
   std::cout << arrayToString(A, N) << std::endl;
  //imprimir();

  delete []A;
  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
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
