#include <iostream>
#include "ListaEstudiantes.h"

using namespace std;

void ejercicioClase();
void pedirDatos();

int main() {

  //pedirDatos();
  ejercicioClase();

  return 0;
}

void ejercicioClase() {
  MultiListaEstudiantes mle;
  Estudiante *auxE;

  auxE = new Estudiante;
  auxE->nom = "Raquel";
  auxE->car = "Electrica";
  auxE->act = "Danza";
  auxE->edad = 17;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Jaime";
  auxE->car = "Industrial";
  //auxE->act = "Natación";
  auxE->act = "Natació";
  auxE->edad = 20;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Arturo";
  auxE->car = "Electrica";
  auxE->act = "Basquet";
  auxE->edad = 19;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Andres";
  auxE->car = "Catastral";
  auxE->act = "Danza";
  auxE->edad = 24;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Ariana";
  auxE->car = "Sistemas";
  auxE->act = "Basquet";
  auxE->edad = 18;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Juanny";
  auxE->car = "Industrial";
  //auxE->act = "Natación";
  auxE->act = "Natació";
  auxE->edad = 21;
  mle.insertar(auxE);

  auxE = new Estudiante;
  //auxE->nom = "Mary Paz";
  auxE->nom = "Mary P";
  auxE->car = "Sistemas";
  auxE->act = "Danza";
  auxE->edad = 25;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Italia";
  auxE->car = "Catastral";
  auxE->act = "Beisbol";
  auxE->edad = 23;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Mario";
  auxE->car = "Sistemas";
  auxE->act = "Basquet";
  auxE->edad = 18;
  mle.insertar(auxE);

  auxE = new Estudiante;
  auxE->nom = "Pilar";
  auxE->car = "Sistemas";
  auxE->act = "Beisbol";
  auxE->edad = 22;
  mle.insertar(auxE);

  mle.imprimir();
}

void pedirDatos(){
  MultiListaEstudiantes mle;
  Estudiante *auxE;
  for (int i = 0; i < 10; i++) {
    auxE = new Estudiante;
    cout << "Ingrese el nombre del estudiante: "; cin >> auxE->nom;
    cout << "Ingrese la edad del estudiante: "; cin >> auxE->edad;
    cout << "Ingrese la carrera universitaria del estudiante: "; cin >> auxE->car;
    cout << "Ingrese la actividad del estudiante: "; cin >> auxE->act;
    mle.insertar(auxE);
  }

  mle.imprimir();
}
