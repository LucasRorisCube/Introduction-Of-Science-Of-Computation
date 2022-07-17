#include <stdio.h>
int fatorial(int n){
  int res = 1;
  int i;
  for(i=1;i<=n;i++){
    res = res * i;
}
return(res);
}

int main(void) {
int n,soma = 0;
scanf("%d",&n);
int i;
for(i=0;i<=n;i++){
soma = soma + fatorial(i);
}
printf("%d\n",soma);
}