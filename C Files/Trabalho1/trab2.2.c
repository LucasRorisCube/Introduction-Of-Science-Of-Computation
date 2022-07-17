#include <stdio.h>
int main(void) {
  int n;
  scanf("%d",&n);
  if(n>1){
    for(int i = 2;n!=1;i++){
      while(n%i==0){
        n = n/i;
        printf("%d x ",i);
      }
    }
  }
  printf("\b\b");
}