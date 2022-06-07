#include <iostream>
#include <stdio.h>

using namespace std;

void proceso(int N){
	
	int tamanio, espacio;
	int i, j, **a;

	tamanio = sizeof(N) + sizeof(i) + sizeof(j) + sizeof(a);
	espacio = 4;
	
	a = new int *[N];
	
	tamanio += sizeof(*a);
		
	for(i = 0; i < N; i++){	
		a[i] = new int [N];
		
		tamanio += sizeof(a[i]);
		espacio += 1;
		
		for(j=0;j<N;j++){
			a[i][j] = j*i;
			
			tamanio += sizeof(a[i][j]);
			espacio += 1;
		}
	}
	for(i = 0; i < N; i++)		
		delete a[i];
	delete []a;
	
	cout << N << "\t"<< espacio << "\t" << tamanio << endl;
}

int main(){
	int i;
	cout << "N\tEspacio\tTamanio"<< endl;
	for(i=50; i<=1000; i=i+50) {
		proceso(i);
	}
}
