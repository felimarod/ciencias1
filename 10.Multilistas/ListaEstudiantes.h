#include "Estudiante.h"

#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H

class MultiListaEstudiantes {
public:
  MultiListaEstudiantes(int _tam = 10) {
    cabs = new int[10]; /* nombre edad sistemas industrial electrica catastral
                           danza basquet natacion beisbol */
    ests = new Estudiante[_tam];
    tamMax = _tam;
    tam = 0;
  }
  //~MultiListaEstudiantes();
  inline bool estaVacia() { return tam == 0; }
  inline bool estaLlena() { return tam == tamMax; }
  inline int getTam() { return tam; }

  void insertar(Estudiante *);

  void imprimir();

private:
  int *cabs;
  Estudiante *ests;
  int tam, tamMax;
  void organizarPorNombre(Estudiante *);
  void organizarPorEdad(Estudiante *);
  void organizarPorCarrera(Estudiante *);
  void organizarPorActividad(Estudiante *);
};

void MultiListaEstudiantes::insertar(Estudiante *inf) {
  if (!estaLlena()) {
    tam++;
    organizarPorNombre(inf);
    organizarPorEdad(inf);
    organizarPorCarrera(inf);
    organizarPorActividad(inf);
    ests[tam - 1] = *inf;
  }
}

/* nombre edad catastral electrica industrial sistemas basquet beisbol danza
 * natacion */
void MultiListaEstudiantes::organizarPorNombre(Estudiante *inf) {
  /* Organizar por Nombre */
  int auxCab;
  auxCab = cabs[0];
}

/* Organizar por Edad */
void MultiListaEstudiantes::organizarPorEdad(Estudiante *inf) {}

/* Organizar por Carrera */
void MultiListaEstudiantes::organizarPorCarrera(Estudiante *inf) {
  int auxCab, cabAnt, posCab;
  if (inf->car == "Catastral") {
    posCab = 2;
  } else if (inf->car == "Electrica") {
    posCab = 3;
  } else if (inf->car == "Industrial") {
    posCab = 4;
  } else if (inf->car == "Sistemas") {
    posCab = 5;
  }
  auxCab = cabs[posCab];
  if (auxCab == 0) {
    cabs[posCab] = tam;
  } else {
    while (auxCab != 0) {
      cabAnt = auxCab;
      auxCab = ests[auxCab - 1].sigCar;
    }
    ests[cabAnt - 1].sigCar = tam;
  }
}

/* Organizar por Actividad */
void MultiListaEstudiantes::organizarPorActividad(Estudiante *inf) {
  int auxCab;
  if (inf->act == "Basquet") {
    inf->sigAct = cabs[6];
    cabs[6] = tam;
  } else if (inf->act == "Beisbol") {
    inf->sigAct = cabs[7];
    cabs[7] = tam;
  } else if (inf->act == "Danza") {
    inf->sigAct = cabs[8];
    cabs[8] = tam;
  } else if (inf->act == "Natació") {
    inf->sigAct = cabs[9];
    cabs[9] = tam;
  }
}

void MultiListaEstudiantes::imprimir() {
  cout << "\tNombre \tCarrera \tActividad \tEdad \tSig Nom \tSig "
          "Carr \tSig Act\t Sig Edad"
       << endl;

  for (int i = 0; i < tam; i++) {
    cout << i + 1 << "\t" << ests[i].nom << "\t" << ests[i].car << "\t"
         << ests[i].act << "\t"

         << "\t" << ests[i].edad << "\t"
         << "\t" << ests[i].sigNom << "\t"
         << "\t" << ests[i].sigCar << "\t"
         << "\t" << ests[i].sigAct << "\t" << ests[i].sigEdad << endl;
  }
  cout << endl;

  cout << "Cabeceras:"
       << "\nNombre:\t\t" << cabs[0]

       << "\nSistemas:\t" << cabs[5] << "\nIndustrial:\t" << cabs[4]
       << "\nElectrica:\t" << cabs[3] << "\nCatastral:\t" << cabs[2]

       << "\nDanza:\t\t" << cabs[8] << "\nBasquet:\t" << cabs[6]
       << "\nNatació:\t" << cabs[9] << "\nBeisbol:\t" << cabs[7]

       << "\nEdad :\t\t" << cabs[1]

       << endl;
}

#endif
