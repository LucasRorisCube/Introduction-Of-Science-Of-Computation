#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"

#define TAMNOME 40

int VerificarExistencia(char nick[40],dados *usuario,int *NumUsuarios){
  for(int i = 0;i<*NumUsuarios;i++){
    if(strcmp(nick,usuario[i].nick) == 0){
      return i;
    }
  }
  return -1;
}

void Inicializar(int *NumUsuarios,FILE *Usuarios,dados *usuario,FILE *ArquivoPosts,dadosPosts *Posts,int *NumPosts){
  fseek(Usuarios,0,SEEK_END);
  if(ftell(Usuarios) != 0){
    fseek(Usuarios,0,SEEK_SET);
    fread(NumUsuarios,sizeof(int),1,Usuarios);
  } else {
    fseek(Usuarios,0,SEEK_SET);
    *NumUsuarios = 0;
  }
  for(int i = 0;i<*NumUsuarios;i++){
    fread(usuario[i].nick,sizeof(char)*TAMNOME,1,Usuarios);
    fread(usuario[i].nome,sizeof(char)*TAMNOME,1,Usuarios);
    fread(&usuario[i].NPosts,sizeof(int),1,Usuarios);

    ///Seguindo
    fread(&usuario[i].NSeguindo,sizeof(int),1,Usuarios);
    usuario[i].Seguindo = NULL;
    usuario[i].Seguindo = realloc(usuario[i].Seguindo,sizeof(char *)*usuario[i].NSeguindo);
    if(usuario[i].Seguindo == NULL){
        printf("Erro de alocamento no Seguindo\n");
        exit(1);
      }

    for(int j = 0;j<usuario[i].NSeguindo;j++){
      usuario[i].Seguindo[j] = NULL;
      usuario[i].Seguindo[j] = realloc(usuario[i].Seguindo[j],sizeof(char)*TAMNOME);
      if(usuario[i].Seguindo[j] == NULL){
        printf("Erro de alocamento no Seguindo**\n");
        exit(1);
      }
      fread(usuario[i].Seguindo[j],sizeof(char)*TAMNOME,1,Usuarios);
    }

    ///Seguidores
    fread(&usuario[i].NSeguidores,sizeof(int),1,Usuarios);
    usuario[i].Seguidores = NULL;
    usuario[i].Seguidores = realloc(usuario[i].Seguidores,sizeof(char *)*usuario[i].NSeguidores);
    if(usuario[i].Seguidores == NULL){
        printf("Erro de alocamento no Seguidores\n");
        exit(1);
      }

    for(int j = 0;j<usuario[i].NSeguidores;j++){
      usuario[i].Seguidores[j] = NULL;
      usuario[i].Seguidores[j] = realloc(usuario[i].Seguidores[j],sizeof(char)*TAMNOME);
      if(usuario[i].Seguidores[j] == NULL){
        printf("Erro de alocamento no Seguidores**\n");
        exit(1);
      }
      fread(usuario[i].Seguidores[j],sizeof(char)*TAMNOME,1,Usuarios);
    }
  }
  
  for(int i = 0;i<*NumPosts;i++){
    fread(Posts[i].nick,sizeof(char)*40,1,ArquivoPosts);
    fread(Posts[i].Post,sizeof(char)*130,1,ArquivoPosts);
  }
}

void Salvar(int *NumUsuarios,FILE *Usuarios,dados *usuario,FILE *ArquivoPosts,dadosPosts *Posts,int *NumPosts){
  fclose(Usuarios);
  remove("Usuarios.txt");
  Usuarios = fopen("Usuarios.txt","a+");
  fclose(ArquivoPosts);
  remove("Posts.txt");
  ArquivoPosts = fopen("Posts.txt","a+");
  fwrite(NumUsuarios,sizeof(int),1,Usuarios);
  for(int i = 0;i<*NumUsuarios;i++){
    fwrite(usuario[i].nick,sizeof(char)*TAMNOME,1,Usuarios);
    fwrite(usuario[i].nome,sizeof(char)*TAMNOME,1,Usuarios);
    fwrite(&usuario[i].NPosts,sizeof(int),1,Usuarios);
    ///Seguindo
    fwrite(&usuario[i].NSeguindo,sizeof(int),1,Usuarios);
    for(int j = 0;j<usuario[i].NSeguindo;j++){
      fwrite(usuario[i].Seguindo[j],sizeof(char)*TAMNOME,1,Usuarios);
    }
    ///Seguidores
    
    fwrite(&usuario[i].NSeguidores,sizeof(int),1,Usuarios);
    for(int j = 0;j<usuario[i].NSeguidores;j++){
      fwrite(usuario[i].Seguidores[j],sizeof(char)*TAMNOME,1,Usuarios);
    }
  }
  fclose(Usuarios);
  Usuarios = fopen("Usuarios.txt","a+");
  fclose(ArquivoPosts);
  ArquivoPosts = fopen("Posts.txt","a+");
}

void Terminar(int *NumUsuarios,FILE *Usuarios,dados *usuario,FILE *ArquivoPosts,dadosPosts *Posts,int *NumPosts){
  for(int i = 0;i<*NumPosts;i++){
    fwrite(Posts[i].nick,sizeof(char)*TAMNOME,1,ArquivoPosts);
    fwrite(Posts[i].Post,sizeof(char)*130,1,ArquivoPosts);
  }
  //Frees
  for(int i = 0;i<*NumUsuarios;i++){
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
  free(NumPosts);
  free(NumUsuarios);
  free(Posts);
  free(usuario);
  fclose(Usuarios);
  fclose(ArquivoPosts);
}

