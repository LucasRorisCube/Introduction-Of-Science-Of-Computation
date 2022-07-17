#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int vetorp[n];
  int vetori[n];
  int numero;
  int aux = 0;
  int aux2 = 0;
  for(int i = 0;i<n;i++){
    scanf("%d",&numero);
    if(numero%2 == 0){
      vetorp[aux] = numero;
      aux++;
    } 
    if(numero%2 == 1){
      vetori[aux2] = numero;
      aux2++;
    }
  }

  for(int i = 0;i<aux;i++){
    printf("%d ",vetorp[i]);
  }
    if(aux == 0){
      printf(" ");
  }
  printf("\n");
  for(int i = 0;i<aux2;i++){
    printf("%d ",vetori[i]);
  }
  if(aux2 == 0){
    printf("\n");
  }
}