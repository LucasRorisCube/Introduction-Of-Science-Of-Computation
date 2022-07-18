#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include"jogadas.h"
#include"tabuleiro.h"
#include"inteligencia.h"

struct dados{
  char simbolo;
  int tipo;
};

void jogadapc(int m,int p,struct dados jogador[m],int i,char simbolo,int n,char **jogo){ // em andamento
printf("%c vai jogar\n",simbolo);
  srand((unsigned)time(NULL));
  int l,c;
  int flag = 0;
  for(int j = i;i<m;i++){
    if(verifganhar(n,p,jogo,jogador[j].simbolo,simbolo) == 1){ // verifica se alguem depois dele pode ganhar
      return;
    }
  }
  for(int k = 0;k<i;k++){
    if(verifganhar(n,p,jogo,jogador[k].simbolo,simbolo) == 1){// termina de verificar se alguem pode ganhar
      return;
    }
  }
  printf("Jogada aleatoria\n");
  while(flag == 0){
    l = rand()%n;
    c = rand()%n;
    if(jogo[l][c] == ' '){
      jogo[l][c] = simbolo;
      flag = 1;
    }
  }
}

int main(void) {
  int u = 2;
  int n,p,m;
  char **jogo;
  while(u == 2){
    int aux = 0;
    while(aux == 0){
      printf("Digite a dimensão do tabuleiro: ");
      scanf("%d",&n);
      printf("Digite o numero de simbolos iguais necessario para ganhar: ");
      scanf("%d",&p);
      if(p<=n){
        aux = 1;
      } else {
        printf("Configuracoes invalidas, escreva de novo\n");
      }
    }
    printf("Digite o numero de jogadores: ");
    scanf("%d",&m);

    struct dados jogador[m];

    for(int i = 0;i<m;i++){
      printf("Digite o simbolo do %d jogador: ",i+1);
      char s[5];
      setbuf (stdin,NULL);
      fgets(s,5,stdin);
      jogador[i].simbolo = s[0];
      printf("%c\n",s[0]);
      printf("Qual o tipo do jogador? 1 para usuario e 0 para computador\n");
      scanf("%d",&jogador[i].tipo); // tipo 0 = computador, tipo 1 = usuário
    }
    jogo = (char **)malloc(sizeof(char *)*n);
    if(jogo == NULL){
      printf("Erro de alocamento no principal\n");
    }
    for(int i = 0;i<n;i++){
      jogo[i] = (char *)malloc(sizeof(char)*n);
      if(jogo[i] == NULL){
        printf("Erro de alocamento no %d\n",i);
      }
    }
    u = 1;
    while(u == 1){
      for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
          jogo[i][j] = ' ';
        }
      }

      int i = 0;
      int flag = 0;
      while(flag == 0){// se for 0 o jogo não acabou
        
        if(jogador[i].tipo == 1){ // se for um usuario
          jogadausuario(jogador[i].simbolo,n,jogo);
        } else { // se for um computador
          jogadapc(m,p,jogador,i,jogador[i].simbolo,n,jogo);
        }
        printjogo(n,jogo);
        if(verifganhador(n,p,jogo,jogador[i].simbolo) == 0){ //se o jogo acabou
          flag = 1;
        }
        i++;
        if(i == m){
          i = 0;
        }
      }
      printf("\nQuer começar de novo?\n0 - terminar\n1 - jogar com as mesmas configuracoes\n2 - comecar do zero\n");
      scanf("%d",&u);
    }
  }
  printf("Obrigado por jogar!\n");
  for(int i = 0;i<n;i++){ // libera a memoria alocada
    free(jogo[i]);
  }
  free(jogo);
}

