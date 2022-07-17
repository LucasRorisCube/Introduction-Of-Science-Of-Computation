#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n); // numero de pessoas
  int m;
  scanf("%d",&m); // qual a posição da pessoa que quer saber
  int restante = n;
  int pessoa[n];
  for(int i = 0;i<=n;i++){ //seta todas as pessoas como vivas
    pessoa[i]=1;
  }
  int flag = 1;
  int posicao = 1;
  while(restante != 0){ // infinito até sobrar 0 pessoas
    posicao++;
    if(posicao>n){ // se chegar no final do circulo volta para o inicio
        posicao -= n;
      }
    if(pessoa[posicao] == 1){ // se a pessoa na posição i estiver viva
      if(flag){ // se já tiver passado por uma pessoa viva
        pessoa[posicao] = 0; // seta ela como morta
        restante -= 1; // menos uma pessoa
        flag = 0; // abaixa a flag
        if(restante == (n-m)){ 
          printf("Morte %d: %d\n",m,posicao);
        }
      } else { // se não, levante a flag
        flag = 1;
      }
    }
  }
  printf("Sobrevivente: %d",posicao);// quebra o laço quando chega em 0 pessoas
}