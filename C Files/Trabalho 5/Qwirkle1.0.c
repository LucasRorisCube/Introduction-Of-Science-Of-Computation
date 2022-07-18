#include <stdio.h>
#include <stdlib.h>

void InicializarTabuleiro(char ***Tabuleiro){
  for(int i = 0;i<36;i++){
    for(int j = 0;j<36;j++){
      Tabuleiro[i][j] = "oi\0";
    }
  }
}

void LiberarMemoria(char **Jogadores,int Njogadores,char ***Tabuleiro){
  for(int i = 0;i<Njogadores;i++){
    free(Jogadores[i]);
  }
  free(Jogadores);
  for(int i = 0;i<36;i++){
    for(int j = 0;j<36;j++){
      //printf("%s\n",Tabuleiro[i][j]);
      //free(Tabuleiro[i][j]);
    }
    free(Tabuleiro[i]);
  }
  free(Tabuleiro);
}

void PrintarTabuleiro(char ***Tabuleiro,int Altura[2],int Largura[2]){
  printf("   ");
  for(int i = Largura[0];i<=Largura[1];i++){
    printf("%d ",i);
  }
  printf("   \n");
  for(int i = Altura[0];i<=Altura[1];i++){
    printf("%d ",i);
    for(int j = Largura[0];j<=Largura[1];j++){
      printf("|%s|",Tabuleiro[i+18][j+18]);
    }
    printf(" %d\n",i);
  }
  printf("   ");
  for(int i = Largura[0];i<=Largura[1];i++){
    printf("%d ",i);
  }
  printf("   \n");
}

int main(void) {
  int Njogadores;
  printf("Numero de jogadores: ");
  scanf("%d",&Njogadores);
  char **Jogadores;
  Jogadores = (char **)malloc(sizeof(char*)*Njogadores);
  if(Jogadores == NULL){
    printf("Erro de alocaçao!!\n");
    exit(0);
  }
  for(int i = 0;i<Njogadores;i++){
    Jogadores[i] = (char *)malloc(sizeof(char)*20);
    if(Jogadores[i] == NULL){
      printf("Erro de alocaçao!!\n");
      exit(0);
    }
  }
  for(int i = 0;i<Njogadores;i++){
    printf("Jogador %d: ",i+1);
    setbuf(stdin,NULL);
    fgets(Jogadores[i],20,stdin);
  }
  printf("Cheat Mode S/N: ");
  getchar();
  int Altura[2] = {0,2};
  int Largura[2] = {0,2};


  char ***Tabuleiro = NULL;
  Tabuleiro = (char ***)malloc(sizeof(char **)*36);
  if(Tabuleiro == NULL){
    printf("Erro de alocaçao principal!!\n");
    exit(0);
  }
  for(int i = 0;i<36;i++){
    Tabuleiro[i] = (char **)malloc(sizeof(char*)*36);
    if(Tabuleiro[i] == NULL){
      printf("Erro de alocaçao secundario %d!!\n",i);
      exit(0);
    }
  }
  for(int i = 0;i<36;i++){
    for(int j = 0;j<36;j++){
      Tabuleiro[i][j] = (char *)malloc(sizeof(char)*3);
      if(Tabuleiro[i][j] == NULL){
        printf("Erro de alocaçao teciario %d!!\n",i);
        exit(0);
      }
    }
  }

  InicializarTabuleiro(Tabuleiro);
  PrintarTabuleiro(Tabuleiro,Altura,Largura);



  LiberarMemoria(Jogadores,Njogadores,Tabuleiro);
}