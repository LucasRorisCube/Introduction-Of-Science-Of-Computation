#include <stdio.h>
#include<stdlib.h>
#include<time.h>
struct dados{
  char simbolo;
  int tipo;
};

int verifganhar(int n,int p,char jogo[n][n], char simbologanhando,char simbolo){
  int flag = 0;
  //verifica por linha
  for(int i = 0;i<n;i++){
    char *aux;
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<n;j++){
      if(jogo[i][j] == simbologanhando){
        count++;
      }
      if(count >= (p-1) && flag1 == 1){
        *aux = simbolo;
        printf("%c impediu %c\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
      if(jogo[i][j] == ' '){
        if(flag1 == 1){
          count = 0;
          flag1 = 0;
        } else {
          aux = &jogo[i][j];
          flag1 = 1;
        }
      }
    }
  }
  // verifica por coluna
  for(int i = 0;i<n;i++){
    int count = 0;
    int flag1 = 0;
    char *aux;
    for(int j = 0;j<n;j++){
      if(jogo[j][i] == simbologanhando){
        count++;
      }
      if(count >= (p-1) && flag1 == 1){
        *aux = simbolo;
        printf("%c impediu %c\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
      if(jogo[j][i] == ' '){
        if(flag1 == 1){
          count = 0;
          flag1 = 0;
        } else {
          aux = &jogo[j][i];
          flag1 = 1;
        }
      }
    }
  }

  // diagonal principal
  
  for(int i = 0;i<n;i++){
    char *aux;
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<i+1;j++){
      if(jogo[n-1+j-i][j] == simbologanhando){
        count++;
      }
      if(count >= (p-1) && flag1 == 1){
        *aux = simbolo;
        printf("%c impediu %c\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
      if(jogo[n-1+j-i][j] == ' '){
        if(flag1 == 1){
          count = 0;
          flag1 = 0;
        } else {
          aux = &jogo[n-1+j-i][j];
          flag1 = 1;
        }
      }
    }
    
  }
  for(int i = 0;i<n-1;i++){
    char *aux;
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<n-1-i;j++){
      if(jogo[j][i-n-1+j] == simbologanhando){
        count++;
      }
      if(count >= (p-1) && flag1 == 1){
        *aux = simbolo;
        printf("%c impediu %c\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
      if(jogo[j][i-n-1+j] == ' '){
        if(flag1 == 1){
          count = 0;
          flag1 = 0;
        }else{
          aux = &jogo[j][i-n-1+j];
          flag1 = 1;
        }
      }
    }
    
  }
//diagonal secundaria
  
  for(int i = 0;i<n;i++){
    char *aux;
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<i+1;j++){
      if(jogo[n-1-j][n-1-i+j] == simbologanhando){
        count++;
      }
      if(count >= (p-1) && flag1 == 1){
        *aux = simbolo;
        printf("%c impediu %c\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
      if(jogo[n-1-j][n-1-i+j] == ' '){
        if(flag1 == 1){
          count = 0;
          flag1 = 0;
        }else{
          aux = &jogo[n-1-j][n-1-i+j];
          flag1 = 1;
        }
      }
    }
  }
  for(int i = 0;i<n-1;i++){
    char *aux;
    int count = 0;
    int flag1 = 0;
    for(int j = 0;j<n-1-i;j++){
      if(jogo[n-i-2-j][j] == simbologanhando){
        count++;
      }
      if(count >= (p-1) && flag1 == 1){
        *aux = simbolo;
        printf("%c impediu %c\n",simbolo,simbologanhando);
        flag = 1;
        return flag;
      }
      if(jogo[n-i-2-j][j] == ' '){
        if(flag1 == 1){
          count = 0;
          flag1 = 0;
        }else{
          aux = &jogo[n-i-2-j][j];
          flag1 = 1;
        }
      }
    }
  }

  return flag;
}
////////////////////////////////
 int verifganhador(int n,int p,char jogo[n][n],char simbolo){
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
      if(count == p){
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
      if(jogo[j][i-n-1+j] == simbolo){
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





///////////////////////////
void jogadapc(int m,int p,struct dados jogador[m],char simbolo,int n,char jogo[n][n]){ // em andamento
printf("%c vai jogar\n",simbolo);
  srand((unsigned)time(NULL));
  int l,c;
  int flag = 0;if(verifganhar(n,p,jogo,simbolo,simbolo) == 1){
      return;
    }
  for(int i = 0;i<m;i++){
    if(verifganhar(n,p,jogo,jogador[i].simbolo,simbolo) == 1){
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


void jogadausuario(char simbolo,int n,char jogo[n][n]){  //CONCLUIDO
  int l,c;
  int flag = 0;
  while(flag == 0){
    printf("Escola a posi????o desejada %c\n",simbolo);
    scanf("%d",&l);
    scanf("%d",&c);
    if(jogo[l][c] == ' '){
      jogo[l][c] = simbolo;
      flag = 1;
    } else {
      printf("Posi????o ocupada, tente outra!\n");
    }
  }
}



int main(void) {
  int n;
  printf("Digite a dimens??o do tabuleiro: ");
  scanf("%d",&n);
  int p;
  printf("Digite o numero de sibolos iguais necessario para ganhar: ");
  scanf("%d",&p);;
  int m;
  printf("Digite o numero de jogadores: ");
  scanf("%d",&m);
  struct dados jogador[m];
  for(int i = 0;i<m;i++){
    printf("Digite o simbolo do %d jogador: ",i+1);
    char s[5];
    setbuf (stdin,NULL);
    fgets(s,5,stdin);
    jogador[i].simbolo = s[0];
    printf("%s",s);
    printf("Qual o tipo do jogador? 1 para usuario e 0 para computador\n");
    scanf("%d",&jogador[i].tipo); // tipo 0 = computador, tipo 1 = usu??rio
  }
  char jogo[n][n];
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      jogo[i][j] = ' ';
    }
  }

  int i = 0;
  int flag = 0;
  while(flag == 0){
    
    if(jogador[i].tipo == 1){
      jogadausuario(jogador[i].simbolo,n,jogo); //CONCLUIDO
    } else {
      jogadapc(m,p,jogador,jogador[i].simbolo,n,jogo);
    }
    printjogo(n,jogo); // CONCLUIDO
    if(verifganhador(n,p,jogo,jogador[i].simbolo) == 0){
      flag = 1;
    }
    i++;
    if(i == m){
      i = 0;
    }
  }
}