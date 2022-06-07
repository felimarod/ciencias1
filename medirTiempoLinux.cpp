#include <iostream>
// Importar librería
#include "2.Ordenamiento Iterativo/ordenIterativo.cpp"
#include "3.Busqueda/busqueda.cpp"
#include "4.Ordenamiento Recursivo/ordenRecursivo.cpp"

using namespace std;

void imprimirArreglo(int a[], int n) {
  for (int i = 0; i < n; ++i)
    cout << a[i] << "\t";
  cout << endl;
}

int main() {
  int *a;
  unsigned t0, t1;
  double time;
  cout << "N\tTiempo(segundos)" << endl;
  for (int N = 50; N <= 500; N += 50) {
    a = new int[N];

    // Llenar arreglo para el peor caso
    for (int i = 0; i < N; i++)
      a[i] = N - (i + 1);

    t0 = clock(); // Toma el tiempo de inicio
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
    t1 = clock(); // Toma el tiempo de finalización

    time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << N << "\t" << time << endl;

    delete a;
  }
  return 0;
}
