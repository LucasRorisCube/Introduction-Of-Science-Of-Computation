#include <stdio.h>
int main(void) {
  int N;
  scanf("%d",&N);

  int primnumero = 0;
  while (N>9){
    if(primnumero == 0 && N%10 == 0){
    } else {
      printf("%d",N%10);
      primnumero = 1;
    }
    N = N/10;
  }
  printf("%d",N);
}