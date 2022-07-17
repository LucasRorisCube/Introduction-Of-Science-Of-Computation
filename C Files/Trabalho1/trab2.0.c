#include <stdio.h>


int prim(int n){
  int j = 1;
  int div = 0;
  while (j<=n){
    if(n%j==0){
      div++;
    }
    j++;
  }
  return div;
}

int pp(int h){
  int i = 0;
  for(int k = 0;k<h;k++){
    int div = 0;
    for(int j=0;div != 2;j++){
      i++;
      div = prim(i);
    }
  }
  return i;
}


int main(void) {
  int n;
  scanf("%d",&n);
  int aux = 0;
  if(n>1){
    for(int i = 1;n != 1;i++){
      for(int j = 0;n%pp(i)==0;j++){  
        n = n/pp(i);
        if(aux == 0){
          printf("%d",pp(i));
          aux = 1;
        } else {
          printf(" x %d",pp(i));
        }
      }
    }
  }
}