#include "iostream"

using namespace std;

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

void proceso(int N) {
  unsigned t0, t1;
  int a[N];
  for (int j = N; j > 0; j--) {
    a[j] = j;
  }

  t0 = clock();
  busquedaSecuencial(a, N);
  t1 = clock();

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
}

int main() {
  int i;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 500; i = i + 50) {
    proceso(i);
  }
  return 0;
}
