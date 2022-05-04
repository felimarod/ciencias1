#include <iostream>
#include <stdio.h>

using namespace std;

void imprimirTamanio(string nombre, int a){
	cout << "Tamanio de " << nombre <<" : " << sizeof(a) << endl;
}
void imprimirTamanio(string nombre, int* a){
	cout << "Tamanio de " << nombre <<" : " << sizeof(a) << endl;
}
void imprimirTamanio(string nombre, int** a){
	cout << "Tamanio de " << nombre <<" : " << sizeof(a) << endl;
}

void proceso(int N){
	
	int tamanio = 0;
	
	int i, j, **a;

	tamanio += sizeof(i) + sizeof(j) + sizeof(**a);
	
	
	a = new int *[N];
	imprimirTamanio("a**", **a);
	
	for(i = 0; i < N; i++){
		a[i] = new int [N];
		//imprimirTamanio("a**", a[i]);
		for(j=0;j<N;j++)
			a[i][j] = j*i;
	}
	for(i = 0; i < N; i++){
		//for(j=0;j<N;j++)
		//	cout << a[i][j];
		delete a[i];
	}
	delete []a;
	
	cout << "Si N = " << N << ", el tamanio es: " << tamanio << endl;
	
}

int main(){
	proceso(50);	
}
