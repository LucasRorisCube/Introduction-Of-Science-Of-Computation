#include <stdio.h>

int main(void) {
  int temp[7];
  int soma=0;
  for(int i = 0;i<7;i++){
    scanf("%d",&temp[i]);
    soma+=temp[i];
  }
  float media = soma/7.0;
  int res = 0;
  for(int i =0;i<7;i++){
    if(temp[i]>media){
      res++;
    }
  }
  printf("%d",res);
}
