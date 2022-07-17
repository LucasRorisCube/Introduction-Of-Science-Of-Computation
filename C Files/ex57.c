#include <stdio.h>
int main(void) {
  long int y = 0;
  scanf("%ld",&y);
  int soma = 0;
  while (y>=10){
    soma += y%10;
    y = y/10;
  }
  soma+=y;
  printf("%d\n",soma);
  }

