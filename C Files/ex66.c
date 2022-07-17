#include <stdio.h>
int main(void) {
  long int y = 0;
  scanf("%ld",&y);
  int numero[10];

  int i;
  for(i=0;y>=10;i++){
    numero[i]=y%10;
    y = y/10;
  }
  numero[i]=y;
  int nd = i+1;
  
  int pali = 1;
  for(int i = 0,j = nd-1;i<j && pali == 1;i++,j--){
    if(numero[i]!=numero[j]){
      pali=0;
    }
  }
    if(pali==1){
      printf("S");
    } else{
    printf("N");
    }
  }
  