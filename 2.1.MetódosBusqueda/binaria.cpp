#include "iostream"

using namespace std;

void busquedaBinaria(int A[], int n){
  int num = 30, primero, ultimo, medio;

  //cout << "Ingrese el numero que desea buscar: ";
  //cin >> num;

  primero = 0;
  ultimo = n - 1;
  medio = (primero + ultimo) / 2;
  while (primero <= ultimo) {
    if (A[medio] < num) {
      primero = medio + 1;
    } else if (A[medio] == num) {
      cout << "Se encontro la posición\n";
      cout << medio + 1;
      break;
    } else {
      ultimo = medio - 1;
    }
    medio = (primero + ultimo) / 2;
  }
  if (primero > ultimo) {
    cout << "No se encontro: "<< num << endl;
  }
}

void proceso(int N) {
  unsigned t0, t1;
  int a[N];
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
    printf("%d\n",j);
  }
  t0 = clock();
  busquedaBinaria(a, N);

  t1 = clock();

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
}

int main() {
  int i;
  cout << "N\tTiempo" << endl;
  for (i = 50; i <= 50; i = i + 50) {
    proceso(i);
  }
  return 0;
}
