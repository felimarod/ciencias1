#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


void ordenrapido(int a[], int izq, int der){
	int i, j, v, aux;
	if(der> izq){
		v= a[der]; i = izq -1; j= der;
		for(;;){
			while (a[++i]<v);
	 			while (a[--j] >v);
	 				if(i>=j) break;
	 		aux = a[i];
	    	a[i] = a[j];
	    	a[j] = aux;
		}
	 	aux = a[i];
    a[i] = a[der];
    a[der] = aux;
	 	ordenrapido(a, izq, i-1);
	 	ordenrapido(a, i+1,der);
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
	
  ordenrapido(a, 0, N-1);
  
  QueryPerformanceCounter(&t_fin);
  segundos = performancecounter_diff(&t_fin, &t_ini);
  
  printf("%d\t%.16g\n", N, segundos * 1000.0);
}


int main(int argc, char *argv[]) {
  int i;
  printf("N\tTiempo\n");
  for (i = 50; i <= 1000; i = i + 50) {
    proceso(i);
  }
  return 0;
}
