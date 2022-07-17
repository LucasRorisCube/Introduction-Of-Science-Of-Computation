#include <stdio.h>

int main(void) {
int L,V = 0;
float res,A,M = 0;
scanf("%d",&L);
scanf("%f",&M);
scanf("%f",&A);
scanf("%d",&V);
if(V>L){
  res = M + (V-L)*A;
}
printf("%.2f",res);
}
