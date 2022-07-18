#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"

#define TAMNOME 40

void AdicionarPost(dadosPosts *Posts,int *NumPosts,dados *usuario,int r){
  setbuf(stdin,NULL);
  
  fgets(Posts[*NumPosts].Post,130,stdin);
  strcpy(Posts[*NumPosts].nick,usuario[r].nick);
  printf("%s",Posts[*NumPosts].Post);
  usuario[r].NPosts = usuario[r].NPosts + 1;
  *NumPosts = *NumPosts + 1;
}

void RemoverPost(dadosPosts *Posts,int *NumPosts,dados *usuario,int r){
  setbuf(stdin,NULL);
  int aux = 0;
  for(int i = 0;i<*NumPosts;i++){
    if(strcmp(usuario[r].nick,Posts[i].nick) == 0){
      printf("%d - %s",aux,Posts[i].Post);
      aux++;
    }
  }
  *NumPosts = *NumPosts - 1;
  int x;
  scanf("%d",&x);
  int flag = 0;
  for(int i = 0;i<*NumPosts;i++){
    if(strcmp(usuario[r].nick,Posts[i].nick) == 0){
      flag++;
    }
    if(flag > x){
      Posts[i] = Posts[i+1];
    }
  }
  usuario[r].NPosts = usuario[r].NPosts - 1;
}

