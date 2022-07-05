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
    for (int i = 0; i < _tam; i++) {
      ests[i].nom = ests[i].car = ests[i].act = "";
      ests[i].edad = ests[i].sigNom = ests[i].sigCar = ests[i].sigAct = ests[i].sigEdad = 0;
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
  bool contiene(string);
  ListaSimple<Estudiante> *obtenerEstudiantesConNombre(string);
  bool eliminar(int);

private:
  int *cabs;
  Estudiante *ests;
  int tam, tamMax;
  int getPosCab(string);
};

void MultiListaEstudiantes::insertar(Estudiante inf) {
  int posEstAnt, posEstSig;
  int auxCab, cabAnt, posCab;

  if (!multilistaLlena()) {
    ests[tam].nom = inf.nom;
    ests[tam].edad = inf.edad;
    ests[tam].car = inf.car;
    ests[tam].act = inf.act;
    tam++;

    if (tam == 1) {
      /* Cabecera Nombre */
      cabs[0] = tam;
      /* Cabecera Edad */
      cabs[1] = tam;
    } else {
      /* Ordenar por Nombre */
      if (inf.nom <= ests[cabs[0] - 1].nom) {
        ests[tam - 1].sigNom = cabs[0];
        cabs[0] = tam;
      } else {
        // Empieza a recorrerlos en orden Alfabetico, mientras halla un siguiente
        posEstAnt = cabs[0];
        posEstSig = ests[posEstAnt - 1].sigNom;
        while (ests[posEstAnt - 1].nom < inf.nom && posEstSig != 0) {
          if (inf.nom < ests[posEstSig - 1].nom)
            break;
          posEstAnt = posEstSig;
          posEstSig = ests[posEstAnt - 1].sigNom;
        }
        ests[posEstAnt - 1].sigNom = tam;
        ests[tam - 1].sigNom = posEstSig;
      }
      /* Ordenar por Edad */
      if (inf.edad >= ests[cabs[1] - 1].edad) {
        ests[tam - 1].sigEdad = cabs[1];
        cabs[1] = tam;
      } else {
        // Empieza a recorrerlos en orden de Edad, mientras halla un siguiente
        posEstAnt = cabs[1];
        posEstSig = ests[posEstAnt - 1].sigEdad;
        while (ests[posEstAnt - 1].edad > inf.edad && posEstSig != 0) {
          if (inf.edad > ests[posEstSig - 1].edad)
            break;
          posEstAnt = posEstSig;
          posEstSig = ests[posEstAnt - 1].sigEdad;
        }
        ests[posEstAnt - 1].sigEdad = tam;
        ests[tam - 1].sigEdad = posEstSig;
      }
    }
    /* Ordenar por Carrera */
    posCab = getPosCab(inf.car);
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
    /* Ordenar por hobbie */
    posCab = getPosCab(inf.act);
    ests[tam - 1].sigAct = cabs[posCab];
    cabs[posCab] = tam;
  }
}

int MultiListaEstudiantes::getPosCab(string orden) {
  if (orden == "Nombre") return 0;
  else if (orden == "Edad") return 1;
  else if (orden == "Catastral") return 2;
  else if (orden == "Electrica") return 3;
  else if (orden == "Industrial") return 4;
  else if (orden == "Sistemas") return 5;
  else if (orden == "Basquet") return 6;
  else if (orden == "Beisbol") return 7;
  else if (orden == "Danza") return 8;
  else if (orden == "Natació") return 9;
}

bool MultiListaEstudiantes::eliminar(int pos) {
  Estudiante auxEst, estActu;
  int auxCab, posCab;
  if (pos > tam || tam < 1)
    return false;

  estActu = ests[pos - 1];
  /* Nombre */
  if (pos == cabs[0]) {
    cabs[0] = estActu.sigNom;
  } else {
    // Empieza a recorrerlos en orden Alfabetico, mientras halla un siguiente
    auxCab = cabs[0];
    posCab = ests[auxCab - 1].sigNom;
    while (posCab != pos && posCab != 0) {
      auxCab = posCab;
      posCab = ests[auxCab - 1].sigNom;
    }
    ests[auxCab - 1].sigNom = estActu.sigNom;
  }
  /* Edad */
  if (pos == cabs[1]) {
    cabs[1] = estActu.sigEdad;
  } else {
    // Empieza a recorrerlos de mayor a menor, mientras exista un siguiente
    auxCab = cabs[1];
    posCab = ests[auxCab - 1].sigEdad;
    while (posCab != pos && posCab != 0) {
      auxCab = posCab;
      posCab = ests[auxCab - 1].sigEdad;
    }
    ests[auxCab - 1].sigEdad = estActu.sigEdad;
  }
  /* Carrera */
  int orden = getPosCab(estActu.car);
  if (pos == cabs[orden]) {
    cabs[orden] = estActu.sigCar;
  } else {
    auxCab = cabs[orden];
    posCab = ests[auxCab - 1].sigCar;
    while (posCab != pos && posCab != 0) {
      auxCab = posCab;
      posCab = ests[auxCab - 1].sigCar;
    }
    ests[auxCab - 1].sigEdad = estActu.sigCar;
  }
  /* Actividad */
  orden = getPosCab(estActu.act);
  if (pos == cabs[orden]) {
    cabs[orden] = estActu.sigAct;
  } else {
    auxCab = cabs[orden];
    posCab = ests[auxCab - 1].sigAct;
    while (posCab != pos && posCab != 0) {
      auxCab = posCab;
      posCab = ests[auxCab - 1].sigAct;
    }
    ests[auxCab - 1].sigEdad = estActu.sigAct;
  }
  for (int i = 0; i < 10; ++i)
    if(cabs[i] >= pos) cabs[i] = cabs[i]-1;

  /* Sube los estudiantes que estaban debajo del que se quitan los datos*/
  pos--;
  for (int i = pos; i < tam - 1; i++) {
    ests[i].nom = ests[i + 1].nom;
    ests[i].edad = ests[i + 1].edad;
    ests[i].car = ests[i + 1].car;
    ests[i].act = ests[i + 1].act;
    ests[i].sigNom = ests[i + 1].sigNom;
    ests[i].sigEdad = ests[i + 1].sigEdad;
    ests[i].sigCar = ests[i + 1].sigCar;
    ests[i].sigAct = ests[i + 1].sigAct;
  }
  /* Cambia las posiciones que apuntaban a la anterior o uno mayor */
  pos++;
  for (int i = 0; i < tam - 1; i++) {
    if(ests[i].sigNom >= pos) ests[i].sigNom--;
    if(ests[i].sigEdad >= pos) ests[i].sigEdad--;
    if(ests[i].sigCar >= pos) ests[i].sigCar--;
    if(ests[i].sigAct >= pos) ests[i].sigAct--;
  }
  tam--;
  ests[tam].nom = "";
  ests[tam].car = "";
  ests[tam].act = "";
  ests[tam].edad = 0;
  ests[tam].sigAct = 0;
  ests[tam].sigCar = 0;
  ests[tam].sigEdad = 0;
  ests[tam].sigNom = 0;
  return true;
}

void MultiListaEstudiantes::imprimirListaOrdenada(string orden) {
  Estudiante auxE;
  int auxPos, ord;

  ord = getPosCab(orden);

  auxPos = cabs[ord];
  if (auxPos != 0) {
    cout << "\tNombre\t\tCarrera\tAct\tEdad\tSiNom\tSiCarr\tSiAct\tSiEdad"
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
           << auxE.edad << "\t" << auxE.sigNom << "\t" << auxE.sigCar << "\t"
           << auxE.sigAct << "\t" << auxE.sigEdad << endl;
    } while (auxPos != 0);
  }
}

bool MultiListaEstudiantes::contiene(string nombre) {
  Estudiante auxE;
  for (int i = 0; i < tam; i++) {
    auxE = ests[i];
    if (auxE.nom == nombre)
      return true;
  }
}

ListaSimple<Estudiante> *
MultiListaEstudiantes::obtenerEstudiantesConNombre(string nombre) {
  ListaSimple<Estudiante> *listaEstOrdNom = obtenerListaOrdenadaPor("Nombre");
  ListaSimple<Estudiante> *lista = NULL;
  Estudiante auxE;
  if (listaEstOrdNom != NULL) {
    if (contiene(nombre)) {
      lista = new ListaSimple<Estudiante>;
      for (int i = 1; i <= listaEstOrdNom->getTam(); i++) {
        auxE = listaEstOrdNom->obtenerElemento(i);
        if (auxE.nom == nombre) {
          cout << "agregandoando\n";
          lista->insertar(auxE);
        }
      }
    }
  }
  return lista;
}

ListaSimple<Estudiante> *
MultiListaEstudiantes::obtenerListaOrdenadaPor(string orden) {
  ListaSimple<Estudiante> *lista = NULL;
  Estudiante auxE;
  int auxPos, ord;
  ord = getPosCab(orden);
  auxPos = cabs[ord];
  if (auxPos != 0) {
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

void MultiListaEstudiantes::imprimir() {
  printf("---------Tabla de Datos---------\n");
  cout << "\tNombre\tCarrera\t\tAct\tEdad\tSiNom\tSiCarr\tSiAct\tSiEdad"
       << endl;
  for (int i = 0; i < tam; i++) {
    cout << i + 1 << "\t" << ests[i].nom << "\t" << ests[i].car << "\t"
         << ests[i].act << "\t" << ests[i].edad << "\t" << ests[i].sigNom
         << "\t" << ests[i].sigCar << "\t" << ests[i].sigAct << "\t"
         << ests[i].sigEdad << endl;
  }
  cout << endl;
  printf("---------Tabla de Cabeceras---------\n");
  cout << "\nNombre:\t\t" << cabs[0] << "\nSistemas:\t" << cabs[5]
       << "\nIndustrial:\t" << cabs[4] << "\nElectrica:\t" << cabs[3]
       << "\nCatastral:\t" << cabs[2] << "\nDanza:\t\t" << cabs[8]
       << "\nBasquet:\t" << cabs[6] << "\nNatació:\t" << cabs[9]
       << "\nBeisbol:\t" << cabs[7] << "\nEdad :\t\t" << cabs[1] << endl;
}

#endif
