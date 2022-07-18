#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void jogcomp(char jogo[3][3]){
  srand((unsigned)time(NULL));
  int l,c;
  int flag = 0;
  while(flag == 0){
    l = rand()%3;
    c = rand()%3;
    if(jogo[l][c] == ' '){
      jogo[l][c] = 'O';
      flag = 1;
    }
  }
 
}

void printjogo(char jogo[3][3]){
  for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
      printf("%c",jogo[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int verifganhador(char jogo[3][3]){
  int flag = 1;
  // verifica se alguma linha tem 3 iguais
  for(int i = 0;i<3;i++){ 
    if(((jogo[i][0] == jogo[i][1]) && (jogo[i][1] == jogo[i][2])) && (jogo[i][0] != ' ')){
      printf("Vencedor %c\n",jogo[i][0]);
      flag = 0;
    }
  }
  // verifica se alguma coluna tem 3 iguais
  for(int i = 0;i<3;i++){    
    if(((jogo[0][i] == jogo[1][i]) && (jogo[1][i] == jogo[2][i])) && (jogo[0][i] != ' ')){
      printf("Vencedor %c\n",jogo[i][0]);
      flag = 0;
    }
  }
  // verifica se a diagonal principal tem 3 iguais
  if(((jogo[0][0] == jogo[1][1]) && (jogo[1][1] == jogo[2][2])) && (jogo[0][0] != ' ')){
    printf("Vencedor %c\n",jogo[0][0]);
    flag = 0;
  }
  // verifica se a diagonal segundaria tem 3 iguais
  if(((jogo[2][0] == jogo[1][1]) && (jogo[1][1] == jogo[0][2])) && (jogo[2][0] != ' ')){
    printf("Vencedor %c\n",jogo[2][0]);
    flag = 0;
  }
  // verifica se todos os espaços estão preenchidos
  int aux = 1;
  for(int i = 0;i<3;i++){
    for( int j = 0;j<3;j++){
      if(jogo[i][j] == ' '){
        aux = 0;
        break;
      }
    }
    if(aux == 0){
      break;
    }
  }
  if(aux == 1){
    flag = 0;
    printf("Empate\n");
  }
  return flag;
}

void jogpes(char jogo[3][3]){
  int l,c;
  int flag = 0;
  while(flag == 0){
    scanf("%d",&l);
    scanf("%d",&c);
    if(jogo[l][c] == ' '){
      jogo[l][c] = 'X';
      flag = 1;
    } else {
      printf("Posição ocupada, tente outra!\n");
    }
  }
}

int main(void) {
  char jogo[3][3] = {"   ","   ","   "};
  int flag = 0;
  while(verifganhador(jogo)){
    if(flag){
      jogcomp(jogo);
      flag = 0;
    } else{
      jogpes(jogo);
      flag = 1;
    }
    printjogo(jogo);
  }
}