void burbuja(int a[], int N) {
  int aux;
  for (int i = N - 1; i >= 1; i--)
    for (int j = 1; j <= i; j++)
      if (a[j - 1] > a[j]) {
        aux = a[j];
        a[j] = a[j - 1];
        a[j - 1] = aux;
      }
}

void insercion(int a[], int N) {
  int i, j;
  int v;
  for (i = 1; i < N; i++) {
    j = i;
    v = a[j];
    while (a[j - 1] > v && j > 0) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

void seleccion(int a[], int N) {
  int i, j, posMin;
  int aux;
  for (i = 0; i < N; i++) {
    posMin = i;
    for (j = i + 1; j < N; j++)
      if (a[j] < a[posMin])
        posMin = j;
    aux = a[i];
    a[i] = a[posMin];
    a[posMin] = aux;
  }
}
