#include <iostream>

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H 

using namespace std;

struct Estudiante {
  string nom, car, act;
  int edad, sigNom, sigCar, sigAct, sigEdad;
};

struct nodo {
  Estudiante info;
  nodo *sig;
};
#endif /* ifndef ESTUDIANTE_H */
