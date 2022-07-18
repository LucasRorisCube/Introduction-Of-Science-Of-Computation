#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int verifganhar(int n,int p,char jogo[n][n], char simbologanhando,char simbolo){
  int flag = 0;
  //verifica por linha
  for(int i = 0;i<n;i++){
    int count = 0;
    for(int j = 0;j<n;j++){
      if(jogo[i][j] == simbologanhando){
        count++;
      } 
    }
    if(count == (p-1)){
      for(int k = 0;k<n;k++){
        if(jogo[i][k] == ' '){
          jogo[i][k] = simbolo;
          flag = 1;
          return flag;
        }
      }
    }
  }
  // verifica por coluna
  for(int i = 0;i<n;i++){
    int count = 0;
    for(int j = 0;j<n;j++){
      if(jogo[j][i] == simbologanhando){
        count++;
      } 
    }
    if(count == (p-1)){
      for(int k = 0;k<n;k++){
        if(jogo[k][i] == ' '){
          jogo[k][i] = simbolo;
          flag = 1;
          return flag;
        }
      }
    }
  }

  // diagonal principal
  int count = 0;
  char *aux;
  for(int i = 0;i<n;i++){
    count = 0;
    for(int j = 0;j<i+1;j++){
      if(jogo[n-1+j-i][j] == simbologanhando){
        count++;
      }
      if(jogo[n-1+j-i][j] == ' '){
        aux = &jogo[n-1+j-i][j];
      }
    }
    if(count == (p-1)){
        *aux = simbolo;
        flag = 1;
        return flag;
      }
  }
  for(int i = 0;i<n-1;i++){
    for(int j = 0;j<n-1-i;j++){
      if(jogo[j][i-n-1+j] == simbologanhando){
        count++;
      }
      if(jogo[j][i-n-1+j] == ' '){
        aux = &jogo[j][i-n-1+j];
      }
    }
    if(count == (p-1)){
        *aux = simbolo;
        flag = 1;
        return flag;
      }
  }
//diagonal secundaria
  
  char *aux1;
  for(int i = 0;i<n;i++){
    count = 0;
    for(int j = 0;j<i+1;j++){
      if(jogo[n-1-j][n-1-i+j] == simbologanhando){
        count++;
      }
      if(jogo[n-1-j][n-1-i+j] == ' '){
        aux1 = &jogo[n-1-j][n-1-i+j];
      }
    }
    if(count == (p-1)){
      *aux1 = simbolo;
      flag = 1;
      return flag;
    }
  }
  for(int i = 0;i<n-1;i++){
    for(int j = 0;j<n-1-i;j++){
      if(jogo[n-i-2-j][j] == simbologanhando){
        count++;
      }
      if(jogo[n-i-2-j][j] == ' '){
        aux1 = &jogo[n-i-2-j][j];
      }
    }
    if(count == (p-1)){
      *aux1 = simbolo;
      flag = 1;
      return flag;

    }
  }

  return flag;
}

void jogadapc(char simbolo,int n,char jogo[3][3]){ // em andamento
  srand((unsigned)time(NULL));
  int l,c;
  int flag = 0;
  if(verifganhar(jogo,'O') == 0){
    if(verifganhar(jogo,'X') == 0){
      while(flag == 0){
        l = rand()%3;
        c = rand()%3;
        if(jogo[l][c] == ' '){
          jogo[l][c] = 'O';
          flag = 1;
        }
      }
    }
  }
}

void printjogo(int n,char jogo[n][n]){ // CONCLUIDO
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      printf("%c",jogo[i][j]);
      if(j != n-1){
        printf("|");
      }
    }
    printf("\n");
    if(i != n-1){
      printf("- - -\n");
    } 
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
      printf("Vencedor %c\n",jogo[0][i]);
      flag = 0;
    }
  }
  // verifica se a diagonal tem 3 iguais
  if((((jogo[2][0] == jogo[1][1]) && (jogo[1][1] == jogo[0][2])) || ((jogo[0][0] == jogo[1][1]) && (jogo[1][1] == jogo[2][2]))) && jogo[1][1] != ' '){
    printf("Vencedor %c\n",jogo[1][1]);
    flag = 0;
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

void jogadausuario(char simbolo,int n,char jogo[n][n]){  //CONCLUIDO
  int l,c;
  int flag = 0;
  while(flag == 0){
    scanf("%d",&l);
    scanf("%d",&c);
    if(jogo[l][c] == ' '){
      jogo[l][c] = simbolo;
      flag = 1;
    } else {
      printf("Posição ocupada, tente outra!\n");
    }
  }
}


struct dados{
  char simbolo;
  int tipo;
};

int main(void) {
  int n;
  scanf("%d",&n);
  int p;
  scanf("%d",&p);
  int m;
  scanf("%d",&m);
  struct dados jogador[m];
  for(int i = 0;i<m;i++){
    scanf("%c",&jogador[i].simbolo);
    scanf("%d",&jogador[m].tipo); // tipo 0 = computador, tipo 1 = usuário
  }

  char jogo[n][n];
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      jogo[i][j] = ' ';
    }
  }

  int i = 0;
  while(verifganhador(jogo)){
    if(jogador[i].tipo == 1){
      jogadausuario(jogador[0].simbolo,n,jogo); //CONCLUIDO
    } else {
      jogadapc(jogo);
    }
    printjogo(n,jogo); // CONCLUIDO
    i++;
    if(i == m){
      i = 0;
    }
  }
}