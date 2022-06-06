#include "iostream"

using namespace std;

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

double proceso(int N) {
  unsigned t0, t1;
  int a[N];
  for (int j = 1; j <= N; j++) {
    a[j - 1] = j;
  }

  t0 = clock();
  busquedaBinaria(a, N);
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
