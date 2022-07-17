#include <stdio.h>

int main(void) {
int a,b,c,res = 0;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
if (a>b){
  if(a>c) res = a;
  else res = c;
}
else{
  if(b>c) res = b;
  else res = c;
}
printf("%d\n",res);
}
