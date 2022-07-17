#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n); // numero de pessoas
  int m;
  scanf("%d",&m); // qual a posição da pessoa que quer saber
  int auxn = n;
  int posicao[n];
  for(int i = 0;i<=n;i++){ //seta todas as pessoas como vivas
    posicao[i]=1;
  }
  int flag = 1;
  int i = 2;
  while(auxn!=0){ // enquanto tiver pelo menos um vivo
    if(posicao[i] == 1){ // se a pessoa na posição i estiver viva
      if(flag){ // se já tiver passado por uma pessoa viva
        posicao[i] = 0; // seta ela como morta
        auxn = auxn - 1; // menos uma pessoa
        flag = 0; // abaixa a flag
        if(auxn == (n-m)){ 
          printf("Morte %d: %d\n",m,i);
        }
      } else { // se não, levante a flag
        flag = 1;
      }
    }
    i++;
    if(i>n){ // se chegar no final do circulo volta para o inicio
        i = i-n;
      }
  }
  printf("Sobrevivente: %d",i-1);
}