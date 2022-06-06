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

double proceso(int N) {
  unsigned t0, t1;
  int a[N];
  for (int j = 1; j <= N; j++) {
    a[j - 1] = j;
  }

  t0 = clock();
  busquedaSecuencial(a, N);
  t1 = clock();

  return (double(t1 - t0) / CLOCKS_PER_SEC);
}

int main() {
  int i;
  double suma;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 500; i = i + 50) {
    suma = 0;
    for (int j = 0; j < 10; j++){
      suma += proceso(i);
    }
    cout << i << "\t" << suma/double(10) << endl;
  }
  return 0;
}
