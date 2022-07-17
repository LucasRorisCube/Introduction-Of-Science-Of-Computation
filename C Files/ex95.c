#include <stdio.h>

int main(void) {
  int n;
  scanf("%d",&n);
  if(n==0){
    printf("0");
  } else {
    int bin[n/2];
    int a;
    for(a = 0;n>0;a++){
      bin[a] = n%2;
      n = n/2;
    }
    a--;
    for(int i = a;i!=-1;i--){
     printf("%d",bin[i]);
    }
  }
}