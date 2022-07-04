#include "Estudiante.h"
#include "ListaSimple.h"

#ifndef MULTILISTAESTUDIANTES_H
#define MULTILISTAESTUDIANTES_H

class MultiListaEstudiantes {
public:
  MultiListaEstudiantes(int _tam = 10) {
    /* nombre edad catastral electrica industrial sistemas basquet beisbol danza natacion */
    cabs = new int[10];
    for (int i = 0; i < 10; i++)
      cabs[i] = 0;
    ests = new Estudiante[_tam];
    for (int i = 0; i < _tam; i++){
      ests[i].nom = "";
      ests[i].car = "";
      ests[i].edad = 0;
      ests[i].act = "";
      ests[i].sigNom = 0;
      ests[i].sigCar = 0;
      ests[i].sigAct = 0;
      ests[i].sigEdad = 0;
    }
    tamMax = _tam;
    tam = 0;
  }
  ~MultiListaEstudiantes() {
    // delete ests;
    delete cabs;
  }
  void insertar(Estudiante);
  // void eliminar(string);
  // Estudiante busquedaPorNombre(string);
  ListaSimple<Estudiante> *obtenerListaOrdenadaPor(string);
  inline bool multilistaLlena() { return tam == tamMax; }
  inline bool multilistaVacia() { return tam == 0; }
  inline int getTam() { return tam; }
  void imprimirListaOrdenada(string);
  void imprimir();

private:
  int *cabs;
  Estudiante *ests;
  int tam, tamMax;
  int getPosCab(string);
  void organizarPorNombre(Estudiante*);
  void organizarPorEdad(Estudiante*);
  void organizarPorCarrera(Estudiante*);
  void organizarPorActividad(Estudiante*);
};

void MultiListaEstudiantes::insertar(Estudiante inf) {
  if (!multilistaLlena()) {
    ests[tam].nom = inf.nom;
    ests[tam].edad = inf.edad;
    ests[tam].car = inf.car;
    ests[tam].act = inf.act;
    tam++;
    organizarPorNombre(&inf);
    organizarPorEdad(&inf);
    organizarPorCarrera(&inf);
    organizarPorActividad(&inf);
  }
}

int MultiListaEstudiantes::getPosCab(string orden){
  if (orden == "Nombre") return 0;
  else if (orden == "Edad") return  1;
  else if (orden == "Catastral") return 2;
  else if (orden == "Electrica") return 3;
  else if (orden == "Industrial") return 4;
  else if (orden == "Sistemas") return 5;
  else if (orden == "Basquet") return 6;
  else if (orden == "Beisbol") return 7;
  else if (orden == "Danza") return 8;
  else if (orden == "Natació") return 9;
}

void MultiListaEstudiantes::imprimirListaOrdenada(string orden) {
  Estudiante auxE;
  int auxPos, ord;

  ord = getPosCab(orden);

  auxPos = cabs[ord];
  if (auxPos != 0) {
    cout << "Nombre \tCarrera \tActividad \tEdad \tSig Nom \tSig Carr \tSig Act\t Sig Edad"
         << endl;
    do {
      auxE = ests[auxPos - 1];
      if (ord == 0)
        auxPos = auxE.sigNom;
      else if (ord == 1)
        auxPos = auxE.sigEdad;
      else if (ord >= 2 && ord <= 5)
        auxPos = auxE.sigCar;
      else if (ord >= 6 && ord <= 9)
        auxPos = auxE.sigAct;
      cout << auxE.nom << "\t" << auxE.car << "\t" << auxE.act << "\t"
           << "\t" << auxE.edad << "\t"
           << "\t" << auxE.sigNom << "\t"
           << "\t" << auxE.sigCar << "\t"
           << "\t" << auxE.sigAct << "\t" << auxE.sigEdad << endl;
    } while (auxPos != 0);
  }
}

ListaSimple<Estudiante>
*MultiListaEstudiantes::obtenerListaOrdenadaPor(string orden) {
  ListaSimple<Estudiante> *lista = NULL;
  Estudiante auxE;
  int auxPos, ord;

  ord = getPosCab(orden);
  auxPos = cabs[ord];

  if (auxPos != 0){
    lista = new ListaSimple<Estudiante>;
    do {
      auxE = ests[auxPos - 1];
      lista->insertar(auxE);
      if (ord == 0)
        auxPos = auxE.sigNom;
      else if (ord == 1)
        auxPos = auxE.sigEdad;
      else if (ord >= 2 && ord <= 5)
        auxPos = auxE.sigCar;
      else if (ord >= 6 && ord <= 9)
        auxPos = auxE.sigAct;
    } while (auxPos != 0);
  }
  return lista;
}

/* Organizar por Nombre */
void MultiListaEstudiantes::organizarPorNombre(Estudiante *inf) {
}

/* Organizar por Edad */
void MultiListaEstudiantes::organizarPorEdad(Estudiante *inf) {}

/* Organizar por Carrera */
void MultiListaEstudiantes::organizarPorCarrera(Estudiante *inf) {
  int auxCab, cabAnt, posCab;
  posCab = getPosCab(inf->car);
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

/* Organizar por Actividad 
 * Agrega al inicio */
void MultiListaEstudiantes::organizarPorActividad(Estudiante *inf) {
  int auxCab, posCab;
  posCab = getPosCab(inf->act);
  
  ests[tam - 1].sigAct = cabs[posCab];
  cabs[posCab] = tam;
}

void MultiListaEstudiantes::imprimir() {
  printf("---------Tabla de Datos---------\n");
  cout << "\tNombre\tCarrera\t\tAct\tEdad\tSiNom\tSiCarr\tSiAct\tSiEdad"
       << endl;

  for (int i = 0; i < tam; i++) {
    cout << i + 1 << "\t" << ests[i].nom << "\t" << ests[i].car << "\t"
         << ests[i].act
         << "\t" << ests[i].edad
         << "\t" << ests[i].sigNom
         << "\t" << ests[i].sigCar
         << "\t" << ests[i].sigAct
         << "\t" << ests[i].sigEdad << endl;
  }
  cout << endl;

  printf("---------Tabla de Cabeceras---------\n");
  cout << "\nNombre:\t\t" << cabs[0]

       << "\nSistemas:\t" << cabs[5] << "\nIndustrial:\t" << cabs[4]
       << "\nElectrica:\t" << cabs[3] << "\nCatastral:\t" << cabs[2]

       << "\nDanza:\t\t" << cabs[8] << "\nBasquet:\t" << cabs[6]
       << "\nNatació:\t" << cabs[9] << "\nBeisbol:\t" << cabs[7]

       << "\nEdad :\t\t" << cabs[1]

       << endl;
}

#endif
