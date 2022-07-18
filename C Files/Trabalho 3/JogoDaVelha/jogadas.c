#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void jogadausuario(char simbolo,int n,char **jogo){  //CONCLUIDO
  int l,c;
  int flag = 0;
  while(flag == 0){
    printf("Escolha a posicao desejada %c\n",simbolo);
    scanf("%d",&l);
    scanf("%d",&c);
    if(l>=0 && l<n && c>=0 && c<n){
      if(jogo[l][c] == ' '){
        jogo[l][c] = simbolo;
        flag = 1;
      } else {
        printf("Posicao ocupada, tente outra!\n");
      }
    } else {
      printf("Posição inválida, tente outra!\n");
    }
  }
}