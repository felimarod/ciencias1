#include <iostream>
// Importar librería
#include "2.Ordenamiento Iterativo/ordenIterativo.cpp"
#include "3.Busqueda/busqueda.cpp"
#include "4.Ordenamiento Recursivo/ordenRecursivo.cpp"
#include "5.P&NP/NP.cpp"
int N = 4;
int **a;
using namespace std;

// void imprimirArreglo() {
// for (int i = 0; i < N; ++i)
// for (int j = 0; j < N; ++j)

// cout << endl;
// }
void crearYLlenarArreglo() {
  a = new int *[N];
  for (int j = 0; j < N; j++) {
    a[j] = new int[N];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = 0;
    }
  }
}

int main() {
  unsigned t0, t1;
  double time;
  cout << "N\tTiempo(segundos)" << endl;
  for (; N <= 10; N++) {
    crearYLlenarArreglo();

    std::cout << "hola" << N << std::endl;

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
    /* Algoritmos para el análisis de problemas P y NP
     * solucionNReinas(a,N);
     */
    //NReinas(a, N);
    hanoi()
    t1 = clock(); // Toma el tiempo de finalización

    delete a;
    time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << N << "\t" << time << endl;
  }
  return 0;
}
