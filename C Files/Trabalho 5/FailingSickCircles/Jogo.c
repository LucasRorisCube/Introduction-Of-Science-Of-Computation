#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct.h"
#include "Tabuleiro.h"
#include "MoviValido.h"
#include <time.h>

int AuxPontuacao(peca **Tabuleiro,int x,int auxX,int y,int auxY,int *Ptemp){
  int count = 0;
  if(Tabuleiro[x+auxX][y+auxY].letra >= 'A' && Tabuleiro[x+auxX][y+auxY].letra <= 'Z'){
    int i = 0;
    int j = 0;
    while(Tabuleiro[x+i][y+j].letra >= 'A' && Tabuleiro[x+i][y].letra <= 'Z'){
      count++;
      if(auxX>0){
        i++;
      }
      if(auxX<0){
        i--;
      }
      if(auxY>0){
        j++;
      }
      if(auxY<0){
        j--;
      }
    }
    if(count == 6){
      count += 6;
    }
    *Ptemp += count;
  } else {
    return 1;
  }
  return 0;
}

void Pontuacao(peca **Tabuleiro,int x, int y,int *Ptemp){
  *Ptemp = 0;
  int count = 0;
  count += AuxPontuacao(Tabuleiro,x,1,y,0,Ptemp);
  count += AuxPontuacao(Tabuleiro,x,-1,y,0,Ptemp);
  count += AuxPontuacao(Tabuleiro,x,0,y,1,Ptemp);
  count += AuxPontuacao(Tabuleiro,x,0,y,-1,Ptemp);
  if(count == 4){
    *Ptemp = *Ptemp + 1;
  }
}

void SortearPecas(dados *Jogador,int r,peca **PecasRestantes,int *qPecasRestantes){
  while(Jogador[r].qpecas < 6 && *qPecasRestantes != 0){
    char aux1 = 'A' + rand()%6;
    char aux2 = '1' + rand()%6;
    int flag = 0;
    for(int i = 0;i<18;i++){
      for(int j = 0;j<6;j++){
        if(PecasRestantes[i][j].letra == aux1 && PecasRestantes[i][j].numero == aux2){
          PecasRestantes[i][j].letra = '0';
          PecasRestantes[i][j].numero = '0';
          *qPecasRestantes = *qPecasRestantes - 1;
          Jogador[r].pecas[Jogador[r].qpecas].letra = aux1;
          Jogador[r].pecas[Jogador[r].qpecas].numero = aux2;
          Jogador[r].qpecas = Jogador[r].qpecas + 1;
          flag = 1;
          break;
        }
      }
      if(flag == 1){
        break;
      }
    }
  }
  if(*qPecasRestantes == 0){
    printf("Nao ha mais pecas para sortear!\n");
  }
}

void InicializarPecasRestantes(peca **PecasRestantes){
  for(int i = 0;i<6;i++){
    for(int k = 0;k<3;k++){
      for(int j = 0;j<6;j++){
        PecasRestantes[j+(6*k)][i].letra = 'A'+ j;
        PecasRestantes[j+(6*k)][i].numero = '1'+i;
      }
    }
  }
}

void PrintPecasRestantes(peca **PecasRestantes){
  for(int i = 0;i<18;i++){
    for(int j = 0;j<6;j++){
      printf("%c%c ",PecasRestantes[i][j].letra,PecasRestantes[i][j].numero);
    }
    printf("\n");
  }
  printf("\n");
}

void TrocarPeca(dados *Jogador,int r,peca **PecasRestantes,int *qPecasRestantes){
  //printf("Digite a peca a ser trocada: ");
  int num = 0;
  int flag = 0;
  int PecaTrocada[6];
  do{
    
    setbuf(stdin,NULL);
    char pecas[6][3];
    int p = 0;
    int a = 0;
    while(a==0){
      setbuf(stdin,NULL);
      fgets(pecas[p],3,stdin);
      if(getchar() == '\n'){a=1;}
      p++;
      
    }
    for(int j = 0; j<p ; j++){
      if(pecas[j][0] >= 'A' && pecas[j][0] <= 'F' && pecas[j][1] >= '1' && pecas[j][1] <= '6'){
        for(int i = 0;i<Jogador[r].qpecas;i++){
          if(pecas[j][0] == Jogador[r].pecas[i].letra && pecas[j][1] == Jogador[r].pecas[i].numero){
            flag = 1;
            PecaTrocada[j] = i;
            num++;
            break;
          }
        }
        if(flag == 0){
          printf("Voce nao possui essa peca,tente outra!\n");
        }
      } else {
        printf("Peca invalida, tente outra!\n");
      }
    }
    while(getchar() != '\n');
  }while(flag != 1);

  flag = 0;
  for(int i = 0;i<18;i++){
      for(int j = 0;j<6;j++){
        for(int k = 0 ; k<num; k++){
          if(PecasRestantes[i][j].letra == '0' && PecasRestantes[i][j].numero == '0'){
            PecasRestantes[i][j].letra = Jogador[r].pecas[PecaTrocada[k]].letra;
            PecasRestantes[i][j].numero = Jogador[r].pecas[PecaTrocada[k]].numero;
            flag = 1;
            break;
          }
        }
      }
      if(flag == 1){
        break;
      }
    }

  for(int j = 0; j<num; j++){
    for(int i = PecaTrocada[j];i<Jogador[r].qpecas-1;i++){
      Jogador[r].pecas[i] = Jogador[r].pecas[i+1];
    }
  }
  Jogador[r].qpecas = Jogador[r].qpecas - 1;
  SortearPecas(Jogador,r,PecasRestantes,qPecasRestantes);
  
}

peca **Jogada(dados *Jogador,int r,peca **Tabuleiro,int *tam,int Largura[2],int Altura[2],int cheat,int possibilidades[4],int *Ptemp){
  printf("Digite a peca que deseja jogar: ");
  int flag = 0;
  int PecaJogada;
  do{
    setbuf(stdin,NULL);
    char peca[3];
    fgets(peca,3,stdin);
    if(peca[0] >= 'A' && peca[0] <= 'F' && peca[1] >= '1' && peca[1] <= '6'){
      for(int i = 0;i<Jogador[r].qpecas;i++){
        if(peca[0] == Jogador[r].pecas[i].letra && peca[1] == Jogador[r].pecas[i].numero){
          flag = 1;
          PecaJogada = i;
          break;
        }
      }
      if(cheat == 1){
        Jogador[r].pecas[5].letra = peca[0];
        Jogador[r].pecas[5].numero = peca[1];
        PecaJogada = 5;
        flag = 1;
      }
      if(flag == 0){
        printf("Voce nao possui essa peca,tente outra!\n");
      }
    } else {
      printf("Peca invalida, tente outra!\n");
    }
    while(getchar() != '\n');
  }while(flag != 1);
  printf("Digite em qual posicao deseja jogar (fomato x y): ");
  int x,y;
  scanf("%d %d",&x,&y);

  if(Altura[1]+1 >= (*tam/2) ||Altura[0]+1 <= -1*(*tam/2) || Largura[1]+1 >= (*tam/2) ||Largura[0]+1 <= -1*(*tam/2)){
    Tabuleiro = AtualizarTabuleiro(Tabuleiro,tam,(*tam+10));
    possibilidades[0] = possibilidades[0] + 5;
    possibilidades[1] = possibilidades[1] + 5;
    possibilidades[2] = possibilidades[2] + 5;
    possibilidades[3] = possibilidades[3] + 5;
    *tam = *tam + 10;
  }

  if(MovimentoValido(Tabuleiro,Jogador[r].pecas[PecaJogada],x+(*tam/2),y+(*tam/2),0,tam,possibilidades) == 1){
    
    if(y <= Largura[0]){
      Largura[0] = y-1;
    }
    if(y >= Largura[1]){
      Largura[1] = y+1;
    }
    if(x <= Altura[0]){
      Altura[0] = x-1;
    }
    if(x >= Altura[1]){
      Altura[1] = x+1;
    }

    Tabuleiro[x+(*tam/2)][y+(*tam/2)].letra = Jogador[r].pecas[PecaJogada].letra;
    Tabuleiro[x+(*tam/2)][y+(*tam/2)].numero = Jogador[r].pecas[PecaJogada].numero;

    for(int i = PecaJogada;i<Jogador[r].qpecas-1;i++){
      Jogador[r].pecas[i] = Jogador[r].pecas[i+1];
    }
    if(cheat == 0){
      Jogador[r].qpecas = Jogador[r].qpecas - 1;
    }
    Pontuacao(Tabuleiro,x+(*tam/2),y+(*tam/2),Ptemp);
  } else {
    printf("=================\nMovimento invalido!\n=================\n");
  }
  return Tabuleiro;
}
