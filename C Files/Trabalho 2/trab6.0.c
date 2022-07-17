#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int m;
  scanf("%d",&m);
  int auxn = n;
  int posicao[n];
  for(int i = 0;i<=n;i++){
    posicao[i]=1;
  }
  int flag = 1;
  int i = 2;
  for(i = 2;auxn!=0;i++){
    if(posicao[i] == 1 && flag == 1){
      posicao[i] = 0;
      auxn = auxn - 1;
      flag = 0;
      if(auxn == n-m){
        printf("Morte %d: %d\n",m,i);
      }
    } else {
      if(posicao[i] == 1){
        flag++;
      }
    }
    if(i>n){
        i = i-n-1;
      }
  }
  printf("Sobrevivente: %d",i-1);
}