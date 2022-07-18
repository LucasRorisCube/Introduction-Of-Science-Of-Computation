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
        for(int j = 0;j<usuario[i].NSeguindo;j++){
          printf("%s",usuario[i].Seguindo[j]);
        }
        printf("%d\n",usuario[i].NSeguidores);
        for(int j = 0;j<usuario[i].NSeguidores;j++){
          printf("%s",usuario[i].Seguidores[j]);
        }
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
        if(y == 3){
          printf("Digite o nick do usuario para segui-lo: ");
          int s = -1;
          while(s == -1){
            setbuf(stdin,NULL);
            char seguir[40];
            fgets(seguir,40,stdin);
            s = VerificarExistencia(seguir,usuario,NumUsuarios);
            if(s == -1){
              printf("Usuario nao existe, tente outro!\n");
            }
          }
          printf("Passei\n");
            usuario[r].Seguindo = realloc(usuario[r].Seguindo,sizeof(char *)*(usuario[r].NSeguindo+1));
            if(usuario[r].Seguindo == NULL){
              printf("Erro de alocamento no Seguindo\n");
              exit(1);
            }
            printf("Passei\n");
            usuario[r].Seguindo[usuario[r].NSeguindo] = NULL;
            usuario[r].Seguindo[usuario[r].NSeguindo] = realloc(usuario[r].Seguindo[usuario[r].NSeguindo],sizeof(char)*40);
            if(usuario[r].Seguindo[usuario[r].NSeguindo] == NULL){
              printf("Erro de alocamento no Seguindo**\n");
              exit(1);
            }
            printf("Passei\n");
            usuario[s].Seguidores = realloc(usuario[s].Seguidores,sizeof(char *)*(usuario[s].NSeguidores+1));
            if(usuario[s].Seguidores == NULL){
              printf("Erro de alocamento no Seguidores\n");
              exit(1);
            }
            printf("Passei\n");
            usuario[s].Seguidores[usuario[s].NSeguidores] = NULL;
            usuario[s].Seguidores[usuario[s].NSeguidores] = realloc(usuario[s].Seguidores[usuario[s].NSeguidores],sizeof(char)*40);
            if(usuario[s].Seguidores[usuario[s].NSeguidores] == NULL){
              printf("Erro de alocamento no Seguidores**\n");
              exit(1);
            }
            printf("Passei\n");
            strcpy(usuario[r].Seguindo[usuario[r].NSeguindo],usuario[s].nick);
          usuario[r].NSeguindo = usuario[r].NSeguindo + 1;
          strcpy(usuario[s].Seguidores[usuario[s].NSeguidores],usuario[r].nick);
          usuario[s].NSeguidores = usuario[s].NSeguidores + 1;
          //Seguir(usuario,r,NumUsuarios);
          Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
        }
      }
    }
  }
  Salvar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
  Terminar(NumUsuarios,Usuarios,usuario,ArquivoPosts,Posts,NumPosts);
}
