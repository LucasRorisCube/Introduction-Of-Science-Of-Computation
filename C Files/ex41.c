#include <stdio.h>
int prim(int n){
  int i = 1;
  int div = 0;
  while (i<=n){
    if(n%i==0){
      div++;
    }
    i++;
  }
  return(div);
}


int main(void) {
int n = 0;
int i = 0;
int div = 0;
int soma = 0;
scanf("%d",&n);
for(i = 0;i<=n;i++){
  div = prim(i);
  if(div == 2){
    soma = soma + i;
  }
}
printf("%d\n",soma);
}

