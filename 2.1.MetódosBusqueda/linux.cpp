#include "iostream"
#include <windows.h>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void busquedaSecuencial(int A[], int n){
  int num = n, posicion = 0;

  //cout << "Ingrese el numero que desea buscar: ";
  //cin >> num;

  while (posicion < n && A[posicion] != num) {
    posicion++;
  }
  //if(A[posicion] == num){
    //cout << "El número se encuentra en la posición: " << posicion << endl;
  //} else {
    //cout << "No se encontro el número " << num << " en el arreglo" << endl;
  //}
  
}

void busquedaBinaria(int A[], int n){
  int num = 0, primero, ultimo, medio;

  primero = 0;
  ultimo = n - 1;
  medio = (primero + ultimo) / 2;
  while (primero <= ultimo) {
    //cout << "primero: " << A[primero] << "\tultimo: "<< A[ultimo] << endl;
    if (A[medio] == num) {
      //cout << "Se encontro la posición\n";
      //cout << medio + 1;
      break;
    } else if (A[medio] < num) {
      primero = medio + 1;
    } else if (A[medio] > num) {
      ultimo = medio - 1;
    }
    medio = (primero + ultimo) / 2;
  }
  //if (primero > ultimo) {
    //cout << "No se encontro: "<< num << endl;
  //}
}

void proceso(int N) {
	LARGE_INTEGER t_ini, t_fin;
  double segundos;
  int a[N];
  for (int j = 1; j <= N; j++) {
    a[j - 1] = j;
  }

	QueryPerformanceCounter(&t_ini);
  //busquedaSecuencial(a, N);
  busquedaBinaria(a, N);
  t1 = clock();

  QueryPerformanceCounter(&t_fin);
  segundos = performancecounter_diff(&t_fin, &t_ini);
  
  printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main() {
  int i;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 500; i = i + 50) {
    proceso(i);
  }
  return 0;
}
