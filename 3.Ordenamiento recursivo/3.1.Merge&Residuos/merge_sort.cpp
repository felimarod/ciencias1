#include <ctime>
#include <iostream>

using namespace std;

string arrayToString(int a[], int tam) {
  string aux = "";
  for (int i = 0; i < tam; i++) {
    if (i < tam - 1) {
      aux += to_string(a[i]);
      aux += ", ";
    } else {
      aux += to_string(a[i]);
    }
  }
  return aux;
}
void mergeLists(int *list, int start1, int end1, int start2, int end2) {
  int finalStart, finalEnd, indexC;
  int result[end2 - start1 + 1];
  // list the elements to be put into order
  // start1 beginning of "list" A
  // end1 end of "list" A
  // start2 beginning of "list" B
  // end2 end of "list" B
  // assumes that the elements of A and B are contiguous in list
  finalStart = start1;
  finalEnd = end2;
  indexC = 0;
  while (start1 <= end1 && start2 <= end2) {
    if (list[start1] < list[start2]) {
      result[indexC] = list[start1];
      start1 = start1 + 1;
    } else {
      result[indexC] = list[start2];
      start2 = start2 + 1;
    }
    indexC = indexC + 1;
  }
  // move the part of the list that is left over
  if (start1 <= end1) {
    for (int i = start1; i < end1; i++) {
      result[indexC] = list[i];
      indexC = indexC + 1;
    }
  } else {
    for (int i = start2; i < end2; i++) {
      result[indexC] = list[i];
      indexC = indexC + 1;
    }
  }
	//cout << arrayToString(result, indexC -1 ) << endl;
  // now put the result back into the list
  indexC = 0;
  for (int i = finalStart; i < finalEnd; i++) {
    list[i] = result[indexC];
    indexC = indexC + 1;
  }
}
void mergeSort(int *list, int first, int last) {
  //cout << arrayToString(list, 20) << endl;
  int middle;

  // list the elements to be put into order
  // first the index of the first element in the part of list to sort
  // last the index of the last element in the part of list to sort
  if (first < last) {
    middle = (first + last) / 2;
    mergeSort(list, first, middle);
    mergeSort(list, middle + 1, last);
    mergeLists(list, first, middle, middle + 1, last);
  }
}
void proceso(int N) {

  unsigned t0, t1;
  int a[N];
  for (int j = N; j > 0; j--) {
    a[N - j] = j;
  }
  cout << arrayToString(a, N) << endl;
  t0 = clock();

  mergeSort(a, 0, N - 1);

  t1 = clock();
  cout << arrayToString(a, N) << endl;

  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << N << "\t" << time << endl;
  // printf("%d\t%.16g\n", N, segundos * 1000.0);
}

int main(int argc, char *argv[]) {
  int i;
  printf("N\tTiempo\n");
  proceso(20);
  // for (i = 50; i <= 1000; i = i + 50) {
  // proceso(i);
  //}
  return 0;
}
