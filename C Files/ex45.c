#include <stdio.h>

int main(void) {
int n,m = 0;
scanf("%d",&n);
scanf("%d",&m);
int soma = 1;
int i;
for(i=0;i<m;i++){
  soma = soma * n;
}
printf("%d",soma);
}