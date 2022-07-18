#include <stdio.h>
#include<stdlib.h> 

int verifganhador(int n,int p,char **jogo,char simbolo){
  int flag = 1;
  //verifica por linha
  for(int i = 0;i<n;i++){
    int count = 0;
    for(int j = 0;j<n;j++){
      if(jogo[i][j] == simbolo){
        count++;
      } else {
        count = 0;
      }
      if(count >= p){
        flag = 0;
        printf("Vencedor %c, por linhas",simbolo);
        return flag;
      }
    }  
  }
  // verifica por coluna
  for(int i = 0;i<n;i++){
    int count = 0;
    for(int j = 0;j<n;j++){
      if(jogo[j][i] == simbolo){
        count++;
      } else{
        count = 0;
      }
      if(count >= p){
        flag = 0;
        printf("Vencedor %c, por colunas",simbolo);
        return flag;
      }
    } 
  }
  // diagonal principal
  for(int i = 0;i<n;i++){
    int count = 0;
    for(int j = 0;j<i+1;j++){
      if(jogo[n-1+j-i][j] == simbolo){
        count++;
      } else {
        count = 0;
      }
      if(count >= p){
        flag = 0;
        printf("Vencedor %c, por diagonais 1",simbolo);
        return flag;
      }
    } 
  }
  for(int i = 0;i<n-1;i++){
    int count = 0;
    for(int j = 0;j<n-1-i;j++){
      if(jogo[j][i+1+j] == simbolo){
        count++;
      } else{
        count = 0;
      }
      if(count >= p){
        flag = 0;
        printf("Vencedor %c, por diagonais 2",simbolo);
        return flag;
      }
    }
  }
  //diagonal secundaria
  for(int i = 0;i<n;i++){
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<i+1;j++){
      if(jogo[n-1-j][n-1-i+j] == simbolo){
        count++;
      } else{
        count = 0;
      }
      if(count >= p){
        flag = 0;
        printf("Vencedor %c, por diagonais 3",simbolo);
        return flag;
      }
    }
  }
  for(int i = 0;i<n-1;i++){
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<n-1-i;j++){
      if(jogo[n-i-2-j][j] == simbolo){
        count++;
      } else{
        count = 0;
      }
      if(count >= p){
        flag = 0;
        printf("Vencedor %c, por diagonais 4",simbolo);
        return flag;
      }
    }
  }
  // verifica se empatou
  int aux2 = 1;
  for(int i = 0;i<n;i++){
    for( int j = 0;j<n;j++){
      if(jogo[i][j] == ' '){
        return flag;
      }
    }
  }
  if(aux2 == 1){
    flag = 0;
    printf("Empate\n");
  }
  return flag;
}

void printjogo(int n,char **jogo){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      printf("%c",jogo[i][j]);
      if(j != n-1){
        printf("|");
      }
    }
    printf("\n");
    if(i != n-1){
      for(int k = 0;k<n;k++){
        if(k != n-1){
          printf("- ");
        } else{
          printf("-\n");
        }
      }
    } 
  }
  printf("\n");
}