#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int verifganhador(char jogo[3][3]){
  int flag = 1;
  // verifica se alguma linha tem 3 iguais
  for(int i = 0;i<3;i++){ 
    if(((jogo[i][0] == jogo[i][1]) && (jogo[i][1] == jogo[i][2])) && (jogo[i][0] != ' ')){
      printf("Vencedor %c\n",jogo[i][0]);
      flag = 0;
      return flag;
    }
  }
  // verifica se alguma coluna tem 3 iguais
  for(int i = 0;i<3;i++){    
    if(((jogo[0][i] == jogo[1][i]) && (jogo[1][i] == jogo[2][i])) && (jogo[0][i] != ' ')){
      printf("Vencedor %c\n",jogo[0][i]);
      flag = 0;
      return flag;
    }
  }
  // verifica se a diagonal tem 3 iguais
  if((((jogo[2][0] == jogo[1][1]) && (jogo[1][1] == jogo[0][2])) || ((jogo[0][0] == jogo[1][1]) && (jogo[1][1] == jogo[2][2]))) && jogo[1][1] != ' '){
    printf("Vencedor %c\n",jogo[1][1]);
    flag = 0;
    return flag;
  }
  // verifica se todos os espaços estão preenchidos
  int aux = 1;
  for(int i = 0;i<3;i++){
    for( int j = 0;j<3;j++){
      if(jogo[i][j] == ' '){
        return flag;
      }
    }
  }
  if(aux == 1){
    flag = 0;
    printf("Empate\n");
  }
  return flag;
}

void jogadausuario(char jogo[3][3]){
  int l,c;
  int flag = 0;
  while(flag == 0){
    printf("Escolha a linha que deseja jogar: ");
    scanf("%d",&l);
    l--;
    printf("Escolha a coluna que deseja jogar: ");
    scanf("%d",&c);
    c--;
    if(l>=0 && l<3 && c>=0 && c<3){
      if(jogo[l][c] == ' '){
        jogo[l][c] = 'X';
        flag = 1;
      } else {
        printf("Posição ocupada, tente outra!\n");
      }
    } else {
      printf("Posição inválida, tente outra!\n");
    }
  }
}

void jogadapc(char jogo[3][3]){
  srand((unsigned)time(NULL));
  printf("Vez do computador:\n");
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
      if(j != 2){
        printf("|");
      }
    }
    printf("\n");
    if(i != 2){
      printf("- - -\n");
    } 
  }
  printf("\n");
}

int main(void) {
  char jogo[3][3] = {"   ","   ","   "};
  printf("Quem vai começar?\n");
  char flag = getc(stdin);
  while(verifganhador(jogo)){
    if(flag == 'X'){
      jogadausuario(jogo);
      flag = 'O';
    } else{
      jogadapc(jogo);
      flag = 'X';
    }
    printjogo(jogo);
  }
}