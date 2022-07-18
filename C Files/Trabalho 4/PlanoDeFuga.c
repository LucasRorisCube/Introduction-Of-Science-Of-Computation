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

int NumUsuarios(FILE *Usuario){
  int c = ftell(Usuario);
  fseek(Usuario,0,SEEK_SET);
  char teste[40];
  int count = 0;
  for(int i = 0;!feof(Usuario);i++){
    fgets(teste,40,Usuario);
    count++;
  }
  count = count/2;
  fseek(Usuario,c,SEEK_SET);
  return count;
}

dados Inicializar(FILE *Usuarios){
  dados usuario;
  fgets(usuario.nick,40,Usuarios);
  fgets(usuario.NomeArquivo,40,Usuarios);
  int r = 0;
  while(usuario.NomeArquivo[r++] != '\0');
  usuario.NomeArquivo[r-2] = '\0';
  usuario.Ausuario = fopen(usuario.NomeArquivo,"a+");
  return usuario;
}

int main(void) {
  FILE *Usuarios = fopen("usuarios.txt","a+");
  dados *usuario;
  usuario = (dados*)malloc(sizeof(dados)*10);
  if(usuario == NULL){
    printf("Erro no alocamento\n");
    exit(1);
  }
  fseek(Usuarios,0,SEEK_SET);
  printf("%d\n",NumUsuarios(Usuarios));
  
  for(int i = 0;i<NumUsuarios(Usuarios);i++){
    usuario[i] = Inicializar(Usuarios);
  }
  
  int x;
  scanf("%d",&x);
  fseek(Usuarios,0,SEEK_SET);
  if(x == 1){
    for(int i = 0;i<NumUsuarios(Usuarios);i++){
      printf("%s",usuario[i].nick);
      printf("%s\n",usuario[i].NomeArquivo);
    }
  }
  if(x == 2){
    int n = NumUsuarios(Usuarios);
    setbuf(stdin,NULL);
    fgets(usuario[n].nick,40,stdin);
    strcpy(usuario[n].NomeArquivo,usuario[n].nick);
    int r = 0;
    while(usuario[n].NomeArquivo[r++] != '\0');
    usuario[n].NomeArquivo[r-2] = '.';
    usuario[n].NomeArquivo[r-1] = 't';
    usuario[n].NomeArquivo[r] = 'x';
    usuario[n].NomeArquivo[r+1] = 't';
    //usuario[n].NomeArquivo[r+2] = '\n';
    usuario[n].NomeArquivo[r+2] = '\0';
    fseek(Usuarios,0,SEEK_END);
    fprintf(Usuarios,"%s",usuario[n].nick);
    fprintf(Usuarios,"%s\n",usuario[n].NomeArquivo);
    usuario[n].Ausuario = fopen(usuario[n].NomeArquivo,"a+");
  }

 






  //FINAL
  for(int i = 0;i<NumUsuarios(Usuarios);i++){
    fclose(usuario[i].Ausuario);
  }
  free(usuario);
  fclose(Usuarios);
}