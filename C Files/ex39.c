#include <stdio.h>

int main(void) {
  int somapar = 0,somaimpar = 0,soma = 0;
  int n = 1;
  while(n!=0){
  scanf("%d",&n);
  if(n%2 == 0){
    somapar = somapar + n;
  }
  else{
    somaimpar = somaimpar + n;
  }
  soma = soma + n;
  }
  printf("%d\n",somapar);
  printf("%d\n",somaimpar);
  printf("%d\n",soma);
}