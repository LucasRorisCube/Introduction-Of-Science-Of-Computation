#include <stdio.h>

int main(void) {
float X,V1,V2,A,res;
scanf("%f",&X);
scanf("%f",&V1);
scanf("%f",&V2);
scanf("%f",&A);
if (A>X) res = A*V2;
else res = A*V1;
printf("%.2f",res);
}
