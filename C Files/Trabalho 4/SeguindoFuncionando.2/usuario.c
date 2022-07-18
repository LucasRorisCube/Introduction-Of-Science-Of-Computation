#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "funcoesbd.h"

#define TAMNOME 40

void InserirUsuario(dados *usuario,int *NumUsuarios){
  printf("Digite o nick desejado: ");
  int r = -2;
  while(r != -1){
    setbuf(stdin,NULL);
    fgets(usuario[*NumUsuarios].nick,TAMNOME,stdin);
    r = VerificarExistencia(usuario[*NumUsuarios].nick,usuario,NumUsuarios);
    if(r != -1){
      printf("Nick ja existente, tente outro!\n");
    }
  }
  printf("Digite o nome desejado: ");
  setbuf(stdin,NULL);
  fgets(usuario[*NumUsuarios].nome,TAMNOME,stdin);
  usuario[*NumUsuarios].NPosts = 0;
  usuario[*NumUsuarios].NSeguindo = 0;
  usuario[*NumUsuarios].NSeguidores = 0;
  *NumUsuarios = *NumUsuarios + 1;
}

void RemoverUsuario(dados *usuario,int *NumUsuarios){
  printf("Digite o nick a ser removido: ");
  char remover[40];
  int r = -1;
  while(r == -1){
    setbuf(stdin,NULL);
    fgets(remover,TAMNOME,stdin);
    r = VerificarExistencia(remover,usuario,NumUsuarios);
    if(r == -1){
      printf("Usuario nao existe, tente outro!\n");
    }
  }

  for(int i = r;i<*NumUsuarios;i++){
    usuario[i] = usuario[i+1];
  }
  *NumUsuarios = *NumUsuarios - 1;
}

void Seguir(dados *usuario,int r,int *NumUsuarios){
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

}