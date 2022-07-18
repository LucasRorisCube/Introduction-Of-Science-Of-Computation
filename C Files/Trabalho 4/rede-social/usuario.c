#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"

#define TAMNOME 40

void InserirUsuario(dados *usuario,int *NumUsuarios){
  printf("Digite o nick desejado: ");
  setbuf(stdin,NULL);
  fgets(usuario[*NumUsuarios].nick,TAMNOME,stdin);
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
  setbuf(stdin,NULL);
  char remover[40];
  fgets(remover,TAMNOME,stdin);
  int r = 0;
  while(strcmp(remover,usuario[r++].nick) != 0);
  r--;
  for(int i = r;i<*NumUsuarios;i++){
    usuario[i] = usuario[i+1];
  }
  *NumUsuarios = *NumUsuarios - 1;
}

