#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int N, i, j, *a;
	
	cout << "ANTES" << endl;
	cout << "Tamaño de N: " << sizeof(N) << endl;
	cout << "Tamaño de N: " << sizeof(i) << endl;
	cout << "Tamaño de N: " << sizeof(j) << endl;
	cout << "Tamaño de N: " << sizeof(a) << endl;
	
	cout << "Ingrese el valor de N: ";cin >> N;
	
	for(i=0;i<N;i++){
		cout << "Nuevo a" << endl;
		a = new int [N];
		for(j=0;j<N;j++){	
			a[j] = j*i;
			cout << "Tamaño de a[" << j <<"]: " << sizeof(a) << endl;
			cout << a[j] << endl;	
		}
		cout << "Tamaño de N: " << sizeof(a) << endl;
		cout << "Elimina a" << endl;
		delete []a;
	}
	
	cout << "DESPUES" << endl;
	cout << "Tamaño de N: " << sizeof(N) << endl;
	cout << "Tamaño de N: " << sizeof(i) << endl;
	cout << "Tamaño de N: " << sizeof(j) << endl;
	cout << "Tamaño de N: " << sizeof(a) << endl;
	
}
