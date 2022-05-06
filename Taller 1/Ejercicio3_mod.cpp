#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo {
	int x,y;
	nodo *sig;
};

int proceso(int N){
	int tamanio, espacio;
	int i, j;
	
	tamanio = sizeof(N) + sizeof(i) + sizeof(j);
	espacio = 3;
	
	nodo *cab = NULL, *Aux;
	tamanio+= sizeof(cab) + sizeof(Aux);
	espacio += 2;
	
	for(i=0; i<N; i++){
		Aux = new nodo;
		if(i==0)
			tamanio += sizeof(Aux);
		
		Aux->x = i;
		espacio += 1;
		tamanio += sizeof(Aux->x);
		
		Aux->y = N-i;
		espacio += 1;
		tamanio += sizeof(Aux->y);
		
		Aux->sig = cab;
		espacio += 1;
		tamanio += sizeof(cab);
		
		cab = Aux;
		
	}
	Aux = cab;
	while (Aux != NULL){
		//cout << Aux->x << Aux->y << endl;
		Aux = Aux -> sig;
	}
	
	for(Aux=cab->sig; Aux!=NULL; Aux = Aux->sig ){
		delete cab;
		cab = Aux;
	}
	delete cab;
	//cout << "N\tEspacio\tTamanio"<< endl;
	cout << N << "\t"<< espacio << "\t" << tamanio << endl;
}

int main(){
	int i;
	cout << "N\tEspacio\tTamanio"<< endl;
	for(i=50; i<=1000; i=i+50){
		proceso(i);
	}
}
