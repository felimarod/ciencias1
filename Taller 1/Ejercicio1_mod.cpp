#include <iostream>
#include <stdio.h>

using namespace std;

void imprimirTamanio(string nombre, int a){
	cout << "Tamanio de " << nombre <<" : " << sizeof(a) << endl;
}
void imprimirTamanio(string nombre, int* a){
	cout << "Tamanio de " << nombre <<" : " << sizeof(a) << endl;
}

void proceso(int N){
	bool aSumado = false;
	int tamanio = 0;
	
	int i, j, *a;
	
	tamanio += sizeof(N) + sizeof(i) + sizeof(j) + sizeof(a);
	//imprimirTamanio("N", N);
	//imprimirTamanio("i", i);
	//imprimirTamanio("j", j);
	
	
	for(i=0;i<N;i++){
		a = new int [N];
		//if(!aSumado)
			//imprimirTamanio("a", a);
		for(j=0;j<N;j++){	
			a[j] = j*i;
			
			if(!aSumado){
				//imprimirTamanio("Elemento dentro de a", a[j]);
				tamanio+=sizeof(a[j]);
			}
			//cout << a[j] << endl;
			if(j==N-1){
				aSumado = true;	
			}
		}
		delete []a;
	}
	
	cout << "Si N = " << N << ", el tamanio es: " << tamanio << endl;
}
int main(){
	int i;
	for(i=0; i<=1000; i=i+50) {
		proceso(i);
	}
}
