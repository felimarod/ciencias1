#include "MultiListaEstudiantes.cpp"
#include <iostream>

MultiListaEstudiantes mle;

using namespace std;

void ejercicioClase();
void pedirDatos();
void imprimirListaOrdenada(string);

int main() {
  // pedirDatos();
  ejercicioClase();
  //imprimirListaOrdenada("Sistemas");
  //imprimirListaOrdenada("Danza");
   mle.imprimirListaOrdenada("Edad");
  return 0;
}

void ejercicioClase() {
  Estudiante auxE;

  auxE.nom = "Raquel";
  auxE.car = "Electrica";
  auxE.act = "Danza";
  auxE.edad = 17;
  mle.insertar(auxE);

  auxE.nom = "Jaime";
  auxE.car = "Industrial"; // auxE->act = "Natación";
  auxE.act = "Natació";
  auxE.edad = 20;
  mle.insertar(auxE);

  auxE.nom = "Arturo";
  auxE.car = "Electrica";
  auxE.act = "Basquet";
  auxE.edad = 19;
  mle.insertar(auxE);

  auxE.nom = "Andres";
  auxE.car = "Catastral";
  auxE.act = "Danza";
  auxE.edad = 24;
  mle.insertar(auxE);

  auxE.nom = "Ariana";
  auxE.car = "Sistemas";
  auxE.act = "Basquet";
  auxE.edad = 18;
  mle.insertar(auxE);

  auxE.nom = "Juanny";
  auxE.car = "Industrial"; // auxE.act = "Natación";
  auxE.act = "Natació";
  auxE.edad = 21;
  mle.insertar(auxE);

   auxE.nom = "Mary Paz";
  auxE.nom = "Mary P";
  auxE.car = "Sistemas";
  auxE.act = "Danza";
  auxE.edad = 25;
  mle.insertar(auxE);

  auxE.nom = "Italia";
  auxE.car = "Catastral";
  auxE.act = "Beisbol";
  auxE.edad = 23;
  mle.insertar(auxE);

  auxE.nom = "Mario";
  auxE.car = "Sistemas";
  auxE.act = "Basquet";
  auxE.edad = 18;
  mle.insertar(auxE);

  auxE.nom = "Pilar";
  auxE.car = "Sistemas";
  auxE.act = "Beisbol";
  auxE.edad = 22;
  mle.insertar(auxE);

   mle.imprimir();
}

void pedirDatos() {
  MultiListaEstudiantes mle;
  Estudiante auxE;
  for (int i = 0; i < 10; i++) {
    cout << "Ingrese el nombre del estudiante: "; cin >> auxE.nom;
    cout << "Ingrese la edad del estudiante: "; cin >> auxE.edad;
    cout << "Ingrese la carrera universitaria del estudiante: "; cin >> auxE.car;
    cout << "Ingrese la actividad del estudiante: "; cin >> auxE.act;
    mle.insertar(auxE);
  }
  mle.imprimir();
}
