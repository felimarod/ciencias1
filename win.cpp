#include <iostream>
#include <windows.h>

#include "2.Ordenamiento Iterativo/ordenIterativo.cpp"
#include "3.Busqueda/busqueda.cpp"
#include "4.Ordenamiento Recursivo/ordenRecursivo.cpp"

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
//double suma; for (i = 50; i <= 500; i = i + 50) { suma = 0; Diferentes procesos... cout << i << "\t" << suma / double(10) << endl; }
int main() {
  int *a;
  LARGE_INTEGER t_ini, t_fin;

  cout << "N\tTiempo(milisegundos)" << endl;
  for (int N = 50; N <= 500; N += 50) {
    a = new int[N];

    // Llenar arreglo para el peor caso
    for (int i = 0; i < N; i++)
      a[i] = N - (i + 1);

    QueryPerformanceCounter(&t_ini);

    /* Algoritmos de ordenamiento iterativos
     *  burbuja(a, N);
     *  insercion(a, N);
     *  seleccion(a, N);
     */
    /* Algoritmos de busqueda
     *  busquedaBinaria(a, N);
     *  busquedaSecuencial(a, N);
     */
    /* Algoritmos de ordenamiento recursivos
     * cambioResiduos(a, 0, N - 1, 4);
     * mergeSort(a, 0, N - 1);
     * quickSort(a, 0, N - 1)
     * radixSort(a, N, 10);
     */
    QueryPerformanceCounter(&t_fin);

    cout << N << "\t" << performancecounter_diff(&t_fin, &t_ini) << endl;

    delete a;
  }
  return 0;
}
