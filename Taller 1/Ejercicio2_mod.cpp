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
	
	int i, j, **a;// **a = int [N][N];

	tamanio += sizeof(i) + sizeof(j) + sizeof(**a);
	
	//imprimirTamanio("a",a);
	
	
	a = new int *[N];
	//imprimirTamanio("a*",*a);
	tamanio += sizeof(*a);
	//imprimirTamanio("a**",**a);
	
	
	for(i = 0; i < N; i++){
			
		a[i] = new int [N];
		tamanio +=sizeof(a[i]);
		//imprimirTamanio("a**", a[i]);
		
		for(j=0;j<N;j++){
			a[i][j] = j*i;
			tamanio += sizeof(a[i][j]);
		}
			
	}
	for(i = 0; i < N; i++){
		//for(j=0;j<N;j++){
			//cout << "Tamaño de a[" << i << "][" << j << "]" << sizeof(a[i][j]) << endl;
			//	cout << a[i][j];
		//}
		
		
		delete a[i];
	}
	delete []a;
	
	cout << "Si N = " << N << ", el tamanio es: " << tamanio << endl;
	
}

int main(){
	int i;
	for(i=0; i<=1000; i=i+50) {
		proceso(i);
	}
}
