#include <iostream>
#include <stdio.h>

using namespace std;

void proceso(int N){
	bool aSumadoArray = false;
	int tamanio, espacioReservado;
	
	int i, j, *a;
	
	tamanio = sizeof(N) + sizeof(i) + sizeof(j) + sizeof(a);
	espacioReservado = 4;
		
	for(i=0;i<N;i++){
		a = new int [N];
		
		for(j=0;j<N;j++){	
			a[j] = j*i;		
			if(!aSumadoArray){
				tamanio += sizeof(a[j]);
				espacioReservado += 1;
			}
			//cout << a[j] << endl;
			if(j == N-1)
				aSumadoArray = true;
		}
		
		//cout << *(a + 49) << endl;
		//printf("Tamaño del arreglo en bytes %d\n",sizeof(a));
		delete []a;
	}
	
	cout << N << "\t"<< espacioReservado << "\t" << tamanio << endl;
}
int main(){
	int i;
	cout << "N\tEspacio\tTamanio"<< endl;
	for(i=50; i<=1000; i=i+50) {
		proceso(i);
	}	
}
