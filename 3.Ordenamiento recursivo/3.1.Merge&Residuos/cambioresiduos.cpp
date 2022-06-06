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


unsigned bits (int x, int k, int j){
	return (x>>k)&~(~0<<j);
}

void cambioresiduos(int a[], int izq, int der, int b){
	int i,j,aux;
	if (der>izq && b>0){
	   	i= izq; j=der;
	    while(j!=i){
			while(!bits(a[i],b,1) && i<j)i++;
	        	while(bits(a[j],b,1) && j>i)j--;
	           		aux = a[i];
	    			a[i] = a[j];
	    			a[j] = aux;
	    }
	    if (!bits(a[i],b,1)) j++;
	    cambioresiduos(a, izq, j-1, b-1);
	    cambioresiduos(a, j, der, b-1);
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
	
  cambioresiduos(a, 0, N-1, 4);
  
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
