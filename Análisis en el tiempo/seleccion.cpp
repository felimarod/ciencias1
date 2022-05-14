#include <ctime>
#include <iostream>

using namespace std;

unsigned t0, t1;

void intercambio(int a[], int pos1, int pos2) {

}

void seleccion(int a[], int N) {
  int i, j, min;
  for (i = 1; i < N; i++) {
    min = i;
    for (j = i + 1; j <= N; j++)
      if (a[j] < a[min])
        min = j;
    intercambio(a, min, j);
  }
}

int main(int argc, char *argv[]) { 
  t0=clock();
  // Code to execute
  t1 = clock();
   
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
  return 0; 
}
