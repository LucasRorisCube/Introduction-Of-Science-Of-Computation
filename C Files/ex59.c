#include <stdio.h>

int main(void) {
int x,y;
scanf("%d",&x);
int res = 0;
int vm = 0;
int i;
for(i=0;i<x;i++){
  scanf("%d",&y);
  if(y==vm) res++;
  if (y > vm){
    res = 0;
    res++;
    vm = y;
  }
}
printf("%d",res);
}