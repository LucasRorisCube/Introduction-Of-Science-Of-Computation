#include <stdio.h>

int main(void) {
int n,c,m;
int x = 0;
int res = 0;
scanf("%d",&n);
scanf("%d",&c);
scanf("%d",&m);
while (n>=c){
  n = n-c;
  x++;
  res++;
}
while (x>=m){
  x = x-m;
  x++;
  res++;
}
printf("%d\n",res);
}