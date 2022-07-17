#include <stdio.h>

int main(void) {
int n;
scanf("%d",&n);
int aux = 0;
for(int i = 0;i*(i+1)*(i+2)<=n;i++){
  if((i*(i+1)*(i+2)) == n){
    printf("S");
    aux++;
  }
}
if(aux == 0) printf("N");
}