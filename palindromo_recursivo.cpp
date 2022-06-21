#include <iostream>

using namespace std;

int F(char pal[], int i, int lon) {
  if (i < lon / 2)
    if (pal[i] == pal[lon - 1 - i])
      return F(pal, i + 1, lon);
    else
      return 0;
  else
    return 1;
}
int main(){
  char *pal="beeb";
  int i = 0;
  int strtam = 4;
  if(F(pal,i,strtam) == 0)
    printf("No lo es\n");
  else
    printf("Si lo es\n");
}
