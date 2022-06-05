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


void merge(int a[],int inicio, int mitad, int final){
    int i,j,k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    int izquierda[elementosIzq];
    int derecha[elementosDer];

    for(int i = 0; i < elementosIzq; i++){
        izquierda[i] = a[inicio+i];
    }
    for(int j = 0; j < elementosDer; j++){
        derecha[j] = a[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer){
        if(izquierda[i] <= derecha[j]){
            a[k] = izquierda[i];
            i++;
        }else{
            a[k] = derecha[j];
            j++;
        }
        k++;
    }

    while(j < elementosDer){
        a[k] = derecha[j];
        j++;
        k++;
    }

    while(i < elementosIzq){
        a[k] = izquierda[i];
        i++;
        k++;
    }

}

void mergeSort(int a[],int inicio, int final){
    if(inicio < final){
        int mitad = inicio + (final - inicio)/2;
        mergeSort(a,inicio,mitad);
        mergeSort(a,mitad+1,final);
        merge(a,inicio,mitad,final);
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
	//imprimirArreglo(a);

	mergeSort(a, 0, N-1);
	//imprimirArreglo(a);

  QueryPerformanceCounter(&t_fin);
  segundos = performancecounter_diff(&t_fin, &t_ini);
  
  printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main(){
	int i;
	printf("N\tTiempo\n");
	for (i = 50; i <= 1000; i = i + 50) {
		proceso(i);
	}
	return 0;

}
