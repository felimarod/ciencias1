#include <iostream>
#include <stdio.h>
#include <string>

int const N = 50;
int *a, **c;

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

void radixSort(int r){
    int i,j,x,d,flag=0,p=-1;
    d=r/10;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < 10; j++) {
            c[i][j] = -1;
        }
    }
    for (i = 0; i < N; ++i) {
        x=a[i]%r;
        int m=x/d;
        if(m>0) flag =1;
        c[i][m] = a[i];
    }
    for (j = 0; j < 10; j++) {
        for (i = 0; i < N; i++) {
            if (c[i][j] != -1) {
               p++;
               a[p]=c[i][j];
            }
        }
    }
    if(flag==1){
        radixSort(r*10);
    }
}

void proceso() {
  a = new int[N];
  c = c[N][10]

  unsigned t0, t1;
  
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
  }
  // std::cout << arrayToString(a, N) << std::endl;
  t0 = clock();
  radixSort(1);

  t1 = clock();
  // std::cout << arrayToString(a, N) << std::endl;

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
  // printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main(int argc, char *argv[]) {
  printf("N\tTiempo\n");
  proceso();
  //for (; N <= 1000; N+=50) {
   //proceso();
  //}
  return 0;
}
