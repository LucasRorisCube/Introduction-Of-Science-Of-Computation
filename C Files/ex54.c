#include <stdio.h>
int main(void) {
int n,i,x;
int max = -10000000;
int min = 10000000;
int soma = 0;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&x);
if(x>max) max = x;
if(x<min) min = x;
soma = soma + x;
}
printf("%d\n",max);
printf("%d\n",min);
printf("%d\n",soma);
}
