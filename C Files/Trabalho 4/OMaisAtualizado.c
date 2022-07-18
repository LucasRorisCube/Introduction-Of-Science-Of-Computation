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
  char **Seguindo;
  int NSeguidores;
  char **Seguidores;
}dados;

int NumUsuarios(FILE *usuarios){
  int c = ftell(usuarios);
  int f,t;
  fseek(usuarios,0,SEEK_END);
  f = ftell(usuarios);
  t = f/(sizeof(char)*TAMNOME*2);
  fseek(usuarios,c,SEEK_SET);
  return t;
}

int main(void) {
  FILE *usuarios = fopen("usuarios.dat","a+");
  int t = NumUsuarios(usuarios);
  dados *usuario;
  usuario = (dados *)malloc(sizeof(dados)*50);
  
  fseek(usuarios,0,SEEK_SET);
  for(int i = 0;i<t;i++){
    fread(usuario[i].nick,sizeof(char)*TAMNOME,1,usuarios);
    fread(usuario[i].NomeArquivo,sizeof(char)*TAMNOME,1,usuarios);
    usuario[i].Ausuario = fopen(usuario[i].NomeArquivo,"a+");
  }
  for(int i = 0;i<t;i++){
    fread(&usuario[i].nome,sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    printf("Recebi %s",usuario[i].nome);
    fread(&usuario[i].NPosts,sizeof(int),1,usuario[i].Ausuario);
    printf("Recebi %d\n",usuario[i].NPosts);
    usuario[i].Posts = (char **)malloc(sizeof(char*)*5);
    if(usuario[i].Posts == NULL){
      printf("Erro de alocamento no Posts\n");
    }
    for(int j = 0;j<usuario[i].NPosts;j++){
      usuario[i].Posts[j] = (char *)malloc(sizeof(char)*130);
      printf("aloquei\n");
      if(usuario[i].Posts == NULL){
        printf("Erro de alocamento no Post %d\n",j);
      }
    }

    for(int j = 0;j<usuario[i].NPosts;j++){
      fread(&usuario[i].Posts[j],sizeof(char)*130,1,usuario[i].Ausuario);
      printf("Recebi %s",usuario[i].Posts[j]);
    }
    fread(&usuario[i].NSeguindo,sizeof(int),1,usuario[i].Ausuario);

    usuario[i].Seguindo = (char **)malloc(sizeof(char*)*5);
    if(usuario[i].Seguindo == NULL){
      printf("Erro de alocamento no Seguindo\n");
    }
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      usuario[i].Seguindo[j] = (char *)malloc(sizeof(char)*TAMNOME);
      if(usuario[i].Seguindo == NULL){
        printf("Erro de alocamento no Seguindo %d\n",j);
      }
    }

    for(int j = 0;j<usuario[i].NSeguindo;j++){
      fread(&usuario[i].Seguindo[j],sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    }
    fread(&usuario[i].NSeguidores,sizeof(int),1,usuario[i].Ausuario);

    usuario[i].Seguidores = (char **)malloc(sizeof(char*)*5);
    if(usuario[i].Seguidores == NULL){
      printf("Erro de alocamento no Seguidores\n");
    }
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      usuario[i].Seguidores[j] = (char *)malloc(sizeof(char)*TAMNOME);
      if(usuario[i].Seguidores[j] == NULL){
        printf("Erro de alocamento no Seguidores %d\n",j);
      }
    }
    
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      fread(&usuario[i].Seguidores[j],sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    }
  }
    
  //PROCESSAMENTO
  int x;
  printf("Digite a opcao: ");
  scanf("%d",&x);
  
  switch(x){
    case 1:
      printf("Digite um nome: ");
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
      fwrite(usuario[0].nick,sizeof(char)*TAMNOME,1,usuarios);
      fwrite(usuario[0].NomeArquivo,sizeof(char)*TAMNOME,1,usuarios);
      break;
    case 2:
      printf("%s",usuario[0].nick);
      printf("%s\n",usuario[0].NomeArquivo);
      printf("%s",usuario[0].nome);
      printf("%d\n",usuario[0].NPosts);
      for(int i = 0;i<usuario[0].NPosts;i++){
        printf("%s",usuario[0].Posts[i]);
      }
      printf("%d\n",usuario[0].NSeguindo);
      for(int i = 0;i<usuario[0].NSeguindo;i++){
        printf("%s",usuario[0].Seguindo[i]);
      }
      printf("%d\n",usuario[0].NSeguidores);
      for(int i = 0;i<usuario[0].NSeguidores;i++){
        printf("%s",usuario[0].Seguidores[i]);
      }
      break;
    case 3:
      //usuario[0].Posts = (char **)malloc(sizeof(char*)*5);
      //if(usuario[0].Posts == NULL){
      //  printf("Erro de alocamento no principal\n");
      //}
      printf("%d\n",usuario[0].NPosts);
      for(int j = 0;j<(usuario[0].NPosts)+1;j++){
        printf("passei\n");
        usuario[0].Posts[j] = (char *)malloc(sizeof(char)*130);
        printf("passei\n");
        if(usuario[0].Posts == NULL){
          printf("Erro de alocamento no %d\n",j);
        }
      }
      printf("passei\n");
      setbuf(stdin,NULL);
      fgets(usuario[0].Posts[usuario[0].NPosts],130,stdin);
      printf("passei\n");
      usuario[0].NPosts = usuario[0].NPosts + 1;
      printf("%d\n",usuario[0].NPosts);
      break;
  }





  //FINAL
  t = NumUsuarios(usuarios);
  printf("t = %d\n",t);
  for(int i = 0;i<t;i++){
    remove(usuario[i].NomeArquivo);
    usuario[i].Ausuario = fopen(usuario[i].NomeArquivo,"a+");
    fseek(usuario[i].Ausuario,0,SEEK_SET);
    fwrite(&usuario[i].nome,sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    printf("Escrevi %s",usuario[i].nome);
    fwrite(&usuario[i].NPosts,sizeof(int),1,usuario[i].Ausuario);
    printf("Escrevi %d\n",usuario[i].NPosts);
    for(int j = 0;j<usuario[i].NPosts;j++){
      fwrite(&usuario[i].Posts[j],sizeof(char)*130,1,usuario[i].Ausuario);
      printf("Escrevi %s",usuario[i].Posts[j]);
    }
    fwrite(&usuario[i].NSeguindo,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      fwrite(&usuario[i].Seguindo[j],sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    }
    fwrite(&usuario[i].NSeguidores,sizeof(int),1,usuario[i].Ausuario);
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      fwrite(&usuario[i].Seguidores[j],sizeof(char)*TAMNOME,1,usuario[i].Ausuario);
    }
    fclose(usuario[i].Ausuario);
  }
  fclose(usuarios);
  for(int i = 0;i<t;i++){
    for(int j = 0;j<usuario[i].NPosts;j++){
      free(usuario[i].Posts[j]);
    }
    free(usuario[i].Posts);
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      free(usuario[i].Seguindo[j]);
    }
    free(usuario[i].Seguindo);
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      free(usuario[i].Seguidores[j]);
    }
    free(usuario[i].Seguidores);
  }
  free(usuario);
}