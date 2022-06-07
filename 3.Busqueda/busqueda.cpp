void busquedaBinaria(int A[], int n){
  int num = 0, primero, ultimo, medio;

  primero = 0;
  ultimo = n - 1;
  medio = (primero + ultimo) / 2;
  while (primero <= ultimo) {
    if (A[medio] == num) {
      break;
    } else if (A[medio] < num) {
      primero = medio + 1;
    } else if (A[medio] > num) {
      ultimo = medio - 1;
    }
    medio = (primero + ultimo) / 2;
  }
}

void busquedaSecuencial(int A[], int tam){
  int posicion = 0, numBuscado = tam; // numBuscado = tamaño del arreglo para que
                                      // no exista y se busque el peor caso
  while (posicion < tam && A[posicion] != numBuscado) 
    posicion++;
}
