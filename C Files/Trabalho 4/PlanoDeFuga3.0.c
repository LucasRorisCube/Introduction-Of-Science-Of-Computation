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
  if(usuario.NomeArquivo[r-2] == '\n'){
    usuario.NomeArquivo[r-2] = '\0';
  }
  if(usuario.NomeArquivo[r-1] == '\n'){
    usuario.NomeArquivo[r-1] = '\0';
  }
  usuario.Ausuario = fopen(usuario.NomeArquivo,"a+");
  setbuf(stdin,NULL);
  fgets(usuario.nome,40,usuario.Ausuario);
  ///
  fscanf(usuario.Ausuario,"%d",&usuario.NPosts);
  usuario.Posts = (char **)malloc(sizeof(char *)*usuario.NPosts);
  if(usuario.Posts == NULL){
      printf("Erro de alocamento no Posts\n");
    }
    for(int i = 0;i<usuario.NPosts;i++){
      usuario.Posts[i] = (char*)malloc(sizeof(char)*130);
      if(usuario.Posts[i] == NULL){
        printf("Erro de alocamento no Post %d\n",i);
      }
    }
  for(int i = 0;i<usuario.NPosts;i++){
    setbuf(stdin,NULL);
    fgets(usuario.Posts[i],40,usuario.Ausuario);
  }
  ///
  fscanf(usuario.Ausuario,"%d",&usuario.NSeguindo);
  usuario.Seguindo = (char **)malloc(sizeof(char *)*usuario.NSeguindo);
  if(usuario.Seguindo == NULL){
      printf("Erro de alocamento no Seguindo\n");
    }
    for(int i = 0;i<usuario.NSeguindo;i++){
      usuario.Seguindo[i] = (char*)malloc(sizeof(char)*40);
      if(usuario.Seguindo[i] == NULL){
        printf("Erro de alocamento no Seguindo %d\n",i);
      }
    }
  for(int i = 0;i<usuario.NSeguindo;i++){
    setbuf(stdin,NULL);
    fgets(usuario.Seguindo[i],40,usuario.Ausuario);
  }
  ///
  fscanf(usuario.Ausuario,"%d",&usuario.NSeguidores);
  usuario.Seguidores = (char **)malloc(sizeof(char *)*usuario.NSeguidores);
  if(usuario.Seguidores == NULL){
      printf("Erro de alocamento no Seguidores\n");
    }
    for(int i = 0;i<usuario.NSeguidores;i++){
      usuario.Seguidores[i] = (char*)malloc(sizeof(char)*40);
      if(usuario.Seguidores[i] == NULL){
        printf("Erro de alocamento no Seguidores %d\n",i);
      }
    }
  for(int i = 0;i<usuario.NSeguidores;i++){
    setbuf(stdin,NULL);
    fgets(usuario.Seguidores[i],40,usuario.Ausuario);
  }
  ///
  return usuario;
}

dados Cadastro(FILE *Usuarios){
  int n = NumUsuarios(Usuarios);
  dados usuario;
  printf("Escreve o seu nick: ");
  setbuf(stdin,NULL);
  fgets(usuario.nick,40,stdin);
  printf("Escreve o seu nome: ");
  setbuf(stdin,NULL);
  fgets(usuario.nome,40,stdin);
  strcpy(usuario.NomeArquivo,usuario.nick);
  int r = 0;
  while(usuario.NomeArquivo[r++] != '\0');
  usuario.NomeArquivo[r-2] = '.';
  usuario.NomeArquivo[r-1] = 't';
  usuario.NomeArquivo[r] = 'x';
  usuario.NomeArquivo[r+1] = 't';
  usuario.NomeArquivo[r+2] = '\0';
  usuario.Ausuario = fopen(usuario.NomeArquivo,"a+");
  usuario.NPosts = 0;
  usuario.NSeguindo = 0;
  usuario.NSeguidores = 0;
  return usuario;
}

void RemoverUsuario(FILE *Usuarios,dados *usuario){
  printf("Digite o nick do usuario que deseja deletar: ");
  setbuf(stdin,NULL);
  char remover[40];
  fgets(remover,40,stdin);
  int r = 0;
  while(strcmp(remover,usuario[r++].nick) != 0);
  printf("Removi %s",remover);
  for(int i = r-1;i<NumUsuarios(Usuarios)-1;i++){
    usuario[i] = usuario[i+1];
  }
  remove(usuario[r].NomeArquivo);
}

void Finalizar(dados *usuario,FILE *Usuarios,int NumeroUsu){
  for(int i = 0;i<NumeroUsu;i++){
    remove(usuario[i].NomeArquivo);
    usuario[i].Ausuario = fopen(usuario[i].NomeArquivo,"a+");
    fprintf(usuario[i].Ausuario,"%s",usuario[i].nome);
    fprintf(usuario[i].Ausuario,"%d\n",usuario[i].NPosts);
    for(int j = 0;j<usuario[i].NPosts;j++){
      fprintf(usuario[i].Ausuario,"%s",usuario[i].Posts[j]);
    }
    fprintf(usuario[i].Ausuario,"%d\n",usuario[i].NSeguindo);
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      fprintf(usuario[i].Ausuario,"%s",usuario[i].Seguindo[j]);
    }
    fprintf(usuario[i].Ausuario,"%d\n",usuario[i].NSeguidores);
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      fprintf(usuario[i].Ausuario,"%s",usuario[i].Seguidores[j]);
    }
    fclose(usuario[i].Ausuario);
  }
  remove("usuarios.txt");
  Usuarios = fopen("usuarios.txt","a+");
  for(int i = 0;i<NumeroUsu;i++){
    fprintf(Usuarios,"%s",usuario[i].nick);
    fprintf(Usuarios,"%s\n",usuario[i].NomeArquivo);
  }
  fclose(Usuarios);
  for(int i = 0;i<NumeroUsu;i++){
    for(int j = 0;j<usuario[i].NPosts;j++){
      free(usuario[i].Posts[j]);
    }
    if(usuario[i].NPosts > 0){
      free(usuario[i].Posts);
    }
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      free(usuario[i].Seguindo[j]);
    }
    if(usuario[i].NSeguindo > 0){
      free(usuario[i].Seguindo);
    }
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      free(usuario[i].Seguidores[j]);
    }
    if(usuario[i].NSeguidores > 0){
      free(usuario[i].Seguidores);
    }
  }
  free(usuario);
}

void ConsultarUsuario(dados *usuario){
  printf("Digite o nick do usuario que deseja consultar: ");
  setbuf(stdin,NULL);
  char consultar[40];
  fgets(consultar,40,stdin);
  int r = 0;
  while(strcmp(consultar,usuario[r++].nick) != 0);
  r--;
  printf("%s",usuario[r].nome);
  printf("%d\n",usuario[r].NPosts);
  for(int i = 0;i<usuario[r].NPosts;i++){
    printf("%s",usuario[r].Posts[i]);
  }
  printf("%d\n",usuario[r].NSeguindo);
  for(int i = 0;i<usuario[r].NSeguindo;i++){
    printf("%s",usuario[r].Seguindo[i]);
  }
  printf("%d\n",usuario[r].NSeguidores);
  for(int i = 0;i<usuario[r].NSeguidores;i++){
    printf("%s",usuario[r].Seguidores[i]);
  }
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
  printf("Numero de Usuarios: %d\n",NumUsuarios(Usuarios));
  
  for(int i = 0;i<NumUsuarios(Usuarios);i++){
    usuario[i] = Inicializar(Usuarios);
  }
  
  int NumeroUsu = NumUsuarios(Usuarios);
  while(1){
    int x;
    printf("Escolha uma opção: ");
    scanf("%d",&x);
    fseek(Usuarios,0,SEEK_SET);
    if(x == 1){
      for(int i = 0;i<NumeroUsu;i++){
        printf("%s",usuario[i].nick);
        printf("%s\n",usuario[i].NomeArquivo);
      }
    }
    if(x == 2){
      usuario[NumeroUsu] = Cadastro(Usuarios);
      NumeroUsu = NumeroUsu + 1;
    }
    if(x == 3){
      RemoverUsuario(Usuarios,usuario);
      NumeroUsu = NumeroUsu - 1;
    }
    if(x == 4){
      Finalizar(usuario,Usuarios,NumeroUsu);
      break;
    }
    if(x == 5){
      ConsultarUsuario(usuario);
    }
  }
 






  //FINAL
}