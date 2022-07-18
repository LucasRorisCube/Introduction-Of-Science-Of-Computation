#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Struct.h"
#include "Alocacao.h"
#include "Tabuleiro.h"
#include "Jogo.h"

#define reset "\e[0m"


int main(void) {
  srand((unsigned)time(NULL));
  system("clear||clr");
  int Njogadores;
  printf("Numero de jogadores: ");
  scanf("%d",&Njogadores);

  dados *Jogador;

  Jogador = (dados *)malloc(sizeof(dados)*Njogadores);
  VerifAlocacaoPDados(Jogador);

  for(int i = 0;i<Njogadores;i++){
    printf("Jogador %d: ",i+1);
    setbuf(stdin,NULL);
    fgets(Jogador[i].nome,20,stdin);
    Jogador[i].pontos = 0;
    Jogador[i].qpecas = 0;
  }
  printf("Cheat Mode S/N: ");
  int cheat = 0;
  if(getchar() == 'S'){
    printf("Voce ativou o modo cheat!\n");
    cheat = 1;
  }
  while(getchar() != '\n');
  int Altura[2] = {0,0};
  int Largura[2] = {0,0};
  int *tam = NULL;
  tam = (int *)realloc(tam,sizeof(int));
  *tam = 0;

  peca **Tabuleiro = NULL;
  Tabuleiro = AtualizarTabuleiro(Tabuleiro,tam,(*tam+10));
  *tam = *tam + 10;
  PrintarTabuleiro(Tabuleiro,tam,Altura,Largura);
  
  peca **PecasRestantes;
  PecasRestantes = (peca **)malloc(sizeof(peca *)*18);
  VerifAlocacaoPPTab(PecasRestantes);
  for(int i = 0;i<18;i++){
    PecasRestantes[i] = (peca *)malloc(sizeof(peca)*6);
    VerifAlocacaoPTab(PecasRestantes[i]);
  }

  InicializarPecasRestantes(PecasRestantes);

  int *qPecasRestantes;
  qPecasRestantes = (int *)malloc(sizeof(int));
  *qPecasRestantes = 108;

  for(int i = 0;i<Njogadores;i++){
    SortearPecas(Jogador,i,PecasRestantes,qPecasRestantes);
  }

  int *Ptemp = (int *)malloc(sizeof(int));
  while(*qPecasRestantes != 0){
    for(int i = 0;i<Njogadores;i++){
      SortearPecas(Jogador,i,PecasRestantes,qPecasRestantes);
      int flag = 0;
      int jogadas = 1;
      int possibilidades[4] = {100,0,0,0};
      *Ptemp = 0;
      while(flag == 0){
        printf("Jogada de %s",Jogador[i].nome);
        printf("Pecas disponiveis : ");
        for(int j = 0;j<Jogador[i].qpecas;j++){
          DefinirCor(Jogador[i].pecas[j]);
          printf("%c%c",Jogador[i].pecas[j].letra,Jogador[i].pecas[j].numero);
          printf("%s ",reset);
        }

        int ok = 1;
        while(ok == 1){
          if(jogadas > 1){
            printf("\nOpcoes : jogar, passar\n");
          } else {
            printf("\nOpcoes : jogar, trocar, passar\n");
          }
          char jogada[30];
          //int b = 0;
          setbuf(stdin,NULL);
          fgets(jogada, 30 , stdin);
          if(jogada[0] == 'j'){
            Tabuleiro = Jogada(Jogador,i,Tabuleiro,tam,Largura,Altura,cheat,possibilidades,Ptemp,jogada);
            ok = 0;
            jogadas++;
          }
          else if(jogada[0] == 't'){
            if(jogadas == 1){
              TrocarPeca(Jogador,i,PecasRestantes,qPecasRestantes,jogada);
              flag = 1;
              ok = 0;
            } else {
              printf("Voce nao pode trocar mais suas pecas!\n");
            }
            
          }
          else if(strcmp(jogada,"passar\n") == 0){
            flag = 1;
            ok = 0;
          }
          else{
            printf("Escolha invalida!\nVoce digitou:%s",jogada);
            //ok = 0;
          }
        }
        PrintarTabuleiro(Tabuleiro,tam,Altura,Largura);
        
      }
      Jogador[i].pontos += *Ptemp;
      printf("Pontuacao = %d\nPontuacao acumulada = %d\n",*Ptemp,Jogador[i].pontos);
    }
  }

  LiberarMemoria(Jogador,Njogadores,Tabuleiro,tam,PecasRestantes,qPecasRestantes,Ptemp);
}