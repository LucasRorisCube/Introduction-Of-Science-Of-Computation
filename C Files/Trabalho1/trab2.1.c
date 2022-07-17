#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int aux = 0;
  if(n>1){
    for(int i = 2;n!=1;i++){
      while(n%i==0){
        n = n/i;
        if(aux == 0){
          printf("%d",i);
          aux++;
        } else{
          printf(" x %d",i);
        }
      }
    }
  }
}