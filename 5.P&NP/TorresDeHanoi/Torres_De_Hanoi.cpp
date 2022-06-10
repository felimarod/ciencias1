#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;
 

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


void hanoi(int num,char A,char C,char B)
{
    if(num>1)
    {
        hanoi(num-1,A,B,C);
        hanoi(num-1,B,C,A);
             
    }
    
}

int main()
{
	LARGE_INTEGER t_ini, t_fin;
	double segundos;
	
    char A,B,C;
    int i;
	printf("N\tTiempo\n");

	
	for (i = 43; i <= 5000; i++) {
		QueryPerformanceCounter(&t_ini);
		hanoi(i,'A','C','B');
		QueryPerformanceCounter(&t_fin);
 		segundos = performancecounter_diff(&t_fin, &t_ini);
  		printf("%d\t%.16g\n", i, segundos * 1000.0);
	}
	return 0;
}
