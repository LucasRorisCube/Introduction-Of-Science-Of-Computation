#include <stdio.h>
int main(void) {
int y;
int soma = 0;
float n = 0;
int m = 0;
float i = 0;
scanf("%d",&y);
while (y>=0){
  soma+=y;
  n+=1;
  if(y>=18) m+=1;
  if(y>75) i+=1;
  scanf("%d",&y);
}
float media = soma/n;
float porc = (i/n)*100;
printf("%.2f\n",media);
printf("%d\n",m);
printf("%.2f%%",porc);
}
