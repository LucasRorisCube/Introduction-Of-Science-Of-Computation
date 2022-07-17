#include <stdio.h>

int main(void) {
float a,b,c,delta;
float res;
scanf("%f",&a);
scanf("%f",&b);
scanf("%f",&c);
delta = b*b-4*a*c;
if (delta < 0){
  printf("nan");
}
else{
  res = -b/a;
  printf("%.2f\n",res);
}
}