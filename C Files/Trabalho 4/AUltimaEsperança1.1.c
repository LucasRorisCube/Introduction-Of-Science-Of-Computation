#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMNOME 40

typedef struct{
  char nick[TAMNOME];
  char NomeArquivo[TAMNOME];
  FILE *Ausuario;
  char nome[TAMNOME];
  int NPosts;
  char **Posts;
  int NSeguindo;
  char *Seguindo[TAMNOME];
  int NSeguidores;
  char *Seguidores[TAMNOME];
}dados;

int main(void) {
  FILE *usuarios = fopen("usuarios.dat","a+");
  fseek(usuarios,0,SEEK_END);
  int f = ftell(usuarios);
  int t = f/(sizeof(char)*TAMNOME*2);
  printf("%d",t);
  dados usuario[50];
  usuario[0].Posts = (char **)malloc(sizeof(char *)*5);
    if(usuario[0].Posts == NULL){
      printf("Erro de alocamento no principal\n");
    }
    for(int i = 0;i<2;i++){
      usuario[0].Posts[i] = (char *)malloc(sizeof(char)*130);
      if(usuario[0].Posts[i] == NULL){
        printf("Erro de alocamento no %d\n",i);
      }
    }
  fseek(usuarios,0,SEEK_SET);
  for(int i = 0;i<t;i++){
    fread(usuario[i].nick,sizeof(char)*TAMNOME,1,usuarios);
    fread(usuario[i].NomeArquivo,sizeof(char)*TAMNOME,1,usuarios);
    usuario[i].Ausuario = fopen(usuario[i].NomeArquivo,"a+");
  }
  for(int i = 0;i<t;i++){
    //fseek(usuario[i].Ausuario,sizeof(char)*TAMNOME,SEEK_SET);
    //fseek(usuario[i].Ausuario,sizeof(char)*TAMNOME,SEEK_SET);
    //fseek(usuario[i].Ausuario,sizeof(FILE),SEEK_SET);
    fread(&usuario[i].nome,sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    printf("%s\n",usuario[i].nome);
    fread(&usuario[i].NPosts,sizeof(int),1,usuario[i].Ausuario);
    printf("%d\n",usuario[i].NPosts);
    for(int j = 0;j<usuario[i].NPosts;j++){
      fread(&usuario[i].Posts[j],sizeof(char)*130,1,usuario[i].Ausuario);
      printf("%s\n",usuario[i].Posts[j]);
    }
    fread(&usuario[i].NSeguindo,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      fread(&usuario[i].Seguindo[j],sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    }
    fread(&usuario[i].NSeguidores,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      fread(&usuario[i].Seguidores[j],sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    }
  }
  printf("passei\n");
    
  //PROCESSAMENTO
  int x;
  printf("Digite a opcao: ");
  scanf("%d",&x);
  switch(x){
    case 1:
      printf("DIgite um nome: ");
      setbuf(stdin,NULL);
      fgets(usuario[0].nome,40,stdin);
      setbuf(stdin,NULL);
      fgets(usuario[0].nick,40,stdin);
      strcpy(usuario[0].NomeArquivo,usuario[0].nick);
      int i = 0;
      while(usuario[0].NomeArquivo[i++] != '\0');
      usuario[0].NomeArquivo[i-2] = '.';
      usuario[0].NomeArquivo[i-1] = 'd';
      usuario[0].NomeArquivo[i] = 'a';
      usuario[0].NomeArquivo[i+1] = 't';
      usuario[0].NomeArquivo[i+2] = '\0';
      usuario[0].Ausuario = fopen(usuario[0].NomeArquivo,"a+");
      usuario[0].NPosts = 2;
      usuario[0].Posts[0] = "acaba logo\n";
      usuario[0].Posts[1] = "quatentena\n";
      usuario[0].NSeguindo = 2;
      usuario[0].Seguindo[0] = "Isabella";
      usuario[0].Seguindo[1] = "Roma";
      usuario[0].NSeguidores = 2;
      usuario[0].Seguidores[0] = "Ades";
      usuario[0].Seguidores[1] = "Jorge";
      fwrite(usuario[0].nick,sizeof(char)*TAMNOME,1,usuarios);
      fwrite(usuario[0].NomeArquivo,sizeof(char)*TAMNOME,1,usuarios);
      break;
    case 2:
      printf("%s",usuario[0].nick);
      printf("%s",usuario[0].NomeArquivo);
      printf("%s\n",usuario[0].nome);
      printf("%d\n",usuario[0].NPosts);
      for(int i = 0;i<usuario[0].NPosts;i++){
        printf("%s\n",usuario[0].Posts[i]);
      }
      printf("%d\n",usuario[0].NSeguindo);
      for(int i = 0;i<usuario[0].NSeguindo;i++){
        printf("%s\n",usuario[0].Seguindo[i]);
      }
      printf("%d\n",usuario[0].NSeguidores);
      for(int i = 0;i<usuario[0].NSeguidores;i++){
        printf("%s\n",usuario[0].Seguidores[i]);
      }
      break;
  }






  //FINAL
  fseek(usuario[0].Ausuario,0,SEEK_SET);
  fwrite(&usuario[0].nome,sizeof(char)*TAMNOME,1,usuario[0].Ausuario);
    fwrite(&usuario[0].NPosts,sizeof(int),1,usuario[0].Ausuario);
    for(int j = 0;j<usuario[0].NPosts;j++){
      fwrite(&usuario[0].Posts[j],sizeof(char)*130,1,usuario[0].Ausuario);
    }
    fwrite(&usuario[0].NSeguindo,sizeof(int),1,usuario[0].Ausuario);
    for(int j = 0;j<usuario[0].NSeguindo;j++){
      fwrite(&usuario[0].Seguindo[j],sizeof(char)*TAMNOME,1,usuario[0].Ausuario);
    }
    fwrite(&usuario[0].NSeguidores,sizeof(int),1,usuario[0].Ausuario);
    for(int j = 0;j<usuario[0].NSeguidores;j++){
      fwrite(&usuario[0].Seguidores[j],sizeof(char)*TAMNOME,1,usuario[0].Ausuario);
    }
  fclose(usuarios);
  fclose(usuario[0].Ausuario);
}