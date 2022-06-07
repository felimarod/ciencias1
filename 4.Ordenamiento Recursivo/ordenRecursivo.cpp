// Cambio de residuos
unsigned bits(int x, int k, int j) { return (x >> k) & ~(~0 << j); }

void cambioresiduos(int a[], int izq, int der, int b) {
  int i, j, aux;
  if (der > izq && b > 0) {
    i = izq;
    j = der;
    while (j != i) {
      while (!bits(a[i], b, 1) && i < j)
        i++;
      while (bits(a[j], b, 1) && j > i)
        j--;
      aux = a[i];
      a[i] = a[j];
      a[j] = aux;
    }
    if (!bits(a[i], b, 1))
      j++;
    cambioresiduos(a, izq, j - 1, b - 1);
    cambioresiduos(a, j, der, b - 1);
  }
}

// Merge sort
void merge(int a[], int inicio, int mitad, int final) {
  int i, j, k;
  int elementosIzq = mitad - inicio + 1;
  int elementosDer = final - mitad;
  int izquierda[elementosIzq];
  int derecha[elementosDer];
  for (int i = 0; i < elementosIzq; i++)
    izquierda[i] = a[inicio + i];
  for (int j = 0; j < elementosDer; j++)
    derecha[j] = a[mitad + 1 + j];
  i = 0;
  j = 0;
  k = inicio;
  while (i < elementosIzq && j < elementosDer) {
    if (izquierda[i] <= derecha[j]) {
      a[k] = izquierda[i];
      i++;
    } else {
      a[k] = derecha[j];
      j++;
    }
    k++;
  }
  while (j < elementosDer) {
    a[k] = derecha[j];
    j++;
    k++;
  }
  while (i < elementosIzq) {
    a[k] = izquierda[i];
    i++;
    k++;
  }
}

void mergeSort(int a[], int inicio, int final) {
  if (inicio < final) {
    int mitad = inicio + (final - inicio) / 2;
    mergeSort(a, inicio, mitad);
    mergeSort(a, mitad + 1, final);
    merge(a, inicio, mitad, final);
  }
}

void quickSort(int a[], int izq, int der) {
  int i, j, v, aux;
  if (der > izq) {
    v = a[der];
    i = izq - 1;
    j = der;
    for (;;) {
      while (a[++i] < v)
        ;
      while (a[--j] > v)
        ;
      if (i >= j)
        break;
      aux = a[i];
      a[i] = a[j];
      a[j] = aux;
    }
    aux = a[i];
    a[i] = a[der];
    a[der] = aux;
    quickSort(a, izq, i - 1);
    quickSort(a, i + 1, der);
  }
}

void radixSort(int *A, int N, int r) {
  // int *A;           // Puntero a arreglo con números a organizar
  // int N;            // Cantidad de números a organizar
  int const MAX = 100; // Espacio en cada cubeta
  int const DIG = 10;  // Cantidad de digitos que pueden aparecer en el arreglo
  int C[DIG][MAX];     // Puntero de las cubetas a utlizar
  int counters[DIG];   // Contadores de las cubetas usadas
  int i, j, x, d, flag = 0, p = -1;
  d = r / 10;
  // Limpiar cubetas
  for (i = 0; i < DIG; i++) {
    for (j = 0; j < MAX; j++)
      C[i][j] = -1;
    counters[i] = 0;
  }
  // Separar en cubetas
  for (i = 0; i < N; i++) {
    x = A[i] % r;
    int m = x / d;
    if (m > 0)
      flag = 1;
    C[m][counters[m]] = A[i];
    counters[m]++;
  }
  // Devolver de las cubetas a la lista inicial
  for (i = 0; i < DIG; i++)
    for (j = 0; j < MAX; j++)
      if (C[i][j] != -1) {
        p++;
        A[p] = C[i][j];
      }
  if (flag == 1)
    radixSort(A, N, r * 10);
}
