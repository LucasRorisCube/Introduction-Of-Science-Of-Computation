#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "funcoesbd.h"
#include "usuario.h"
#include "post.h"

#define TAMNOME 40

int main(void) {
  FILE *Usuarios = fopen("Usuarios.txt","a+");
  FILE *ArquivoPosts = fopen("Posts.txt","a+");
  dadosPosts *Posts = NULL;
  int *NumUsuarios = NULL;
  NumUsuarios = realloc(NumUsuarios,sizeof(int));
  if(NumUsuarios == NULL){
    printf("Erro de alocamento no usuario\n");
    exit(1);
  }
  int *NumPosts = NULL;
  NumPosts = realloc(NumPosts,sizeof(int)*1);
  if(NumPosts == NULL){
    printf("Erro de alocamento no usuario\n");
    exit(1);
  }
  dados *usuario = NULL;
  usuario = realloc(usuario,sizeof(dados)*10);
  if(usuario == NULL){
    printf("Erro de alocamento no usuario\n");
    exit(1);
  }
  fseek(ArquivoPosts,0,SEEK_END);
  *NumPosts = ftell(ArquivoPosts);
  *NumPosts = *NumPosts/(sizeof(char)*40+sizeof(char)*130);
  Posts = realloc(Posts,sizeof(dadosPosts)*(*NumPosts));
  if(Posts == NULL){
    printf("Erro de alocamento no Posts\n");
    exit(1);
  }
  fseek(ArquivoPosts,0,SEEK_SET);
  Inicializar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);

  int x = 0;
  while(x != 7){
    printf("Escolha uma opcao: ");
    scanf("%d",&x);
    if(x == 1){
      InserirUsuario(usuario,NumUsuarios);
      Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
    }
    if(x == 2){
      RemoverUsuario(usuario,NumUsuarios);
      Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
    }
    if(x == 3){
      for(int i = 0;i<*NumUsuarios;i++){
        printf("%s",usuario[i].nome);
        printf("%s",usuario[i].nick);
        printf("%d\n",usuario[i].NPosts);
        for(int j = 0;j<*NumPosts;j++){
          if(strcmp(usuario[i].nick,Posts[j].nick) == 0){
            printf("%s",Posts[j].Post);
          }
        }
        printf("%d\n",usuario[i].NSeguindo);
        printf("%d\n",usuario[i].NSeguidores);
        printf("%d\n",*NumPosts);
        printf("%d\n",*NumUsuarios);
      }
    }
    if(x == 4){
      printf("Digite o nick do login: ");
      int r = -1;
      while(r == -1){
        setbuf(stdin,NULL);
        char login[40];
        fgets(login,40,stdin);
        r = VerificarExistencia(login,usuario,NumUsuarios);
        if(r == -1){
          printf("Usuarios nao existe, tente outro!\n");
        }
      }
      int y = 0;
      while(y != 7){
        printf("Digite um opcao: ");
        scanf("%d",&y);
        if(y == 1){
        Posts = realloc(Posts,sizeof(dadosPosts)*(*NumPosts+1));
        if(Posts == NULL){
          printf("Erro no alocamento Posts ADDPosts\n");
          exit(1);
        }
        AdicionarPost(Posts,NumPosts,usuario,r);
        Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
        }
        if(y == 2){
          RemoverPost(Posts,NumPosts,usuario,r);
          Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
        }
      }
    }
  }
  Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
  Terminar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
}
