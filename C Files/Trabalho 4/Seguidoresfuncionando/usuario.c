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
  

}