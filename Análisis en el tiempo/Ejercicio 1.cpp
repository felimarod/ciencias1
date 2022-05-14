#include <ctime>
#include <iostream>

using namespace std;

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
void insercion(int a[], int N){
  int i,j;
  int v;
  for (i=1; i<N; i++) {
    j=i;
    v=a[j];
    while(a[j-1]>v && j>0) {
      a[j]=a[j-1];
      j--;
    }
    a[j]= v;
  }
}

void burbuja(int a[], int N){
  int i,j;
  for (i=N; i>=1; i--)
    for(j=2; j<=i; j++)
      if(a[j-1]> a[j]) 
        intercambio(a,j-1,j);
}



int main(int argc, char *argv[]) { 
  unsigned t0, t1;
  int N = 100;
  int a[N];
  
  for(int j=N; j>0; j--){
  	a[N-j] = j;
  	cout<<a[N-j]<<endl;
  }
  cout<<endl;
  t0=clock();
  // Code to execute
  insercion(a, N);
  
  for(int j=0; j<N; j++){
  	cout<<a[j]<<endl;
  }
  t1 = clock();
  
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
  return 0; 
}
