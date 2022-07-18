#include <stdio.h>
#include<stdlib.h>
int verifganhar(int n,int p,char **jogo, char simbologanhando,char simbolo){
  int flag = 0;
  //verifica por linha
  for(int i = 0;i<n;i++){
    int flag1 = 0;
    for(int k = 0;p+k<=n;k++){
      int count = 0;
      char *aux = NULL;
      for(int j = k;j<p+k;j++){
        if(jogo[i][j] == simbologanhando){
          count++;
        } else{
          if(jogo[i][j] != ' '){
            count = 0;
            break;
          } else {
            flag1 = 1;
            aux = &jogo[i][j];
          }
        }
      }
      if(count == p-1 && flag1 == 1){
        *aux = simbolo;
        printf(" %c impediu %c por linha\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
    }
  }
  // verifica por coluna
  for(int i = 0;i<n;i++){
    int flag1 = 0;
    for(int k = 0;p+k<=n;k++){
      int count = 0;
      char *aux = NULL;
      for(int j = k;j<p+k;j++){
        if(jogo[j][i] == simbologanhando){
          count++;
        } else{
          if(jogo[j][i] != ' '){
            count = 0;
            break;
          } else {
            flag1 = 1;
            aux = &jogo[j][i];
          }
        }
      }
      if(count == p-1 && flag1 == 1){
        *aux = simbolo;
        printf(" %c impediu %c por coluna\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
    }
  }
  // diagonal principal
  //1 parte
  int i = 0;
  int j = 0;
  while(i<n){
    int count = 0;
    char *aux = NULL;
    int aux2 = 0;
    while(aux2<p && j<i+1){
      if(jogo[n-1+j-i][j] == simbologanhando){ // se for o simbolo
        count++;
      } else{
        if(jogo[n-1+j-i][j] == ' '){ //se for espaço
          aux = &jogo[n-1+j-i][j];
        } else{ //se for outro simbolo
          count = 0;
          aux = NULL;
        }
      }
      j++;
      aux2++;
    }
    if(count == (p-1) && aux != NULL){
      *aux = simbolo;
      printf(" %c impediu %c por diagonal 1\n",simbolo,simbologanhando);
      return 1;
    }
    if(j<i+1){
      j -= p-1;
    } else{
      i++;
      j = 0;
    }
  }
  //diagonal principal
  //2 parte
  i = 0;
  j = 0;
  while(i<n-1){
    int count = 0;
    char *aux = NULL;
    int aux2 = 0;
    while(aux2<p && j<n-1-i){
      if(jogo[j][i+1+j] == simbologanhando){ // se for o simbolo
        count++;
      } else{
        if(jogo[j][i+1+j] == ' '){ //se for espaço
          aux = &jogo[j][i+1+j];
        } else{ //se for outro simbolo
          count = 0;
          aux = NULL;
        }
      }
      j++;
      aux2++;
    }
    if(count == (p-1) && aux != NULL){
      *aux = simbolo;
      printf(" %c impediu %c por diagonal 2\n",simbolo,simbologanhando);
      return 1;
    }
    if(j<n-1-i){
      j -= p-1;
    } else{
      i++;
      j = 0;
    }
  }
  //diagonal secundaria
  // 1 parte
  i = 0;
  j = 0;
  while(i<n){
    int count = 0;
    char *aux = NULL;
    int aux2 = 0;
    while(aux2<p && j<i+1){
      if(jogo[n-1-j][n-1-i+j] == simbologanhando){ // se for o simbolo
        count++;
      } else{
        if(jogo[n-1-j][n-1-i+j] == ' '){ //se for espaço
          aux = &jogo[n-1-j][n-1-i+j];
        } else{ //se for outro simbolo
          count = 0;
          aux = NULL;
        }
      }
      j++;
      aux2++;
    }
    if(count == (p-1) && aux != NULL){
      *aux = simbolo;
      printf(" %c impediu %c por diagonal 3\n",simbolo,simbologanhando);
      return 1;
    }
    if(j<i+1){
      j -= p-1;
    } else{
      i++;
      j = 0;
    }
  }
  //diagonal secundaria
  //2 parte
  i = 0;
  j = 0;
  while(i<n-1){
    int count = 0;
    char *aux = NULL;
    int aux2 = 0;
    while(aux2<p && j<n-1-i){
      if(jogo[n-i-2-j][j] == simbologanhando){ // se for o simbolo
        count++;
      } else{
        if(jogo[n-i-2-j][j] == ' '){ //se for espaço
          aux = &jogo[n-i-2-j][j];
        } else{ //se for outro simbolo
          count = 0;
          aux = NULL;
        }
      }
      j++;
      aux2++;
    }
    if(count == (p-1) && aux != NULL){
      *aux = simbolo;
      printf(" %c impediu %c por diagonal 4\n",simbolo,simbologanhando);
      return 1;
    }
    if(j<n-1-i){
      j -= p-1;
    } else{
      i++;
      j = 0;
    }
  }

  return flag;
}